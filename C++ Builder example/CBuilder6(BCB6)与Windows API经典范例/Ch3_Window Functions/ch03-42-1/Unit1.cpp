//---------------------------------------------------------------------------
//目的：程序启动时，在系统登录文件取得上次窗口关闭时范围尺寸的信息，并依之显示
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//在"登录编辑器"(Regedit.exe)的 HKEY_USERS\\.DEFAULT\\ 路径下--------------
const char RegistryKey[] = "Software\\MyCompany\\MyApp" ;
const char RegExtents[] = "Extents" ;
//---------------------------------------------------------------------------
//建构式中，在系统登录文件取得上次程序关闭时Form1范围尺寸的信息
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
WINDOWPLACEMENT wp;//窗口范围
//新建一登录组件
RegUser = new TRegistry;
//打开指定登录路径，若否，则建立一指定登录路径
RegUser->OpenKey( RegistryKey, true);
//建立一登录目录名称，并读取二进制数值，重建Form1范围与位置
if(RegUser->ValueExists(RegExtents))
  {//依登录数值，填入WINDOWPLACEMENT结构中
  RegUser->ReadBinaryData( RegExtents, &wp, sizeof(WINDOWPLACEMENT));
  //重建Form1范围与位置
  ::SetWindowPlacement( Handle, &wp);
  }
//完成取出登录数值后，删除此登录组件
delete RegUser;
}
//---------------------------------------------------------------------------
//解构式中，在系统登录文件登录Form1范围尺寸的信息
__fastcall TForm1::~TForm1()
{
WINDOWPLACEMENT wp;//声明WINDOWPLACEMENT结构
wp.length = sizeof(WINDOWPLACEMENT);//划出结构内存位置
//新建一登录组件
RegUser = new TRegistry ;
//打开指定登录路径，若否，则建立一指定登录路径
RegUser->OpenKey( RegistryKey, true);
//取得Form1范围与位置，填入结构中
::GetWindowPlacement( Handle, &wp);
//将结构数据以二进制数值，填入指定登录目录中
RegUser->WriteBinaryData( RegExtents, &wp, sizeof(WINDOWPLACEMENT));
//完成写入登录数值后，关闭并删除此登录组件
RegUser->CloseKey();
delete RegUser;
}
//---------------------------------------------------------------------------


