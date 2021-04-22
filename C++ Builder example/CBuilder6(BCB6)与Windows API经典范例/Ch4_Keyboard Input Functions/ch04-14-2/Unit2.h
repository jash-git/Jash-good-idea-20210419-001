//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *FileSub101;
    TMenuItem *FileSub102;
    TMenuItem *FileSub103;
    TMenuItem *FileSub104;
    TMenuItem *File2;
    TMenuItem *FileSub201;
    TMenuItem *FileSub202;
    TMenuItem *FileSub203;
    TMenuItem *FileSub204;
    TMenuItem *File3;
    TMenuItem *FileSub301;
    TMenuItem *FileSub302;
    TMenuItem *FileSub303;
    TToolBar *ToolBar1;
    TButton *Button1;
    TStaticText *StaticText1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall File1Click(TObject *Sender);
    void __fastcall FileSub104Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
