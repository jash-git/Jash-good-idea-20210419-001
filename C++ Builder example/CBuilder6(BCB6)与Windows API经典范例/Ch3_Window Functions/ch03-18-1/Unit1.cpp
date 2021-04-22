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
//��Image1ͼ��ָ�ɸ�bm��bmΪImage1������
bm = new Graphics::TBitmap;
bm->Width = Image1->Picture->Bitmap->Width;
bm->Height = Image1->Picture->Bitmap->Height;
bm->Assign(Image1->Picture->Bitmap);
Image1->Hide();
//�����������ԣ���Ϊbool����
Button1->Default = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
RECT r;
HDC hdc;
//������ť���л�bmͼ���ƴ�������
if(Button1->Default)
  {//��bmͼ��ƴ����ȫ��Ļ��Χ
  RECT r1 = {0,0,Screen->Width,Screen->Height};
  r =r1;
  hdc = ::GetDC(0);
  }
else//��bmͼ��ƴ����Form1��Χ
  {
  ::GetClientRect(Handle, &r);
  hdc = Canvas->Handle;
  }
//��һ��bmƴ����ָ����Χ��
for(int i=0; i<r.bottom; i += bm->Height)
  for(int j=0; j<r.right; j+= bm->Width )
    {
    ::BitBlt(hdc,j,i, bm->Width, bm->Height,
             bm->Canvas->Handle, 0, 0, SRCCOPY);
    }
}
//---------------------------------------------------------------------------
//�������ʱ��ɾ��bm--Image1������
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
delete bm;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//������ťʱ�����л�ƴ����Χ
Button1->Default = !Button1->Default;
//�ͳ�������Ϣ��������OnPaint�¼�
SNDMSG(Handle,WM_PAINT,0,0);
//�������ȫ��Ļʱ����������Ҳһ�����ǣ�ָ�����λ��
//������Ƶ�Form1�����Ͻ�ϵͳѡ��λ��
POINT p = { 5, -5};
p = ClientToScreen(p);
::SetCursorPos(p.x,p.y);
//���浥��������һ�Σ���Form1��ϵͳ�˵�
::mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 );
::mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
}
//---------------------------------------------------------------------------


