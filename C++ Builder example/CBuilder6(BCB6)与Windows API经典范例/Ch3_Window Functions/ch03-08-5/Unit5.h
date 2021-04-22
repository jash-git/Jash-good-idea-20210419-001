//---------------------------------------------------------------------------
#ifndef Unit5H
#define Unit5H
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
    TStaticText *StaticText2;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
    HWND HComboBox;
public:		// User declarations
    HWND CreateComboBox(HWND HParent, int nID, RECT *r, unsigned int uiStyle);
    //¿πΩÿ√¸¡Ó–≈œ¢Æß
    void __fastcall NewComboBoxClick(TMessage &Msg);
BEGIN_MESSAGE_MAP
VCL_MESSAGE_HANDLER(WM_COMMAND,TMessage,NewComboBoxClick)
END_MESSAGE_MAP(TForm)
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
