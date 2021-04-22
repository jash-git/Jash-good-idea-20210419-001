//---------------------------------------------------------------------------

#ifndef main_cH
#define main_cH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include "signal_c.hh"
//---------------------------------------------------------------------------
class TMain_cForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TChart *Chart1;
        TLineSeries *Series1;
        TButton *Button1;
        TComboBox *NumberBox;
        TComboBox *FreqBox;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
        void __fastcall DrawChart(TChart *chart,SignalType signal,int N,float fs);
public:		// User declarations
        __fastcall TMain_cForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TMain_cForm *Main_cForm;
//---------------------------------------------------------------------------
#endif
