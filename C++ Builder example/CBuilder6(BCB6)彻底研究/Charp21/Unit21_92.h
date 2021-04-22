//---------------------------------------------------------------------------
#ifndef Unit21_92H
#define Unit21_92H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <mxgraph.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <MXGRAPH.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TDecisionGraph *DecisionGraph1;
        TBarSeries *Series5;
        TBarSeries *Series6;
        TBarSeries *Series7;
        TBarSeries *Series8;
        TBarSeries *Series9;
        TBarSeries *Series10;
        TBarSeries *Series11;
        TBarSeries *Series1;
        TBarSeries *Series2;
        TBarSeries *Series3;
        TBarSeries *Series4;
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
