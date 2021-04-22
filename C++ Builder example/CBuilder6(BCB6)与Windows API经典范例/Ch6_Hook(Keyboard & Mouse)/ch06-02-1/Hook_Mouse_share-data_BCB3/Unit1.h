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
class TCallHookForm : public TForm
{
__published:	// IDE-managed Components
    TToolBar *ToolBar1;
    TButton *Button1;
    TButton *Button2;
    TEdit *Edit1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    UINT timer;//¶¨Ê±Æ÷
public:		// User declarations
    __fastcall TCallHookForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCallHookForm *CallHookForm;
//---------------------------------------------------------------------------
#endif
 