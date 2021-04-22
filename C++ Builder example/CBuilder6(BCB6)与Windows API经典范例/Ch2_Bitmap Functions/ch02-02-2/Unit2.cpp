//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//自定义光标常数---------------------------------------------------------------
const int crUser = 10;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//将自定义光标handle填入第10个Form1系统光标数组
Screen->Cursors[crUser] =
     ImageCursor(Screen->Cursors[crArrow], Image1->Picture->Bitmap);
//将自定义光标指派给Form1使用
Screen->Cursor = (TCursor)crUser;
}
//---------------------------------------------------------------------------
//
HCURSOR TForm1::ImageCursor(HCURSOR cur, Graphics::TBitmap *bmp)
{
//返回的新光标handle
HCURSOR result;
ICONINFO src, dest;

//若取回指定光标信息失败，则跳离
if(!::GetIconInfo(cur, &src)) return 0;
//将原光标屏蔽，设为全透明，让箭头消失
src.hbmMask = NULL;

//取得系统光标长宽位图
int cursorWidth = ::GetSystemMetrics(SM_CXCURSOR);
int cursorHeight = ::GetSystemMetrics(SM_CYCURSOR);

//A.先创建屏蔽图文件--不透明光标
int maskDataSize = (cursorWidth/8)*cursorHeight;
char *maskData = new char[maskDataSize];
//::ZeroMemory(maskData, maskDataSize);
//将屏蔽(mask)全部位，皆填上0
::FillMemory(maskData, maskDataSize, 0x00);
//User可将 0x00 改为 0x55(01010101) 或 0xaa(10101010)测试
//依照以上条件，创建一屏蔽图文件并返回handle
HBITMAP destMask = ::CreateBitmap(cursorWidth,
                                  cursorHeight,
                                  1, 1,
                                  maskData);
//删除位数组
delete[] maskData;

//B.再创建一新彩色图文件，长宽为光标大小，并复制Image1图文件
Graphics::TBitmap* colorData = new Graphics::TBitmap;
colorData->Width = cursorWidth;
colorData->Height = cursorHeight;
colorData->Canvas->Draw(0,0,bmp);
//在内存中创建新DC，兼容于此新图文件DC
HDC mem_dc = ::CreateCompatibleDC(colorData->Canvas->Handle);
//此为保存原有数据的handle
HBITMAP old_bitmap;
//将图文件数据相加及其他变化
//若系统光标为单色光标(即黑白双色)
if(src.hbmColor == 0)
   {
   //将原系统光标屏蔽传入内存DC，并返回原图文件数据
   old_bitmap = ::SelectObject(mem_dc,src.hbmMask);                                               SelectObject(mem_dc, src.hbmMask);
   //将内存HDC与彩色图文件HDC两者高位AND运算
   ::BitBlt(colorData->Canvas->Handle,
            0,0,
            cursorWidth,cursorHeight,
            mem_dc,
            0,0,
            SRCAND);
   //将内存HDC与彩色图文件HDC两者低位XOR运算
   ::BitBlt(colorData->Canvas->Handle,
            0,0,
            cursorWidth,cursorHeight,
            mem_dc,
            0,cursorHeight,
            SRCINVERT);

   }
else //若系统光标为彩色光标
   {
   //选取原系统光标屏蔽，并返回原图文件数据
   old_bitmap = ::SelectObject(mem_dc, src.hbmMask);
   //将内存HDC与彩色图文件HDC两者AND运算
   ::BitBlt(colorData->Canvas->Handle,
            0,0,
            cursorWidth,cursorHeight,
            mem_dc,0,0,
            SRCAND);
   //再选取原系统光标图文件
   ::SelectObject(mem_dc, src.hbmColor);
   //将内存HDC与彩色图文件HDC两者XOR运算
   ::BitBlt(colorData->Canvas->Handle,
            0,0,
            cursorWidth,cursorHeight,
            mem_dc,0,0,
            SRCINVERT);
   }
//完成图文件相加运算，即还原成原设置
::SelectObject(mem_dc, old_bitmap);
//释放内存DC
::DeleteDC(mem_dc);
//释放对象handle
::DeleteObject(src.hbmMask);
::DeleteObject(src.hbmColor);
//设置新光标信息 ICONINFO结构
dest.fIcon = FALSE;//false为光标
dest.xHotspot = src.xHotspot;//原光标热点位置
dest.yHotspot = src.yHotspot;
dest.hbmMask = destMask;//屏蔽图文件handle
dest.hbmColor = colorData->Handle;//光标彩色图文件
//即设置一完整新光标
result = ::CreateIconIndirect(&dest);
//释放彩色图文件
delete colorData;
//释放选取之对象
::DeleteObject(destMask);
//返回新光标
return result;
}
//---------------------------------------------------------------------------
//新光标功能测试
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Color = (TColor)RGB(200,255,200);
}
//---------------------------------------------------------------------------

