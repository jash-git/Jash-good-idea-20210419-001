//---------------------------------------------------------------------------
#ifndef Unit6_4H
#define Unit6_4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Shape1;
        TShape *Shape2;
        TShape *Shape3;
        THeaderControl *HeaderControl1;
        TStatusBar *StatusBar1;
        TProgressBar *ProgressBar1;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall HeaderControl1DrawSection(THeaderControl *HeaderControl,
	THeaderSection *Section, const TRect &Rect, bool Pressed);
        void __fastcall HeaderControl1SectionTrack(
      THeaderControl *HeaderControl, THeaderSection *Section,
      int Width, TSectionTrackState State);
        void __fastcall StatusBar1DrawPanel(TStatusBar *StatusBar,
	TStatusPanel *Panel, const TRect &Rect);
        
        
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
