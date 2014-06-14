// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.

#include "Simulator.hh"
#include <omniORB4/IOP_S.h>
#include <omniORB4/IOP_C.h>
#include <omniORB4/callDescriptor.h>
#include <omniORB4/callHandle.h>
#include <omniORB4/objTracker.h>


OMNI_USING_NAMESPACE(omni)

static const char* _0RL_library_version = omniORB_4_1;



ssr::Simulator_ptr ssr::Simulator_Helper::_nil() {
  return ::ssr::Simulator::_nil();
}

::CORBA::Boolean ssr::Simulator_Helper::is_nil(::ssr::Simulator_ptr p) {
  return ::CORBA::is_nil(p);

}

void ssr::Simulator_Helper::release(::ssr::Simulator_ptr p) {
  ::CORBA::release(p);
}

void ssr::Simulator_Helper::marshalObjRef(::ssr::Simulator_ptr obj, cdrStream& s) {
  ::ssr::Simulator::_marshalObjRef(obj, s);
}

ssr::Simulator_ptr ssr::Simulator_Helper::unmarshalObjRef(cdrStream& s) {
  return ::ssr::Simulator::_unmarshalObjRef(s);
}

void ssr::Simulator_Helper::duplicate(::ssr::Simulator_ptr obj) {
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);
}

ssr::Simulator_ptr
ssr::Simulator::_duplicate(::ssr::Simulator_ptr obj)
{
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);
  return obj;
}

ssr::Simulator_ptr
ssr::Simulator::_narrow(::CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}


ssr::Simulator_ptr
ssr::Simulator::_unchecked_narrow(::CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_uncheckedNarrow(_PD_repoId);
  return e ? e : _nil();
}

ssr::Simulator_ptr
ssr::Simulator::_nil()
{
#ifdef OMNI_UNLOADABLE_STUBS
  static _objref_Simulator _the_nil_obj;
  return &_the_nil_obj;
#else
  static _objref_Simulator* _the_nil_ptr = 0;
  if( !_the_nil_ptr ) {
    omni::nilRefLock().lock();
    if( !_the_nil_ptr ) {
      _the_nil_ptr = new _objref_Simulator;
      registerNilCorbaObject(_the_nil_ptr);
    }
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
#endif
}

const char* ssr::Simulator::_PD_repoId = "IDL:ssr/Simulator:1.0";


ssr::_objref_Simulator::~_objref_Simulator() {
  
}


ssr::_objref_Simulator::_objref_Simulator(omniIOR* ior, omniIdentity* id) :
   omniObjRef(::ssr::Simulator::_PD_repoId, ior, id, 1)
   
   
{
  _PR_setobj(this);
}

void*
ssr::_objref_Simulator::_ptrToObjRef(const char* id)
{
  if( id == ::ssr::Simulator::_PD_repoId )
    return (::ssr::Simulator_ptr) this;
  
  if( id == ::CORBA::Object::_PD_repoId )
    return (::CORBA::Object_ptr) this;

  if( omni::strMatch(id, ::ssr::Simulator::_PD_repoId) )
    return (::ssr::Simulator_ptr) this;
  
  if( omni::strMatch(id, ::CORBA::Object::_PD_repoId) )
    return (::CORBA::Object_ptr) this;

  return 0;
}

// Proxy call descriptor class. Mangled signature:
//  _cssr_mRETURN__VALUE_i_cstring
class _0RL_cd_698515b8e775a3ed_00000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_698515b8e775a3ed_00000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ssr::RETURN_VALUE result;
};

void _0RL_cd_698515b8e775a3ed_00000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);

}

void _0RL_cd_698515b8e775a3ed_00000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();

}

void _0RL_cd_698515b8e775a3ed_00000000::marshalReturnedValues(cdrStream& _n)
{
  result >>= _n;

}

void _0RL_cd_698515b8e775a3ed_00000000::unmarshalReturnedValues(cdrStream& _n)
{
  (ssr::RETURN_VALUE&)result <<= _n;

}

const char* const _0RL_cd_698515b8e775a3ed_00000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_10000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_00000000* tcd = (_0RL_cd_698515b8e775a3ed_00000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->loadProject(tcd->arg_0);


}

ssr::RETURN_VALUE ssr::_objref_Simulator::loadProject(const char* path)
{
  _0RL_cd_698515b8e775a3ed_00000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_10000000, "loadProject", 12);
  _call_desc.arg_0 = path;

  _invoke(_call_desc);
  return _call_desc.result;


}
// Proxy call descriptor class. Mangled signature:
//  _cssr_mRETURN__VALUE
class _0RL_cd_698515b8e775a3ed_20000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_698515b8e775a3ed_20000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  
  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ssr::RETURN_VALUE result;
};

