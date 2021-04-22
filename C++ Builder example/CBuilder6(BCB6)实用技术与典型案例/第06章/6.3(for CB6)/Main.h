//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#define MaxCaptureNum       5
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu;
    TMenuItem *MenuHide;
    TLabel *LabelCapture;
    TStatusBar *StatusBar1;
    TListBox *ListBoxCapture;
    TLabel *LabelHasCapture;
    TLabel *Label2;
    TPanel *PanelInfo;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TCheckBox *CheckBoxHide;
    TTimer *Timer1;
    TButton *BtnClearSelect;
    void __fastcall MenuHideClick(TObject *Sender);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall BtnClearSelectClick(TObject *Sender);
private:
    BOOL            bStartCapture;
    BOOL            bNextHide;
    int             m_CaptureNum;
    int             m_iSpyTime;
    TStringList     *m_strCaptureWindow;
    AnsiString      m_strWindowTitle;
    AnsiString      m_strOSPath;


private:	// User declarations
    void __fastcall CreateParams(TCreateParams &Params);
    void    SaveCaptureWindow(void);
    void    LoadHistoryInfo(void);
    void    WriteReg(void);
    void    ReadReg(void);
    void    DiasableCaptureWindow(void);
    void    RecordHwnd(void);

public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
