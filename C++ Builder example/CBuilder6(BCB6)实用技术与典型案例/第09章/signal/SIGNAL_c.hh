/*
 * Copyright 2001 Borland Software Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#ifndef __SIGNAL_IDL___client
#define __SIGNAL_IDL___client
#include "vpre.h"

#ifndef _corba_h_
# include "corba.h"
#endif   // _corba_h_

class  SignalType;
typedef SignalType* SignalType_ptr;

class  SignalType : private VISResource {
private:
  CORBA::Float *_contents;
  CORBA::ULong _count;
  CORBA::ULong _num_allocated;
  CORBA::Boolean _release_flag;

public:
  #if defined(MSVCNEWDLL_BUG)
    void *operator new(size_t ts);
    void *operator new(size_t ts, char*, int) {return operator new(ts);}
    void operator delete(void *p);
  #endif // MSVCNEWDLL_BUG

  static CORBA::Float *allocbuf(CORBA::ULong _nelems);
  static void freebuf(CORBA::Float* _data);

  SignalType(CORBA::ULong _max = 0);
  SignalType(CORBA::ULong max, CORBA::ULong length, CORBA::Float *_data,
             CORBA::Boolean release = (CORBA::Boolean)0);
  SignalType(const SignalType&);
  virtual ~SignalType();

  SignalType& operator=(const SignalType&);
  SignalType& operator=(const SignalType* _obj) {
    assert(_obj);
    return operator=(*_obj);
  }

  CORBA::ULong maximum() const { return _num_allocated; }

  void length(CORBA::ULong _len);
  CORBA::ULong length() const { return _count; }

  void replace(CORBA::ULong _max, CORBA::ULong _len, CORBA::Float *_data,
               CORBA::Boolean _release = (CORBA::Boolean)0);

  CORBA::Float *get_buffer(CORBA::Boolean orphan = (CORBA::Boolean) 0);
  const CORBA::Float* get_buffer() const;

  CORBA::Float& operator[](CORBA::ULong _index);
  const CORBA::Float& operator[](CORBA::ULong _index) const;

  static SignalType *_duplicate(SignalType* _ptr) {
    if (_ptr) _ptr->_ref();
    return _ptr;
  }

  static void _release(SignalType *_ptr) {
    if (_ptr && (_ptr->_deref() == 0L)) 
      delete _ptr;
  }

  friend VISostream& operator<<(VISostream&, const  SignalType&);
  friend VISistream& operator>>(VISistream&, SignalType&);

  friend VISostream& operator<<(VISostream& _strm, const SignalType* _obj);
  friend VISistream& operator>>(VISistream& _strm, SignalType_ptr& _obj);

  friend void _pretty_print(VISostream&, const SignalType&);

  friend Ostream& operator<<(Ostream&, const SignalType&);
  friend Istream& operator>>(Istream&, SignalType&);
  friend Istream& operator>>(Istream&, SignalType_ptr&);
};

class  SignalType_out;

class  SignalType_var {
  friend class SignalType_out;
   private:
  SignalType *_ptr;
   public:
  SignalType_var() : _ptr((SignalType*)NULL) {}
  SignalType_var(SignalType *_p) : _ptr(_p) {}
  SignalType_var(const SignalType_var& _var) :_ptr(SignalType::_duplicate(_var._ptr)){}
  virtual ~SignalType_var() { SignalType::_release(_ptr); }
  SignalType_var& operator=(SignalType* _p) {
    SignalType::_release(_ptr);
    _ptr = _p;
    return *this;
  }

  SignalType_var& operator=(const SignalType_var& _var) {
    SignalType::_release(_ptr);
    _ptr = SignalType::_duplicate(_var._ptr);
    return *this;
  }
  operator SignalType*() const { return _ptr; }

  SignalType* operator->() { return _ptr; }
  const SignalType* operator->() const { return _ptr; }

  operator SignalType&() { return *_ptr; }
  operator const SignalType&() const { return *_ptr; }

  const SignalType& in() const { return *_ptr; }
  SignalType& inout() { return *_ptr; }
  SignalType_ptr & out() {
    SignalType::_release(_ptr);
    _ptr = (SignalType *)NULL;
    return _ptr;
  }

  SignalType* _retn() {
    SignalType* _tmp_ptr;
    _tmp_ptr = _ptr;
    _ptr = (SignalType *)NULL;
    return _tmp_ptr;
  }
  friend VISostream& operator<<(VISostream&, const SignalType_var&);
  friend VISistream& operator>>(VISistream&, SignalType_var&);

  CORBA::Float& operator[](CORBA::ULong _index);
  const CORBA::Float& operator[](CORBA::ULong _index) const;

};
class  SignalType_out {
 private:
  SignalType_ptr& _ptr;
  static SignalType* _nil() { return (SignalType*)NULL; }

  void operator=(const SignalType_out&);
  void operator=(const SignalType_var&);
   public:
  SignalType_out(const SignalType_out& _o) : _ptr(_o._ptr) {}
  SignalType_out(SignalType_ptr& _p) : _ptr(_p) {
    _ptr = _nil();
  }
  SignalType_out(SignalType_var& _v) : _ptr(_v._ptr) {
    _v = _nil();
  }
  SignalType_out& operator=(SignalType* _p) {
    _ptr = _p;
    return *this;
  }
  operator SignalType_ptr&() { return _ptr; }
  SignalType_ptr& ptr() { return _ptr; }
};
#ifndef Signal_var_
#define Signal_var_

class  Signal;

typedef Signal* Signal_ptr;
typedef Signal_ptr SignalRef;
 VISistream& operator>>(VISistream&, Signal_ptr&);
 VISostream& operator<<(VISostream&, const Signal_ptr);
class  Signal_out;

class  Signal_var : public CORBA::_var {
friend class Signal_out;
 private:
  Signal_ptr _ptr;

 public:
  Signal_var();
  Signal_var(Signal_ptr);
  Signal_var(const Signal_var &);
  virtual ~Signal_var();

  static Signal_ptr _duplicate(Signal_ptr);
  static void _release(Signal_ptr);

  Signal_var& operator=(const Signal_var& _var);
  Signal_var& operator=(Signal_ptr);

  operator Signal*() const { return _ptr; }
  Signal* operator->() const { return _ptr; }

  Signal_ptr in() const { return _ptr; }
  Signal_ptr& inout() { return _ptr; }
  Signal_ptr& out();
  Signal_ptr _retn();

  friend VISostream& operator<<(VISostream&, const Signal_var&);
  friend VISistream& operator>>(VISistream&, Signal_var&);

  friend Istream& operator>>(Istream&, Signal_var&);
  friend Ostream& operator<<(Ostream&, const Signal_var&);
};
class  Signal_out {
 private:
  Signal_ptr& _ptr;
  static Signal* _nil() { return (Signal*)NULL; }

  void operator=(const Signal_out&);
  void operator=(const Signal_var&);
   public:
  Signal_out(const Signal_out& _o) : _ptr(_o._ptr) {}
  Signal_out(Signal_ptr& _p) : _ptr(_p) {
    _ptr = _nil();
  }
  Signal_out(Signal_var& _v) : _ptr(_v._ptr) {
    _v = _nil();
  }
  Signal_out& operator=(Signal* _p) {
    _ptr = _p;
    return *this;
  }
  operator Signal_ptr&() { return _ptr; }
  Signal_ptr& ptr() { return _ptr; }
  Signal* operator->() { return _ptr; }
};

#endif // Signal_var_

// idl interface: Signal
class  Signal : public virtual CORBA_Object {
 private:
  static const CORBA::TypeInfo _class_info;
  void operator=(const Signal&) {}

  protected:
  Signal() {}
  Signal(const Signal&) {}

 public:
  virtual ~Signal() {}
  static  const CORBA::TypeInfo *_desc();
  virtual const CORBA::TypeInfo *_type_info() const;
  virtual void *_safe_narrow(const CORBA::TypeInfo& ) const;
  static CORBA::Object*_factory();
  Signal_ptr _this();
  static Signal_ptr _duplicate(Signal_ptr _obj) {
    if (_obj) _obj->_ref();
    return _obj;
  }
  static Signal_ptr _nil() { return (Signal_ptr)NULL; }
  static Signal_ptr _narrow(CORBA::Object* _obj);
  static Signal_ptr _clone(Signal_ptr _obj) {
    CORBA::Object_var _obj_var(CORBA_Object::_clone(_obj));
    #if defined(_HPCC_BUG)
      return _narrow(_obj_var.operator CORBA::Object_ptr());
    #else
      return _narrow(_obj_var);
    #endif  // _HPCC_BUG
  }
  static Signal_ptr _bind(const char *_object_name = (const char*)NULL,
                          const char *_host_name = (const char*)NULL,
                          const CORBA::BindOptions* _opt = (CORBA::BindOptions*)NULL,
                          CORBA::ORB_ptr _orb = (CORBA::ORB_ptr)NULL);

  static Signal_ptr _bind(const char *_poa_name,
                          const CORBA::OctetSequence& _id,
                          const char *_host_name = (const char*)NULL,
                          const CORBA::BindOptions* _opt = (CORBA::BindOptions*)NULL,
                          CORBA::ORB_ptr _orb = (CORBA::ORB_ptr)NULL);

  virtual void GetSignal(CORBA::Long _n, CORBA::Long _fs, SignalType& _output);

  friend VISostream& operator<<(VISostream& _strm, const Signal_ptr _obj);
  friend VISistream& operator>>(VISistream& _strm, Signal_ptr& _obj);
  friend Ostream& operator<<(Ostream& _strm, const Signal_ptr _obj);
  friend Istream& operator>>(Istream& _strm, Signal_ptr& _obj);
};

class Signal_ops;
typedef Signal_ops* Signal_ops_ptr;

class  Signal_ops  {
 public:
  Signal_ops() {}
  virtual ~Signal_ops () {}

  virtual void GetSignal(CORBA::Long _n, CORBA::Long _fs, SignalType& _output) = 0;

  static const VISOps_Info *_desc();
  static Signal_ops_ptr _nil() { return (Signal_ops_ptr)NULL; }
  static Signal_ops_ptr _downcast(PortableServer::ServantBase* _servant);
protected:
  static const VISOps_Info _ops_info;
};


#include "vpost.h"
#endif // __SIGNAL_IDL___client
 