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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(StringGrid1->EditorMode)
  {
  //ȡ��StringGrid1��handle
  HWND HEdit = FindWindowEx(StringGrid1->Handle, NULL,
                            "TInplaceEdit", NULL);
  //�ͳ���Ϣ��������������ڵ��ַ�λ�ã�����ʾ����
  int pos = LOWORD(SNDMSG(HEdit, EM_GETSEL, NULL, NULL));
  StaticText2->Caption = "���ڱ༭��λ���ڵ� " + AnsiString(pos) + " ����";
  }
}
//---------------------------------------------------------------------------
