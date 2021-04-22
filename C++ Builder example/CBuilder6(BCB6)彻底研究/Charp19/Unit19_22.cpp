
// ******************************************************************** //
//                                                                    
//                          XML Data Binding                          
//                                                                    
//         Generated on: 2002/4/22 ¤U¤È 03:05:38                      
//       Generated from: C:\Paul\CBuilder6\Example\Charp19\xml1.xml   
//   Settings stored in: C:\Paul\CBuilder6\Example\Charp19\xml1.xdb   
//                                                                    
// ******************************************************************** //

#include <vcl.h>
#pragma hdrstop

#include "Unit19_22.h"


// Global Functions 

_di_IXMLstockType __fastcall Getstock(_di_IXMLDocument Doc)
{
  return (_di_IXMLstockType) Doc->GetDocBinding("stock", __classid(TXMLstockType));
};

_di_IXMLstockType __fastcall Getstock(TXMLDocument *Doc)
{
  _di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getstock(DocIntf);
};

_di_IXMLstockType __fastcall Loadstock(const WideString FileName)
{
  return (_di_IXMLstockType) LoadXMLDocument(FileName)->GetDocBinding("stock", __classid(TXMLstockType));
};

_di_IXMLstockType __fastcall  Newstock()
{
  return (_di_IXMLstockType) NewXMLDocument()->GetDocBinding("stock", __classid(TXMLstockType));
};


// TXMLstockType 

WideString __fastcall TXMLstockType::Get_exchange()
{
  return TXMLNode::AttributeNodes->Nodes[WideString("exchange")]->Text;
};

void __fastcall TXMLstockType::Set_exchange(WideString Value)
{
  TXMLNode::SetAttribute(WideString("exchange"), Value);
};

WideString __fastcall TXMLstockType::Get_name()
{
  return TXMLNode::ChildNodes->Nodes[WideString("name")]->Text;
};

void __fastcall TXMLstockType::Set_name(WideString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("name")]->NodeValue = Value;
};

WideString __fastcall TXMLstockType::Get_price()
{
  return TXMLNode::ChildNodes->Nodes[WideString("price")]->Text;
};

void __fastcall TXMLstockType::Set_price(WideString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("price")]->NodeValue = Value;
};

WideString __fastcall TXMLstockType::Get_symbol()
{
  return TXMLNode::ChildNodes->Nodes[WideString("symbol")]->Text;
};

void __fastcall TXMLstockType::Set_symbol(WideString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("symbol")]->NodeValue = Value;
};

int __fastcall TXMLstockType::Get_shares()
{
  return TXMLNode::ChildNodes->Nodes[WideString("shares")]->NodeValue;
};

void __fastcall TXMLstockType::Set_shares(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("shares")]->NodeValue = Value;
};
