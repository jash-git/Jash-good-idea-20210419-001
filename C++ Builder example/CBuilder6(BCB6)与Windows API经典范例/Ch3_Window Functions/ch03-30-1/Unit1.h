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
#include <shellapi.h> //Ö´ÐÐShellExecute APIº¯Êý
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TToolBar *ToolBar1;
    TButton *Button1;
    TMemo *Memo1;
    TStaticText *StaticText1;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    bool VaultWindowThreadID(HWND hWnd);
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
