//---------------------------------------------------------------------------
//Ŀ�ģ�����ƶ��µ�MaskEdit����ȡ�ý��㣬����겻��MaskEdit��Χ�У�
//�������MaskEdit�����ͷŽ��㣬ʹ����һMaskEdit���޽���
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//������TListBox���������ͬ�¼�
for(int i=0; i < ComponentCount; i++)
   if(Components[i]->ClassNameIs("TMaskEdit"))
      {
      TMaskEdit *MaskEdit = (TMaskEdit *)Components[i];
      MaskEdit->OnMouseMove = AllMouseMove;
      }
}
//---------------------------------------------------------------------------
//MaskEdit��ͨ��OnMouseMove�¼�
void __fastcall TForm1::AllMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{//����Ϣת����TMaskEdit���
TMaskEdit *MaskEdit = dynamic_cast<TMaskEdit *>(Sender);
if(MaskEdit)
  {//������ƶ��µ�MaskEdit��ȡ�ý���Ķ���ͬ���A
  if(::GetCapture() != MaskEdit->Handle)
    {//��������ƶ��µ�MaskEditȡ�ý���
    ::SetCapture(MaskEdit->Handle);
    ActiveControl = MaskEdit;
    }

  RECT R = static_cast<RECT>(MaskEdit->ClientRect);
  POINT P = Point(X, Y);
  //����겻��MaskEdit��Χ�У�������ڶ����ͷŽ��㣬
  //ʹ����һMaskEdit���޽���
  if(!::PtInRect(&R, P))
    {
    ::ReleaseCapture();
    ::SetFocus(NULL);
    }
  }
}
//---------------------------------------------------------------------------
