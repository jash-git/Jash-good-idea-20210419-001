//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//<1> 在空白的树状窗口组件上，开始新建三层树状结构
//先增加一根目录
TreeView1->Items->Add(TreeView1->Selected, "第一层A");
//接着建立子目录
TTreeNode *MyTreeNode1 = TreeView1->Items->Item[0];
TreeView1->Items->AddChild(MyTreeNode1,"第二层A");
//增加第二个根目录与三个子目录
TreeView1->Items->Add(TreeView1->Selected, "第一层B");
TTreeNode *MyTreeNode2 = TreeView1->Items->Item[2];
TreeView1->Items->AddChild(MyTreeNode2,"第二层B");
MyTreeNode2=TreeView1->Items->Item[3];
TreeView1->Items->AddChild(MyTreeNode2,"第三层B");
MyTreeNode2 = TreeView1->Items->Item[4];
TreeView1->Items->Add(MyTreeNode2,"第三层B");
//增加第三个根目录
TreeView1->Items->Add(TreeView1->Selected, "第一层C");

//<2>完成新建内容后，修改此树状窗口组件性质，可自由缩放大小
DWORD dwStyle = ::GetWindowLong(TreeView1->Handle, GWL_STYLE);
::SetWindowLong(TreeView1->Handle, GWL_STYLE, dwStyle | WS_SIZEBOX);

//<3>修正此树状窗口组件在Form1上的实际尺寸与范围
//以便USER直接调整树状窗口组件边沿
::MoveWindow(TreeView1->Handle, TreeView1->Left, TreeView1->Top,
             TreeView1->Width, TreeView1->Height + 4, false);
::MoveWindow(TreeView1->Handle, TreeView1->Left, TreeView1->Top,
             TreeView1->Width, TreeView1->Height - 4, true);
}
//---------------------------------------------------------------------------
