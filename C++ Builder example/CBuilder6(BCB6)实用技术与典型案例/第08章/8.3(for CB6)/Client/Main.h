//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ScktComp.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *MenuConnect;
    TMenuItem *MenuDisconnect;
    TListBox *ListUser;
    TLabel *Label1;
    TClientSocket *ClientSocket1;
    TLabel *Label2;
    TLabel *Label3;
    TMemo *MemoReceive;
    TStatusBar *StatusBar1;
    TLabel *LabelNotice;
    TEdit *EdtSend;
    TButton *BtnToAll;
    TMenuItem *MenuSet;
    void __fastcall ClientSocket1Connecting(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall MenuConnectClick(TObject *Sender);
    void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall ListUserClick(TObject *Sender);
    void __fastcall EdtSendKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall BtnToAllClick(TObject *Sender);
    void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall MenuDisconnectClick(TObject *Sender);
    void __fastcall MenuSetClick(TObject *Sender);
private:	// User declarations
    BOOL        m_HasConnected;
    AnsiString  m_sHostAddress;
    AnsiString  m_sName;
    AnsiString  m_sIsChat;
    AnsiString  m_sSpeakTo;
    AnsiString  m_sPart;
    AnsiString  m_sSendInfo;
    AnsiString  m_sIsName;

public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
