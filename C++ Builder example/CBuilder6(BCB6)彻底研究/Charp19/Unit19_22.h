
// ******************************************************************** //
//                                                                    
//                          XML Data Binding                          
//                                                                    
//         Generated on: 2002/4/22 ¤U¤È 03:05:38                      
//       Generated from: C:\Paul\CBuilder6\Example\Charp19\xml1.xml   
//   Settings stored in: C:\Paul\CBuilder6\Example\Charp19\xml1.xdb   
//                                                                    
// ******************************************************************** //

#ifndef   Unit19_22H
#define   Unit19_22H

#include <System.hpp>
#include <xmldom.hpp>
#include <XMLDoc.hpp>
#include <XMLIntf.hpp>
#include <XMLNodeImp.h>


// Forward Decls 

__interface IXMLstockType;
typedef System::DelphiInterface<IXMLstockType> _di_IXMLstockType;

// IXMLstockType 

__interface INTERFACE_UUID("{A0108DCA-9EF8-4E54-BD3A-8EC8B2309CAF}") IXMLstockType : public IXMLNode
{
public:
  // Property Accessors 
  virtual WideString __fastcall Get_exchange() = 0;
  virtual WideString __fastcall Get_name() = 0;
  virtual WideString __fastcall Get_price() = 0;
  virtual WideString __fastcall Get_symbol() = 0;
  virtual int __fastcall Get_shares() = 0;
  virtual void __fastcall Set_exchange(WideString Value) = 0;
  virtual void __fastcall Set_name(WideString Value) = 0;
  virtual void __fastcall Set_price(WideString Value) = 0;
  virtual void __fastcall Set_symbol(WideString Value) = 0;
  virtual void __fastcall Set_shares(int Value) = 0;
  // Methods & Properties 
  __property WideString exchange = { read=Get_exchange, write=Set_exchange };
  __property WideString name = { read=Get_name, write=Set_name };
  __property WideString price = { read=Get_price, write=Set_price };
  __property WideString symbol = { read=Get_symbol, write=Set_symbol };
  __property int shares = { read=Get_shares, write=Set_shares };
};

// Forward Decls 

class TXMLstockType;

// TXMLstockType 

class TXMLstockType : public TXMLNode, public IXMLstockType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLstockType 
  virtual WideString __fastcall Get_exchange();
  virtual WideString __fastcall Get_name();
  virtual WideString __fastcall Get_price();
  virtual WideString __fastcall Get_symbol();
  virtual int __fastcall Get_shares();
  virtual void __fastcall Set_exchange(WideString Value);
  virtual void __fastcall Set_name(WideString Value);
  virtual void __fastcall Set_price(WideString Value);
  virtual void __fastcall Set_symbol(WideString Value);
  virtual void __fastcall Set_shares(int Value);
};


// Global Functions 

_di_IXMLstockType __fastcall Getstock(_di_IXMLDocument Doc);
_di_IXMLstockType __fastcall Getstock(TXMLDocument *Doc);
_di_IXMLstockType __fastcall Loadstock(const WideString FileName);
_di_IXMLstockType __fastcall  Newstock();

#endif