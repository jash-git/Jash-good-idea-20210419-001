// ************************************************************************ //
// Invokable interface declaration header for QueryCapital
// ************************************************************************ //
#ifndef   Unit20_12H
#define   Unit20_12H

#include <System.hpp>
#include <InvokeRegistry.hpp>
#include <XSBuiltIns.hpp>
#include <Types.hpp>
#include <DBTables.hpp>

// ************************************************************************ //
//  Invokable interfaces must derive from IInvokable
//  The methods of the interface will be exposed via SOAP
// ************************************************************************ //
__interface INTERFACE_UUID("{15A5AA9D-2EEB-46E2-8878-A55DFEEDE6E0}") IQueryCapital : public IInvokable
{
public:
  virtual AnsiString QueryCountry() = 0;
  virtual AnsiString QueryCapital(AnsiString Country) = 0;
};
typedef DelphiInterface<IQueryCapital> _di_IQueryCapital;


#endif // QueryCapitalH
//---------------------------------------------------------------------------


