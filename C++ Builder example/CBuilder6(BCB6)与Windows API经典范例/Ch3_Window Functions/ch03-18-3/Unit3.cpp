//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
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
void __fastcall TForm1::WMNotify(TMessage &Msg)
{
//转换信息内容
LPNMHDR nmh = (NMHDR *)Msg.LParam;
//若通过的信息是属于ToolBar的NM_CUSTOMDRAW信息
HWND HToolBar = ToolBar1->Handle;
if(nmh->code == NM_CUSTOMDRAW && nmh->hwndFrom == HToolBar)
  {
  //转换成NMTBCUSTOMDRAW结构
  LPNMTBCUSTOMDRAW lptbcd = (NMTBCUSTOMDRAW *)Msg.LParam;
  //并解析与改换此结构<背景绘制>成员
  switch (lptbcd->nmcd.dwDrawStage)
  {
  //取得ToolBar重绘信息
  case CDDS_PREPAINT:
      {
      //取得装置设备的handle
      HDC HToolBarDC = lptbcd->nmcd.hdc;
      //取得ToolBar范围
      RECT R;
      ::GetClientRect(HToolBar, &R);
      //拼贴Image1图像--自定义函数--见最后
      TileBmp(HToolBarDC,
              Image1->Picture->Bitmap->Width,
              Image1->Picture->Bitmap->Height,
              R,
              Image1->Picture->Bitmap->Canvas->Handle);
      //返回信息，通知窗口开始绘制
      Msg.Result = CDRF_DODEFAULT;
      return;
      }
  }
  }
//将其它信息依原方式处理
TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
//自定义函数--连续拼贴图像
void TForm1::TileBmp(HDC HDestDC, int w, int h,
                     RECT r, HDC HSourceDC)
{
for(int y = r.top; y < r.bottom; y = y + h)
   for(int x = r.left; x < r.right; x = x + w)
      ::BitBlt(HDestDC, x, y, w, h, HSourceDC, 0, 0, SRCCOPY);
}
//---------------------------------------------------------------------------


