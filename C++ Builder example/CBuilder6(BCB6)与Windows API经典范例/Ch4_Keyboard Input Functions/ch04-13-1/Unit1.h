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
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TToolBar *ToolBar1;
    TButton *Button1;
    TMemo *Memo1;
    TTimer *Timer1;
    TRadioGroup *RadioGroup1;
    void __fastcall Button1Click(TObject *Sender);
    
    void __fastcall Timer1Timer(TObject *Sender);
    
    void __fastcall RadioGroup1Click(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
    int s, pass;//输入法总数
    TStringList *list;//所有输入法名称临时清单
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
