//---------------------------------------------------------------------------
#ifndef Unit5_51H
#define Unit5_51H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TRichEdit *RichEdit1;
        TMainMenu *MainMenu1;
        TMenuItem *F1;
        TMenuItem *O2;
        TMenuItem *S2;
        TMenuItem *N1;
        TMenuItem *N3;
        TMenuItem *P1;
        TMenuItem *N2;
        TMenuItem *E2;
        TMenuItem *E1;
        TMenuItem *U1;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *S1;
        TMenuItem *R1;
        TMenuItem *H1;
        TMenuItem *N10;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TFontDialog *FontDialog1;
        TColorDialog *ColorDialog1;
        TPrintDialog *PrintDialog1;
        TPrinterSetupDialog *PrinterSetupDialog1;
        TFindDialog *FindDialog1;
        TReplaceDialog *ReplaceDialog1;
        TMenuItem *U2;
        TMenuItem *P2;
        TMenuItem *P3;
        TMenuItem *N6;
        TMenuItem *L1;
        void __fastcall E2Click(TObject *Sender);
        void __fastcall FindDialog1Find(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall O2Click(TObject *Sender);
        void __fastcall P1Click(TObject *Sender);
        void __fastcall R1Click(TObject *Sender);
        void __fastcall S1Click(TObject *Sender);
        void __fastcall S2Click(TObject *Sender);
        void __fastcall U1Click(TObject *Sender);
        
        void __fastcall ReplaceDialog1Replace(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall U2Click(TObject *Sender);
        void __fastcall P2Click(TObject *Sender);
        void __fastcall P3Click(TObject *Sender);
        void __fastcall L1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
