//---------------------------------------------------------------------------
//Ŀ�ģ�����Esc������ģ���������(Ctrl+V)��ϼ���ͬ���ܯ�
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//��������һ�ַ������󣬸������������У��Ա�ִ�з���<����>���ܯ�
TCustomEdit *str = new TCustomEdit(this);
str->Parent = Form1;
str->Text = "ģ���������(Ctrl+V)��ϼ�";
str->SelectAll();
str->CopyToClipboard();
delete str;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1KeyPress(TObject *Sender, char &Key)
{
//������Esc��������ͬ����Ctrl+V��ϼ�
if(Key == VK_ESCAPE)
  {
  //��'V'�ַ�ת�������������
  SHORT vks =  ::VkKeyScan('V');
  //���� Ctrl��
  ::keybd_event((BYTE)VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL, 0), 0, 0 );
  //����V��
  ::keybd_event((BYTE)vks, (BYTE)::MapVirtualKey( vks,0), 0, 0);
  //����ſ���ϼ�
  ::keybd_event((BYTE)vks, (BYTE)::MapVirtualKey( vks,0), KEYEVENTF_KEYUP, 0);
  ::keybd_event((BYTE)VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL, 0), KEYEVENTF_KEYUP,0 );
  }
}
//---------------------------------------------------------------------------


