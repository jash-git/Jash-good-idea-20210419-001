//---------------------------------------------------------------------------
#ifndef Unit7_2H
#define Unit7_2H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TPanel *Panel2;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TComboBox *ComboBox1;
    TGroupBox *GroupBox1;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TGroupBox *GroupBox2;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TProgressBar *ProgressBar1;
    TTimer *Timer1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    void __fastcall TForm1::GetSpecifyDiskInfor(char *DriverName);
    void __fastcall TForm1::GetFullDriveInfor(char *DriverName);
};
//---------------------------------------------------------------------------
extern TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
