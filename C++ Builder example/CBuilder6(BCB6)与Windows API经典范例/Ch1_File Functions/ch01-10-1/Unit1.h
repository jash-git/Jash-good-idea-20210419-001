//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <FileCtrl.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TToolBar *ToolBar1;
    TButton *Button1;
    TPanel *Panel1;
    TDriveComboBox *DriveComboBox1;
    TDirectoryListBox *DirectoryListBox1;
private:	// User declarations
public:		// User declarations

    void __fastcall WMCommand(TMessage &Msg);

BEGIN_MESSAGE_MAP
VCL_MESSAGE_HANDLER(WM_COMMAND, TMessage, WMCommand)
END_MESSAGE_MAP(TForm)

    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
