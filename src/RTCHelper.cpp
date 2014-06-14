#include "rtm/Manager.h"
#include "rtm/CorbaNaming.h"
#include "rtm/CorbaConsumer.h"
#include "rtm/OpenHRPExecutionContext.h"
#include "coil/Properties.h"
#include <iostream>
#include <sstream>
#include "VREPRTC.h"
#include "RangeRTC.h"
#include "CameraRTC.h"
#include "RobotRTC.h"
#include "RTCHelper.h"
//#include "v_repExtRTC.h"
#include "v_repLib.h"

using namespace RTC;

ManagerRunner* pRunner;
void MyModuleInit(RTC::Manager* manager);

int ManagerRunner::svc() {
  int argc = 1;
  char* argv[1] = {"vrep"};
  
  RTC::Manager* manager;
  manager = RTC::Manager::init(argc, argv);
  manager->init(argc, argv);
  manager->setModuleInitProc(MyModuleInit);
  manager->activateManager();
  manager->runManager(false);
  return 0;
}

void MyModuleInit(RTC::Manager* manager)
{
  RobotRTCInit(manager);
  RangeRTCInit(manager);
  CameraRTCInit(manager);
  VREPRTCInit(manager);
  manager->registerECFactory("SynchExtTriggerEC", 
			     RTC::ECCreate<RTC::OpenHRPExecutionContext>,
			     RTC::ECDelete<RTC::OpenHRPExecutionContext>);
  /*
			     ::coil::Creator< ::RTC::ExecutionContextBase,
			     ::RTC::OpenHRPExecutionContext>,            
			     ::coil::Destructor< ::RTC::ExecutionContextBase,         
			     ::RTC::OpenHRPExecutionContext>);    
  */
  //OpenHRPExecutionContextInit(manager);
  RTC::RtcBase* comp;

  // Create a component automatically
  comp = manager->createComponent("VREPRTC");
  if (comp==NULL)
  {
    std::cerr << "Component create failed." << std::endl;
    abort();
  }

  return;
}

bool initRTM() {
  pRunner = new ManagerRunner();
  return true;
}

bool exitRTM() {
  std::cout << "Shutting Down RTC::Manager......" << std::endl;
  RTC::Manager& manager = RTC::Manager::instance();
  manager.shutdown();
  //manager.terminate();
  std::cout << "Waiting RTC::Manager......" << std::endl;
  //manager.join();
  delete pRunner;
  
  return false;
}

#include <vector>
#include <string>
#include <sstream>

static int indent = 0;
static simInt getChildren(simInt h, std::vector<simInt>& jointHandles, std::vector<std::string>& jointNames, simInt typeFilter) {
  indent += 1;
  int i = 0;
  simInt r = 0;
  while (1) {
    r = simGetObjectChild(h, i++);
    if (r < 0) {
      indent -= 1;
      return 0;
    }
    std::string name = simGetObjectName(r);
    simInt type = simGetObjectType(r);
    if (type == typeFilter) {
      jointHandles.push_back(r);
      jointNames.push_back(name);
    }
    getChildren(r, jointHandles, jointNames, typeFilter);
  }
  indent -= 1;
  return 0;
}

int spawnRangeRTC(std::string& key, std::string& arg) {
  std::cout << " -- Spawning RTC (objectName = " << key << ")" << std::endl;
  simInt objHandle = simGetObjectHandle(key.c_str());
  if (objHandle == -1) {
    std::cout << " --- Failed to get object handle." << std::endl;
    return -1;
  }

  std::vector<simInt> sensorHandles;
  std::vector<std::string> sensorNames;
  getChildren(objHandle, sensorHandles, sensorNames, sim_object_proximitysensor_type);

  if (sensorHandles.size() !=1 || sensorNames.size() != 1) {
    std::cout << " --- Failed to get object handle." << std::endl;
    return -1;
  }

  
  simInt bufSize = 4096;
  simInt tubeHandle = simTubeOpen(0, (key+"_HOKUYO").c_str(), bufSize, false);
  if (tubeHandle < 0) {
    std::cout << " --- Can not open Communication Tube to " << key << std::endl;
    return -1;
  }

  std::ostringstream arg_oss;
  arg_oss << "RangeRTC?" 
	  << "exec_cxt.periodic.type=" << "SynchExtTriggerEC" << "&"
	  << "conf.default.objectName=" << key << "&"
    ///<< "conf.default.activeJointNames=" << names << "&"
	  << "conf.__innerparam.objectName=" << key << "&"
	  << "conf.__innerparam.argument=" << arg << "&"
	  << "conf.__innerparam.objectHandle=" << objHandle << "&"
	  << "conf.__innerparam.tubeHandle=" << tubeHandle<< "&"
	  << "conf.__innerparam.bufSize=" << bufSize << "&"
	  << arg;
  RTObject_impl* cmp = RTC::Manager::instance().createComponent(arg_oss.str().c_str());
  robotContainer.push(cmp->getObjRef(), key);
  return 0;
}


int spawnCameraRTC(std::string& key, std::string& arg) {
  std::cout << " -- Spawning Camera RTC (objectName = " << key << ")" << std::endl;
  simInt objHandle = simGetObjectHandle(key.c_str());
  if (objHandle == -1) {
    std::cout << " --- failed to get object handle." << std::endl;
    return -1;
  }

  simInt objType = simGetObjectType(objHandle);
  if (objType != sim_object_visionsensor_type) {
    std::cout << " --- Object "<<key << "is not Vision Sensor Type." << std::endl;
    return -1;
  }
  std::ostringstream arg_oss;
  arg_oss << "CameraRTC?" 
	  << "exec_cxt.periodic.type=" << "SynchExtTriggerEC" << "&"
	  << "conf.default.objectName=" << key << "&"
	  << "conf.__innerparam.objectName=" << key << "&"
	  << "conf.__innerparam.argument=" << arg << "&"
	  << "conf.__innerparam.objectHandle=" << objHandle << "&"
	  << arg;
  RTObject_impl* cmp = RTC::Manager::instance().createComponent(arg_oss.str().c_str());
  robotContainer.push(cmp->getObjRef(), key);

  return 0;
}


