//---------------------------------------------------------------------------
//Ŀ�ģ�����Esc�������Զ�����һ���д�Сд���ո�����ַ���
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
void __fastcall TForm1::Memo1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
//Ĭ���ַ���
AnsiString str = "This is a test!";
//�����ַ�����������AnsiString��һ���ַ�Ϊstr[1]
int pass = 1;
//��USER����Esc��������������ַ���
if(Key == VK_ESCAPE)
  {//����ѭ�������������ַ���
  while(pass <= str.Length())
    {
    char ch = str[pass];
    //��ָ�����ַ�ת�������������
    SHORT vks =  ::VkKeyScan(ch);
    //����&�ۿ���
    //Memo1->Lines->Add(AnsiString(HIBYTE(vks))+ ":" +
    //                  AnsiString(LOBYTE(vks)));

    //��ͬʱ����Shift��ʱ��16-bit��λ��1
    if((int)HIBYTE(vks)== 1)
       ::keybd_event((BYTE)VK_SHIFT, (BYTE)::MapVirtualKey(VK_SHIFT, 0), 0, 0 );
    //��ͬʱ����Ctrl��ʱ��16-bit��λ��2
    if((int)HIBYTE(vks)== 2)
       ::keybd_event((BYTE)VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL, 0), 0, 0 );
    //��ͬʱ����Alt��ʱ��16-bit��λ��4
    if((int)HIBYTE(vks)== 4)
       ::keybd_event((BYTE)VK_MENU, (BYTE)::MapVirtualKey(VK_MENU, 0), 0, 0 );
    //�����ַ���
    ::keybd_event((BYTE)vks, (BYTE)::MapVirtualKey( vks,0), 0, 0);

    //������һ�ſ���ϼ�
    ::keybd_event((BYTE)vks, (BYTE)::MapVirtualKey( vks,0), KEYEVENTF_KEYUP, 0);
    if((int)HIBYTE(vks)== 4)
       ::keybd_event((BYTE)VK_MENU, (BYTE)::MapVirtualKey(VK_MENU, 0), KEYEVENTF_KEYUP,0 );
    if((int)HIBYTE(vks)== 2)
       ::keybd_event((BYTE)VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL, 0), KEYEVENTF_KEYUP,0 );
    if((int)HIBYTE(vks)== 1)
      ::keybd_event((BYTE)VK_SHIFT, (BYTE)::MapVirtualKey(VK_SHIFT, 0), KEYEVENTF_KEYUP,0 );
    //����������ַ�������λ����һλ
    pass++;
    }
  }
}
//---------------------------------------------------------------------------




