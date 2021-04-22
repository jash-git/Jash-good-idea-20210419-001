//---------------------------------------------------------------------------
#ifndef Unit3_7H
#define Unit3_7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <FileCtrl.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TFileListBox *FileListBox1;
        TDirectoryListBox *DirectoryListBox1;
        TDriveComboBox *DriveComboBox1;
        TFilterComboBox *FilterComboBox1;
        void __fastcall Image1DragDrop(TObject *Sender, TObject *Source,
      int X, int Y);
        void __fastcall Image1DragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
