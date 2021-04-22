//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
const int ABE_FLOAT = -1;
const int WM_MYAPPBAR = WM_USER + 101;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//<1>������Form1���Ӷ���״̬
BorderStyle = bsSizeToolWin;//Form1����Ϊ����������ߴ�
//ȥ��Form1�ı�����
DWORD dwStyle = ::GetWindowLong(Handle, GWL_STYLE);
dwStyle &= ~WS_CAPTION;
::SetWindowLong(Handle, GWL_STYLE, dwStyle);
Caption = "�Զ���Ŀ�ݹ�����";
//����סʱ������������קForm1����Ļ��һ����
StaticText1->OnMouseDown = Form1->OnMouseDown;

//<2>��Form1�ĳ�һ���Զ���Ŀ�ݹ�����
//����APPBARDATA�ṹ���ͳ���Ϣ
abd.cbSize = sizeof(APPBARDATA);
abd.hWnd = Handle;
abd.uCallbackMessage = WM_MYAPPBAR;//�Զ�����Ϣ
abd.lParam = 0;
::SHAppBarMessage(ABM_NEW, &abd);//����ɿ�ݹ�����

//<3>�ȷ��������±��أ���Ӱ������������������
abd.uEdge = ABE_BOTTOM;//ά��SetAppBarPos��������һ����
//�Զ��庯��--�����Զ����ݹ�����λ��
SetAppBarPos(abd.uEdge, BoundsRect);
::SetWindowPos(Handle, HWND_TOPMOST, 0, Screen->Height-50,
               Screen->Width, 50, SWP_DRAWFRAME);
}
//---------------------------------------------------------------------------
//��סʱ������������ҷForm1����Ļ��һ����
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
::ReleaseCapture();
SNDMSG(Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{//�رճ���ʱ���Ƴ��Զ���Ŀ�ݹ�����
::SHAppBarMessage(ABM_REMOVE, &abd);
}
//---------------------------------------------------------------------------
//����ק����ʱ�����ɴ˺����ж����������λ�ã����Զ�������������
void __fastcall TForm1::SetAppBarPos(int flag, TRect R)
{
//�������ڸ���״̬�£�����ϱ�������ֹͣ�������ִ�ж����ئ^
  DWORD dwStyle = ::GetWindowLong(Handle, GWL_STYLE);
if(flag == ABE_FLOAT)
  {//�½�Form1�ı�����
  dwStyle |= WS_CAPTION;
  ::SetWindowLong(Handle, GWL_STYLE, dwStyle);
  return;
  }
else//ȥ��Form1�ı�����
  {
  dwStyle &= ~WS_CAPTION;
  ::SetWindowLong(Handle, GWL_STYLE, dwStyle);
  }
//�ȴ�����������־
int iHeight = 0, iWidth = 0;
abd.rc = R;
abd.uEdge = flag;
//������������Ļ�ұ��ػ������ʱ���򶨳��߶�����
if(flag == ABE_LEFT || flag == ABE_RIGHT)
  {
  iWidth = abd.rc.right - abd.rc.left;
  abd.rc.top = 0;
  abd.rc.bottom = ::GetSystemMetrics(SM_CYSCREEN);
  }
else//������������Ļ�ϱ��ػ��±���ʱ���򶨳��߶�����
  {
  iHeight = abd.rc.bottom - abd.rc.top;
  abd.rc.left = 0;
  abd.rc.right = ::GetSystemMetrics(SM_CXSCREEN);
  }
//�ͳ���Ϣ����ϵͳ�ٴ�ȷ��λ����ߴ�
::SHAppBarMessage(ABM_QUERYPOS, &abd);
//ȡ�ñ���״̬��ȷ��λ��
switch(flag)
  {
  case ABE_LEFT:
      abd.rc.right = abd.rc.left + iWidth; break;
  case ABE_RIGHT:
      abd.rc.left = abd.rc.right - iWidth; break;
  case ABE_TOP:
      abd.rc.bottom = abd.rc.top + iHeight; break;
  case ABE_BOTTOM:
      abd.rc.top = abd.rc.bottom - iHeight; break;
  }
//֪ͨϵͳ��ȷ�����λ�ü���Χ
::SHAppBarMessage(ABM_SETPOS, &abd);
//���ƶ���ȷ��λ����ߴ�
::MoveWindow(abd.hWnd, abd.rc.left, abd.rc.top,
             abd.rc.right - abd.rc.left,
             abd.rc.bottom - abd.rc.top, true);
}
//---------------------------------------------------------------------------
//����Form1��Ϣ��������׽���ڵĻ�����Ϣ���Զ�����Ϣ
void __fastcall TForm1::WndProc(TMessage &Msg)
{
switch(Msg.Msg)
  {//����׽���Զ�����Ϣ������һ�ֱ�ִ��
  case WM_MYAPPBAR:
    switch(Msg.LParam)
      {
      case ABN_FULLSCREENAPP:
           {
           if(Msg.WParam)
             ::SetWindowPos(Handle, HWND_BOTTOM, 0, 0, 0, 0,
                            SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
           else
             ::SetWindowPos(Handle, HWND_TOPMOST, 0, 0, 0, 0,
                            SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
           break;
           }
      case ABN_STATECHANGE: break;
      case ABN_POSCHANGED: break;
      }
  case WM_ACTIVATE://��Form1��ִ��ʱ��Ҳ�ͳ��¹��������ڿ�ִ��״̬
       ::SHAppBarMessage(ABM_ACTIVATE, &abd);
       TForm::Dispatch(&Msg);
       break;
  case WM_WINDOWPOSCHANGED://��Form1λ�øı�ʱ��Ҳ�ͳ��¹�����������ͬ��Ϣ��
       TForm::Dispatch(&Msg);
       ::SHAppBarMessage(ABM_WINDOWPOSCHANGED, &abd);
       break;
  //��Form1ֹͣ�ƶ��������Сʱ����ִ���Զ��庯��--�����Զ����ݹ�����λ��
  case WM_EXITSIZEMOVE:
       TForm::Dispatch(&Msg);
       SetAppBarPos(abd.uEdge, abd.rc);
       break;
  //��Form1�ƶ��У�ʵʱ�Y��
  case WM_MOVING: AppBarMoving(Msg); break;
  default: TForm::Dispatch(&Msg);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AppBarMoving(TMessage &Msg)
{//����Ϣȡ���¹��������ڵ�ʵʱ��̬��Χ
LPRECT DragRect = (RECT *)Msg.LParam;
//��RECT�ṹ�벼��ֵ����һ�̶���ַ
static RECT BackupRect = Rect(0, 0, 0, 0);
static bool boolFirstTime = true;
//�Ƚ綨�¹����д����������Ļ��λ���뷶Χ
RECT DesktopRect = Rect(0, 0, Screen->Width, Screen->Height);
RECT LeftRect = Rect(DesktopRect.left, DesktopRect.top,
                     DesktopRect.left + 50, DesktopRect.bottom);
RECT RightRect = Rect(DesktopRect.right - 50, DesktopRect.top,
                      DesktopRect.right, DesktopRect.bottom);
RECT TopRect = Rect(DesktopRect.left, DesktopRect.top,
                    DesktopRect.right, DesktopRect.top + 50);
RECT BottomRect = Rect(DesktopRect.left, DesktopRect.bottom - 50,
                       DesktopRect.right, DesktopRect.bottom);
//ȡ����Ļ�����λ��
POINT P;
::GetCursorPos(&P);
//���������λ�ã��ж��¹���������Ӧ���ںδ�����
if(::PtInRect(&LeftRect, P))//�������߷�Χ
  {
  if(boolFirstTime)
    {//ʵʱ�����ڷ�Χ���룬�Թ�����ҷ����״̬�е����λ��
    ::CopyRect(&BackupRect, DragRect);
    boolFirstTime = false;
    }
  *DragRect = LeftRect;
  abd.rc = LeftRect;
  abd.uEdge = ABE_LEFT;
  }
else if(::PtInRect(&TopRect, P))//������ϱ߷�Χ
  {
  if(boolFirstTime)
    {
    ::CopyRect(&BackupRect, DragRect);
    boolFirstTime = false;
    }
  *DragRect = TopRect;
  abd.rc = TopRect;
  abd.uEdge = ABE_TOP;
  }
else if(::PtInRect(&RightRect, P))//������ұ߷�Χ
  {
  if(boolFirstTime)
    {
    ::CopyRect(&BackupRect, DragRect);
    boolFirstTime = false;
    }
  *DragRect = RightRect;
  abd.rc = RightRect;
  abd.uEdge = ABE_RIGHT;
  }
else if(::PtInRect(&BottomRect, P))//����ڵױ߷�Χ
  {
  if(boolFirstTime)
    {
    ::CopyRect(&BackupRect, DragRect);
    boolFirstTime = false;
    }
  *DragRect = BottomRect;
  abd.rc = BottomRect;
  abd.uEdge = ABE_BOTTOM;
  }
else //������м䷶Χ�����ڸ���״̬
  {
  abd.uEdge = ABE_FLOAT;
  if(!::IsRectEmpty(&BackupRect) && boolFirstTime == false)
    {
    POINT P;
    ::GetCursorPos(&P);
    RECT TempRect = Rect(P.x, P.y,
                         P.x + BackupRect.right - BackupRect.left,
                         P.y + BackupRect.bottom - BackupRect.top);

    *DragRect = TempRect;
    boolFirstTime = true;
    }
  }
Msg.Result = true;
}
//---------------------------------------------------------------------------

