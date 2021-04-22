//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Mask.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TMaskEdit *MaskEdit1;
    TMaskEdit *MaskEdit2;
    TMaskEdit *MaskEdit3;
    TMaskEdit *MaskEdit4;
    TMaskEdit *MaskEdit5;
    TMaskEdit *MaskEdit6;
private:	// User declarations
public:		// User declarations
    //MaskEdit共同的OnMouseMove事件
    void __fastcall AllMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
