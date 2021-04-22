/*
 * Copyright 2001 Borland Software Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#include <corbapch.h>
#pragma hdrstop
#include "time_c.hh"
#if defined(MSVCNEWDLL_BUG)
void *MyTime::TimeOfDay::operator new(size_t ts) {
  return ::operator new(ts);
}
void MyTime::TimeOfDay::operator delete(void *p) {
  ::operator delete(p);
}
#endif // MSVCNEWDLL_BUG

VISostream& operator<<(VISostream& _strm, const MyTime::TimeOfDay& _s) {
    _strm << _s.hour;

    _strm << _s.minute;

    _strm << _s.second;

  return _strm;
}

VISistream& operator>>(VISistream& _strm, MyTime::TimeOfDay& _s) {
    _strm >> _s.hour;

    _strm >> _s.minute;

    _strm >> _s.second;

  return _strm;
}

VISostream& operator<<(VISostream& _strm, const MyTime::TimeOfDay* _obj) {
  if (!_obj)
    VISTHROW(CORBA::BAD_PARAM())
  else
    _strm << *_obj;
  return _strm;
}
VISistream& operator>>(VISistream& _strm, MyTime::TimeOfDay*& _obj) {
  _obj = new MyTime::TimeOfDay();
  _strm >> *_obj;
  return _strm;
}

void _pretty_print(VISostream& _strm, const MyTime::TimeOfDay& _s) {
  _strm << "STRUCT MyTime::TimeOfDay {" << endl;
    _strm << "\thour:" << endl;
  _strm << "\t" << _s.hour << endl;

    _strm << "\tminute:" << endl;
  _strm << "\t" << _s.minute << endl;

    _strm << "\tsecond:" << endl;
  _strm << "\t" << _s.second << endl;

  _strm << "}" << endl;
}
Ostream& operator<<(Ostream& _strm, const MyTime::TimeOfDay& _s) {
  VISostream _ostrm(_strm);
  if (&_strm == &Cout || &_strm == &Cerr || &_strm == &Clog) {
    _pretty_print(_ostrm, _s);
    _ostrm << endl;
  } else {
      _ostrm << _s;
  }
  return _strm;
}
Istream& operator>>(Istream& _strm, MyTime::TimeOfDay& _obj) {
  VISistream _istrm(_strm);
    _istrm >> _obj;
  return _strm;
}
Istream& operator>>(Istream& _strm, MyTime::TimeOfDay*& _obj) {
  VISistream _istrm(_strm);
    _istrm >> _obj;
  return _strm;
}

VISostream& operator<<(VISostream& _strm, const MyTime::TimeOfDay_var& _var) {
  if (!_var._ptr)
    VISTHROW(CORBA::BAD_PARAM())
  else
    _strm << *_var._ptr;
  return _strm;
}

VISistream& operator>>(VISistream& _strm, MyTime::TimeOfDay_var& _var) {
  if (!_var._ptr)
    _var._ptr = new MyTime::TimeOfDay;
  _strm >> *_var._ptr;
  return _strm;
}

MyTime::TimeOfDay_var& MyTime::TimeOfDay_var::operator=(MyTime::TimeOfDay* _p) {
  delete _ptr;
  _ptr = _p;
  return *this;
}

MyTime::TimeOfDay_var& MyTime::TimeOfDay_var::operator=(const MyTime::TimeOfDay_var& _var) {
  delete _ptr;
  _ptr = _var._ptr ? new MyTime::TimeOfDay(*_var._ptr) : 
  (MyTime::TimeOfDay*)NULL;
  return *this;
}

MyTime::Time_ptr MyTime::Time_var::_duplicate(MyTime::Time_ptr _p) {
  return MyTime::Time::_duplicate(_p);
}

void
MyTime::Time_var::_release(MyTime::Time_ptr _p) {
  CORBA::release((CORBA::Object_ptr)_p);
}

MyTime::Time_var::Time_var()
  : _ptr(MyTime::Time::_nil()) {}

MyTime::Time_var::Time_var(MyTime::Time_ptr _p)
  : _ptr(_p) {}

MyTime::Time_var::Time_var(const MyTime::Time_var& _var)
  : _ptr(MyTime::Time::_duplicate((MyTime::Time_ptr) _var)) {}

MyTime::Time_var::~Time_var() {
  CORBA::release((CORBA::Object_ptr)_ptr);
}

MyTime::Time_var&
MyTime::Time_var::operator=(const MyTime::Time_var& _var) {
    _release(_ptr);
    _ptr = _duplicate(_var._ptr);
    return *this;
}

MyTime::Time_var&
MyTime::Time_var::operator=(MyTime::Time_ptr _p) {
  CORBA::release((CORBA::Object_ptr)_ptr);
  _ptr = _p;
  return *this;
}

MyTime::Time_ptr& MyTime::Time_var::out() {
  _release(_ptr);
  _ptr = (MyTime::Time_ptr)NULL;
  return _ptr;
}

MyTime::Time_ptr MyTime::Time_var::_retn() {
  MyTime::Time_ptr _tmp_ptr = _ptr;
  _ptr = (MyTime::Time_ptr)NULL;
  return _tmp_ptr;
}

VISistream& operator>>(VISistream& _strm, MyTime::Time_var& _var) {
  _strm >> _var._ptr;
  return _strm;
}

VISostream& operator<<(VISostream& _strm, const MyTime::Time_var& _var) {
  _strm << _var._ptr;
  return _strm;
}

Istream& operator>>(Istream& _strm, MyTime::Time_var& _var) {
  VISistream _istrm(_strm);
  _istrm >> _var._ptr;
  return _strm;
}

Ostream& operator<<(Ostream& _strm, const MyTime::Time_var& _var) {
  _strm << (CORBA::Object_ptr)_var._ptr;
  return _strm;
}

#if defined(__BORLANDC__)
 #pragma option push
 #pragma warn -8057
#endif

MyTime::Time::TimeException::TimeException() {}
MyTime::Time::TimeException::~TimeException() {}

MyTime::Time::TimeException::TimeException( const char* _S ) {
     S = CORBA::string_dup(_S);

}

VISistream& operator>>(VISistream& _strm, MyTime::Time::TimeException& _e) {
  CORBA::String_var _exp_name;
  _strm >> _exp_name;
  _e._copy(_strm);
  return _strm;
}

const CORBA_Exception::Description MyTime::Time::TimeException::_description(
        "::MyTime::Time::TimeException", "IDL:MyTime/Time/TimeException:1.0",
MyTime::Time::TimeException::_factory, &CORBA::UserException::_description);

#if defined(MSVCNEWDLL_BUG)
void *MyTime::Time::TimeException::operator new(size_t ts) {
  return ::operator new(ts);
}
void MyTime::Time::TimeException::operator delete(void *p) {
  ::operator delete(p);
}
#endif // MSVCNEWDLL_BUG

const CORBA_Exception::Description& MyTime::Time::TimeException::_desc() const {
return _description;
}

MyTime::Time::TimeException* MyTime::Time::TimeException::_downcast(CORBA::Exception *_exc) {
  if (_exc && _exc->_desc().can_cast(_description)) {
    return (MyTime::Time::TimeException *)_exc;
  } else {
    return (MyTime::Time::TimeException *)NULL;
  }
}

const MyTime::Time::TimeException* MyTime::Time::TimeException::_downcast(const CORBA::Exception *_exc) {
  return _downcast((CORBA::Exception *)_exc);
}

void MyTime::Time::TimeException::_write(VISostream& _strm) const {
     _strm << S;

}

void MyTime::Time::TimeException::_copy(VISistream& _strm) {
     _strm >> S;

}
void _pretty_print(VISostream& _strm, const MyTime::Time::TimeException& _s) {
  _strm << "EXCEPTION MyTime::Time::TimeException {" << endl;
    _strm << "\tS:" << endl;
  _strm << "\t" << _s.S << endl;

  _strm << "}" << endl;
}
#if defined(__BORLANDC__)
 #pragma option pop
#endif

// If dllimport is specified, you might probably want to
// disable these definitions
// disable the const definitions
const VISOps_Info MyTime::Time_ops::_ops_info("MyTime::Time_ops");
const VISOps_Info *MyTime::Time_ops::_desc() { return &_ops_info; }
MyTime::Time_ops_ptr MyTime::Time_ops::_downcast(PortableServer::ServantBase* _servant) {
  if (_servant == (PortableServer::ServantBase*)NULL)
    return MyTime::Time_ops::_nil();
  return (MyTime::Time_ops_ptr)_servant->_safe_downcast_ops(_ops_info);
}
const CORBA::TypeInfo
#ifdef AIXV3
MyTime::Time::_class_info("MyTime::Time", "IDL:MyTime/Time:1.0", NULL,
                          MyTime::Time::_factory, NULL, 0, NULL, 0,
                          CORBA::Object::_desc(), 0L);
#else
MyTime::Time::_class_info("MyTime::Time", "IDL:MyTime/Time:1.0", NULL,
                          MyTime::Time::_factory, NULL, 0, NULL, 0,
                          CORBA::Object::_desc(), 0L);
#endif

const CORBA::TypeInfo *MyTime::Time::_desc() { return &_class_info; }
const CORBA::TypeInfo *MyTime::Time::_type_info() const {
  return &_class_info;
}

VISistream& operator>>(VISistream& _strm, MyTime::Time_ptr& _obj) {
  CORBA::Object_var _var_obj(_obj);
  _var_obj = CORBA::Object::_read(_strm, MyTime::Time::_desc());
  _obj = MyTime::Time::_narrow(_var_obj);
  return _strm;
}

VISostream& operator<<(VISostream& _strm, const MyTime::Time_ptr _obj) {
  _strm << (CORBA::Object_ptr)_obj;
  return _strm;
}
void* MyTime::Time::_safe_narrow(const CORBA::TypeInfo& _info) const {
  if (_info == _class_info)
    return (void *)this;
  return CORBA_Object::_safe_narrow(_info);
}

CORBA::Object *MyTime::Time::_factory() {
  return new MyTime::Time;
}

MyTime::Time_ptr MyTime::Time::_this() {
  return MyTime::Time::_duplicate(this);
}

MyTime::Time_ptr MyTime::Time::_narrow(CORBA::Object * _obj) {
  if (_obj == MyTime::Time::_nil())
    return MyTime::Time::_nil();
  else
    return MyTime::Time::_duplicate((MyTime::Time_ptr)_obj->_safe_narrow(_class_info));
}

Ostream& operator<<(Ostream& _strm, const MyTime::Time_ptr _obj) {
  _strm << (CORBA::Object_ptr) _obj;
  return _strm;
}
Istream& operator>>(Istream& _strm, MyTime::Time_ptr& _obj) {
  VISistream _istrm(_strm);
  _istrm >> _obj;
  return _strm;
}

MyTime::Time *MyTime::Time::_bind(const char *_object_name,
                                  const char *_host_name,
                                  const CORBA::BindOptions *_opt,
                                  CORBA::ORB_ptr _orb)
{
  VISCLEAR_EXCEP
  CORBA::Object_var _obj = CORBA::Object::_bind_to_object(
          "IDL:MyTime/Time:1.0", _object_name, _host_name, _opt, _orb);
  return Time::_narrow(_obj);
}

MyTime::Time *MyTime::Time::_bind(const char *_poa_name,
                                  const CORBA::OctetSequence& _id,
                                  const char *_host_name,
                                  const CORBA::BindOptions *_opt,
                                  CORBA::ORB_ptr _orb)
{
  VISCLEAR_EXCEP
  CORBA::Object_var _obj = CORBA::Object::_bind_to_object(
   "IDL:MyTime/Time:1.0", _poa_name, _id, _host_name, _opt, _orb);
  return Time::_narrow(_obj);
}
#if defined(__BORLANDC__)
#pragma option push
#pragma warn -8057
#pragma warn -8004
#endif
MyTime::TimeOfDay MyTime::Time::get_gmt() {
  MyTime::TimeOfDay _ret;
  CORBA_MarshalInBuffer_var _ibuf;

  while (1) {
    VISCLEAR_EXCEP 

    if (_is_local()) {
      PortableServer::ServantBase_ptr _servant;
      VISTRY {
        _servant = _preinvoke("get_gmt");
      }
      VISCATCH(VISRemarshal, _vis_except) { continue; } 
      VISEND_CATCH

      MyTime::Time_ops*  _time = MyTime::Time_ops::_downcast(_servant);
      if (!_time) {
        if ((PortableServer::ServantBase*)_servant)
          _postinvoke(_servant, "get_gmt");
        VISTHROW(CORBA::BAD_OPERATION());
#if defined(_VIS_NOEXCEPTIONS)
        VISRETURN(return _ret;)
#endif
      }

      VISTRY {
         _ret = _time->get_gmt();
      }
      VISCATCH_ALL{
        _postinvoke(_servant, "get_gmt"); 
        VISTHROW_LAST;
#if defined(_VIS_NOEXCEPTIONS)
        VISRETURN(return _ret;)
#endif
      }
      VISEND_CATCH
      _postinvoke(_servant, "get_gmt");
      return _ret;
    }

    CORBA::MarshalOutBuffer_var _obuf;
    _obuf = _request("get_gmt", 1);
    VISIF_EXCEP(return _ret;)

    VISTRY {
      _ibuf = _invoke(_obuf);
      VISIFNOT_EXCEP
      break;
      VISEND_IFNOT_EXCEP
    } VISCATCH(VISRemarshal, _vis_except) { continue; } 
    VISEND_CATCH
#if defined(_VIS_NOEXCEPTIONS)
    VISRETURN(return _ret;)
#endif
  }

  VISistream& _istrm = *VISistream::_downcast(_ibuf);
  _istrm >> _ret;
  return _ret;
}

#if defined(__BORLANDC__)
 #pragma option pop
#endif

