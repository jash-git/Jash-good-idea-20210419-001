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
    TEdit *Edit1;
    TListBox *ListBox1;
        TStaticText *StaticText1;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    //�Զ��庯��
    void ShowDrive(void);
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
