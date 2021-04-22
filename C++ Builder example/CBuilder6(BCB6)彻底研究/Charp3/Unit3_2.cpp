//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3_2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
int i,count;
char p1[255],p2[255],*p3,*p4;
bool flag;

Memo1->Visible=false;
// 把Memo1設成執行後看不到

try {
   Memo1->Lines->LoadFromFile(Edit1->Text);
   // 直接將文字檔載入Memo1物件
}
catch (...) {
   ShowMessage("找不到檔案，無法開啟!!");
}

Button1->Caption="尋找中...";

count=0;  // 符合個數
for(i=0; i<Memo1->Lines->Count; i++) {
   StrPCopy(p1, Memo1->Lines->Strings[i]);
   // 取出文字檔的每一行字串

   p3=&(p1[0]);
   while ((*p3)!='\0') {
      StrPCopy(p2, Edit2->Text);	// 取出指定的字串
      p4=&(p2[0]);
      if (strlen(p4)>strlen(p3)) break;
      flag=true;
      while ((*p4)!='\0' && (*p3)!='\0') {  // 比較字串迴圈
         if(*p4!=*p3) {
            flag=false;
            p3++;
            break;
         }
	     p4++;
         p3++;
      }
      if (flag==true) count++;
   }
}
if (count) {
   Label4->Caption="找到"+IntToStr(count)+"個相同的字串！";
} else {
   Label4->Caption="抱歉，找不到任何相同的字串！";
}
Button1->Caption="開始搜尋";
}
//---------------------------------------------------------------------------
