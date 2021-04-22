//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//见winresrc.h & winuser.h 中定义的图像资源----------------------------------
#define OBM_COMBO        32738 //小倒三角形
#define OBM_REDUCED      32746 //单击[缩到最小]按钮
#define OBM_REDUCE       32749 //弹起[缩到最小]按钮
#define OBM_CLOSE        32754 //MS95窗口符号
#define OBM_BTNCORNERS   32758 //黑色圆点
#define OBM_CHECK        32760 //勾选符号
#define OBM_SIZE         32766 //缩放符号
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//预备好Image1状态
Image1->Align = alClient;
Image1->Center = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
unsigned int rs;
//判断资源图像的代码
if(ComboBox1->Text == "OBM_COMBO -- 小倒三角形")
   rs = OBM_COMBO;
if(ComboBox1->Text == "OBM_REDUCED -- 单击[缩到最小]按钮")
   rs = OBM_REDUCED;
if(ComboBox1->Text == "OBM_REDUCE -- 弹起[缩到最小]按钮")
   rs = OBM_REDUCE;
if(ComboBox1->Text == "OBM_CLOSE -- MS95窗口符号")
   rs = OBM_CLOSE;
if(ComboBox1->Text == "OBM_BTNCORNERS -- 黑色圆点")
   rs = OBM_BTNCORNERS;
if(ComboBox1->Text == "OBM_CHECK -- 勾选符号")
   rs = OBM_CHECK;
if(ComboBox1->Text == "OBM_SIZE -- 缩放符号")
   rs = OBM_SIZE;

//从系统中取得指定资源图像
Image1->Picture->Bitmap->Handle = ::LoadBitmap(NULL, MAKEINTRESOURCE(rs));
//更新Image1显示
Image1->Refresh();
}
//---------------------------------------------------------------------------


