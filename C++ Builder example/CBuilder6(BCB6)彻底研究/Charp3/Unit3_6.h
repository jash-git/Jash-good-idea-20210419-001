//---------------------------------------------------------------------------
#ifndef Unit3_6H
#define Unit3_6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label10;
        TPanel *Panel1;
        void __fastcall Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y);
        void __fastcall Panel1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y);
        void __fastcall FormCreate(TObject *Sender);
        
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
