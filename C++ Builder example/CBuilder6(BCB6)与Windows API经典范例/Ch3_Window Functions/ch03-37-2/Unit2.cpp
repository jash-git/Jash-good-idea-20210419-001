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
//<1> �ڿհ׵���״��������ϣ���ʼ�½�������״�ṹ
//������һ��Ŀ¼
TreeView1->Items->Add(TreeView1->Selected, "��һ��A");
//���Ž�����Ŀ¼
TTreeNode *MyTreeNode1 = TreeView1->Items->Item[0];
TreeView1->Items->AddChild(MyTreeNode1,"�ڶ���A");
//���ӵڶ�����Ŀ¼��������Ŀ¼
TreeView1->Items->Add(TreeView1->Selected, "��һ��B");
TTreeNode *MyTreeNode2 = TreeView1->Items->Item[2];
TreeView1->Items->AddChild(MyTreeNode2,"�ڶ���B");
MyTreeNode2=TreeView1->Items->Item[3];
TreeView1->Items->AddChild(MyTreeNode2,"������B");
MyTreeNode2 = TreeView1->Items->Item[4];
TreeView1->Items->Add(MyTreeNode2,"������B");
//���ӵ�������Ŀ¼
TreeView1->Items->Add(TreeView1->Selected, "��һ��C");

//<2>����½����ݺ��޸Ĵ���״����������ʣ����������Ŵ�С�j�p
DWORD dwStyle = ::GetWindowLong(TreeView1->Handle, GWL_STYLE);
::SetWindowLong(TreeView1->Handle, GWL_STYLE, dwStyle | WS_SIZEBOX);

//<3>��������״���������Form1�ϵ�ʵ�ʳߴ��뷶Χ
//�Ա�USERֱ�ӵ�����״�����������
::MoveWindow(TreeView1->Handle, TreeView1->Left, TreeView1->Top,
             TreeView1->Width, TreeView1->Height + 4, false);
::MoveWindow(TreeView1->Handle, TreeView1->Left, TreeView1->Top,
             TreeView1->Width, TreeView1->Height - 4, true);
}
//---------------------------------------------------------------------------