void _0RL_cd_698515b8e775a3ed_20000000::marshalReturnedValues(cdrStream& _n)
{
  result >>= _n;

}

void _0RL_cd_698515b8e775a3ed_20000000::unmarshalReturnedValues(cdrStream& _n)
{
  (ssr::RETURN_VALUE&)result <<= _n;

}

const char* const _0RL_cd_698515b8e775a3ed_20000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_30000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_20000000* tcd = (_0RL_cd_698515b8e775a3ed_20000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->start();


}

ssr::RETURN_VALUE ssr::_objref_Simulator::start()
{
  _0RL_cd_698515b8e775a3ed_20000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_30000000, "start", 6);


  _invoke(_call_desc);
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_40000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_20000000* tcd = (_0RL_cd_698515b8e775a3ed_20000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->pause();


}

ssr::RETURN_VALUE ssr::_objref_Simulator::pause()
{
  _0RL_cd_698515b8e775a3ed_20000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_40000000, "pause", 6);


  _invoke(_call_desc);
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_50000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_20000000* tcd = (_0RL_cd_698515b8e775a3ed_20000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->resume();


}

ssr::RETURN_VALUE ssr::_objref_Simulator::resume()
{
  _0RL_cd_698515b8e775a3ed_20000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_50000000, "resume", 7);


  _invoke(_call_desc);
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_60000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_20000000* tcd = (_0RL_cd_698515b8e775a3ed_20000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->stop();


}

ssr::RETURN_VALUE ssr::_objref_Simulator::stop()
{
  _0RL_cd_698515b8e775a3ed_20000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_60000000, "stop", 5);


  _invoke(_call_desc);
  return _call_desc.result;


}
// Proxy call descriptor class. Mangled signature:
//  _cssr_mRETURN__VALUE_i_cstring_i_cstring
class _0RL_cd_698515b8e775a3ed_70000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_698515b8e775a3ed_70000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::String_var arg_1_;
  const char* arg_1;
  ssr::RETURN_VALUE result;
};

void _0RL_cd_698515b8e775a3ed_70000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  _n.marshalString(arg_1,0);

}

void _0RL_cd_698515b8e775a3ed_70000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  arg_1_ = _n.unmarshalString(0);
  arg_1 = arg_1_.in();

}

void _0RL_cd_698515b8e775a3ed_70000000::marshalReturnedValues(cdrStream& _n)
{
  result >>= _n;

}

void _0RL_cd_698515b8e775a3ed_70000000::unmarshalReturnedValues(cdrStream& _n)
{
  (ssr::RETURN_VALUE&)result <<= _n;

}

const char* const _0RL_cd_698515b8e775a3ed_70000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_80000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_70000000* tcd = (_0RL_cd_698515b8e775a3ed_70000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->spawnRobotRTC(tcd->arg_0, tcd->arg_1);


}

ssr::RETURN_VALUE ssr::_objref_Simulator::spawnRobotRTC(const char* objectName, const char* arg)
{
  _0RL_cd_698515b8e775a3ed_70000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_80000000, "spawnRobotRTC", 14);
  _call_desc.arg_0 = objectName;
  _call_desc.arg_1 = arg;

  _invoke(_call_desc);
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_90000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_70000000* tcd = (_0RL_cd_698515b8e775a3ed_70000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->spawnRangeRTC(tcd->arg_0, tcd->arg_1);


}

ssr::RETURN_VALUE ssr::_objref_Simulator::spawnRangeRTC(const char* objectName, const char* arg)
{
  _0RL_cd_698515b8e775a3ed_70000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_90000000, "spawnRangeRTC", 14);
  _call_desc.arg_0 = objectName;
  _call_desc.arg_1 = arg;

  _invoke(_call_desc);
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_a0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_70000000* tcd = (_0RL_cd_698515b8e775a3ed_70000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->spawnCameraRTC(tcd->arg_0, tcd->arg_1);


}

ssr::RETURN_VALUE ssr::_objref_Simulator::spawnCameraRTC(const char* objectName, const char* arg)
{
  _0RL_cd_698515b8e775a3ed_70000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_a0000000, "spawnCameraRTC", 15);
  _call_desc.arg_0 = objectName;
  _call_desc.arg_1 = arg;

  _invoke(_call_desc);
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_b0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_00000000* tcd = (_0RL_cd_698515b8e775a3ed_00000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->killRobotRTC(tcd->arg_0);


}

