//---------------------------------------------------------------------------
#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TImage *Image1;
    TToolBar *ToolBar1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;
    TToolButton *ToolButton8;
    TToolButton *ToolButton10;
    TToolButton *ToolButton6;
    TToolButton *ToolButton7;
    TToolButton *ToolButton9;
private:	// User declarations
public:		// User declarations
    //�Զ��庯��--����ճ��ͼ��
    void TileBmp(HDC HDestDC, int w, int h,
                 RECT r, HDC HSourceDC);
    //��׽WM_NOTIFY��Ϣ�е�NM_CUSTOMDRAW����Ϣ��
    void __fastcall WMNotify(TMessage &Msg);
BEGIN_MESSAGE_MAP
VCL_MESSAGE_HANDLER(WM_NOTIFY, TMessage, WMNotify)
END_MESSAGE_MAP(TForm)
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
