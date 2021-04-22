///////////////////////////////////////////////////////////////////////
//  PaletteMain.h                                                    //
//  Project: Palette                                                 //
//  Copyright (c) 1998 by Jeff Cottingham                            //
///////////////////////////////////////////////////////////////////////


//---------------------------------------------------------------------------
#ifndef PaletteMainH
#define PaletteMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *ImageGrayscale;
        TLabel *Label1;
        TLabel *Label2;
        TImage *ImageOrig;
        TButton *btnLoad;
        TButton *btnGrayscale;
        TOpenDialog *OpenDialog1;
        TStatusBar *StatusBar1;
        void __fastcall btnLoadClick(TObject *Sender);
        void __fastcall btnGrayscaleClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ImageOrigMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
private:	// User declarations
        Graphics::TBitmap *pBitmap;

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
