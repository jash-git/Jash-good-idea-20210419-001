//---------------------------------------------------------------------------
#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
#include <memory>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TToolBar *ToolBar1;
    TButton *Button1;
    TMemo *Memo1;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    //颜色的共同变量
    unsigned long fboxColor;
    //见cpp中函数前的说明
    void GetFontBoxItemsID_Text(HWND handle);
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
//自定义字体对话框类
class TMyFontDialog : public TFontDialog
{
private:
    HWND HNewBtn;
protected:
    virtual void __fastcall ShowColorDialog();
    void __fastcall WndProc(TMessage& Msg);
public:
    __fastcall TMyFontDialog(TComponent* Owner) : TFontDialog(Owner){}
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
