//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//ȡ���Ӵ��ڵ�callback����---------------------------------------------------
bool CALLBACK EnumWindowsProc (HWND hWnd, LPARAM lParam);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��TreeView1������״�ṹ
TreeView1->Items->Clear();
//��һ��Ѱ�������д���handle
::EnumWindows((WNDENUMPROC)EnumWindowsProc, NULL);
//չ��TreeView1��״�ṹ
TreeView1->FullExpand();
}
//---------------------------------------------------------------------------
//���ô�ɨ���Ӵ��ڵ����Լ��������д�һ���Ӵ��ڶ�ɨ���Ϊֹ
bool CALLBACK EnumWindowsProc (HWND hWnd, LPARAM lParam)
{
//û����handleʱ��������
if (hWnd==NULL) return false;
//�������������У������
if (!::IsWindowVisible(hWnd)) return true;
//ȡ�����ڴ��ڵ�����������ں�����(����)
char winTitle[128]; char winClass[128];
::GetClassName(hWnd, winClass, sizeof(winClass));
::GetWindowText(hWnd, winTitle, sizeof(winTitle));
//��ȡ�����ִ���TreeView1��
TTreeNode *ParentNode;
if (strlen(winTitle) > 0)
  ParentNode = Form1->TreeView1->Items->Add( Form1->TreeView1->Selected,
                                             "���⣺"+(AnsiString)winTitle);
else
  ParentNode = Form1->TreeView1->Items->Add( Form1->TreeView1->Selected,
                                             "���⣺��");

Form1->TreeView1->Items->AddChild(ParentNode, "�ࣺ"+(AnsiString)winClass);
//������ֵ����ִ֪���´�handleɨ��
return true;
}
//---------------------------------------------------------------------------

