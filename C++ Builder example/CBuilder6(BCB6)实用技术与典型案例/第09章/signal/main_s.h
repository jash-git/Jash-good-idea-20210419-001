//---------------------------------------------------------------------------

#ifndef main_sH
#define main_sH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include "signal_s.hh"
//---------------------------------------------------------------------------
class TMain_sForm : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TStatusBar *StatusBar1;
        TMainMenu *MainMenu1;
        TMenuItem *FIle1;
        TMenuItem *Exit1;
        TMenuItem *Setting1;
        TMenuItem *Property1;
        void __fastcall Property1Click(TObject *Sender);
private:	// User declarations

        CORBA::ORB_var orb;
        CORBA::BOA_var boa;
        CORBA::Object_ptr obj;

public:		// User declarations
        __fastcall TMain_sForm(TComponent* Owner);
};

class SignalImpl: public _sk_Signal
{
protected:
public:
        SignalImpl(const char *object_name=NULL); 
        void GetSignal(CORBA::Long _n, CORBA::Long _fs,
          SignalType& _output);
};

//---------------------------------------------------------------------------
extern PACKAGE TMain_sForm *Main_sForm;
//---------------------------------------------------------------------------
#endif
