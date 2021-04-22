//---------------------------------------------------------------------------
#ifndef Unit4_4H
#define Unit4_4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TRichEdit *RichEdit1;
        TCoolBar *CoolBar1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *O1;
        TMenuItem *O2;
        TMenuItem *N2;
        TMenuItem *A1;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *P1;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *E1;
        TMenuItem *N9;
        TMenuItem *CCtrlC1;
        TMenuItem *PCtrlV1;
        TMenuItem *N10;
        TMenuItem *S1;
        TMenuItem *N12;
        TMenuItem *N13;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TPrinterSetupDialog *PrinterSetupDialog1;
        TFindDialog *FindDialog1;
        TPrintDialog *PrintDialog1;
        TImageList *ImageList1;
        TActionList *ActionList1;
        TAction *NewFile;
        TAction *OldFile;
        TAction *SaveFile;
        TAction *SaveAsFile;
        TAction *PrinterSetup;
        TAction *Print;
        TAction *Exit;
        TAction *Cut;
        TAction *Copy;
        TAction *Paste;
        TAction *Delete;
        TAction *Find;
        TAction *Next;
        void __fastcall FindDialog1Find(TObject *Sender);
        void __fastcall NewFileExecute(TObject *Sender);
        void __fastcall OldFileExecute(TObject *Sender);
        void __fastcall SaveFileExecute(TObject *Sender);
        void __fastcall SaveAsFileExecute(TObject *Sender);
        void __fastcall PrinterSetupExecute(TObject *Sender);
        void __fastcall PrintExecute(TObject *Sender);
        void __fastcall ExitExecute(TObject *Sender);
        void __fastcall CutExecute(TObject *Sender);
        void __fastcall CopyExecute(TObject *Sender);
        void __fastcall PasteExecute(TObject *Sender);
        void __fastcall DeleteExecute(TObject *Sender);
        void __fastcall FindExecute(TObject *Sender);
        void __fastcall NextExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
