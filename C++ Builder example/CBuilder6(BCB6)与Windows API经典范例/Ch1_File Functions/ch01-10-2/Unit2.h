//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <FileCtrl.hpp>
#include <ToolWin.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
#include <stdlib.h>//char *_ltoa(long value, char *string, int radix);
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TListBox *ListBox1;
    TToolBar *ToolBar1;
    TButton *Button1;
    TStaticText *StaticText1;
    void __fastcall Button1Click(TObject *Sender);
    
private:	// User declarations
public:		// User declarations
    AnsiString diskfree(AnsiString disk,int s);
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
