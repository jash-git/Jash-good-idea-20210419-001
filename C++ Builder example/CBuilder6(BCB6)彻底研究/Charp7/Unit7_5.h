//---------------------------------------------------------------------------
#ifndef Unit7_5H
#define Unit7_5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label3;
    TPanel *Panel1;
    TLabel *Label1;
    TFileListBox *FileListBox1;
    TDirectoryListBox *DirectoryListBox1;
    TDriveComboBox *DriveComboBox1;
    TEdit *Edit1;
    TPanel *Panel2;
    TLabel *Label2;
    TDirectoryListBox *DirectoryListBox2;
    TDriveComboBox *DriveComboBox2;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall DirectoryListBox2DragOver(TObject *Sender,
          TObject *Source, int X, int Y, TDragState State, bool &Accept);
    void __fastcall DirectoryListBox2DragDrop(TObject *Sender,
          TObject *Source, int X, int Y);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
