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
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//���Memo1������
Memo1->Clear();
AnsiString showstr;
//��WINDOWPLACEMENT�ṹ��Ա��ȡ��ָ������������Ϣ
WINDOWPLACEMENT Wpl;
Wpl.length = sizeof(WINDOWPLACEMENT);
::GetWindowPlacement(Handle, &Wpl);
//��������ȡ��֮�������ýṹ��Ա����Memo1��ʾ
//Wpl.flags�ṹ��Ա
if(Wpl.flags == WPF_RESTORETOMAXIMIZED)
   showstr = "�ظ���ԭ�����״̬";
else if(Wpl.flags == WPF_SETMINPOSITION)
   showstr = "ָ����С����λ��";
else if(Wpl.flags == (WPF_RESTORETOMAXIMIZED & WPF_SETMINPOSITION))
   showstr = "��߻ָ���ԭ�����״̬��ָ����С����λ��";
Memo1->Lines->Add(showstr);
//Wpl.showCmd�ṹ��Ա
switch(Wpl.showCmd)
    {
    case SW_HIDE :
       showstr = "�������������״̬"; break;
    case SW_MINIMIZE :
       showstr = "���������������ݹ�������"; break;
    case SW_RESTORE :
       showstr = "��������ǻָ�������ʱ��״̬"; break;
    case SW_SHOW :
       showstr = "�����������ʾ״̬"; break;
    case SW_SHOWMAXIMIZED :
       showstr = "������������״̬"; break;
    case SW_SHOWMINIMIZED :
       showstr = "�����������ʾ��ͼ��״̬"; break;
    case SW_SHOWMINNOACTIVE :
       showstr = "�����������ʾͼ��״̬"; break;
    case SW_SHOWNA :
       showstr = "���������ά��Ŀǰ״̬"; break;
    case SW_SHOWNOACTIVATE :
       showstr = "�����������ʾ�ϴ�״̬"; break;
    case SW_SHOWNORMAL :
       showstr = "�������������״̬"; break;
    default :
       showstr = "��������ǲ���״̬"; break;
    }
Memo1->Lines->Add(showstr);
//Wpl.ptMinPosition�ṹ��Ա
showstr = "��С��ʱλ����X= " + AnsiString(Wpl.ptMinPosition.x) +
          AnsiString(Wpl.ptMinPosition.y);
Memo1->Lines->Add(showstr);
//Wpl.ptMaxPosition�ṹ��Ա��
showstr = "���ʱλ����X=  " + AnsiString(Wpl.ptMaxPosition.x) +
          AnsiString(Wpl.ptMaxPosition.y);
Memo1->Lines->Add(showstr);
//Wpl.rcNormalPosition�ṹ��Ա��
RECT r = Wpl.rcNormalPosition;
showstr = "������������ʱ�������" + AnsiString(r.left) +
          "���ϱ���" + AnsiString(r.top) +
          "���ұ��� " + AnsiString(r.right) +
          "���ױ���" + AnsiString(r.bottom);
Memo1->Lines->Add(showstr);
}
//---------------------------------------------------------------------------
