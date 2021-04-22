//---------------------------------------------------------------------------
#ifndef Unit20_51H
#define Unit20_51H
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
        void __fastcall WebModule1QueryHeadLineAction(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
private:	// User declarations
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
        _di_IHeadLine FHeadLine;
        _di_IHeadLine GetHeadLine();
__property
        _di_IHeadLine HeadLine = { read=GetHeadLine };        
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif
