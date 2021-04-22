//---------------------------------------------------------------------------
#ifndef Unit20_41H
#define Unit20_41H
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <HTTPApp.hpp>
#include <Rio.hpp>
#include <SOAPHTTPClient.hpp>
//---------------------------------------------------------------------------
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
        THTTPRIO *HTTPRIO1;
        void __fastcall WebModule1QueryCountryAction(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
        void __fastcall WebModule1QueryCapitalAction(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
private:	// User declarations
        AnsiString fQueryCountry();
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
        _di_IQueryCapital FQueryCapital;
        _di_IQueryCapital GetQueryCapital();
__property
        _di_IQueryCapital QueryCapital = { read=GetQueryCapital };        
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif
