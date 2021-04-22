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
   // 把从FileListBox中选出的AVI文件文件名传给OLE Server
   MediaServer->set_FileStr((Variant)(ExpandUNCFileName(FileListBox1->FileName)));

   // 控制OLE Server播放指定的AVI文件
   MediaServer->OpenFile();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   // 控制OLE Server播放指定的AVI文件
   MediaServer->PlayFile();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   // 控制OLE Server停播指定的AVI文件
   MediaServer->StopFile();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   Close();        
}
//---------------------------------------------------------------------------
