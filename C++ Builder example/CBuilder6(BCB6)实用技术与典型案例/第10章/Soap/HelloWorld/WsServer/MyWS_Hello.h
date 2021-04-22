// ************************************************************************ //
// Invokable interface declaration header for MyWS_Hello
// ************************************************************************ //
#ifndef   MyWS_HelloH
#define   MyWS_HelloH

#include <System.hpp>
#include <InvokeRegistry.hpp>
#include <XSBuiltIns.hpp>
#include <Types.hpp>

// ************************************************************************ //
//  Enums exposed via SOAP must be byte-aligned
// ************************************************************************ //
#pragma option -b-
enum SampleEnum
{
  etNone,
  etAFew,
  etSome,
  etALot
};
#pragma option -b.

// ************************************************************************ //
//  To expose complex types via SOAP, the type must derive from TRemotable
//  All published members of the type will be exposed.
// ************************************************************************ //
class TSampleStruct : public TRemotable {
private:
  AnsiString         FLastName;
  AnsiString         FFirstName;
  double             FSalary;
__published:
  __property AnsiString    LastName = { read=FLastName, write=FLastName };
  __property AnsiString    FirstName = { read=FFirstName, write=FFirstName };
  __property double        Salary = { read=FSalary, write=FSalary };
};

// ************************************************************************ //
//  Remotable arrays must be Dynamic arrays since they must be discoverable
//  at runtime.
// ************************************************************************ //
typedef DynamicArray<double>  TDoubleArray;


// ************************************************************************ //
//  Invokable interfaces must derive from IInvokable
//  The methods of the interface will be exposed via SOAP
// ************************************************************************ //
__interface INTERFACE_UUID("{49DB6645-5FAA-46E3-AD94-62E7F298D8A1}") IMyWS_Hello : public IInvokable
{
public:  
    virtual SampleEnum     echoEnum(SampleEnum eValue) = 0;
    virtual TDoubleArray   echoDoubleArray(const TDoubleArray daValue) = 0;
    virtual TSampleStruct* echoStruct(const TSampleStruct* pEmployee) = 0;
    virtual double         echoDouble(double dValue) = 0;

    virtual String         GetAString() = 0;
};
typedef DelphiInterface<IMyWS_Hello> _di_IMyWS_Hello;


#endif // MyWS_HelloH
//---------------------------------------------------------------------------


 