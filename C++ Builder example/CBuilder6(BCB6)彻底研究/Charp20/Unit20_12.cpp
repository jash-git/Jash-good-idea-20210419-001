// ************************************************************************ //
// Implementation class for interface IQueryCapital
// ************************************************************************ //
#include <vcl.h>
#pragma hdrstop

#if !defined(QueryCapitalH)
#include "Unit20_12.h"
#include "Unit20_11.h"
#endif

// ************************************************************************ //
//  TQueryCapitalImpl implements interface IQueryCapital
// ************************************************************************ //
class TQueryCapitalImpl : public TInvokableClass, public IQueryCapital
{
public:
  AnsiString QueryCountry();
  AnsiString QueryCapital(AnsiString Country);

  /* IUnknown */
  HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& IID, void **Obj)
                        { return GetInterface(IID, Obj) ? S_OK : E_NOINTERFACE; }
  ULONG STDMETHODCALLTYPE AddRef() { return TInterfacedObject::_AddRef();  }
  ULONG STDMETHODCALLTYPE Release(){ return TInterfacedObject::_Release(); }

};

AnsiString TQueryCapitalImpl::QueryCountry()
{
  TStringList *c=new TStringList();
  TTable *t1=new TTable(Application);
  AnsiString st;

  t1->DatabaseName="BCDEMOS";
  t1->TableType=ttParadox;
  t1->TableName="COUNTRY.DB";
  t1->Open();
  t1->First();
  while (!t1->Eof) {
    c->Add(t1->FieldByName("Name")->AsString);
    t1->Next();
  }
  st=c->Text;
  delete c;
  delete t1;
  return st;
}

AnsiString TQueryCapitalImpl::QueryCapital(AnsiString Country)
{
  TQuery *q1=new TQuery(Application);

  q1->DatabaseName="BCDEMOS" ;
  q1->SQL->Add("select * from Country ");
  q1->SQL->Add(" where Name=:Name ");
  q1->ParamByName("Name")->AsString=Country;
  q1->Open();
  return q1->FieldByName("Capital")->AsString;
  q1->Free();
}

// ************************************************************************ //
//  The following routine registers the interface and implementation class.
// ************************************************************************ //
static void RegTypes()
{
  InvRegistry()->RegisterInterface(__interfaceTypeinfo(IQueryCapital));
  InvRegistry()->RegisterInvokableClass(__classid(TQueryCapitalImpl));
}
#pragma startup RegTypes 32

