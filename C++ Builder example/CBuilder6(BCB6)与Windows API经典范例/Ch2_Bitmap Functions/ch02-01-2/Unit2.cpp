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
//动态建立一新图像对象
image = new TImage(this);
image->Parent = Form1;
image->Align = alClient;
//建立一暂时图文件
Graphics::TBitmap *Bitmap=new Graphics::TBitmap;
//设置这暂时图文件属性
Bitmap->Width=Screen->Width;
Bitmap->Height=Screen->Height;
Bitmap->PixelFormat=pf16bit;
//取得桌面的DC handle
HDC NewDC=::GetWindowDC(0);
//将全屏幕复制到Bitmap上
::BitBlt(Bitmap->Canvas->Handle,0,0,
         Screen->Width,Screen->Height,
         NewDC,0,0,SRCCOPY);
//将Bitmap指派给image
image->Picture->Assign(Bitmap);
//释放DC
::ReleaseDC(Form1->Handle,NewDC);
//删除Bitmap
delete Bitmap;

//将Form1最大化、提到最前面、制止滚动条产生
WindowState = wsMaximized;
FormStyle = fsStayOnTop;
AutoScroll = false;

//去除Form1的标题栏
DWORD dwStyle = ::GetWindowLong(Handle, GWL_STYLE);
dwStyle &= ~WS_CAPTION;
::SetWindowLong(Handle, GWL_STYLE, dwStyle);
}
//---------------------------------------------------------------------------
//建立可移动的关闭窗口按钮
void __fastcall TForm1::FormShow(TObject *Sender)
{
//动态建立一有说明标题的黄色区块对象
box = new TGroupBox(this);
box->Parent = Form1;
box->Width = 170; box->Height = 50;
box->Left = (Width-box->Width)/2;
box->Top = (Height-box->Height)/2;
box->Caption = "按住黄色区域，即可移动";
box->Color = (TColor)RGB(255,255,200);
box->Font->Size = 10;
//设置可拖曳的事件
box->OnMouseDown = MoveBoxMouseDown;
box->OnMouseMove = MoveBoxMouseMove;
box->OnMouseUp = MoveBoxMouseUp;
//动态建立一<关闭>按钮对象
btn = new TButton(this);
btn->Parent = box;
btn->Width = 76; btn->Height = 26;
btn->Left =(box->Width-btn->Width)/2;
btn->Top = (box->Height-btn->Height)/2;
btn->Caption = "关闭";
btn->OnClick = AllBtnClick;//自定义OnClick事件
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MoveBoxMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//确认鼠标是按住box上
if(::DragDetect(box->Handle, Point(X, Y)))
  {//鼠标图标改为手状
  box->Cursor = crHandPoint;
  //限制鼠标在单击状态，才可移动box
  box->Tag = true; //运用闲置属性为bool运算
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
box->Cursor = crDefault;//鼠标恢复箭头图标
}
//---------------------------------------------------------------------------
//单击<关闭>按钮，则关闭本程序
void __fastcall TForm1::AllBtnClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
//程最后释放动态新建的对象内存
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete box, btn, image;
}
//---------------------------------------------------------------------------

