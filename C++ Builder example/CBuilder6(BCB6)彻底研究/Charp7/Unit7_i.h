//---------------------------------------------------------------------------

#ifndef Unit7_iH
#define Unit7_iH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TDriveComboBox *DriveComboBox1;
        TFileListBox *FileListBox1;
        TDirectoryListBox *DirectoryListBox1;
        TFilterComboBox *FilterComboBox1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FileListBox1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
