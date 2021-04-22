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
    	str="终止";
    	break;
	case IDCANCEL:
      	str="取消";
    	break;
	case IDIGNORE:
        str="忽略";
    	break;
	case IDNO:
        str="否";
    	break;
	case IDOK:
    	str="确定";
    	break;
	case IDRETRY:
    	str="重试";
    	break;
	case IDYES:
        str="是";
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

  i=MessageBox(NULL, "是、否信息窗口","Dialog" ,MB_YESNOCANCEL);
  Label6->Caption=GetMessageString(i);
  Label6->Caption+="*";
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  MessageBox(NULL, "警告信息显示窗口!!" , "Warning" ,MB_ICONWARNING);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  MessageBox(NULL, "疑问信息显示窗口!!" , "Question" ,MB_ICONQUESTION);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
  MessageBox(NULL, "错误信息显示窗口!!" , "Error" ,MB_ICONERROR);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
  MessageBox(NULL, "信息提示显示窗口 !!" , "Message" ,MB_ICONASTERISK);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "帮助信息窗口!!" , "Help" ,MB_HELP);
  Label1->Caption=GetMessageString(i);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "确定信息窗口!!" , "Dialog" ,MB_OK);
  Label2->Caption=GetMessageString(i);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn7Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "确认取消、信息窗口!!" , "Dialog" ,MB_OKCANCEL);
  Label3->Caption=GetMessageString(i);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn8Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "重试、取消信息窗口!!" , "Dialog" ,MB_RETRYCANCEL);
  Label4->Caption=GetMessageString(i);
}
//---------------------------------------------------------------------
void __fastcall TForm1::BitBtn9Click(TObject *Sender)
{
  int i;

  i=MessageBox(NULL, "是、否信息窗口!!" , "Dialog" ,MB_YESNO);
  Label5->Caption=GetMessageString(i);
}
//-------------------------------------------------------------------





