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
// ��Memo1�]�������ݤ���

try {
   Memo1->Lines->LoadFromFile(Edit1->Text);
   // �����N��r�ɸ��JMemo1����
}
catch (...) {
   ShowMessage("�䤣���ɮסA�L�k�}��!!");
}

Button1->Caption="�M�䤤...";

count=0;  // �ŦX�Ӽ�
for(i=0; i<Memo1->Lines->Count; i++) {
   StrPCopy(p1, Memo1->Lines->Strings[i]);
   // ���X��r�ɪ��C�@��r��

   p3=&(p1[0]);
   while ((*p3)!='\0') {
      StrPCopy(p2, Edit2->Text);	// ���X���w���r��
      p4=&(p2[0]);
      if (strlen(p4)>strlen(p3)) break;
      flag=true;
      while ((*p4)!='\0' && (*p3)!='\0') {  // ����r��j��
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
   Label4->Caption="���"+IntToStr(count)+"�ӬۦP���r��I";
} else {
   Label4->Caption="��p�A�䤣�����ۦP���r��I";
}
Button1->Caption="�}�l�j�M";
}
//---------------------------------------------------------------------------
