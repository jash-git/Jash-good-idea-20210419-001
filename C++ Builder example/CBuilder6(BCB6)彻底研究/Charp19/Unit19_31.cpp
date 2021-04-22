//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit19_31.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall TForm1::DomToTree(_di_IXMLNode XMLNode,TTreeNode *TreeNode)
{
  TTreeNode *NewTreeNode;
  AnsiString NodeText,temp;
  _di_IXMLNode AttrNode;
  int i;

  if (XMLNode==NULL) return;
  NodeText=XMLNode->NodeName;
  if (XMLNode->IsTextElement)
    NodeText=NodeText+'='+XMLNode->NodeValue;
  NewTreeNode=TreeView1->Items->AddChild(TreeNode,NodeText);
  for (i=0; i<XMLNode->AttributeNodes->Count-1; i++)
  {
    AttrNode=XMLNode->AttributeNodes->Nodes[i];
    temp="["+AttrNode->NodeName+" = '"+AttrNode->Text+"']";
    TreeView1->Items->AddChild(NewTreeNode,temp);
  }
  if (XMLNode->HasChildNodes)
    for (i=0; i<XMLNode->ChildNodes->Count-1; i++)
      DomToTree(XMLNode->ChildNodes->Nodes[i],NewTreeNode);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  ClientDataSet1->Close();
  ClientDataSet1->Open();
  ClientDataSet1->SaveToFile("xml2.xml",dfXML);
  XMLDocument1->LoadFromFile("xml2.xml");
  Memo1->Lines->Text=FormatXMLData(XMLDocument1->XML->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  TreeView1->Items->Clear();
  DomToTree(XMLDocument1->DocumentElement,(TTreeNode *)NULL);
  TreeView1->FullExpand();
}
//---------------------------------------------------------------------------
