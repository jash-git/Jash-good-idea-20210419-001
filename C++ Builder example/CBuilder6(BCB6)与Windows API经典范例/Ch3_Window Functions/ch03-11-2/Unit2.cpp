//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//-����Ի������ӡ�Ի����callback����----------------------------------------------------
UINT APIENTRY CFHookProc(HWND hdlg, UINT uiMsg,
                      WPARAM wParam, LPARAM lParam);
UINT APIENTRY PrintHookProc(HWND hdlg, UINT uiMsg,
                      WPARAM wParam, LPARAM lParam);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//LOGFONT�ṹΪCHOOSEFONT�ṹ�ĳ�Ա
LOGFONT lf;
::ZeroMemory(&lf, sizeof(&lf));
//����CHOOSEFONT�ṹ��Ա
CHOOSEFONT cf;
::ZeroMemory(&cf, sizeof(CHOOSEFONT));
cf.lStructSize = sizeof(CHOOSEFONT);
cf.hwndOwner = Handle;
cf.lpLogFont = &lf;
//ָ��callback����CFHookProc
cf.lpfnHook = CFHookProc;
cf.Flags = CF_SCREENFONTS | CF_EFFECTS | CF_ENABLEHOOK | CF_SHOWHELP;
//������Ի���
if(::ChooseFont(&cf))
  {//�ı�StaticText1����&�ߴ�
  StaticText1->Font->Handle =
            ::CreateFontIndirect(cf.lpLogFont);
    }
}
//---------------------------------------------------------------------------
//����Ի���CHOOSEFONT�ṹ��callback����
UINT APIENTRY CFHookProc(HWND hdlg, UINT uiMsg, WPARAM wParam,
    LPARAM lParam)
{
//grp1,grp2,pshHelp,psh2������dlgs.h�У����� #include <dlgs.h>
if (uiMsg == WM_INITDIALOG)
   {
   ::EnableWindow(::GetDlgItem(hdlg, grp1), false);//<Ч��>���
   ::EnableWindow(::GetDlgItem(hdlg, grp2), false);//<����>���~��
   ::EnableWindow(::GetDlgItem(hdlg, pshHelp), false);//<˵��>��ť
   ::EnableWindow(::GetDlgItem(hdlg, cmb2), false);//<������ʽ>������ѡ��
   return true;
   }
return 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//PRINTDLG�ṹ����&����ڴ�
PRINTDLG pd;
::ZeroMemory(&pd, sizeof(PRINTDLG));
//����PRINTDLG�ṹ��Ա
pd.lStructSize = sizeof(PRINTDLG);
pd.hwndOwner = Handle;
pd.nCopies = 1;
pd.nFromPage = 0xFFFF;
pd.nToPage = 0xFFFF;
pd.nMinPage = 1;
pd.nMaxPage = 0xFFFF;
pd.Flags = PD_ENABLEPRINTHOOK;
pd.lpfnPrintHook = PrintHookProc;
//�򿪴�ӡ�Ի���
if(::PrintDlg(&pd))
  {
  //�ͷ�PRINTDLG�ṹ�г�Ա��ȫ�����ڴ�
  if(pd.hDevMode) ::GlobalFree(pd.hDevMode);
  if (pd.hDevNames) ::GlobalFree(pd.hDevNames);
  }
}
//---------------------------------------------------------------------------
//��ӡ�Ի���PRINTDLG�ṹ��callback����
UINT APIENTRY PrintHookProc(HWND hdlg, UINT uiMsg, WPARAM wParam,
    LPARAM lParam)
{
if (uiMsg == WM_INITDIALOG)
  {//psh2������dlgs.h�У����� #include <dlgs.h>
  //psh2��Ϊ<����>��ť
  ::EnableWindow(::GetDlgItem(hdlg, chx1), false);//<��ӡ���ļ�>ѡ��
  ::EnableWindow(::GetDlgItem(hdlg, rad1), false);//<ȫ��>ѡ��
  ::EnableWindow(::GetDlgItem(hdlg, edt1), false);//<��>ҳ�����봦
  return true;
  }
return 0;
}
//---------------------------------------------------------------------------



