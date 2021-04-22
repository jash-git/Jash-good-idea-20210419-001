//---------------------------------------------------------------------------
#ifndef Unit4_1H
#define Unit4_1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TPanel *Panel1;
        TPanel *Panel2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TMainMenu *MainMenu1;
        TMenuItem *F1;
        TMenuItem *O1;
        TMenuItem *O2;
        TMenuItem *S2;
        TMenuItem *N12;
        TMenuItem *N13;
        TMenuItem *N1;
        TMenuItem *N3;
        TMenuItem *P1;
        TMenuItem *N2;
        TMenuItem *E2;
        TMenuItem *E1;
        TMenuItem *U1;
        TMenuItem *N4;
        TMenuItem *C1;
        TMenuItem *C2;
        TMenuItem *P2;
        TMenuItem *L1;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *H1;
        TMenuItem *N10;
        TMenuItem *N11;
        TMenuItem *A2;
        TPopupMenu *PopupMenu1;
        TMenuItem *N14;
        TMenuItem *N15;
        TMenuItem *N16;
        TMenuItem *N17;
        TMenuItem *N18;
        TMenuItem *N19;
        TMenuItem *N20;
        TMenuItem *N21;
        TMenuItem *N22;
        void __fastcall O1Click(TObject *Sender);
        void __fastcall O2Click(TObject *Sender);
        void __fastcall N13Click(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall P1Click(TObject *Sender);
        void __fastcall E2Click(TObject *Sender);
        void __fastcall N14Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall N17Click(TObject *Sender);
        void __fastcall N18Click(TObject *Sender);
        void __fastcall N20Click(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
        void __fastcall N22Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
