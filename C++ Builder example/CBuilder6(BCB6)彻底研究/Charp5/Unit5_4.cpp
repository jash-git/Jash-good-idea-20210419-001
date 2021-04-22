//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5_4.h"
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
char* GetMessageString(int i)
{
  char *str;

  switch(i) {
	case IDABORT:
    	str="��ֹ";
    	break;
	case IDCANCEL:
      	str="ȡ��";
    	break;
	case IDIGNORE:
        str="����";
    	break;
	case IDNO:
        str="��";
    	break;
	case IDOK:
    	str="ȷ��";
    	break;
	case IDRETRY:
    	str="����";
    	break;
	case IDYES:
        str="��";
    	break;
    default :
    	str="";
        break;
  }
  return(str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn10Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "�ǡ�����Ϣ����","Dialog" ,MB_YESNOCANCEL);
  Label6->Caption=GetMessageString(i);
  Label6->Caption+="*";
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  MessageBox(NULL, "������Ϣ��ʾ����!!" , "Warning" ,MB_ICONWARNING);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  MessageBox(NULL, "������Ϣ��ʾ����!!" , "Question" ,MB_ICONQUESTION);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
  MessageBox(NULL, "������Ϣ��ʾ����!!" , "Error" ,MB_ICONERROR);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
  MessageBox(NULL, "��Ϣ��ʾ��ʾ���� !!" , "Message" ,MB_ICONASTERISK);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "������Ϣ����!!" , "Help" ,MB_HELP);
  Label1->Caption=GetMessageString(i);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "ȷ����Ϣ����!!" , "Dialog" ,MB_OK);
  Label2->Caption=GetMessageString(i);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn7Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "ȷ��ȡ������Ϣ����!!" , "Dialog" ,MB_OKCANCEL);
  Label3->Caption=GetMessageString(i);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn8Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "���ԡ�ȡ����Ϣ����!!" , "Dialog" ,MB_RETRYCANCEL);
  Label4->Caption=GetMessageString(i);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn9Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "�ǡ�����Ϣ����!!" , "Dialog" ,MB_YESNO);
  Label5->Caption=GetMessageString(i);
}
//-------------------------------------------------------------------





