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
    TStaticText *StaticText1;
    TToolBar *ToolBar1;
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

    void __fastcall WMCloseQuery(TMessage &Msg);
BEGIN_MESSAGE_MAP
VCL_MESSAGE_HANDLER(WM_CLOSE,TMessage,WMCloseQuery)
//这里要注意被关闭组件是否继承TWinControl类
END_MESSAGE_MAP(TWinControl)
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
