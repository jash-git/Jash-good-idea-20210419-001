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
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TToolBar *ToolBar1;
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *FileSub101;
    TMenuItem *FileSub102;
    TCheckBox *CheckBox1;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FileSub101Click(TObject *Sender);
    void __fastcall FileSub102Click(TObject *Sender);
    void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
