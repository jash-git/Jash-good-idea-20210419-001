//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TStaticText *StaticText1;
    TDirectoryListBox *DirectoryListBox1;
    TDriveComboBox *DriveComboBox1;
    TFileListBox *FileListBox1;
    TEdit *FileEdit;
    TFilterComboBox *FilterComboBox1;
    TDirectoryListBox *DirectoryListBox2;
    TFileListBox *FileListBox2;
    TEdit *Edit1;
    TFilterComboBox *FilterComboBox2;
    TDriveComboBox *DriveComboBox2;
    void __fastcall Button1Click(TObject *Sender);
    
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
