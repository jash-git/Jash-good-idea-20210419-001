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
    TToolBar *ToolBar1;
    TButton *Button1;
    TStaticText *StaticText1;
    TCheckBox *CheckBox1;
    TMemo *Memo1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall CheckBox1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    char key[256];
    AnsiString str;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