int spawnRobotRTC(std::string& key, std::string &arg) {
  std::cout << " -- Spawning RTC (objectName = " << key << ")" << std::endl;
  simInt objHandle = simGetObjectHandle(key.c_str());
  if (objHandle == -1) {
    std::cout << " --- failed to get object handle." << std::endl;
    return -1;
  }

  std::vector<simInt> jointHandles;
  std::vector<std::string> jointNames;
  getChildren(objHandle, jointHandles, jointNames, sim_object_joint_type);

  std::ostringstream name_oss;
  for (int i = 0;i < jointNames.size();i++) {
    name_oss << jointNames[i];
    if (i != jointNames.size()-1) { // If not the last object,
      name_oss << ",";
    }
  }
  std::string names = name_oss.str();

  std::ostringstream handle_oss;
  for (int i = 0;i < jointHandles.size();i++) {
    handle_oss << jointHandles[i];
    if (i != jointHandles.size()-1) { // If not the last object,
      handle_oss << ",";
    }
  }
  std::string handles = handle_oss.str();
  std::cout << " --- jointNames = " << names << std::endl;;
  std::cout << " --- jointHandles = " << handles << std::endl;;

  std::ostringstream arg_oss;
  arg_oss << "RobotRTC?" 
	  << "exec_cxt.periodic.type=" << "SynchExtTriggerEC" << "&"
	  << "conf.default.objectName=" << key << "&"
    	  << "conf.default.controlledJointNames=" << names << "&"
	  << "conf.default.observedJointNames=" << names << "&"
	  << "conf.__innerparam.objectName=" << key << "&"
	  << "conf.__innerparam.argument=" << arg << "&"
	  << "conf.__innerparam.objectHandle=" << objHandle << "&"
	  << "conf.__innerparam.allNames=" << names << "&"
	  << "conf.__innerparam.allHandles=" << handles << "&"
	  << arg;
  RTObject_impl* cmp = RTC::Manager::instance().createComponent(arg_oss.str().c_str());
  robotContainer.push(cmp->getObjRef(), key);
  return 0;
}

void startRTCs() {
  robotContainer.start();
}

void stopRTCs() {
  robotContainer.stop();
}

void tickRTCs(const float interval) {
  robotContainer.tick(interval);
}

int killRTC(const std::string& key) {
  return robotContainer.kill(key);
}

int killAllRTC() {
  return robotContainer.killall();
}

int syncRTC(const std::string& fullpath) {
  std::cout << " -- syncRTC to " << fullpath << std::endl;
  std::istringstream iss(fullpath);
  
  std::string nsAddr;
  std::string rtcName;

  std::getline(iss, nsAddr, '/');
  std::getline(iss, rtcName);
  std::cout << " --- NameServer : " << nsAddr << std::endl;
  std::cout << " --- RTC        : " << rtcName << std::endl;

  CorbaNaming corbaNaming((RTC::Manager::instance().getORB()),
			  nsAddr.c_str());

  RTC::CorbaConsumer<RTC::RTObject> corbaConsumer;
  try {
    ::CORBA::Object_ptr object = corbaNaming.resolve(rtcName.c_str());
    if(::CORBA::is_nil(object)) {
      std::cout << " --- resolve failed" << std::endl;
      return -1;
    }
    corbaConsumer.setObject(object);

    RTC::ExecutionContextList_var ecList = corbaConsumer->get_owned_contexts();
    double rate = ecList[0]->get_rate();
    std::cout << " --- EC[0]'s rate = " << rate << std::endl;

    std::cout << " --- Creating SynchExtTriggerEC" << std::endl;
    std::ostringstream oss;
    oss << "SynchExtTriggerEC";// << "?" << "exec_cxt.periodic.rate=" << rate;
    ///ExecutionContextBase* pEC = RTC::ExecutionContextFactory::instance().createObject(oss.str().c_str());
    ExecutionContextBase* pEC = RTC::Manager::instance().createContext(oss.str().c_str());
    pEC->setRate(rate);
    std::cout << " --- Add Component to ExecutionContext." << std::endl;
    RTC::RTObject_ptr rtc_ptr = RTC::RTObject::_narrow(corbaConsumer._ptr());
    
    RTC::ReturnCode_t r = pEC->addComponent(rtc_ptr);
    if (r != RTC::RTC_OK) {
      std::cout << " --- addComponent failed." << std::endl;
      return -1;
    }
    std::cout << " --- Starting ExecutionContext." << std::endl;
    pEC->start();
    //ecList[0]->stop();
    robotContainer.push(rtc_ptr, fullpath, pEC);
  } catch (CosNaming::NamingContext::NotFound& e) {
    std::cout << " --- Name resolve failed" << std::endl;
    return -1;
  }
  return 0;
}


int getSyncRTCs(std::vector<std::string>& stringList) {
  RobotRTCContainer::iterator it = robotContainer.begin();
  for(;it != robotContainer.end();++it) { 
    if (!(*it).isSimulatorRTC()) {
      stringList.push_back((*it).getObjectName());

    }
  }
  return 0;
}
