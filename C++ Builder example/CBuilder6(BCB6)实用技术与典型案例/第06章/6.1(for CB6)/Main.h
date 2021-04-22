//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
#define WM_MYMESSAGE   WM_USER+10
#define LEFTBUTTON     0
#define RIGHTBUTTON    1
//---------------------------------------------------------------------------

class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TBitBtn *BtnOk;
        TButton *BtnOpen;
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall BtnOkClick(TObject *Sender);
        void __fastcall BtnOpenClick(TObject *Sender);
private:
        void DrawFace(void);	// User declarations
        void __fastcall WMNCHitTest(TMessage &Msg);
        void __fastcall MyMessage(TMessage &Msg);
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
public:
         BEGIN_MESSAGE_MAP
           VCL_MESSAGE_HANDLER(WM_NCHITTEST,TMessage,WMNCHitTest)
           VCL_MESSAGE_HANDLER(WM_MYMESSAGE,TMessage,MyMessage)
         END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
