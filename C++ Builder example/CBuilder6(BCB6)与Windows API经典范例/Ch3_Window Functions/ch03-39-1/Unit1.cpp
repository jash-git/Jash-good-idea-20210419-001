//---------------------------------------------------------------------------
//����Ŀ�ģ�����һ״̬��Сͼ��(TrayIcon)������ִ��POP�˵�����
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//���ɹ�����һ��TrayIconʱ��ʶ��ID-------------------------------------------
const int WM_TRAYID = WM_USER + 100;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//-----------------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
//�½�һ��ͼʾ��������ȡImageList1�е�ͼ��
TrayIcon = new Graphics::TIcon;
//�Զ��庯��--��һ�μ�Ϊ��ݼ��Զ����TrayIcon
AddorChangeIcon(0);
//����ݹ������ϵ�ĸ����Project1����
::ShowWindow(Application->Handle, SW_HIDE);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{//�Ե����ִ��TrayIcon�ṹ����
NOTIFYICONDATA tray;
tray.cbSize = sizeof(tray);
tray.uID =  WM_TRAYID;//�Զ���ID
tray.hWnd = Handle;
tray.hIcon = TrayIcon->Handle;
//���˽ṹ��������ɾ����TrayIcon
::Shell_NotifyIcon(NIM_DELETE, &tray);
delete TrayIcon;//ɾ������ʼʱ�½���ͼ�����
ShowMessage("�رձ�TrayIcon������ԣ�");
}
//---------------------------------------------------------------------------
//�½�������Զ����TrayIcon
void __fastcall TForm1::AddorChangeIcon(int iconNum)
{
//�ڳ������ǰ�����˲������������������ı���λ�ù̶�ס��
static bool AlreadyAdded = false;
static int IconAdded = -1;
//��һ�����ñ�����֮�󣬼��ų���ͬ�������ظ�ִ��
if (IconAdded == iconNum) return;
//����������TrayIcon�ṹ
NOTIFYICONDATA newIcon;
newIcon.cbSize = sizeof(newIcon);
newIcon.uID =  WM_TRAYID;//�Զ���ʶ��ID
newIcon.hWnd = Handle;
//�Զ����TrayIcon��callback��Ϣ
newIcon.uCallbackMessage = WM_TRAYICON;
//���ַ���������"��ʾ"��
lstrcpy(newIcon.szTip, "�Զ���TRAY_ICON����");
//���ô�ImageList1��ȡ����ͼʾ
ImageList1->GetIcon(iconNum, TrayIcon);
newIcon.hIcon = TrayIcon->Handle;
//�������½����޸�TrayIcon
DWORD dwMessage;
(AlreadyAdded)?(dwMessage = NIM_MODIFY):(dwMessage = NIM_ADD);
//���ñ�־--�����ͳ��Զ�����Ϣ���Զ���ͼ�ꡢ�Զ�����ʾ
newIcon.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
//����һ�½����޸�����TrayIcon
::Shell_NotifyIcon(dwMessage, &newIcon);
//������һ�����½�TrayIcon���Ժ��Ǹ����޸�
//��2ֵ�����ұ���̶���ַ���Թ��´�ִ�б�����ʹ��
AlreadyAdded = true;
IconAdded = iconNum;
}
//------------------------------------------------------------------------------------
void __fastcall TForm1::WmNewTray(TMessage &Msg)
{//רΪ��׽TrayIcon�Զ�����Ϣ
if(Msg.Msg == WM_TRAYICON)
 {
 switch(Msg.LParam)
  {//�����˫����TrayIconʱ�����л���ʾ������Form1����
  case WM_LBUTTONDBLCLK:
        {
        ::ShowWindow(Handle,::IsWindowVisible(Handle)?SW_HIDE:SW_SHOW);
        break;
        }
  case WM_RBUTTONUP://��������Ҽ����TrayIcon�������POP�˵�
        {
        POINT p;
        ::GetCursorPos(&p);//ȡ����Ļ����
        ::SetForegroundWindow(Handle);//��Form1������ǰ�汸��
        PopupMenu1->Popup(p.x, p.y);//��ʾPOP�˵�
        PostMessage(Handle, WM_NULL, 0,0);//ɾ��δ֪��Ϣ
        break;
        }
  }
 }
//����������Ϣ��Ĭ�ϴ���
TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
//���¶��ǵ���POP�˵�ʱ��Ӧִ�еĹ��ܣ���user�����޸�
void __fastcall TForm1::pop011Click(TObject *Sender)
{//�Զ��庯��--�޸��Զ����TrayIconͼʾ
AddorChangeIcon(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pop021Click(TObject *Sender)
{//�Զ��庯��--�޸��Զ����TrayIconͼʾ
AddorChangeIcon(2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pop031Click(TObject *Sender)
{//�رձ�����
Close();
}
//---------------------------------------------------------------------------

