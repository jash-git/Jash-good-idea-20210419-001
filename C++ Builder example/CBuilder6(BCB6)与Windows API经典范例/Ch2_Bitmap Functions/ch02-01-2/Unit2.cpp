//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//��̬����һ��ͼ�����
image = new TImage(this);
image->Parent = Form1;
image->Align = alClient;
//����һ��ʱͼ�ļ�
Graphics::TBitmap *Bitmap=new Graphics::TBitmap;
//��������ʱͼ�ļ�����
Bitmap->Width=Screen->Width;
Bitmap->Height=Screen->Height;
Bitmap->PixelFormat=pf16bit;
//ȡ�������DC handle
HDC NewDC=::GetWindowDC(0);
//��ȫ��Ļ���Ƶ�Bitmap��
::BitBlt(Bitmap->Canvas->Handle,0,0,
         Screen->Width,Screen->Height,
         NewDC,0,0,SRCCOPY);
//��Bitmapָ�ɸ�image
image->Picture->Assign(Bitmap);
//�ͷ�DC
::ReleaseDC(Form1->Handle,NewDC);
//ɾ��Bitmap
delete Bitmap;

//��Form1��󻯡��ᵽ��ǰ�桢��ֹ����������
WindowState = wsMaximized;
FormStyle = fsStayOnTop;
AutoScroll = false;

//ȥ��Form1�ı�����
DWORD dwStyle = ::GetWindowLong(Handle, GWL_STYLE);
dwStyle &= ~WS_CAPTION;
::SetWindowLong(Handle, GWL_STYLE, dwStyle);
}
//---------------------------------------------------------------------------
//�������ƶ��Ĺرմ��ڰ�ť
void __fastcall TForm1::FormShow(TObject *Sender)
{
//��̬����һ��˵������Ļ�ɫ�������
box = new TGroupBox(this);
box->Parent = Form1;
box->Width = 170; box->Height = 50;
box->Left = (Width-box->Width)/2;
box->Top = (Height-box->Height)/2;
box->Caption = "��ס��ɫ���򣬼����ƶ�";
box->Color = (TColor)RGB(255,255,200);
box->Font->Size = 10;
//���ÿ���ҷ���¼�
box->OnMouseDown = MoveBoxMouseDown;
box->OnMouseMove = MoveBoxMouseMove;
box->OnMouseUp = MoveBoxMouseUp;
//��̬����һ<�ر�>��ť����
btn = new TButton(this);
btn->Parent = box;
btn->Width = 76; btn->Height = 26;
btn->Left =(box->Width-btn->Width)/2;
btn->Top = (box->Height-btn->Height)/2;
btn->Caption = "�ر�";
btn->OnClick = AllBtnClick;//�Զ���OnClick�¼�
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MoveBoxMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//ȷ������ǰ�סbox��
if(::DragDetect(box->Handle, Point(X, Y)))
  {//���ͼ���Ϊ��״
  box->Cursor = crHandPoint;
  //��������ڵ���״̬���ſ��ƶ�box
  box->Tag = true; //������������Ϊbool����
  p = Point(X, Y);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MoveBoxMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
if(box->Tag)
  {
  box->Left = box->Left + (X - p.x);
  box->Top = box->Top + (Y - p.y);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MoveBoxMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
box->Tag = false;
box->Cursor = crDefault;//���ָ���ͷͼ��
}
//---------------------------------------------------------------------------
//����<�ر�>��ť����رձ�����
void __fastcall TForm1::AllBtnClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
//������ͷŶ�̬�½��Ķ����ڴ�
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete box, btn, image;
}
//---------------------------------------------------------------------------

