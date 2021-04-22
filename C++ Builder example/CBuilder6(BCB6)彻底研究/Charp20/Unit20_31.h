//---------------------------------------------------------------------------

#ifndef Unit20_31H
#define Unit20_31H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Rio.hpp>
#include <SOAPHTTPClient.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TLabel *Label1;
        TLabel *Label2;
        TMemo *Memo2;
        TLabel *Label3;
        TMemo *Memo3;
        TLabel *Label4;
        TMemo *Memo4;
        TLabel *Label5;
        TMemo *Memo5;
        TLabel *Label6;
        TMemo *Memo6;
        TButton *Button1;
        THTTPRIO *HTTPRIO1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        _di_IHeadLine FHeadLine;
        _di_IHeadLine GetHeadLine();
__property
        _di_IHeadLine HeadLine = { read=GetHeadLine };
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
