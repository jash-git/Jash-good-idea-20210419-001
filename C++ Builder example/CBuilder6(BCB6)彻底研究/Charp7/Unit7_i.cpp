//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7_i.h"
#include "Project7_h_TLB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TCOMITmedia_server MediaServer;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   MediaServer=CoTmedia_server::Create();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileListBox1Click(TObject *Sender)
{
   // �Ѵ�FileListBox��ѡ����AVI�ļ��ļ�������OLE Server
   MediaServer->set_FileStr((Variant)(ExpandUNCFileName(FileListBox1->FileName)));

   // ����OLE Server����ָ����AVI�ļ�
   MediaServer->OpenFile();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   // ����OLE Server����ָ����AVI�ļ�
   MediaServer->PlayFile();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   // ����OLE Serverͣ��ָ����AVI�ļ�
   MediaServer->StopFile();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   Close();        
}
//---------------------------------------------------------------------------
