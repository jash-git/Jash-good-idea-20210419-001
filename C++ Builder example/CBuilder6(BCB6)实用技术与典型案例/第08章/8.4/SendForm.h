//---------------------------------------------------------------------------

#ifndef SendFormH
#define SendFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TSMTPForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TEdit *EdtToAddress;
    TLabel *Label1;
    TEdit *EdtCarbonCopy;
    TLabel *Label2;
    TLabel *Label3;
    TButton *BtnAddAttach;
    TLabel *Label4;
    TEdit *EdtBlindCopy;
    TButton *BtnDeleteAttach;
    TRadioGroup *RadioGroup1;
    TLabel *Label5;
    TEdit *EdtSubject;
    TMemo *MemoContent;
    TLabel *Label6;
    TButton *BtnSend;
    TListBox *ListBoxAttach;
    TOpenDialog *OpenDialog1;
    void __fastcall BtnSendClick(TObject *Sender);
    void __fastcall BtnAddAttachClick(TObject *Sender);
    void __fastcall BtnDeleteAttachClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TSMTPForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSMTPForm *SMTPForm;
//---------------------------------------------------------------------------
#endif
