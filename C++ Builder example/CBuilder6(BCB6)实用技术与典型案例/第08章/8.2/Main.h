//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SHDocVw_OCX.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <OleCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TStatusBar *StatusBar1;
    TCppWebBrowser *CppWebBrowser1;
    TPanel *Panel2;
    TComboBox *CmbURL;
    TSpeedButton *BtnForward;
    TSpeedButton *BtnBack;
    TSpeedButton *BtnHome;
    TSpeedButton *BtnGoto;
    TSpeedButton *SpeedButton5;
    TSpeedButton *BtnStop;
    void __fastcall BtnGotoClick(TObject *Sender);
    void __fastcall CmbURLKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall BtnBackClick(TObject *Sender);
    void __fastcall BtnForwardClick(TObject *Sender);
    void __fastcall BtnHomeClick(TObject *Sender);
    void __fastcall BtnStopClick(TObject *Sender);
    void __fastcall SpeedButton5Click(TObject *Sender);
    void __fastcall CppWebBrowser1DownloadComplete(TObject *Sender);
    void __fastcall CppWebBrowser1DownloadBegin(TObject *Sender);
    void __fastcall CppWebBrowser1ProgressChange(TObject *Sender,
          long Progress, long ProgressMax);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    TProgressBar  *ProgressBar;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
