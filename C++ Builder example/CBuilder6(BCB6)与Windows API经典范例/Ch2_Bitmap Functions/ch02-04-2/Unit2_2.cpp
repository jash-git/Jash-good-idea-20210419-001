//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2_2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNewform *Newform;
//---------------------------------------------------------------------------
__fastcall TNewform::TNewform(TComponent* Owner)
    : TForm(Owner)
{
//��Form1���UButton1�ɡA
//�޵oNewform��l�ơA�i��U�C�ʧ@�G
//�h��Form2��u
Newform->BorderStyle = bsNone;
//�T��Form2�A��øForm2�I���A
//�ӥi�N�ୱ�v���d��Form2�I����
Newform->Brush->Style = bsClear;
//Form2��j�ܥ��ù�
Newform->SetBounds(0, 0, Screen->Width, Screen->Height);
//�G�i��User�{�����U���s�ɡA�ୱ�������즳�e�����A�A
//��ڤw�g�ܦ�Newform�I������
}
//---------------------------------------------------------------------------
//����&���]NewForm���T��
void __fastcall TNewform::WndProc(TMessage &Msg)
{
//�O���H�U��Ӱϰ��ܼƦs���m�A���H����T�����ܰ�
static bool Drawing = false;
static bool FirstRect = false;
//���o�ƹ��bNewform�W�즲�X�Ӫ���ذϰ�
switch (Msg.Msg)
    {
    case WM_LBUTTONDOWN:
        {
        //��ƹ��bNewform�W���U�ɡA
        //�T�wNewform�b�e������
        ::SetCapture(Handle);
        //��ت��e�Ҭ� 0
        R.left = R.right = LOWORD(Msg.LParam);
        R.top = R.bottom = HIWORD(Msg.LParam);
        FirstRect = true;
        Drawing = true;
        Msg.Result = 0;
        return;
        }
    case WM_MOUSEMOVE:
        {
        if (Drawing)
            {
            HDC Hdc = ::GetDC(Handle);
            //����ù��e���C��
            int OldR2Mode = ::SetROP2(Hdc, R2_NOT);
            //���W�L����(�z��)
            HBRUSH HOldBrush =
                ::SelectObject(Hdc, ::GetStockObject(NULL_BRUSH));
            //�Y�D�ج[�_�I�A�h�]���ؽd��
            if (!FirstRect)
                ::Rectangle(Hdc, R.left, R.top, R.right, R.bottom);
            //�A���o�ƹ����ʳ̫�T����J�ج[�k��&����
            R.right = LOWORD(Msg.LParam);
            R.bottom = HIWORD(Msg.LParam);
            ::Rectangle(Hdc, R.left, R.top, R.right, R.bottom);

            FirstRect = false;
            //�^�_�ù��e���C��
            ::SelectObject(Hdc, HOldBrush);
            ::SetROP2(Hdc, OldR2Mode);
            ::ReleaseDC(Handle, Hdc);
            }
        Msg.Result = 0;
        return;
        }
    case WM_LBUTTONUP:
        {
        //����ƹ����U�ɪ��������A
        ::ReleaseCapture();
        FirstRect = false;
        Drawing = false;
        Close();

        Msg.Result = 0;
        return;
        }
    }
    TForm::WndProc(Msg);
}
//---------------------------------------------------------------------------
//�NForm1�d��ƻs��NewForm���A�@���̾ڰѦ�
void __fastcall TNewform::GetRect(LPRECT lpRect)
{
::CopyRect(lpRect, &R);
}
//---------------------------------------------------------------------------
