/*
 * Copyright 2001 Borland Software Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#include <corbapch.h>
#pragma hdrstop
#include "SIGNAL_c.hh"

#if defined(MSVCNEWDLL_BUG)
void *SignalType::operator new(size_t ts) {
  return ::operator new(ts);
}
void SignalType::operator delete(void *p) {
  ::operator delete(p);
}
#endif // MSVCNEWDLL_BUG

Ostream& operator<<(Ostream& _strm, const SignalType& _seq) {
  VISostream _ostrm(_strm);
  if (&_strm == &Cout || &_strm == &Cerr || &_strm == &Clog) {
    _pretty_print(_ostrm, _seq);
    _ostrm << endl;
  } else {
    _ostrm << _seq;
  }
  return _strm;
}
Istream& operator>>(Istream& _strm, SignalType& _obj) {
  VISistream _istrm(_strm);
  _istrm >> _obj;
  return _strm;
}
Istream& operator>>(Istream& _strm, SignalType_ptr& _ptr) {
  VISistream _istrm(_strm);
  _istrm >> _ptr;
  return _strm;
}

CORBA::Float* SignalType::allocbuf(CORBA::ULong _nelems) {
  if (_nelems) {
    return new CORBA::Float[_nelems];
  }
  return (CORBA::Float *)NULL;
}

void SignalType::freebuf(CORBA::Float *_data) {
  if (_data)
    delete[] _data;
}

SignalType::SignalType(CORBA::ULong _max) {
  _num_allocated = _max;
  _count = 0;
  _contents = allocbuf(_num_allocated);
  _release_flag = 1;
}

SignalType::SignalType(CORBA::ULong _max, CORBA::ULong _len,
                       CORBA::Float *_data, CORBA::Boolean _release) {
  _num_allocated = _max;
  _count = _len;
  _contents = _data;
  _release_flag = _release;
}

SignalType::SignalType(const SignalType& _seq) {
  _num_allocated = _seq._num_allocated;
  _count = _seq._count;
  _contents = allocbuf(_num_allocated);
  if (_num_allocated > 0) {
    memcpy(_contents, _seq._contents, (size_t(_count) * sizeof(CORBA::Float)));
  }
  _release_flag = 1;
}

SignalType::~SignalType() {
  if (_release_flag) 
    freebuf(_contents);
}

SignalType& SignalType::operator=(const SignalType& _seq) {
  if (_num_allocated < _seq._count) {
    if (_release_flag) 
      freebuf(_contents);
    else
      _release_flag = (CORBA::Boolean) 1;

    _contents = allocbuf(_seq._num_allocated);
    _num_allocated = _seq._num_allocated;
  }
  _count = _seq._count;
  if (_num_allocated > 0) {
    memcpy(_contents, _seq._contents, (size_t(_count) * sizeof(CORBA::Float)));
  }
  return *this;
}

void SignalType::length(CORBA::ULong _newlen) {
  if (_newlen > _num_allocated) {
    CORBA::Float *temp = allocbuf(_newlen);
    memcpy(temp, _contents, (size_t(_count) * sizeof(CORBA::Float)));
    if (_release_flag) 
      freebuf(_contents);
    else
      _release_flag = (CORBA::Boolean) 1;

    _num_allocated = _newlen;
    _contents = temp;
  }
  _count = _newlen;
}

void SignalType::replace(CORBA::ULong _max, CORBA::ULong _len,
                         CORBA::Float *_data, CORBA::Boolean _release) {
  if (_release_flag) 
    freebuf(_contents);
  _num_allocated = _max;
  _count = _len;
  _contents = _data;
  _release_flag = _release;
}

CORBA::Float *SignalType::get_buffer(CORBA::Boolean orphan) {
  if (orphan == (CORBA::Boolean) 1) {
    if (_release_flag == (CORBA::Boolean) 0)
      return (CORBA::Float*)NULL;
    else {
      _release_flag = (CORBA::Boolean) 0;
      return _contents;
    }
  } else
    return _contents;
}

const CORBA::Float* SignalType::get_buffer() const {
  // Do not use const_cast here because it might not be supported by the compiler
  return (const CORBA::Float*)(void*)_contents;
}

CORBA::Float& SignalType::operator[](CORBA::ULong _index) {
  if (_index >= _count) {
    VISTHROW(CORBA::BAD_PARAM())
#if defined(_VIS_NOEXCEPTIONS)
    VISRETURN(static CORBA::Float *_null = 0; return *_null;)
#endif
  }
  return _contents[_index];
}

const CORBA::Float& SignalType::operator[](CORBA::ULong _index) const {
  if (_index >= _count) {
    VISTHROW(CORBA::BAD_PARAM())
#if defined(_VIS_NOEXCEPTIONS)
    VISRETURN(static CORBA::Float *_null = 0; return (const CORBA::Float&)*_null;)
#endif
  }
  // Do not use const_cast here because it might not be supported by the compiler
  return *(const CORBA::Float*)(void*)&_contents[_index];
}

VISostream& operator<<(VISostream& _strm, const SignalType& _seq) {
  _strm << _seq._count;
  if (_seq._count > 0)
    _strm.put(_seq._contents, (unsigned int)_seq._count);
  return _strm;
}

VISistream& operator>>(VISistream& _strm,  SignalType& _seq) {
  CORBA::ULong t_count;
  _strm >> t_count;

  if (t_count > _seq._count) {
    if (_seq._num_allocated < t_count) {
      if (_seq._release_flag)
        SignalType::freebuf(_seq._contents);
      else
        _seq._release_flag = (CORBA::Boolean) 1;
      _seq._contents = SignalType::allocbuf(t_count);
      _seq._num_allocated = t_count;
    }
  }
  _seq._count = t_count;

  if (_seq._count > 0) {
    _strm.get(_seq._contents, (unsigned int)_seq._count);
  }
  return _strm;
}

VISostream& operator<<(VISostream& _strm, const SignalType* _obj) {
  if (!_obj)
    VISTHROW(CORBA::BAD_PARAM())
  else
    _strm << *_obj;
  return _strm;
}
VISistream& operator>>(VISistream& _strm, SignalType_ptr& _obj) {
  _obj = new SignalType();
  _strm >> *_obj;
  return _strm;
}

void _pretty_print(VISostream& _strm, const SignalType& _seq) {
  _strm << "SEQUENCE SignalType" << endl;
  _strm << "Number of Elements: " << _seq._count << endl;
  for (CORBA::ULong i=0; i < _seq._count; i++) {
    _strm << "[" << i << "]" << endl;
    _strm << "\t_contents[i]:" << endl;
    _strm << "\t" << _seq._contents[i] << endl;
    _strm << endl;
  }
}
CORBA::Float& SignalType_var::operator[](CORBA::ULong _index) {
  if (_ptr)
    return (*_ptr)[_index];
  static SignalType _tmp;
  return _tmp[_index];
}

const CORBA::Float& SignalType_var::operator[](CORBA::ULong _index) const {
  if (_ptr)
    return (*(const SignalType*)_ptr)[_index];
  static const SignalType _tmp;
  return _tmp[_index];
}

VISostream& operator<<(VISostream& _strm, const SignalType_var& _var) {
  if (!_var._ptr)
    VISTHROW(CORBA::BAD_PARAM())
  else
    _strm << *_var._ptr;
  return _strm;
}

VISistream& operator>>(VISistream& _strm, SignalType_var& _var) {
  if (!_var._ptr)
    _var._ptr = new SignalType;
  _strm >> *_var._ptr;
  return _strm;
}

Signal_ptr Signal_var::_duplicate(Signal_ptr _p) {
  return Signal::_duplicate(_p);
}

void
Signal_var::_release(Signal_ptr _p) {
  CORBA::release((CORBA::Object_ptr)_p);
}

Signal_var::Signal_var()
  : _ptr(Signal::_nil()) {}

Signal_var::Signal_var(Signal_ptr _p)
  : _ptr(_p) {}

Signal_var::Signal_var(const Signal_var& _var)
  : _ptr(Signal::_duplicate((Signal_ptr) _var)) {}

Signal_var::~Signal_var() {
  CORBA::release((CORBA::Object_ptr)_ptr);
}

Signal_var&
Signal_var::operator=(const Signal_var& _var) {
    _release(_ptr);
    _ptr = _duplicate(_var._ptr);
    return *this;
}

Signal_var&
Signal_var::operator=(Signal_ptr _p) {
  CORBA::release((CORBA::Object_ptr)_ptr);
  _ptr = _p;
  return *this;
}

Signal_ptr& Signal_var::out() {
  _release(_ptr);
  _ptr = (Signal_ptr)NULL;
  return _ptr;
}

Signal_ptr Signal_var::_retn() {
  Signal_ptr _tmp_ptr = _ptr;
  _ptr = (Signal_ptr)NULL;
  return _tmp_ptr;
}

VISistream& operator>>(VISistream& _strm, Signal_var& _var) {
  _strm >> _var._ptr;
  return _strm;
}

VISostream& operator<<(VISostream& _strm, const Signal_var& _var) {
  _strm << _var._ptr;
  return _strm;
}

Istream& operator>>(Istream& _strm, Signal_var& _var) {
  VISistream _istrm(_strm);
  _istrm >> _var._ptr;
  return _strm;
}

Ostream& operator<<(Ostream& _strm, const Signal_var& _var) {
  _strm << (CORBA::Object_ptr)_var._ptr;
  return _strm;
}

// If dllimport is specified, you might probably want to
// disable these definitions
// disable the const definitions
const VISOps_Info Signal_ops::_ops_info("Signal_ops");
const VISOps_Info *Signal_ops::_desc() { return &_ops_info; }
Signal_ops_ptr Signal_ops::_downcast(PortableServer::ServantBase* _servant) {
  if (_servant == (PortableServer::ServantBase*)NULL)
    return Signal_ops::_nil();
  return (Signal_ops_ptr)_servant->_safe_downcast_ops(_ops_info);
}
const CORBA::TypeInfo
#ifdef AIXV3
Signal::_class_info("Signal", "IDL:Signal:1.0", NULL, Signal::_factory, NULL,
                    0, NULL, 0, CORBA::Object::_desc(), 0L);
#else
Signal::_class_info("Signal", "IDL:Signal:1.0", NULL, Signal::_factory, NULL,
                    0, NULL, 0, CORBA::Object::_desc(), 0L);
#endif

const CORBA::TypeInfo *Signal::_desc() { return &_class_info; }
const CORBA::TypeInfo *Signal::_type_info() const {
  return &_class_info;
}

VISistream& operator>>(VISistream& _strm, Signal_ptr& _obj) {
  CORBA::Object_var _var_obj(_obj);
  _var_obj = CORBA::Object::_read(_strm, Signal::_desc());
  _obj = Signal::_narrow(_var_obj);
  return _strm;
}

VISostream& operator<<(VISostream& _strm, const Signal_ptr _obj) {
  _strm << (CORBA::Object_ptr)_obj;
  return _strm;
}
void* Signal::_safe_narrow(const CORBA::TypeInfo& _info) const {
  if (_info == _class_info)
    return (void *)this;
  return CORBA_Object::_safe_narrow(_info);
}

CORBA::Object *Signal::_factory() {
  return new Signal;
}

Signal_ptr Signal::_this() {
  return Signal::_duplicate(this);
}

Signal_ptr Signal::_narrow(CORBA::Object * _obj) {
  if (_obj == Signal::_nil())
    return Signal::_nil();
  else
    return Signal::_duplicate((Signal_ptr)_obj->_safe_narrow(_class_info));
}

Ostream& operator<<(Ostream& _strm, const Signal_ptr _obj) {
  _strm << (CORBA::Object_ptr) _obj;
  return _strm;
}
Istream& operator>>(Istream& _strm, Signal_ptr& _obj) {
  VISistream _istrm(_strm);
  _istrm >> _obj;
  return _strm;
}

Signal *Signal::_bind(const char *_object_name, const char *_host_name,
                      const CORBA::BindOptions *_opt, CORBA::ORB_ptr _orb)
{
  VISCLEAR_EXCEP
  CORBA::Object_var _obj = CORBA::Object::_bind_to_object(
          "IDL:Signal:1.0", _object_name, _host_name, _opt, _orb);
  return Signal::_narrow(_obj);
}

Signal *Signal::_bind(const char *_poa_name, const CORBA::OctetSequence& _id,
                      const char *_host_name, const CORBA::BindOptions *_opt,
                      CORBA::ORB_ptr _orb)
{
  VISCLEAR_EXCEP
  CORBA::Object_var _obj = CORBA::Object::_bind_to_object(
   "IDL:Signal:1.0", _poa_name, _id, _host_name, _opt, _orb);
  return Signal::_narrow(_obj);
}
#if defined(__BORLANDC__)
#pragma option push
#pragma warn -8057
#pragma warn -8004
#endif
void Signal::GetSignal(CORBA::Long _arg_n , CORBA::Long _arg_fs ,
                       SignalType& _arg_output ) {
  CORBA_MarshalInBuffer_var _ibuf;

  while (1) {
    VISCLEAR_EXCEP 

    if (_is_local()) {
      PortableServer::ServantBase_ptr _servant;
      VISTRY {
        _servant = _preinvoke("GetSignal");
      }
      VISCATCH(VISRemarshal, _vis_except) { continue; } 
      VISEND_CATCH

      Signal_ops*  _signal = Signal_ops::_downcast(_servant);
      if (!_signal) {
        if ((PortableServer::ServantBase*)_servant)
          _postinvoke(_servant, "GetSignal");
        VISTHROW(CORBA::BAD_OPERATION());
#if defined(_VIS_NOEXCEPTIONS)
        VISRETURN(return;)
#endif
      }

      VISTRY {
        _signal->GetSignal(_arg_n , _arg_fs , _arg_output );
      }
      VISCATCH_ALL{
        _postinvoke(_servant, "GetSignal"); 
        VISTHROW_LAST;
#if defined(_VIS_NOEXCEPTIONS)
        VISRETURN(return;)
#endif
      }
      VISEND_CATCH
      _postinvoke(_servant, "GetSignal");
      return;
    }

    CORBA::MarshalOutBuffer_var _obuf;
    _obuf = _request("GetSignal", 1);
    VISIF_EXCEP(return;)
    VISostream& _ostrm = *VISostream::_downcast(_obuf);
    _ostrm << _arg_n;
    _ostrm << _arg_fs;
    _ostrm << _arg_output;

    VISTRY {
      _ibuf = _invoke(_obuf);
      VISIFNOT_EXCEP
      break;
      VISEND_IFNOT_EXCEP
    } VISCATCH(VISRemarshal, _vis_except) { continue; } 
    VISEND_CATCH
#if defined(_VIS_NOEXCEPTIONS)
    VISRETURN(return;)
#endif
  }

  VISistream& _istrm = *VISistream::_downcast(_ibuf);
  _istrm >> _arg_output;

}

#if defined(__BORLANDC__)
 #pragma option pop
#endif

