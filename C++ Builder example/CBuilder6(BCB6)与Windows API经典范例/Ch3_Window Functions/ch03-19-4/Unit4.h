//---------------------------------------------------------------------------
#ifndef Unit4H
#define Unit4H
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
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TImage *Image1;
    TToolBar *ToolBar1;
    TButton *Button1;
    TImage *Image2;
    void __fastcall Button1Click(TObject *Sender);
    
private:	// User declarations
public:		// User declarations
    HWND CreateWindowForm(HWND HWndParent);
//    LONG APIENTRY WndProc2(HWND HWnd, UINT Msg,
//                           WPARAM WParam, LPARAM LParam);

/*
    void __fastcall CreateParams(TCreateParams &Params);
    void __fastcall WMSysCommand(TMessage &Msg);

BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(WM_SYSCOMMAND, TMessage, WMSysCommand)
END_MESSAGE_MAP(TForm)
*/
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
