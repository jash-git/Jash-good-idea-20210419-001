//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//��winresrc.h & winuser.h �ж����ͼ����Դ----------------------------------
#define OBM_COMBO        32738 //С��������
#define OBM_REDUCED      32746 //����[������С]��ť
#define OBM_REDUCE       32749 //����[������С]��ť
#define OBM_CLOSE        32754 //MS95���ڷ���
#define OBM_BTNCORNERS   32758 //��ɫԲ��
#define OBM_CHECK        32760 //��ѡ����
#define OBM_SIZE         32766 //���ŷ���
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//Ԥ����Image1״̬
Image1->Align = alClient;
Image1->Center = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
unsigned int rs;
//�ж���Դͼ��Ĵ���
if(ComboBox1->Text == "OBM_COMBO -- С��������")
   rs = OBM_COMBO;
if(ComboBox1->Text == "OBM_REDUCED -- ����[������С]��ť")
   rs = OBM_REDUCED;
if(ComboBox1->Text == "OBM_REDUCE -- ����[������С]��ť")
   rs = OBM_REDUCE;
if(ComboBox1->Text == "OBM_CLOSE -- MS95���ڷ���")
   rs = OBM_CLOSE;
if(ComboBox1->Text == "OBM_BTNCORNERS -- ��ɫԲ��")
   rs = OBM_BTNCORNERS;
if(ComboBox1->Text == "OBM_CHECK -- ��ѡ����")
   rs = OBM_CHECK;
if(ComboBox1->Text == "OBM_SIZE -- ���ŷ���")
   rs = OBM_SIZE;

//��ϵͳ��ȡ��ָ����Դͼ��
Image1->Picture->Bitmap->Handle = ::LoadBitmap(NULL, MAKEINTRESOURCE(rs));
//����Image1��ʾ
Image1->Refresh();
}
//---------------------------------------------------------------------------


