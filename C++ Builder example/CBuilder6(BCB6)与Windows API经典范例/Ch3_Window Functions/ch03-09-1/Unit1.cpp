//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//Form1��handle
HWND hdle = Form1->Handle;
RECT rect = {150,150,400,400};
//<1>�����ڴ�λ�ø��������ڲ�����λ��handle
HDWP hbwinp = ::BeginDeferWindowPos( 1 );
//<2>�����ڴ�λ�ø��������ڲ�����λ��handle
HDWP hwinp = ::DeferWindowPos(hbwinp, hdle,
                              HWND_TOPMOST,
                              rect.left, rect.top,
                              rect.right, rect.bottom,
                              SWP_DRAWFRAME | SWP_NOSIZE
                              | SWP_NOACTIVATE
                              );
//<3>��һ�µ���Ļ����ѭ���У���С&λ�ö�ͬ���������
::EndDeferWindowPos(hwinp);
//<4>����΢����ĳ���λ�ã��������ô���
::SetWindowPos(hdle,
               HWND_TOP,
               rect.left, rect.top,
               rect.right-rect.left,
               rect.bottom-rect.top,
               SWP_SHOWWINDOW
               );
}
//---------------------------------------------------------------------------


