//---------------------------------------------------------------------------
#ifndef Unit16_4H
#define Unit16_4H
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <HTTPApp.hpp>
#include <CompProd.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <HTTPProd.hpp>
#include <MConnect.hpp>
#include <MidItems.hpp>
#include <MidProd.hpp>
#include <PagItems.hpp>
#include <SConnect.hpp>
#include <WebComp.hpp>
#include <XMLBrokr.hpp>
//---------------------------------------------------------------------------
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
        TSocketConnection *SocketConnection1;
        TXMLBroker *XMLBroker1;
        TInetXPageProducer *InetXPageProducer1;
        TClientDataSet *ClientDataSet1;
        TQueryForm *QueryForm1;
        TQueryFieldGroup *QueryFieldGroup1;
        TQueryButtons *QueryButtons1;
        TResetQueryButton *ResetQueryButton1;
        TSubmitQueryButton *SubmitQueryButton1;
        void __fastcall WebModule1WebActionItem1Action(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
private:	// User declarations
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif
