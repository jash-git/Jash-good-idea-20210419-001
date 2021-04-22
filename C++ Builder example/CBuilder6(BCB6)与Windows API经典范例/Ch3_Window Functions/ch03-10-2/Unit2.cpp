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
//�����������ԣ���Ϊbool����
Button1->Default = true;
}
//---------------------------------------------------------------------------
//�ڳ���ʼʱ��Image1List������ϵͳ��������ͼ��
//��һ�ּ��ط�ʽ
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//����һ��ʱ�¹�����ToolBar����
HWND HToolBar = ::CreateWindowEx(0, TOOLBARCLASSNAME,
                                 (LPSTR) NULL,
                                 WS_CHILD, 0, 0, 0, 0,
                                 Handle, (HMENU)0,
                                 HInstance, NULL);
//ȡ����ImageList�������
SNDMSG(HToolBar, TB_SETIMAGELIST, 0, (LPARAM)ImageList1->Handle);
//����ϵͳ����ͼ�굽ImageList�У�����ʾ����
SNDMSG(HToolBar, TB_LOADIMAGES, IDB_STD_LARGE_COLOR,
       (LPARAM)HINST_COMMCTRL);
//��ɺ󣬹رմ���ʱ������ToolBar����
::DestroyWindow(HToolBar);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ִ���Զ��庯��
if(Button1->Default)
   LoadAllIcons(ImageList1, ToolBar1->Handle, eSmallIcons);
else
   LoadAllIcons(ImageList1, ToolBar1->Handle, eLargeIcons);
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------

bool TForm1::LoadAllIcons(TImageList * List, HWND Handle, SizeIcon iconsize)
{
//�����ɹ����ķ���ֵ
bool OK;
//����ͼʾ�ߴ�
if(iconsize == eSmallIcons)
  {List->Width=16; List->Height=16; }
else
  {List->Width=24; List->Height=24; }
//
//ͼʾ��С������Commctrl.h��
if(iconsize == eSmallIcons)
  iconsize = (SizeIcon)IDB_STD_SMALL_COLOR;
else
  iconsize = (SizeIcon)IDB_STD_LARGE_COLOR;
//����һ��ʱ�¹�����ToolBar����
HWND hToolBar =
     ::CreateWindowEx(0, TOOLBARCLASSNAME, (LPSTR) NULL,
                      WS_CHILD,
                      0, 0,
                      0, 0,
                      Handle, (HMENU)0, HInstance, NULL);
if(hToolBar)
  {
  //ȡ����ImageList�������
  SNDMSG(hToolBar, TB_SETIMAGELIST, 0, (LPARAM)List->Handle);
  //����ϵͳ����ͼ�굽ImageList�У�����ʾ����
  SNDMSG(hToolBar, TB_LOADIMAGES,
         iconsize,(LPARAM)HINST_COMMCTRL);
  //��ɺ󣬹رմ���ʱ������ToolBar����
  ::DestroyWindow(hToolBar);
  //�������������¼���ִ��
  Application->ProcessMessages();
  OK = true;
  }
else
  OK = false;
//���سɹ����
return OK;
}
//---------------------------------------------------------------------------

