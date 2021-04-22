//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu;
    TMenuItem *MenuFile;
    TMenuItem *MenuExit;
    TMemo *Memo1;
    TOpenDialog *OpenDialog;
    TMenuItem *MenuOpen;
    TMenuItem *MenuSave;
    TSaveDialog *SaveDialog;
    void __fastcall MenuOpenClick(TObject *Sender);
    void __fastcall MenuSaveClick(TObject *Sender);
    void __fastcall MenuExitClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:
    AnsiString  m_LastFileName;  // 上一次运行时打开的文件名
private:
    void SavePosInfo(void);//保存窗口的位置和大小信息
    void InitialStatus(void);	// 设置初始化信息。
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
