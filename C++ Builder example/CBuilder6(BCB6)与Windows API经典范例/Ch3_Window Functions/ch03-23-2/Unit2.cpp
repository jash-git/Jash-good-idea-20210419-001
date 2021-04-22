//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//<�򿪾��ļ�>�Ի������Ϣ������ṹ����---------------------------------------
UINT APIENTRY OFNHookProc(HWND, UINT, WPARAM, LPARAM);
bool ShowOpenDialog(HWND, char *FileName, char *Title,
                    char *InitialDir, char *Filter);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//��<��>�Ի���
void __fastcall TForm1::Button1Click(TObject *Sender)
{
char FileName[MAX_PATH];
if (ShowOpenDialog(Handle,
                   FileName,
                   "��׼API���򿪡��Ի���",
                   "C:\\Program Files",
                   "Text Files (*.txt)\0*.txt\0"
                   "Zip Files (*.zip)\0*.zip\0"
                   "All Files (*.*)\0*.*\0"))
    {
    ::MessageBox(Handle, FileName, "ѡ���ļ��ǣ�", MB_OK);
    }
}
//<�򿪾��ļ�>�Ի������Ϣ����-------------------------------------------------
UINT APIENTRY OFNHookProc(HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
//
HWND HOpenDialogBox = ::GetParent(hdlg);
//��<��>�Ի���ȡ�ó�ʼ����Ϣʱ���ɡA
//���ͳ��ı��ض������������
if (uiMsg == WM_INITDIALOG)
    {
    SNDMSG(HOpenDialogBox, CDM_SETCONTROLTEXT,
           IDOK, (LPARAM)"SUBMIT!");
    }
return 0L;
}
//<�򿪾��ļ�>�Ի���Ľṹ���ú���---------------------------------------------
bool ShowOpenDialog(HWND HWndOwner, char *FileName, char *Title,
    char *InitialDir, char *Filter)
{
//����OPENFILENAME�ṹ
OPENFILENAME ofn;
//������ṹλ������
ZeroMemory(&ofn, sizeof(OPENFILENAME));
char szFile[MAX_PATH];
ZeroMemory(szFile, MAX_PATH);
//��ʼ����OPENFILENAME�ṹ��Ա��
ofn.lStructSize = sizeof(OPENFILENAME);
ofn.hwndOwner = HWndOwner;
ofn.lpstrFile = szFile;
ofn.nMaxFile = MAX_PATH;
ofn.lpstrFilter = Filter;
ofn.nFilterIndex = 0;
ofn.lpstrTitle = Title;
ofn.lpstrInitialDir = InitialDir;
//�˶Ի�������´��ڷ�񡢶���ѡȡ�ļ����Զ�����Ϣ����
ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_ENABLEHOOK;
//�Զ�����Ϣ����
ofn.lpfnHook = OFNHookProc;
//����ṹ��Ա��ָ�ɸ�"��"�Ի��򣬲���ʾ�Ի���
if (::GetOpenFileName(&ofn))
    {//����ѡȡ���ļ����򷵻��ļ���������ֵ
    strcpy(FileName, ofn.lpstrFile);
    return true;
    }
//���򷵻�αֵ   
return false;
}
//---------------------------------------------------------------------------

