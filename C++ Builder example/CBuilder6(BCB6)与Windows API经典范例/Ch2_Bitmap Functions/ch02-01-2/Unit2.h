//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
    TGroupBox *box;
    TButton *btn;
    TImage *image;
    POINT p;
public:		// User declarations
    //自定义事件函数
    void __fastcall AllBtnClick(TObject *Sender);
    void __fastcall MoveBoxMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall MoveBoxMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall MoveBoxMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);

    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