ssr::RETURN_VALUE ssr::_objref_Simulator::killRobotRTC(const char* objectName)
{
  _0RL_cd_698515b8e775a3ed_00000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_b0000000, "killRobotRTC", 13);
  _call_desc.arg_0 = objectName;

  _invoke(_call_desc);
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_c0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_20000000* tcd = (_0RL_cd_698515b8e775a3ed_20000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->killAllRobotRTC();


}

ssr::RETURN_VALUE ssr::_objref_Simulator::killAllRobotRTC()
{
  _0RL_cd_698515b8e775a3ed_20000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_c0000000, "killAllRobotRTC", 16);


  _invoke(_call_desc);
  return _call_desc.result;


}
// Proxy call descriptor class. Mangled signature:
//  _cssr_mRETURN__VALUE_i_cstring_o_cRTC_mPose3D
class _0RL_cd_698515b8e775a3ed_d0000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_698515b8e775a3ed_d0000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  RTC::Pose3D arg_1_;
  RTC::Pose3D* arg_1;
  ssr::RETURN_VALUE result;
};

void _0RL_cd_698515b8e775a3ed_d0000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);

}

void _0RL_cd_698515b8e775a3ed_d0000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();

}

void _0RL_cd_698515b8e775a3ed_d0000000::marshalReturnedValues(cdrStream& _n)
{
  result >>= _n;
  (const RTC::Pose3D&) *arg_1 >>= _n;

}

void _0RL_cd_698515b8e775a3ed_d0000000::unmarshalReturnedValues(cdrStream& _n)
{
  (ssr::RETURN_VALUE&)result <<= _n;
  (RTC::Pose3D&)*arg_1 <<= _n;

}

const char* const _0RL_cd_698515b8e775a3ed_d0000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_e0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_d0000000* tcd = (_0RL_cd_698515b8e775a3ed_d0000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->getObjectPose(tcd->arg_0, *tcd->arg_1);


}

ssr::RETURN_VALUE ssr::_objref_Simulator::getObjectPose(const char* objectName, ::RTC::Pose3D& pose)
{
  _0RL_cd_698515b8e775a3ed_d0000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_e0000000, "getObjectPose", 14);
  _call_desc.arg_0 = objectName;
  _call_desc.arg_1 = &(::RTC::Pose3D&) pose;

  _invoke(_call_desc);
  return _call_desc.result;


}
// Proxy call descriptor class. Mangled signature:
//  _cssr_mRETURN__VALUE_i_cstring_i_cRTC_mPose3D
class _0RL_cd_698515b8e775a3ed_f0000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_698515b8e775a3ed_f0000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  RTC::Pose3D arg_1_;
  const RTC::Pose3D* arg_1;
  ssr::RETURN_VALUE result;
};

void _0RL_cd_698515b8e775a3ed_f0000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  (const RTC::Pose3D&) *arg_1 >>= _n;

}

void _0RL_cd_698515b8e775a3ed_f0000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  (RTC::Pose3D&)arg_1_ <<= _n;
  arg_1 = &arg_1_;

}

void _0RL_cd_698515b8e775a3ed_f0000000::marshalReturnedValues(cdrStream& _n)
{
  result >>= _n;

}

void _0RL_cd_698515b8e775a3ed_f0000000::unmarshalReturnedValues(cdrStream& _n)
{
  (ssr::RETURN_VALUE&)result <<= _n;

}

const char* const _0RL_cd_698515b8e775a3ed_f0000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_01000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_f0000000* tcd = (_0RL_cd_698515b8e775a3ed_f0000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->setObjectPose(tcd->arg_0, *tcd->arg_1);


}

ssr::RETURN_VALUE ssr::_objref_Simulator::setObjectPose(const char* objectName, const ::RTC::Pose3D& pose)
{
  _0RL_cd_698515b8e775a3ed_f0000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_01000000, "setObjectPose", 14);
  _call_desc.arg_0 = objectName;
  _call_desc.arg_1 = &(::RTC::Pose3D&) pose;

  _invoke(_call_desc);
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_11000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_00000000* tcd = (_0RL_cd_698515b8e775a3ed_00000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->synchronizeRTC(tcd->arg_0);


}

