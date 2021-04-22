//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BtnOpenClick(TObject *Sender)
{
   switch(RadioGroup1->ItemIndex)
   {
        case 0:
               THelpContext HC;
               HC=0;
               Application->HelpContext(HC);
               break;
        case 1:
               Application->HelpCommand(HELP_CONTENTS,0);
               break;
        case 2:
              Application->HelpJump("Book");
              break;
        case 3:
              String sExeName=Application->ExeName;
              String sDir=ExtractFilePath(sExeName)+"MyHelp.hlp";
              char sHlpFile[200];
              StrPCopy(sHlpFile,sDir);
              WinHelp(Handle,sHlpFile,HELP_CONTENTS,0);
              break;
    }

}
//---------------------------------------------------------------------------

