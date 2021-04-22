//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
#include <memory>
#include <assert.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TPanel *Panel1;
    TImage *Image1;
    void __fastcall Panel1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Panel1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Panel1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
    bool is_dragging_;
    POINT PMouse_;
    RECT DragRect_;
    //在内存中动态配置
    std::auto_ptr<Graphics::TBitmap> Bitmap_;
    std::auto_ptr<TCanvas> ScreenCanvas_;
public:		// User declarations
    //自定义函数，将此矩形区域对象绘制成网状边框状态
    void RenderTrackingRect(IN HDC HDestDC, IN RECT& RRender);
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
