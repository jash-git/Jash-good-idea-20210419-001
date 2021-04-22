//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include <Registry.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
   OpenDialog->Filter = "Text files (*.txt)|*.TXT";
   SaveDialog->Filter = "Text files (*.txt)|*.TXT";
   InitialStatus();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuOpenClick(TObject *Sender)
{
    if(OpenDialog->Execute())
    {
        m_LastFileName=OpenDialog->FileName;
        Memo1->Lines->LoadFromFile(m_LastFileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuSaveClick(TObject *Sender)
{
    AnsiString FileName;
    if(SaveDialog->Execute())
    {
      FileName=OpenDialog->FileName;
      Memo1->Lines->SaveToFile(FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuExitClick(TObject *Sender)
{

    Close();
}
//---------------------------------------------------------------------------

void TMainForm::SavePosInfo(void)
{
    TRegistry *Registry = new TRegistry;
    try
    {
       Registry->RootKey = HKEY_LOCAL_MACHINE;
       if(Registry->OpenKey("SOFTWARE\\×¢²á±í²âÊÔ³ÌÐò",true))
       {
            if(!Registry->KeyExists("Pos"))
            {
                Registry->CreateKey("Pos");
            }
            if(!Registry->KeyExists("History"))
            {
                Registry->CreateKey("History");
            }
            if(Registry->OpenKey("Pos",false))
            {
                Registry->WriteInteger("LeftPos",MainForm->Left);
                Registry->WriteInteger("TopPos",MainForm->Top);
                Registry->WriteInteger("Width",MainForm->Width);
                Registry->WriteInteger("Height",MainForm->Height);
            }
            Registry->CloseKey();
        }

        if(Registry->OpenKey("SOFTWARE\\×¢²á±í²âÊÔ³ÌÐò",false))
        {
            if(Registry->OpenKey("History",false))
            {
               Registry->WriteString("LastFile",m_LastFileName);
            }
        }
    }
   __finally
   {
        delete Registry;
        Registry=NULL;
   }
   if(Registry)
   {
        delete Registry;

   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    SavePosInfo();
}
//---------------------------------------------------------------------------

void TMainForm::InitialStatus(void)
{
    TRegistry *Registry = new TRegistry;
    try
    {
       Registry->RootKey = HKEY_LOCAL_MACHINE;
       if(Registry->OpenKey("SOFTWARE\\×¢²á±í²âÊÔ³ÌÐò",false))
       {
            if(Registry->KeyExists("Pos"))
            {
                if(Registry->OpenKey("Pos",false))
                {
                    MainForm->Left=Registry->ReadInteger("LeftPos");
                    MainForm->Top=Registry->ReadInteger("TopPos");
                    MainForm->Width=Registry->ReadInteger("Width");
                    MainForm->Height=Registry->ReadInteger("Height");
                }
            }
             Registry->CloseKey();

        }

        if(Registry->OpenKey("SOFTWARE\\×¢²á±í²âÊÔ³ÌÐò",false))
        {
            if(Registry->KeyExists("History"))
            {
                if(Registry->OpenKey("History",false))
                {

                    m_LastFileName=Registry->ReadString("LastFile");
                    if(!m_LastFileName.IsEmpty())
                        Memo1->Lines->LoadFromFile(m_LastFileName);
                }
            }

        }
    }
   __finally
   {
        delete Registry;
        Registry=NULL;
   }
   if(Registry)
   {
        delete Registry;
   }
}
