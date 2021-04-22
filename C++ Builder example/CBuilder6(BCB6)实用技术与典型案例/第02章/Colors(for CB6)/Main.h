///////////////////////////////////////////////////////////////////////
//  ColorMain.h                                                      //
//  Project: Colors                                                  //
//  Copyright (c) 1998 by Jeff Cottingham                            //
///////////////////////////////////////////////////////////////////////


//---------------------------------------------------------------------------
#ifndef ColorMainH
#define ColorMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TTrackBar *TrackBar1;
        TTrackBar *TrackBar2;
        TTrackBar *TrackBar3;
        TPanel *Panel1;
        TLabel *Label1;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TPaintBox *PaintBox1;void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall PaintBox1Paint(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
