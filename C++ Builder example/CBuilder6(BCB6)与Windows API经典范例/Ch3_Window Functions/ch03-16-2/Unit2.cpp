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
{
//���˳�����Ϊ�������ϲ�
FormStyle = fsStayOnTop;
//����ʼʱ������<��ݹ�����>
HWND hTaskbarWnd;
hTaskbarWnd = ::FindWindow("Shell_TrayWnd", NULL);
::ShowWindow(hTaskbarWnd, SW_HIDE);
//��������������������2��GetWindow
HWND hwnd;
hwnd = ::FindWindow("ProgMan",NULL);
hwnd = ::GetWindow(hwnd, GW_CHILD);
hwnd = ::GetWindow(hwnd, GW_CHILD);
::ShowWindow(hwnd, SW_HIDE);
//�������л���(Alt+Tab��ϼ�)ʧЧ
::SystemParametersInfo(SPI_SCREENSAVERRUNNING, true, &OldValue, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//��������������������2��GetWindow
HWND hwnd;
hwnd = ::FindWindow("ProgMan",NULL);
hwnd = ::GetWindow(hwnd, GW_CHILD);
hwnd = ::GetWindow(hwnd, GW_CHILD);
::ShowWindow(hwnd, SW_SHOW);

//����ر�ʱ������<��ݹ�����>
HWND hTaskbarWnd;
hTaskbarWnd = ::FindWindow("Shell_TrayWnd", NULL);
::ShowWindow(hTaskbarWnd, SW_SHOW);

//�������л���(Alt+Tab��ϼ�) ʹ֮��Ч
::SystemParametersInfo(SPI_SCREENSAVERRUNNING, false, &OldValue, 0);
}
//---------------------------------------------------------------------------
//ʹ�˶Ի����ޱ���
void __fastcall TForm1::CreateParams(TCreateParams &Params)
{
TForm::CreateParams(Params); //����Form1�Ļ�����̬����
Params.Style &= ~WS_CAPTION; //������λ��ɾ��
}
// -------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if(Edit1->Text != "1234")
  {
  Application->MessageBox("���벻��ร�","",MB_OK);
  Edit1->SetFocus();
  }
else
  {
  Application->MessageBox("������ȷ��","",MB_OK);
  Form1->Close();//����Form1��OnDestroy�¼�
  }
}
//---------------------------------------------------------------------------
//�ü��̵���Enter������ͬ����Button1��ť
void __fastcall TForm1::Edit1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key == VK_RETURN	)
   Button1Click(Sender);
}
//---------------------------------------------------------------------------


