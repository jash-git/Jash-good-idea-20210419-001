//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <NMUDP.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TNMUDP *CUDP;
    TLabel *Label1;
    TEdit *EdtRemoteAddress;
    TCheckBox *ChkBoxHide;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall CUDPDataReceived(TComponent *Sender, int NumberBytes,
          AnsiString FromIP, int Port);
    void __fastcall ChkBoxHideClick(TObject *Sender);
private:	// User declarations
    AnsiString m_sCommand;
    AnsiString m_sReceiveData;
    TMemoryStream* m_BmpStream;
    int m_Bufsize;
    int m_iLeftSize;
    int m_SendSize;
    int m_LeftPos;
    int m_TopPos;
    int m_RightPos;
    int m_BottomPos;
    Byte *m_pBuf;
private:
    void ScreenCapture(void);
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
