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
{
//�Զ��庯��--����һListView���ڣ�������handle
HListView = CreateListView();
// ���ɹ�����һ��ListView���ڣ����ٽ����Զ������Գ���
if(HListView)
  {
  // ����һ�¶���״̬
  NewListViewWP = MakeObjectInstance(ListViewWndProc);
  // ������ListView�������ԣ�������ԭ�ж������ԣ����ڳ������ʱ���ظ�
  OldListViewWP = (TFarProc)::SetWindowLong(HListView, GWL_WNDPROC, (LONG)NewListViewWP);
  // ������ListView����Ŀ����
  LV_COLUMN lvc;
  lvc.mask = LVCF_WIDTH | LVCF_SUBITEM;
  lvc.cx = 100;
  lvc.iSubItem = 0;
  // �ͳ���Ϣ���ı�ListView����Ŀ����
  SendMessage(HListView, LVM_INSERTCOLUMN, 0, (LPARAM)&lvc);
  lvc.iSubItem = 1;
  SendMessage(HListView, LVM_INSERTCOLUMN, 1, (LPARAM)&lvc);
  }
}
//---------------------------------------------------------------------------
// ����ر�ʱ����ListView�ظ�ԭʼ����
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
::SetWindowLong(HListView, GWL_WNDPROC, (LONG)OldListViewWP);
FreeObjectInstance(NewListViewWP);
}
//---------------------------------------------------------------------------
// ����ListView���ڸ�����Ϣ�ĺ������������յĲ�ͬ��Ϣ��������ͬ��Ӧ
void __fastcall TForm1::ListViewWndProc(TMessage &Msg)
{
if(Msg.Msg == WM_NOTIFY)
   {
   LPNMHDR lpnmh = (NMHDR *)Msg.LParam;
    // ����Ϣ������Ҽ�����ListView��Ŀ��ʱ���������û�����
    if (lpnmh->code == NM_RCLICK)
        {
        Beep(10, 10);
        Msg.Result = true;
        return;
        }
    }
// ����ǰ��ָ����Ϣ��������ԭ����Ϣ��ʽ����
Msg.Result = CallWindowProc((FARPROC)OldListViewWP, HListView,
                             Msg.Msg, Msg.WParam, Msg.LParam);
}
//---------------------------------------------------------------------------
// ����һ��ListView����
HWND TForm1::CreateListView()
{
return CreateWindow(WC_LISTVIEW, "--�µĴ���--",
           WS_CAPTION | WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT,
           10, 10,
           (ClientWidth/3)*2, (ClientHeight/3)*2,
           Handle, NULL, HInstance, NULL);
}
//---------------------------------------------------------------------------

