//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <NMDayTim.hpp>
#include <NMEcho.hpp>
#include <NMTime.hpp>
#include <Psock.hpp>
#include <ComCtrls.hpp>
#include <NMUDP.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *EdtSpyAddress;
    TLabel *Label2;
    TPanel *PanelDisplay;
    TLabel *Label3;
    TEdit *EdtTimeOut;
    TNMEcho *NMEcho1;
    TNMDayTime *NMDayTime1;
    TNMTime *NMTime1;
    TStatusBar *StatusBar1;
    TNMUDP *SUDP;
    TLabel *Label4;
    TTimer *Timer1;
    TEdit *EdtCaptureSize;
    TImage *Image1;
    TLabel *LabelTime;
    TGroupBox *GroupBox1;
    TButton *BtnTestTime;
    TButton *BtnTestDayTime;
    TButton *BtnTestEcho;
    TGroupBox *GroupBox2;
    TButton *BtnCapture;
    TButton *BtnCloseClient;
    TButton *BtnSetCaptureRec;
    TLabel *Label5;
    TCheckBox *ChkBoxAutoCapture;
    void __fastcall BtnTestEchoClick(TObject *Sender);
    void __fastcall NMEcho1Connect(TObject *Sender);
    void __fastcall NMEcho1ConnectionFailed(TObject *Sender);
    void __fastcall NMEcho1InvalidHost(bool &Handled);
    void __fastcall BtnTestDayTimeClick(TObject *Sender);
    void __fastcall NMDayTime1InvalidHost(bool &Handled);
    void __fastcall BtnTestTimeClick(TObject *Sender);
    void __fastcall NMTime1InvalidHost(bool &Handled);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall BtnCaptureClick(TObject *Sender);
    void __fastcall SUDPDataReceived(TComponent *Sender, int NumberBytes,
          AnsiString FromIP, int Port);
    void __fastcall BtnCloseClientClick(TObject *Sender);
    void __fastcall BtnSetCaptureRecClick(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall ChkBoxAutoCaptureClick(TObject *Sender);
private:	// User declarations
    int             m_BufferSize;
    int             m_LeftPos;
    int             m_RightPos;
    int             m_TopPos;
    int             m_BottomPos;
    TMemoryStream  *m_ResultStream;
    TMemoryStream  *m_TempStream;
    AnsiString      m_sCommand;
private:
    void GetCaptureSize(void);
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
