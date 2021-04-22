//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//��׼��hook�г̺���---------------------------------------------------------
UINT APIENTRY PageSetupHook(HWND, UINT, WPARAM, LPARAM);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//<���ô�ӡ��ʽ>�Ի���ṹ�����ŧi
PAGESETUPDLG psd;
::ZeroMemory(&psd, sizeof(PAGESETUPDLG));
//���ýṹ��Ա
psd.lStructSize = sizeof(PAGESETUPDLG);
psd.hwndOwner = Handle;
//ʹ��ӡ��ʽhook������Ч
psd.Flags = PSD_ENABLEPAGESETUPHOOK;
//ָ���Զ����hook�����������Զ��幦�ܯ�
psd.lpfnPageSetupHook = PageSetupHook;
//����һ��<���ô�ӡ��ʽ>�Ի���
if(::PageSetupDlg(&psd))
  {
  HANDLE HMem;
  char device[MAX_PATH], driver[MAX_PATH], port[MAX_PATH];
  //user��ֱ�Ӵ�ӡ
  Printer()->PrinterIndex = -1;
  Printer()->GetPrinter(device, driver, port, (int)HMem);
  Printer()->SetPrinter(device, driver, port, (int)psd.hDevMode);
  //�˴�����׫д��ӡ���в���֮�������....
  //Printer()->BeginDoc();
  //Printer()->Canvas->Rectangle(20,20,1000,1000);
  //Printer()->EndDoc();
  //�ͷ�ȫ�����ڴ�
  ::GlobalFree(HMem);
  ::GlobalFree(psd.hDevNames);
  }
}
//---------------------------------------------------------------------------
//������һ��<���ô�ӡ��ʽ>�Ի���ʱ������׽�Ի����ʼ����Ϣ
UINT APIENTRY PageSetupHook(HWND HDlg, UINT uiMsg, WPARAM WParam,
    LPARAM LParam)
{
if(uiMsg == WM_INITDIALOG)
  {
  RECT FormRect, DialogRect;
  //ȡ����Ϣת���ɶԻ���ṹ
  LPPAGESETUPDLG lppsd = (LPPAGESETUPDLG)LParam;
  //ȡ��Form1��Ի���ķ�Χ
  ::GetWindowRect(lppsd->hwndOwner, &FormRect);
  ::GetWindowRect(HDlg, &DialogRect);
  //����Form1��Ի���ĳ���
  int cxForm = FormRect.right - FormRect.left;
  int cyForm = FormRect.bottom - FormRect.top;
  int cxDialog = DialogRect.right - DialogRect.left;
  int cyDialog = DialogRect.bottom - DialogRect.top;
  //���Ի�����ƶ���Form1���г���
  ::MoveWindow(HDlg,
           (cxForm - cxDialog) / 2 + FormRect.left,
           (cyForm - cyDialog) / 2 + FormRect.top,
           cxDialog, cyDialog,
           true);
  }
return 0;
}
//---------------------------------------------------------------------------

