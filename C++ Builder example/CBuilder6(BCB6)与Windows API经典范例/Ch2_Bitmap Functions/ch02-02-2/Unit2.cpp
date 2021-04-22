//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//�Զ����곣��---------------------------------------------------------------
const int crUser = 10;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//���Զ�����handle�����10��Form1ϵͳ�������
Screen->Cursors[crUser] =
     ImageCursor(Screen->Cursors[crArrow], Image1->Picture->Bitmap);
//���Զ�����ָ�ɸ�Form1ʹ��
Screen->Cursor = (TCursor)crUser;
}
//---------------------------------------------------------------------------
//
HCURSOR TForm1::ImageCursor(HCURSOR cur, Graphics::TBitmap *bmp)
{
//���ص��¹��handle
HCURSOR result;
ICONINFO src, dest;

//��ȡ��ָ�������Ϣʧ�ܣ�������
if(!::GetIconInfo(cur, &src)) return 0;
//��ԭ������Σ���Ϊȫ͸�����ü�ͷ��ʧ
src.hbmMask = NULL;

//ȡ��ϵͳ��곤��λͼ
int cursorWidth = ::GetSystemMetrics(SM_CXCURSOR);
int cursorHeight = ::GetSystemMetrics(SM_CYCURSOR);

//A.�ȴ�������ͼ�ļ�--��͸�����
int maskDataSize = (cursorWidth/8)*cursorHeight;
char *maskData = new char[maskDataSize];
//::ZeroMemory(maskData, maskDataSize);
//������(mask)ȫ��λ��������0
::FillMemory(maskData, maskDataSize, 0x00);
//User�ɽ� 0x00 ��Ϊ 0x55(01010101) �� 0xaa(10101010)����
//������������������һ����ͼ�ļ�������handle
HBITMAP destMask = ::CreateBitmap(cursorWidth,
                                  cursorHeight,
                                  1, 1,
                                  maskData);
//ɾ��λ����
delete[] maskData;

//B.�ٴ���һ�²�ɫͼ�ļ�������Ϊ����С��������Image1ͼ�ļ�
Graphics::TBitmap* colorData = new Graphics::TBitmap;
colorData->Width = cursorWidth;
colorData->Height = cursorHeight;
colorData->Canvas->Draw(0,0,bmp);
//���ڴ��д�����DC�������ڴ���ͼ�ļ�DC
HDC mem_dc = ::CreateCompatibleDC(colorData->Canvas->Handle);
//��Ϊ����ԭ�����ݵ�handle
HBITMAP old_bitmap;
//��ͼ�ļ�������Ӽ������仯
//��ϵͳ���Ϊ��ɫ���(���ڰ�˫ɫ)
if(src.hbmColor == 0)
   {
   //��ԭϵͳ������δ����ڴ�DC��������ԭͼ�ļ�����
   old_bitmap = ::SelectObject(mem_dc,src.hbmMask);                                               SelectObject(mem_dc, src.hbmMask);
   //���ڴ�HDC���ɫͼ�ļ�HDC���߸�λAND����
   ::BitBlt(colorData->Canvas->Handle,
            0,0,
            cursorWidth,cursorHeight,
            mem_dc,
            0,0,
            SRCAND);
   //���ڴ�HDC���ɫͼ�ļ�HDC���ߵ�λXOR����
   ::BitBlt(colorData->Canvas->Handle,
            0,0,
            cursorWidth,cursorHeight,
            mem_dc,
            0,cursorHeight,
            SRCINVERT);

   }
else //��ϵͳ���Ϊ��ɫ���
   {
   //ѡȡԭϵͳ������Σ�������ԭͼ�ļ�����
   old_bitmap = ::SelectObject(mem_dc, src.hbmMask);
   //���ڴ�HDC���ɫͼ�ļ�HDC����AND����
   ::BitBlt(colorData->Canvas->Handle,
            0,0,
            cursorWidth,cursorHeight,
            mem_dc,0,0,
            SRCAND);
   //��ѡȡԭϵͳ���ͼ�ļ�
   ::SelectObject(mem_dc, src.hbmColor);
   //���ڴ�HDC���ɫͼ�ļ�HDC����XOR����
   ::BitBlt(colorData->Canvas->Handle,
            0,0,
            cursorWidth,cursorHeight,
            mem_dc,0,0,
            SRCINVERT);
   }
//���ͼ�ļ�������㣬����ԭ��ԭ����
::SelectObject(mem_dc, old_bitmap);
//�ͷ��ڴ�DC
::DeleteDC(mem_dc);
//�ͷŶ���handle
::DeleteObject(src.hbmMask);
::DeleteObject(src.hbmColor);
//�����¹����Ϣ ICONINFO�ṹ
dest.fIcon = FALSE;//falseΪ���
dest.xHotspot = src.xHotspot;//ԭ����ȵ�λ��
dest.yHotspot = src.yHotspot;
dest.hbmMask = destMask;//����ͼ�ļ�handle
dest.hbmColor = colorData->Handle;//����ɫͼ�ļ�
//������һ�����¹��
result = ::CreateIconIndirect(&dest);
//�ͷŲ�ɫͼ�ļ�
delete colorData;
//�ͷ�ѡȡ֮����
::DeleteObject(destMask);
//�����¹��
return result;
}
//---------------------------------------------------------------------------
//�¹�깦�ܲ���
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Color = (TColor)RGB(200,255,200);
}
//---------------------------------------------------------------------------

