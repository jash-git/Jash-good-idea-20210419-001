//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
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
#include <stdlib.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TToolBar *ToolBar1;
    TButton *Button1;
    TStaticText *StaticText1;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void DrawDIBuffer(HDC HTargetDC, int X, int Y,
                      int dst_width, int dst_height,
                      COLORREF *clrrf,
                      int src_width, int src_height);
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
