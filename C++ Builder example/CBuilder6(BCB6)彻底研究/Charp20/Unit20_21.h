//---------------------------------------------------------------------------

#ifndef Unit20_21H
#define Unit20_21H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Rio.hpp>
#include <SOAPHTTPClient.hpp>
#include "Unit20_22.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        THTTPRIO *HTTPRIO1;
        TButton *Button1;
        TButton *Button2;
        TComboBox *ComboBox1;
        TLabel *Label1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        _di_IQueryCapital FQueryCapital;
        _di_IQueryCapital GetQueryCapital();
__property
        _di_IQueryCapital QueryCapital = { read=GetQueryCapital };
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
