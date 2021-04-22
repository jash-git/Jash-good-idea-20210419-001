/*
 * Copyright 2001 Borland Software Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#ifndef __time_idl___client
#define __time_idl___client
#include "vpre.h"

#ifndef _corba_h_
# include "corba.h"
#endif   // _corba_h_

class  MyTime {
  public:
  // idl struct: MyTime::TimeOfDay
  struct  TimeOfDay {

    CORBA::Short hour;
    CORBA::Short minute;
    CORBA::Short second;
    #if defined(MSVCNEWDLL_BUG)
      void *operator new(size_t ts);
      void *operator new(size_t ts, char*, int) {return operator new(ts);}
      void operator delete(void *p);
    #endif // MSVCNEWDLL_BUG
    friend VISostream& operator<<(VISostream&, const TimeOfDay&);
    friend VISistream& operator>>(VISistream&, TimeOfDay&);

    friend VISostream& operator<<(VISostream& _strm, const TimeOfDay* _obj);
    friend VISistream& operator>>(VISistream& _strm, TimeOfDay*& _obj);

    friend void _pretty_print(VISostream&, const TimeOfDay&);
    friend Ostream& operator<<(Ostream&, const TimeOfDay&);
    friend Istream& operator>>(Istream&, TimeOfDay&);
    friend Istream& operator>>(Istream&, TimeOfDay*&);
  };
  typedef TimeOfDay * TimeOfDay_ptr;

  class  TimeOfDay_var {
  private:
    TimeOfDay_ptr _ptr;
  public:
    TimeOfDay_var() : _ptr((TimeOfDay*)NULL) {}
    TimeOfDay_var(TimeOfDay *_p) : _ptr(_p) {}

    TimeOfDay_var(const TimeOfDay_var& _var) {
      _ptr = _var._ptr ? (new TimeOfDay(*_var._ptr)) : (TimeOfDay*)NULL;
    }

    virtual ~TimeOfDay_var() { delete _ptr; }
    TimeOfDay_var& operator=(TimeOfDay* _p);
    TimeOfDay_var& operator=(const TimeOfDay_var& _var);
    operator TimeOfDay*() const { return _ptr; }

    TimeOfDay* operator->() { return _ptr; }
    const TimeOfDay* operator->() const { return _ptr; }

    operator TimeOfDay&() { return *_ptr; }
    operator const TimeOfDay&() const { return *_ptr; }

    const TimeOfDay& in() const { return *_ptr; }
    TimeOfDay& inout() { return *_ptr; }
    TimeOfDay& out() { return *_ptr; }
    TimeOfDay _retn() { return *_ptr; }
    friend VISostream& operator<<(VISostream&, const TimeOfDay_var&);
    friend VISistream& operator>>(VISistream&, TimeOfDay_var&);
  };
  typedef TimeOfDay& TimeOfDay_out;
  #ifndef MyTime_Time_var_
  #define MyTime_Time_var_

  class  Time;

  typedef Time* Time_ptr;
  typedef Time_ptr TimeRef;
  friend VISistream& operator>>(VISistream&, Time_ptr&);
  friend VISostream& operator<<(VISostream&, const Time_ptr);
  class  Time_out;

  class  Time_var : public CORBA::_var {
  friend class Time_out;
   private:
    Time_ptr _ptr;

   public:
    Time_var();
    Time_var(Time_ptr);
    Time_var(const Time_var &);
    virtual ~Time_var();

    static Time_ptr _duplicate(Time_ptr);
    static void _release(Time_ptr);

    Time_var& operator=(const Time_var& _var);
    Time_var& operator=(Time_ptr);

    operator Time*() const { return _ptr; }
    Time* operator->() const { return _ptr; }

    Time_ptr in() const { return _ptr; }
    Time_ptr& inout() { return _ptr; }
    Time_ptr& out();
    Time_ptr _retn();

    friend VISostream& operator<<(VISostream&, const Time_var&);
    friend VISistream& operator>>(VISistream&, Time_var&);

    friend Istream& operator>>(Istream&, Time_var&);
    friend Ostream& operator<<(Ostream&, const Time_var&);
  };
  class  Time_out {
   private:
    Time_ptr& _ptr;
    static Time* _nil() { return (Time*)NULL; }

    void operator=(const Time_out&);
    void operator=(const Time_var&);
     public:
    Time_out(const Time_out& _o) : _ptr(_o._ptr) {}
    Time_out(Time_ptr& _p) : _ptr(_p) {
      _ptr = _nil();
    }
    Time_out(Time_var& _v) : _ptr(_v._ptr) {
      _v = _nil();
    }
    Time_out& operator=(Time* _p) {
      _ptr = _p;
      return *this;
    }
    operator Time_ptr&() { return _ptr; }
    Time_ptr& ptr() { return _ptr; }
    Time* operator->() { return _ptr; }
  };

  #endif // MyTime_Time_var_

  // idl interface: MyTime::Time
  class  Time : public virtual CORBA_Object {
   private:
    static const CORBA::TypeInfo _class_info;
    void operator=(const Time&) {}

    protected:
    Time() {}
    Time(const Time&) {}

   public:
    virtual ~Time() {}
    class  TimeException : public CORBA_UserException {
     public:

      #if defined(MSVCNEWDLL_BUG)
        void *operator new(size_t ts);
        void *operator new(size_t ts, char*, int) {return operator new(ts);}
        void operator delete(void *p);
      #endif // MSVCNEWDLL_BUG

      TimeException();
      TimeException( const char* _S );
      virtual ~TimeException();

      CORBA::String_var S;
      static CORBA::Exception *_factory() { return new TimeException(); }
      virtual const CORBA_Exception::Description& _desc() const;
      static TimeException* _downcast(CORBA::Exception *_exc);
      static const TimeException* _downcast(const CORBA::Exception *_exc);
      CORBA::Exception *_deep_copy() { return new TimeException(*this); }
    #ifdef AIXV3
      void _raise() const { VISTHROW_INST((TimeException*)this) }
    #else
      void _raise() const { VISTHROW_INST(this) }
    #endif

      friend void _pretty_print(VISostream&, const TimeException&);
      void _write(VISostream&) const;
      void _copy(VISistream&);

      friend VISistream& operator>>(VISistream& _strm, TimeException& _e);
      static const CORBA_Exception::Description _description;
    };

    static  const CORBA::TypeInfo *_desc();
    virtual const CORBA::TypeInfo *_type_info() const;
    virtual void *_safe_narrow(const CORBA::TypeInfo& ) const;
    static CORBA::Object*_factory();
    Time_ptr _this();
    static Time_ptr _duplicate(Time_ptr _obj) {
      if (_obj) _obj->_ref();
      return _obj;
    }
    static Time_ptr _nil() { return (Time_ptr)NULL; }
    static Time_ptr _narrow(CORBA::Object* _obj);
    static Time_ptr _clone(Time_ptr _obj) {
      CORBA::Object_var _obj_var(CORBA_Object::_clone(_obj));
      #if defined(_HPCC_BUG)
        return _narrow(_obj_var.operator CORBA::Object_ptr());
      #else
        return _narrow(_obj_var);
      #endif  // _HPCC_BUG
    }
    static Time_ptr _bind(const char *_object_name = (const char*)NULL,
                          const char *_host_name = (const char*)NULL,
                          const CORBA::BindOptions* _opt = (CORBA::BindOptions*)NULL,
                          CORBA::ORB_ptr _orb = (CORBA::ORB_ptr)NULL);

    static Time_ptr _bind(const char *_poa_name,
                          const CORBA::OctetSequence& _id,
                          const char *_host_name = (const char*)NULL,
                          const CORBA::BindOptions* _opt = (CORBA::BindOptions*)NULL,
                          CORBA::ORB_ptr _orb = (CORBA::ORB_ptr)NULL);

    virtual TimeOfDay get_gmt();

    friend VISostream& operator<<(VISostream& _strm, const Time_ptr _obj);
    friend VISistream& operator>>(VISistream& _strm, Time_ptr& _obj);
    friend Ostream& operator<<(Ostream& _strm, const Time_ptr _obj);
    friend Istream& operator>>(Istream& _strm, Time_ptr& _obj);
  };

  class Time_ops;
  typedef Time_ops* Time_ops_ptr;

  class  Time_ops  {
   public:
    Time_ops() {}
    virtual ~Time_ops () {}

    virtual TimeOfDay get_gmt() = 0;

    static const VISOps_Info *_desc();
    static Time_ops_ptr _nil() { return (Time_ops_ptr)NULL; }
    static Time_ops_ptr _downcast(PortableServer::ServantBase* _servant);
  protected:
    static const VISOps_Info _ops_info;
  };

};

#include "vpost.h"
#endif // __time_idl___client
 