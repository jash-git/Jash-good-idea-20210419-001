//---------------------------------------------------------------------------
#ifndef Unit4H
#define Unit4H
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
    TToolBar *ToolBar2;
    TComboBox *ComboBox1;
    TStaticText *StaticText2;
    TComboBox *ComboBox2;
    TStaticText *StaticText3;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    bool FPushed;
    ::TWndMethod OldComboBoxWP;
public:		// User declarations
    void DrawComboBox(HDC Hdc, bool pushed);
    void __fastcall NewComboBoxWP(TMessage &Msg);

    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
