//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <NMsmtp.hpp>
#include <Psock.hpp>
#include <ComCtrls.hpp>
#include <NMpop3.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TNMSMTP *NMSMTP1;
    TGroupBox *GroupBox1;
    TEdit *EdtSMTPServer;
    TLabel *Label1;
    TButton *BtnSMTPConnect;
    TLabel *Label2;
    TEdit *EdtSMTPPort;
    TLabel *Label3;
    TEdit *EdtSMTPUser;
    TButton *BtnSendMail;
    TButton *BtnSMTPDisClose;
    TGroupBox *GroupBox2;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *EdtPop3Server;
    TButton *BtnPop3Connect;
    TEdit *EdtPop3Port;
    TEdit *EdtPop3User;
    TButton *BtnReciveMail;
    TButton *BtnPop3DisConnect;
    TButton *BtnClose;
    TLabel *Label7;
    TEdit *EdtPop3Password;
    TStatusBar *StatusBar1;
    TNMPOP3 *NMPOP31;
    TLabel *Label8;
    TEdit *EdtFromAddress;
    void __fastcall BtnSMTPConnectClick(TObject *Sender);
    void __fastcall NMSMTP1Connect(TObject *Sender);
    void __fastcall BtnPop3ConnectClick(TObject *Sender);
    void __fastcall NMPOP31Connect(TObject *Sender);
    void __fastcall BtnPop3DisConnectClick(TObject *Sender);
    void __fastcall BtnReciveMailClick(TObject *Sender);
    void __fastcall NMPOP31Disconnect(TObject *Sender);
    void __fastcall NMPOP31List(int Msg, int Size);
    void __fastcall BtnSMTPDisCloseClick(TObject *Sender);
    void __fastcall NMPOP31RetrieveStart(TObject *Sender);
    void __fastcall NMPOP31RetrieveEnd(TObject *Sender);
    void __fastcall NMSMTP1Disconnect(TObject *Sender);
    void __fastcall BtnCloseClick(TObject *Sender);
private:	// User declarations
public:


public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
