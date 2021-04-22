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

    root=TreeView1->Items->AddChild(NULL,"本书目录");
    root->ImageIndex=0;
    root->SelectedIndex=3;
    node=TreeView1->Items->AddChild(root,"第一章 可视化设计的集成开发环境");
    node->ImageIndex=1;
    node->SelectedIndex=3;
    node1=TreeView1->Items->AddChild(node,"代码编辑器");
    node1->ImageIndex=2;
    node1->SelectedIndex=3;
    node1->StateIndex=4;
    node1=TreeView1->Items->AddChild(node,"对象检查器");
    node1->ImageIndex=2;
    node1->SelectedIndex=3;
    node1->StateIndex=4;
    node=TreeView1->Items->AddChild(root,"第二章 C++ Builder 的项目程序结构");
    node->ImageIndex=1;
    node->SelectedIndex=3;
    node1=TreeView1->Items->AddChild(node,"项目结构分析");
    node1->ImageIndex=2;
    node1->SelectedIndex=3;
    node1->StateIndex=4;
    node1=TreeView1->Items->AddChild(node,"项目选项设置");
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
    node1=TreeView1->Items->AddChild(node,"未命名");
    node1->ImageIndex=node->ImageIndex+1;
    node1->SelectedIndex=node->ImageIndex+1;;
    node1->StateIndex=4;
}
//---------------------------------------------------------------------------

