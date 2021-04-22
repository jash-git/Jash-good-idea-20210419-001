//---------------------------------------------------------------------------
#ifndef BitmanipH
#define BitmanipH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TButton *btnLoad;
        TButton *btnSlideLeft;
        TButton *btnSlideRight;
        TButton *btnHShutter;
        TButton *btnVShutter;
        TButton *btnUnroll;
        void __fastcall btnLoadClick(TObject *Sender);
        void __fastcall btnSlideLeftClick(TObject *Sender);
        void __fastcall btnSlideRightClick(TObject *Sender);
        void __fastcall btnHShutterClick(TObject *Sender);
        void __fastcall btnVShutterClick(TObject *Sender);
        void __fastcall btnUnrollClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
        Graphics::TBitmap *pBitmap1; // First user loaded Bitmap
        Graphics::TBitmap *pBitmap2; // Second user loaded Bitmap
        Graphics::TBitmap *pBitmap3; // Work area Bitmap
        bool Image1Loaded;
        bool Image2Loaded;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
