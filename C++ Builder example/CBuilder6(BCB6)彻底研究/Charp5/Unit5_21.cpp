//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5_21.h"
#include "Unit5_12.h"
#include "Unit5_13.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
    // �ʺA�إߤl���� Form2
    Form2 = new TForm2(Application);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
    // �ʺA�إߤl���� Form3
    Form3 = new TForm3(Application);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
    // ���|���
    Cascade();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender)
{
    // �D���|���
    Tile();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{
    // �ƦC�ϥ�
    ArrangeIcons();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N9Click(TObject *Sender)
{
    int i;

    // �����̤p��
    for (i=MDIChildCount-1; i >= 0; i--)
        MDIChildren[i]->WindowState = wsMinimized;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::N10Click(TObject *Sender)
{
    int i;

    // �����Ҧ��l����
    for (i=MDIChildCount-1; i >= 0; i--)
        MDIChildren[i]->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
    // �����D����
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    WindowState=wsMaximized;
    WindowMenu=N5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N11Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

