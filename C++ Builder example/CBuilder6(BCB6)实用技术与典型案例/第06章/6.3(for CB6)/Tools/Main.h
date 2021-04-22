//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TCheckBox *CheckBox1;
    TButton *Button1;
    TListBox *ListBoxCptureInfo;
    TButton *Button2;
    TEdit *EdtHwn;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *EdtInterval;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
private:
    BOOL        m_bNextHide;
    int         m_iSpyTime;
    AnsiString  m_strHistoryFile;
    HWND        m_APITestHwnd;
    AnsiString  m_strOSPath;
private:	// User declarations
    void    ReadReg(void);
    void    WriteReg(void);
    void    LoadHistoryInfo(void);
    void    SaveHistoryFile(void);
    void    ReadHwnd(void);
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
