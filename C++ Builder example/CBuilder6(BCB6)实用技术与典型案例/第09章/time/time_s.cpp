/*
 * Copyright 2001 Borland Software Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#include <corbapch.h>
#pragma hdrstop
#include "time_s.hh"

#if defined(__BORLANDC__)
#pragma option push
#pragma warn -8060
#endif

static CORBA::MethodDescription _sk_MyTime_Time_methods[] = {
  {"get_gmt", POA_MyTime::Time::_get_gmt}
};

const CORBA::TypeInfo POA_MyTime::Time::_skel_info(
 "MyTime::Time", NULL, (CORBA::ULong) 1, _sk_MyTime_Time_methods         ,
 NULL, 0, NULL);
         
const CORBA::TypeInfo *POA_MyTime::Time::_type_info() const {
  return &_skel_info;
}

MyTime::Time_ptr POA_MyTime::Time::_this() {
  return (MyTime::Time *)(PortableServer_ServantBase::_this()->_safe_narrow(*MyTime::Time::_desc()));
}

void *POA_MyTime::Time::_safe_narrow(const CORBA::TypeInfo& _info) const {
  if (_info == _skel_info) {
    return (void *)this;
  }

  if (_info == PortableServer_ServantBase::_skel_info) {
    return (void *)(PortableServer_ServantBase *)this;
  }
  return 0;
}

POA_MyTime::Time * POA_MyTime::Time::_narrow(PortableServer::ServantBase *_obj) {
  if (!_obj) {
    return (POA_MyTime::Time*)NULL;
  } else {
    return (Time*)_obj->_safe_narrow(_skel_info);
  }
}

#if defined(__BORLANDC__)
#pragma option push
#pragma warn -8057
#pragma warn -8004
#endif
void POA_MyTime::Time::_get_gmt (void *_obj, CORBA::MarshalInBuffer &_istrm,
                                 const char *_oper, VISReplyHandler& _handler) {
  VISCLEAR_EXCEP
  VISistream& _vistrm = _istrm;
  POA_MyTime::Time *_impl = (POA_MyTime::Time*)_obj;
MyTime::TimeOfDay _ret = _impl->get_gmt();
  CORBA::MarshalOutBuffer_var _obuf = _handler.create_reply();
  VISostream& _ostrm = *VISostream::_downcast(_obuf);
  VISIF_EXCEP(return;)
  _ostrm << _ret;
}

#if defined(__BORLANDC__)
 #pragma option pop
#endif

#if defined(__BORLANDC__)
#pragma option pop
#endif

