//---------------------------------------------------------------------------
#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
#include <memory>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TImage *Image1;
    TToolBar *ToolBar1;
    TCheckBox *CheckBox1;
    void __fastcall FormPaint(TObject *Sender);
    
    
    void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
    Graphics::TBitmap *gridBitmap, *Bitmap;
    int x, y;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
