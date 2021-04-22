//---------------------------------------------------------------------------

#ifndef RecevieFormH
#define RecevieFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TPOP3Form : public TForm
{
__published:	// IDE-managed Components
    TMemo *MemoContent;
    TLabel *Label1;
    TLabel *Label2;
    TGroupBox *GroupBox1;
    TLabel *Label3;
    TEdit *EdtMailCount;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TEdit *EdtMailName;
    TEdit *EdtSubject;
    TEdit *EdtFrom;
    TEdit *EdtSize;
    TLabel *Label8;
    TEdit *EdtMailID;
    TListBox *ListBoxMail;
    TLabel *Label9;
    TLabel *Label10;
    TMemo *MemoHead;
    TLabel *Label11;
    TMemo *MemoAttach;
    void __fastcall ListBoxMailClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TPOP3Form(TComponent* Owner);
    void SetMailCount(int Count);
    void ListMail(int Msg, int Size);
};
//---------------------------------------------------------------------------
extern PACKAGE TPOP3Form *POP3Form;
//---------------------------------------------------------------------------
#endif
