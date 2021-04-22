///////////////////////////////////////////////////////////////////////
//  RotateMain.h                                                     //
//  Project: Rotate                                                  //
//  Copyright (c) 1998 by Jeff Cottingham                            //
///////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
#ifndef RotateMainH
#define RotateMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TButton *btnLoad;
        TButton *btnR180;
        TButton *btnR90;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnLoadClick(TObject *Sender);
        void __fastcall btnR180Click(TObject *Sender);
        void __fastcall btnR90Click(TObject *Sender);
private:	// User declarations
        Graphics::TBitmap* pBitmap1;
        Graphics::TBitmap* pBitmap2;
        Byte *ptr1;
        Byte *ptr2;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
