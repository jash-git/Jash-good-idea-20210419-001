//---------------------------------------------------------------------------

#ifndef Unit19_31H
#define Unit19_31H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTable *Table1;
        TClientDataSet *ClientDataSet1;
        TButton *Button1;
        TDataSetProvider *DataSetProvider1;
        TMemo *Memo1;
        TXMLDocument *XMLDocument1;
        TTreeView *TreeView1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
        void __fastcall DomToTree(_di_IXMLNode XMLNode,TTreeNode *TreeNode);
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