ssr::RETURN_VALUE ssr::_objref_Simulator::synchronizeRTC(const char* rtcFullPath)
{
  _0RL_cd_698515b8e775a3ed_00000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_11000000, "synchronizeRTC", 15);
  _call_desc.arg_0 = rtcFullPath;

  _invoke(_call_desc);
  return _call_desc.result;


}
// Proxy call descriptor class. Mangled signature:
//  _cssr_mRETURN__VALUE_o_cssr_mStringSeq
class _0RL_cd_698515b8e775a3ed_21000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_698515b8e775a3ed_21000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  
  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ssr::StringSeq_var arg_0;
  ssr::RETURN_VALUE result;
};

void _0RL_cd_698515b8e775a3ed_21000000::marshalReturnedValues(cdrStream& _n)
{
  result >>= _n;
  (const ssr::StringSeq&) arg_0 >>= _n;

}

void _0RL_cd_698515b8e775a3ed_21000000::unmarshalReturnedValues(cdrStream& _n)
{
  (ssr::RETURN_VALUE&)result <<= _n;
  arg_0 = new ssr::StringSeq;
  (ssr::StringSeq&)arg_0 <<= _n;

}

const char* const _0RL_cd_698515b8e775a3ed_21000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_31000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_21000000* tcd = (_0RL_cd_698515b8e775a3ed_21000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->getSynchronizingRTCs(tcd->arg_0.out());


}

ssr::RETURN_VALUE ssr::_objref_Simulator::getSynchronizingRTCs(::ssr::StringSeq_out fullPaths)
{
  _0RL_cd_698515b8e775a3ed_21000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_31000000, "getSynchronizingRTCs", 21);


  _invoke(_call_desc);
  fullPaths = _call_desc.arg_0._retn();
  return _call_desc.result;


}
// Proxy call descriptor class. Mangled signature:
//  _cssr_mRETURN__VALUE_o_cfloat
class _0RL_cd_698515b8e775a3ed_41000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_698515b8e775a3ed_41000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  
  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::Float arg_0;
  ssr::RETURN_VALUE result;
};

void _0RL_cd_698515b8e775a3ed_41000000::marshalReturnedValues(cdrStream& _n)
{
  result >>= _n;
  arg_0 >>= _n;

}

void _0RL_cd_698515b8e775a3ed_41000000::unmarshalReturnedValues(cdrStream& _n)
{
  (ssr::RETURN_VALUE&)result <<= _n;
  (::CORBA::Float&)arg_0 <<= _n;

}

const char* const _0RL_cd_698515b8e775a3ed_41000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_51000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_41000000* tcd = (_0RL_cd_698515b8e775a3ed_41000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->getSimulationTimeStep(tcd->arg_0);


}

ssr::RETURN_VALUE ssr::_objref_Simulator::getSimulationTimeStep(::CORBA::Float& timeStep)
{
  _0RL_cd_698515b8e775a3ed_41000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_51000000, "getSimulationTimeStep", 22);


  _invoke(_call_desc);
  timeStep = _call_desc.arg_0;
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_61000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_41000000* tcd = (_0RL_cd_698515b8e775a3ed_41000000*)cd;
  ssr::_impl_Simulator* impl = (ssr::_impl_Simulator*) svnt->_ptrToInterface(ssr::Simulator::_PD_repoId);
  tcd->result = impl->getSimulationTime(tcd->arg_0);


}

ssr::RETURN_VALUE ssr::_objref_Simulator::getSimulationTime(::CORBA::Float& time)
{
  _0RL_cd_698515b8e775a3ed_41000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_61000000, "getSimulationTime", 18);


  _invoke(_call_desc);
  time = _call_desc.arg_0;
  return _call_desc.result;


}
ssr::_pof_Simulator::~_pof_Simulator() {}


omniObjRef*
ssr::_pof_Simulator::newObjRef(omniIOR* ior, omniIdentity* id)
{
  return new ::ssr::_objref_Simulator(ior, id);
}


::CORBA::Boolean
ssr::_pof_Simulator::is_a(const char* id) const
{
  if( omni::ptrStrMatch(id, ::ssr::Simulator::_PD_repoId) )
    return 1;
  
  return 0;
}

const ssr::_pof_Simulator _the_pof_ssr_mSimulator;

ssr::_impl_Simulator::~_impl_Simulator() {}


