//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TToolBar *ToolBar1;
    TButton *Button1;
    TButton *Button2;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
    TOpenDialog *OpenDlg;
public:		// User declarations
    void __fastcall AllOpenDlgShow(TObject *Sender);
    __fastcall TForm1(TComponent* Owner);
};
//重载【打开】对话框，成为新类型-------------------------------------------
class TMySelectDlg : public Dialogs::TOpenDialog
{
public:
  __fastcall virtual TMySelectDlg(Classes::TComponent* AOwner) :
        Dialogs::TOpenDialog(AOwner) {}
  void __fastcall WndProc(Messages::TMessage& Msg);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
