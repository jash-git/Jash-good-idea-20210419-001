//---------------------------------------------------------------------------
//Ŀ�ģ�������Ҽ��ƶ���ť�ļ�������
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
{//Ĭ�ϻ�����������뱳����ɫ
Canvas->Pen->Width = 10;
Color = (TColor)RGB(200,255,200);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{//�������סָ������
::SetCapture(Handle);
//ȷ��������ʼ��
pLineHead.x = X; pLineHead.y = Y;
//ȷ����굥����������ʼ��������
bDrawing = true;
//��������״λ����������������
bFirstLine = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
if(bDrawing)
  {//��������λ�øı�ʱ����ת��ǰλ�������ۼ�
  Canvas->Pen->Mode = pmNot;
  if(!bFirstLine)//��һ���ƶ��󣬻�������
    {
    Canvas->MoveTo(pLineHead.x, pLineHead.y);
    Canvas->LineTo(pLineTail.x, pLineTail.y);
    }
  //ȡ������ƶ�ʱ��ʵʱ����
  pLineTail.x = X; pLineTail.y = Y;
  bFirstLine = false;
  //�ٻ����ƶ�ʱ����
  Canvas->MoveTo(pLineHead.x, pLineHead.y);
  Canvas->LineTo(pLineTail.x, pLineTail.y);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{//����갴���ſ�ʱ���ٻ������ͣסʱ����
bDrawing = false;
Canvas->MoveTo(pLineHead.x, pLineHead.y);
Canvas->LineTo(X, Y);
//�ͷű���׽���Ĵ��ڣ����ػ洰�ڣ�ɾ������������
::ReleaseCapture();
}
//---------------------------------------------------------------------------

