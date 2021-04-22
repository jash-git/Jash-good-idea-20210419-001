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
void __fastcall TForm1::WMCommand(TMessage &Msg)
{
if ((HWND)Msg.LParam == DriveComboBox1->Handle
           && HIWORD(Msg.WParam) == CBN_CLOSEUP)
    {
    // if drive "A:" is selected
    if (DriveComboBox1->ItemIndex == 0)
        {
        DWORD dwData;
        AnsiString text = DriveComboBox1->Items->Strings[0];
        int OldErrorMode = ::SetErrorMode(SEM_FAILCRITICALERRORS);
        bool HasDisk = ::GetDiskFreeSpace(text.c_str(), &dwData,
                                          &dwData,
                                          &dwData, &dwData);
        SetErrorMode(OldErrorMode);
        if (!HasDisk)
            {
            ShowMessage("ÄãµÄ£ÁÅÌÃ»ÓÐ´ÅÅÌ¡£");
            DriveComboBox1->ItemIndex = 1;
            }
        }
    }
TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------


