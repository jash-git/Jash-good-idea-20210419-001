/*
 * Copyright 2001 Borland Software Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#include <corbapch.h>
#pragma hdrstop
#include "SIGNAL_s.hh"

#if defined(__BORLANDC__)
#pragma option push
#pragma warn -8060
#endif

static CORBA::MethodDescription _sk_Signal_methods[] = {
  {"GetSignal", POA_Signal::_GetSignal}
};

const CORBA::TypeInfo POA_Signal::_skel_info(
 "Signal", NULL, (CORBA::ULong) 1, _sk_Signal_methods         , NULL, 0, NULL);
         
const CORBA::TypeInfo *POA_Signal::_type_info() const {
  return &_skel_info;
}

Signal_ptr POA_Signal::_this() {
  return (Signal *)(PortableServer_ServantBase::_this()->_safe_narrow(*Signal::_desc()));
}

void *POA_Signal::_safe_narrow(const CORBA::TypeInfo& _info) const {
  if (_info == _skel_info) {
    return (void *)this;
  }

  if (_info == PortableServer_ServantBase::_skel_info) {
    return (void *)(PortableServer_ServantBase *)this;
  }
  return 0;
}

POA_Signal * POA_Signal::_narrow(PortableServer::ServantBase *_obj) {
  if (!_obj) {
    return (POA_Signal*)NULL;
  } else {
    return (POA_Signal*)_obj->_safe_narrow(_skel_info);
  }
}

#if defined(__BORLANDC__)
#pragma option push
#pragma warn -8057
#pragma warn -8004
#endif
void POA_Signal::_GetSignal (void *_obj, CORBA::MarshalInBuffer &_istrm,
                             const char *_oper, VISReplyHandler& _handler) {
  VISCLEAR_EXCEP
  VISistream& _vistrm = _istrm;
  POA_Signal *_impl = (POA_Signal*)_obj;
  CORBA::Long _local_n;
  CORBA::Long _local_fs;
  SignalType_var _local_output;

      _vistrm >> _local_n;

        _vistrm >> _local_fs;
      _vistrm >> _local_output;

    _impl->GetSignal( _local_n,  _local_fs,  _local_output);
      CORBA::MarshalOutBuffer_var _obuf = _handler.create_reply();
      VISostream& _ostrm = *VISostream::_downcast(_obuf);
      VISIF_EXCEP(return;)
      _ostrm << _local_output;
    }

    #if defined(__BORLANDC__)
     #pragma option pop
    #endif

    #if defined(__BORLANDC__)
    #pragma option pop
    #endif

