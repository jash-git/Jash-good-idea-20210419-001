//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//TrayIcon专属头文件---------------------------------------------------------
#include <shellapi.h>
#include <ImgList.hpp>
//TrayIcon自定义信息---------------------------------------------------------
const int WM_TRAYICON = WM_USER + 1001;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TImageList *ImageList1;
    TPopupMenu *PopupMenu1;
    TMenuItem *pop011;
    TMenuItem *pop021;
    TMenuItem *pop031;
    TStaticText *StaticText2;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall pop031Click(TObject *Sender);
    void __fastcall pop011Click(TObject *Sender);
    void __fastcall pop021Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    Graphics::TIcon *TrayIcon;
public:		// User declarations
    //新建或更新自定义的TrayIcon
    void __fastcall AddorChangeIcon(int iconNum);
    //捕捉TrayIcon自定义信息
    void __fastcall WmNewTray(TMessage &Msg);
BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(WM_TRAYICON, TMessage, WmNewTray)
END_MESSAGE_MAP(TForm)
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
