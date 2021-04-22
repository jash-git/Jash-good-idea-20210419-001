//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <FileCtrl.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TDirectoryListBox *DirectoryListBox1;
    TDriveComboBox *DriveComboBox1;
    TFileListBox *FileListBox1;
    TFilterComboBox *FilterComboBox1;
    TToolBar *ToolBar1;
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);
    
private:	// User declarations
    AnsiString filename;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
