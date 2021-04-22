//---------------------------------------------------------------------------

#ifndef MessageDlgH
#define MessageDlgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TMessageForm : public TForm
{
__published:	// IDE-managed Components
    TButton *BtnLeft;
    TButton *BtnRight;
    TButton *BtnClose;
    void __fastcall BtnCloseClick(TObject *Sender);
    void __fastcall BtnLeftClick(TObject *Sender);
    void __fastcall BtnRightClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMessageForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMessageForm *MessageForm;
//---------------------------------------------------------------------------
#endif
