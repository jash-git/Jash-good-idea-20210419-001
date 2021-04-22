//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ScktComp.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TServerSocket *ServerSocket1;
    TStatusBar *StatusBar1;
    TMainMenu *MainMenu1;
    TMenuItem *MenuListen;
    TMenuItem *MenuClose;
    TMenuItem *MenuDisConnect;
    TLabel *Label1;
    TLabel *LabelNotice;
    TListBox *ListUserAddr;
    TListBox *ListUserName;
    TLabel *Label3;
    TLabel *Label4;
    TEdit *EdtSend;
    TButton *BtnToAll;
    void __fastcall ServerSocket1Accept(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ServerSocket1ClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ServerSocket1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall EdtSendKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ListUserNameClick(TObject *Sender);
    void __fastcall BtnToAllClick(TObject *Sender);
    void __fastcall MenuDisConnectClick(TObject *Sender);
    void __fastcall MenuCloseClick(TObject *Sender);
    void __fastcall MenuListenClick(TObject *Sender);
private:	// User declarations
    int         m_iClientNum;
    AnsiString  m_sIsName;
    AnsiString  m_sIsChat;
    AnsiString  m_sIsCommand;
    AnsiString  m_sPart;
    AnsiString  m_sTo;
private:
    void __fastcall AppException(TObject *Sender, Exception *E);
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
