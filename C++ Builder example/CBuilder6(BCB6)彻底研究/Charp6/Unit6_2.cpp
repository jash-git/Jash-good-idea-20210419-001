//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit6_2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
TTreeNode *root,*node,*node1;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{

    ImageList1->Height=32;
    ImageList1->Width=32;


    TreeView1->Images=ImageList1;
    TreeView1->StateImages=ImageList1;


    root=new TTreeNode(TreeView1->Items);
    node=new TTreeNode(TreeView1->Items);
    node1=new TTreeNode(TreeView1->Items);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{

    delete node1;
    delete node;
    delete root;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormActivate(TObject *Sender)
{

    root=TreeView1->Items->AddChild(NULL,"����Ŀ¼");
    root->ImageIndex=0;
    root->SelectedIndex=3;
    node=TreeView1->Items->AddChild(root,"��һ�� ���ӻ���Ƶļ��ɿ�������");
    node->ImageIndex=1;
    node->SelectedIndex=3;
    node1=TreeView1->Items->AddChild(node,"����༭��");
    node1->ImageIndex=2;
    node1->SelectedIndex=3;
    node1->StateIndex=4;
    node1=TreeView1->Items->AddChild(node,"��������");
    node1->ImageIndex=2;
    node1->SelectedIndex=3;
    node1->StateIndex=4;
    node=TreeView1->Items->AddChild(root,"�ڶ��� C++ Builder ����Ŀ����ṹ");
    node->ImageIndex=1;
    node->SelectedIndex=3;
    node1=TreeView1->Items->AddChild(node,"��Ŀ�ṹ����");
    node1->ImageIndex=2;
    node1->SelectedIndex=3;
    node1->StateIndex=4;
    node1=TreeView1->Items->AddChild(node,"��Ŀѡ������");
    node1->ImageIndex=2;
    node1->SelectedIndex=3;
    node1->StateIndex=4;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N1Click(TObject *Sender)
{

    TreeView1->Selected->EditText();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N2Click(TObject *Sender)
{

    TreeView1->Items->Delete(TreeView1->Selected);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N3Click(TObject *Sender)
{

    node=TreeView1->Selected;
    node1=TreeView1->Items->AddChild(node,"δ����");
    node1->ImageIndex=node->ImageIndex+1;
    node1->SelectedIndex=node->ImageIndex+1;;
    node1->StateIndex=4;
}
//---------------------------------------------------------------------------

