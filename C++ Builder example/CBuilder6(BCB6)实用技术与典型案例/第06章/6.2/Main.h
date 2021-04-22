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
    AnsiString  m_LastFileName;  // ��һ������ʱ�򿪵��ļ���
private:
    void SavePosInfo(void);//���洰�ڵ�λ�úʹ�С��Ϣ
    void InitialStatus(void);	// ���ó�ʼ����Ϣ��
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