::CORBA::Boolean
ssr::_impl_Simulator::_dispatch(omniCallHandle& _handle)
{
  const char* op = _handle.operation_name();

  if( omni::strMatch(op, "loadProject") ) {

    _0RL_cd_698515b8e775a3ed_00000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_10000000, "loadProject", 12, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "start") ) {

    _0RL_cd_698515b8e775a3ed_20000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_30000000, "start", 6, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "pause") ) {

    _0RL_cd_698515b8e775a3ed_20000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_40000000, "pause", 6, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "resume") ) {

    _0RL_cd_698515b8e775a3ed_20000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_50000000, "resume", 7, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "stop") ) {

    _0RL_cd_698515b8e775a3ed_20000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_60000000, "stop", 5, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "spawnRobotRTC") ) {

    _0RL_cd_698515b8e775a3ed_70000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_80000000, "spawnRobotRTC", 14, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "spawnRangeRTC") ) {

    _0RL_cd_698515b8e775a3ed_70000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_90000000, "spawnRangeRTC", 14, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "spawnCameraRTC") ) {

    _0RL_cd_698515b8e775a3ed_70000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_a0000000, "spawnCameraRTC", 15, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "killRobotRTC") ) {

    _0RL_cd_698515b8e775a3ed_00000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_b0000000, "killRobotRTC", 13, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "killAllRobotRTC") ) {

    _0RL_cd_698515b8e775a3ed_20000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_c0000000, "killAllRobotRTC", 16, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "getObjectPose") ) {

    _0RL_cd_698515b8e775a3ed_d0000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_e0000000, "getObjectPose", 14, 1);
    _call_desc.arg_1 = &_call_desc.arg_1_;
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "setObjectPose") ) {

    _0RL_cd_698515b8e775a3ed_f0000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_01000000, "setObjectPose", 14, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "synchronizeRTC") ) {

    _0RL_cd_698515b8e775a3ed_00000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_11000000, "synchronizeRTC", 15, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "getSynchronizingRTCs") ) {

    _0RL_cd_698515b8e775a3ed_21000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_31000000, "getSynchronizingRTCs", 21, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "getSimulationTimeStep") ) {

    _0RL_cd_698515b8e775a3ed_41000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_51000000, "getSimulationTimeStep", 22, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "getSimulationTime") ) {

    _0RL_cd_698515b8e775a3ed_41000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_61000000, "getSimulationTime", 18, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }


  return 0;
}

void*
ssr::_impl_Simulator::_ptrToInterface(const char* id)
{
  if( id == ::ssr::Simulator::_PD_repoId )
    return (::ssr::_impl_Simulator*) this;
  
  if( id == ::CORBA::Object::_PD_repoId )
    return (void*) 1;

  if( omni::strMatch(id, ::ssr::Simulator::_PD_repoId) )
    return (::ssr::_impl_Simulator*) this;
  
  if( omni::strMatch(id, ::CORBA::Object::_PD_repoId) )
    return (void*) 1;
  return 0;
}

const char*
ssr::_impl_Simulator::_mostDerivedRepoId()
{
  return ::ssr::Simulator::_PD_repoId;
}

ssr::SimulatedRobot_ptr ssr::SimulatedRobot_Helper::_nil() {
  return ::ssr::SimulatedRobot::_nil();
}

::CORBA::Boolean ssr::SimulatedRobot_Helper::is_nil(::ssr::SimulatedRobot_ptr p) {
  return ::CORBA::is_nil(p);

}

void ssr::SimulatedRobot_Helper::release(::ssr::SimulatedRobot_ptr p) {
  ::CORBA::release(p);
}

void ssr::SimulatedRobot_Helper::marshalObjRef(::ssr::SimulatedRobot_ptr obj, cdrStream& s) {
  ::ssr::SimulatedRobot::_marshalObjRef(obj, s);
}

ssr::SimulatedRobot_ptr ssr::SimulatedRobot_Helper::unmarshalObjRef(cdrStream& s) {
  return ::ssr::SimulatedRobot::_unmarshalObjRef(s);
}

void ssr::SimulatedRobot_Helper::duplicate(::ssr::SimulatedRobot_ptr obj) {
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);
}

ssr::SimulatedRobot_ptr
ssr::SimulatedRobot::_duplicate(::ssr::SimulatedRobot_ptr obj)
{
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);
  return obj;
}

ssr::SimulatedRobot_ptr
ssr::SimulatedRobot::_narrow(::CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}


ssr::SimulatedRobot_ptr
ssr::SimulatedRobot::_unchecked_narrow(::CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_uncheckedNarrow(_PD_repoId);
  return e ? e : _nil();
}

