/*
 * Copyright 2001 Borland Software Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#ifndef __SIGNAL_IDL___server
#define __SIGNAL_IDL___server
#include "vpre.h"

#include "SIGNAL_c.hh"

class  POA_Signal : public Signal_ops ,public virtual PortableServer_ServantBase {
 protected:
  POA_Signal() {}

  virtual ~POA_Signal() {}

 public:
  static const CORBA::TypeInfo _skel_info;
  virtual const CORBA::TypeInfo *_type_info() const;

  Signal_ptr _this();

  virtual void *_safe_narrow(const CORBA::TypeInfo& ) const;

  static POA_Signal * _narrow(PortableServer_ServantBase *_obj);

  // The following operations need to be implemented
  virtual void GetSignal(CORBA::Long _n, CORBA::Long _fs, SignalType& _output) = 0;

  // Skeleton Operations implemented automatically
  virtual void* _safe_downcast_ops(const VISOps_Info& _info) {
    if (_info == *Signal_ops::_desc())
      return (void*)(Signal_ops*)this;
    return (void*)NULL;
  }

  static void _GetSignal(void *_obj, CORBA::MarshalInBuffer &_istrm,
                         const char *_oper, VISReplyHandler& handler);

};

template <class T> class POA_Signal_tie : public POA_Signal {
  private:
   CORBA::Boolean _rel;
   PortableServer::POA_ptr _poa;
   T *_ptr;
   POA_Signal_tie(const POA_Signal_tie <T>&) {}
   void operator=(const POA_Signal_tie <T>&) {}

  public:
   POA_Signal_tie (T& t): _ptr(&t), _poa(NULL), _rel((CORBA::Boolean)0) {}

 POA_Signal_tie (T& t, PortableServer::POA_ptr poa): _ptr(&t), 
   _poa(PortableServer_POA::_duplicate(poa)), _rel((CORBA::Boolean)0) {}

 POA_Signal_tie (T *p, CORBA::Boolean release= 1) : _ptr(p), _poa(NULL), _rel(release) {}

 POA_Signal_tie (T *p, PortableServer::POA_ptr poa, CORBA::Boolean release =1)
   : _ptr(p), _poa(PortableServer_POA::_duplicate(poa)), _rel(release) {}

 virtual ~POA_Signal_tie() {
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

  void GetSignal(CORBA::Long _n, CORBA::Long _fs, SignalType& _output) {
  _ptr->GetSignal(_n, _fs, _output);
  }
  PortableServer::POA_ptr _default_POA() {
    if ( !CORBA::is_nil(_poa) ) {
      return _poa;
    } else {
      return PortableServer_ServantBase::_default_POA();
    }
  }

};
class  _sk_Signal : public POA_Signal,
                    public PortableServer_RefCountServantBase, public Signal {
 protected:
  _sk_Signal (const char *_obj_name = (const char*)NULL) {
    PortableServer_ServantBase::_object_name(_obj_name);
  }
  _sk_Signal (const char *_service_name, const CORBA::ReferenceData& _data) {
    PortableServer_ServantBase::_service(_service_name, _data);
  }

 public:
  virtual ~_sk_Signal() {}
  virtual PortableServer_ServantBase *_get_servant() {
    return this;
  }
  virtual CORBA::Object_ptr _backcompat_object() {
    return this;
  }
  Signal_ptr _this() {
    POA_Signal *_temp = this;
    return _temp->_this();
  }

  void _release() { _remove_ref(); }
  void _ref() { _add_ref(); }

  const char *_repository_id() const {
    return PortableServer_ServantBase::_repository_id();
  }
};
template <class T>
class _tie_Signal : public POA_Signal_tie<T>, public virtual CORBA_Object {
 private:
  _tie_Signal (const _tie_Signal <T>&) : POA_Signal_tie<T>((T *)NULL, (CORBA::Boolean)0) {}
  void operator=(const _tie_Signal <T>&) {}
   public:
  _tie_Signal(T& _t, const char *_obj_name = (char *) NULL, CORBA::Boolean _r_f = 0) 
      : POA_Signal_tie<T>(&_t, _r_f) {
    PortableServer_ServantBase::_object_name(_obj_name);
  }

  _tie_Signal(T& _t, const char *_serv_name, const CORBA::ReferenceData& _id, CORBA::Boolean _r_f = 0)
      : POA_Signal_tie<T>(&_t, _r_f) {
    PortableServer_ServantBase::_service(_serv_name, _id);
  }

  CORBA::Boolean rel_flag() { 
    return _is_owner(); 
  }

  void rel_flag(CORBA::Boolean flag) { 
    _is_owner(flag); 
  }

  virtual ~_tie_Signal() {}

  virtual PortableServer_ServantBase *_get_servant() {
    return this;
  }

  const char *repository_id() const {
    return PortableServer_ServantBase::_repository_id();
  }
};

#include "vpost.h"
#endif  // __SIGNAL_IDL___server
 