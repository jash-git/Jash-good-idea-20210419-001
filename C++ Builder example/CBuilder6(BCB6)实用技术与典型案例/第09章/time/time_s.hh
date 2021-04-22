/*
 * Copyright 2001 Borland Software Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#ifndef __time_idl___server
#define __time_idl___server
#include "vpre.h"

#include "time_c.hh"

class  POA_MyTime {
public:

  class  Time : public MyTime::Time_ops ,public virtual PortableServer_ServantBase {
   protected:
    Time() {}

    virtual ~Time() {}

   public:
    static const CORBA::TypeInfo _skel_info;
    virtual const CORBA::TypeInfo *_type_info() const;

    MyTime::Time_ptr _this();

    virtual void *_safe_narrow(const CORBA::TypeInfo& ) const;

    static Time * _narrow(PortableServer_ServantBase *_obj);

    // The following operations need to be implemented
    virtual MyTime::TimeOfDay get_gmt() = 0;

    // Skeleton Operations implemented automatically
    virtual void* _safe_downcast_ops(const VISOps_Info& _info) {
      if (_info == *MyTime::Time_ops::_desc())
        return (void*)(MyTime::Time_ops*)this;
      return (void*)NULL;
    }

    static void _get_gmt(void *_obj, CORBA::MarshalInBuffer &_istrm,
                         const char *_oper, VISReplyHandler& handler);

  };

};
template <class T> class POA_MyTime_Time_tie : public POA_MyTime::Time {
  private:
   CORBA::Boolean _rel;
   PortableServer::POA_ptr _poa;
   T *_ptr;
   POA_MyTime_Time_tie(const POA_MyTime_Time_tie <T>&) {}
   void operator=(const POA_MyTime_Time_tie <T>&) {}

  public:
   POA_MyTime_Time_tie (T& t): _ptr(&t), _poa(NULL), _rel((CORBA::Boolean)0) {}

 POA_MyTime_Time_tie (T& t, PortableServer::POA_ptr poa): _ptr(&t), 
   _poa(PortableServer_POA::_duplicate(poa)), _rel((CORBA::Boolean)0) {}

 POA_MyTime_Time_tie (T *p, CORBA::Boolean release= 1) : _ptr(p), _poa(NULL), _rel(release) {}

 POA_MyTime_Time_tie (T *p, PortableServer::POA_ptr poa, CORBA::Boolean release =1)
   : _ptr(p), _poa(PortableServer_POA::_duplicate(poa)), _rel(release) {}

 virtual ~POA_MyTime_Time_tie() {
   CORBA::release(_poa);
     if (_rel) {
     delete _ptr;
       }
     }

 T* _tied_object() { return _ptr; }
   void _tied_object(T& t) {
   if (_rel) {
     delete _ptr;
       }
     _ptr = &t;
     _rel = 0;
     }
   void _tied_object(T *p, CORBA::Boolean release=1) {
      if (_rel) { 
        delete _ptr;
      }
      _ptr = p;
      _rel = release;
       }

 CORBA::Boolean _is_owner() { return _rel; }
   void _is_owner(CORBA::Boolean b) { _rel = b; }

  MyTime::TimeOfDay get_gmt() {
  return _ptr->get_gmt();
  }
  PortableServer::POA_ptr _default_POA() {
    if ( !CORBA::is_nil(_poa) ) {
      return _poa;
    } else {
      return PortableServer_ServantBase::_default_POA();
    }
  }

};

class  _sk_MyTime {
public:
  class  _sk_Time : public POA_MyTime::Time,
                    public PortableServer_RefCountServantBase,
                    public MyTime::Time {
   protected:
    _sk_Time (const char *_obj_name = (const char*)NULL) {
      PortableServer_ServantBase::_object_name(_obj_name);
    }
    _sk_Time (const char *_service_name, const CORBA::ReferenceData& _data) {
      PortableServer_ServantBase::_service(_service_name, _data);
    }

   public:
    virtual ~_sk_Time() {}
    virtual PortableServer_ServantBase *_get_servant() {
      return this;
    }
    virtual CORBA::Object_ptr _backcompat_object() {
      return this;
    }
    MyTime::Time_ptr _this() {
      POA_MyTime::Time *_temp = this;
      return _temp->_this();
    }

    void _release() { _remove_ref(); }
    void _ref() { _add_ref(); }

    const char *_repository_id() const {
      return PortableServer_ServantBase::_repository_id();
    }
  };
};
template <class T>
class MyTime_tie_Time : public POA_MyTime_Time_tie<T>, public virtual CORBA_Object {
 private:
  MyTime_tie_Time (const MyTime_tie_Time <T>&) : POA_MyTime_Time_tie<T>((T *)NULL, (CORBA::Boolean)0) {}
  void operator=(const MyTime_tie_Time <T>&) {}
   public:
  MyTime_tie_Time(T& _t, const char *_obj_name = (char *) NULL, CORBA::Boolean _r_f = 0) 
      : POA_MyTime_Time_tie<T>(&_t, _r_f) {
    PortableServer_ServantBase::_object_name(_obj_name);
  }

  MyTime_tie_Time(T& _t, const char *_serv_name, const CORBA::ReferenceData& _id, CORBA::Boolean _r_f = 0)
      : POA_MyTime_Time_tie<T>(&_t, _r_f) {
    PortableServer_ServantBase::_service(_serv_name, _id);
  }

  CORBA::Boolean rel_flag() { 
    return _is_owner(); 
  }

  void rel_flag(CORBA::Boolean flag) { 
    _is_owner(flag); 
  }

  virtual ~MyTime_tie_Time() {}

  virtual PortableServer_ServantBase *_get_servant() {
    return this;
  }

  const char *repository_id() const {
    return PortableServer_ServantBase::_repository_id();
  }
};

#include "vpost.h"
#endif  // __time_idl___server