ssr::SimulatedRobot_ptr
ssr::SimulatedRobot::_nil()
{
#ifdef OMNI_UNLOADABLE_STUBS
  static _objref_SimulatedRobot _the_nil_obj;
  return &_the_nil_obj;
#else
  static _objref_SimulatedRobot* _the_nil_ptr = 0;
  if( !_the_nil_ptr ) {
    omni::nilRefLock().lock();
    if( !_the_nil_ptr ) {
      _the_nil_ptr = new _objref_SimulatedRobot;
      registerNilCorbaObject(_the_nil_ptr);
    }
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
#endif
}

const char* ssr::SimulatedRobot::_PD_repoId = "IDL:ssr/SimulatedRobot:1.0";


ssr::_objref_SimulatedRobot::~_objref_SimulatedRobot() {
  
}


ssr::_objref_SimulatedRobot::_objref_SimulatedRobot(omniIOR* ior, omniIdentity* id) :
   omniObjRef(::ssr::SimulatedRobot::_PD_repoId, ior, id, 1)
   
   
{
  _PR_setobj(this);
}

void*
ssr::_objref_SimulatedRobot::_ptrToObjRef(const char* id)
{
  if( id == ::ssr::SimulatedRobot::_PD_repoId )
    return (::ssr::SimulatedRobot_ptr) this;
  
  if( id == ::CORBA::Object::_PD_repoId )
    return (::CORBA::Object_ptr) this;

  if( omni::strMatch(id, ::ssr::SimulatedRobot::_PD_repoId) )
    return (::ssr::SimulatedRobot_ptr) this;
  
  if( omni::strMatch(id, ::CORBA::Object::_PD_repoId) )
    return (::CORBA::Object_ptr) this;

  return 0;
}

// Local call call-back function.
static void
_0RL_lcfn_698515b8e775a3ed_71000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_698515b8e775a3ed_21000000* tcd = (_0RL_cd_698515b8e775a3ed_21000000*)cd;
  ssr::_impl_SimulatedRobot* impl = (ssr::_impl_SimulatedRobot*) svnt->_ptrToInterface(ssr::SimulatedRobot::_PD_repoId);
  tcd->result = impl->getJointTagNames(tcd->arg_0.out());


}

ssr::RETURN_VALUE ssr::_objref_SimulatedRobot::getJointTagNames(::ssr::StringSeq_out tags)
{
  _0RL_cd_698515b8e775a3ed_21000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_71000000, "getJointTagNames", 17);


  _invoke(_call_desc);
  tags = _call_desc.arg_0._retn();
  return _call_desc.result;


}
ssr::_pof_SimulatedRobot::~_pof_SimulatedRobot() {}


omniObjRef*
ssr::_pof_SimulatedRobot::newObjRef(omniIOR* ior, omniIdentity* id)
{
  return new ::ssr::_objref_SimulatedRobot(ior, id);
}


::CORBA::Boolean
ssr::_pof_SimulatedRobot::is_a(const char* id) const
{
  if( omni::ptrStrMatch(id, ::ssr::SimulatedRobot::_PD_repoId) )
    return 1;
  
  return 0;
}

const ssr::_pof_SimulatedRobot _the_pof_ssr_mSimulatedRobot;

ssr::_impl_SimulatedRobot::~_impl_SimulatedRobot() {}


::CORBA::Boolean
ssr::_impl_SimulatedRobot::_dispatch(omniCallHandle& _handle)
{
  const char* op = _handle.operation_name();

  if( omni::strMatch(op, "getJointTagNames") ) {

    _0RL_cd_698515b8e775a3ed_21000000 _call_desc(_0RL_lcfn_698515b8e775a3ed_71000000, "getJointTagNames", 17, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }


  return 0;
}

void*
ssr::_impl_SimulatedRobot::_ptrToInterface(const char* id)
{
  if( id == ::ssr::SimulatedRobot::_PD_repoId )
    return (::ssr::_impl_SimulatedRobot*) this;
  
  if( id == ::CORBA::Object::_PD_repoId )
    return (void*) 1;

  if( omni::strMatch(id, ::ssr::SimulatedRobot::_PD_repoId) )
    return (::ssr::_impl_SimulatedRobot*) this;
  
  if( omni::strMatch(id, ::CORBA::Object::_PD_repoId) )
    return (void*) 1;
  return 0;
}

const char*
ssr::_impl_SimulatedRobot::_mostDerivedRepoId()
{
  return ::ssr::SimulatedRobot::_PD_repoId;
}

POA_ssr::Simulator::~Simulator() {}

POA_ssr::SimulatedRobot::~SimulatedRobot() {}

