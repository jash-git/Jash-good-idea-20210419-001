//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef Unit7_d2H
#define Unit7_d2H
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:
        TButton *OKBtn;
        TButton *CancelBtn;
        TBevel *Bevel1;
        TLabel *Label1;
        TEdit *WidthEdit;
        TLabel *Label2;
        TEdit *HeightEdit;

private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
