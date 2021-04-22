//---------------------------------------------------------------------------
#ifndef Unit16_2H
#define Unit16_2H
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <HTTPApp.hpp>
#include <CompProd.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <MConnect.hpp>
#include <MidItems.hpp>
#include <MidProd.hpp>
#include <PagItems.hpp>
#include <XMLBrokr.hpp>
#include <DB.hpp>
#include <HTTPProd.hpp>
#include <WebComp.hpp>
#include <SConnect.hpp>
//---------------------------------------------------------------------------
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
        TXMLBroker *XMLBroker1;
        TInetXPageProducer *InetXPageProducer1;
        TDataForm *DataForm1;
        TFieldGroup *FieldGroup1;
        TDataNavigator *DataNavigator1;
        TFirstButton *FirstButton1;
        TPriorPageButton *PriorPageButton1;
        TPriorButton *PriorButton1;
        TNextButton *NextButton1;
        TNextPageButton *NextPageButton1;
        TLastButton *LastButton1;
        TInsertButton *InsertButton1;
        TDeleteButton *DeleteButton1;
        TPostButton *PostButton1;
        TApplyUpdatesButton *ApplyUpdatesButton1;
        TSocketConnection *SocketConnection1;
        void __fastcall InetXPageProducer2HTMLTag(TObject *Sender,
          TTag Tag, const AnsiString TagString, TStrings *TagParams,
          AnsiString &ReplaceText);
private:	// User declarations
void __fastcall AddScript(void * Data, _di_IAddScriptElements AddScriptElements);
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif
