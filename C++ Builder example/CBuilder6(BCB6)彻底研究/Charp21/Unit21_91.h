//---------------------------------------------------------------------------
#ifndef Unit21_91H
#define Unit21_91H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <mxDB.hpp>
#include <mxgrid.hpp>
#include <mxpivsrc.hpp>
#include <mxstore.hpp>
#include <mxtables.hpp>
#include <DB.hpp>
#include <MXDB.hpp>
#include <MXGRID.hpp>
#include <MXPIVSRC.hpp>
#include <Mxstore.hpp>
#include <MXTABLES.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TDecisionPivot *DecisionPivot1;
        TDecisionGrid *DecisionGrid1;
        TDecisionCube *DecisionCube1;
        TDecisionQuery *DecisionQuery1;
        TDecisionSource *DecisionSource1;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
