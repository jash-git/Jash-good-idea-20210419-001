//---------------------------------------------------------------------------
//���ϡ�ж��Keyboard hook���������Զ�����Ϣ����Hook����
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKeyHookForm *KeyHookForm;
//---------------------------------------------------------------------------
__fastcall TKeyHookForm::TKeyHookForm(TComponent* Owner)
        : TForm(Owner)
{
inthook = 0;//���㰴��������������
//��KeyHookFormά���ڴ���������
FormStyle = fsStayOnTop;
//���Ϻ�ж��Hook�İ�ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//����Hook���������ö�ʱ���ӹ����ڴ���ȡ�ؼ�����Ϣ
void __fastcall TKeyHookForm::Button1Click(TObject *Sender)
{
//���㰴��������������
inthook = 0;
//��keydll.dll�У�SetHook����ִ��ע��Hook�г̵���Ϣ����
//��������һSetHook����
void (*SetHook)();
//����ͬһĿ¼�µ�ָ�������ļ�--keydll.dll
inst = ::LoadLibrary("keydll.dll");
//ȡ��dll��SetHook������ַ
(FARPROC &)SetHook = ::GetProcAddress(inst,"SetHook");
//ִ��ָ��dll�е�SetHook����
SetHook();
//���Ϻ�ж��Hook�İ�ť״̬
Button1->Enabled = false;
Button2->Enabled = true;
}
//---------------------------------------------------------------------------
//ж��Hook��������Զ����hook
void __fastcall TKeyHookForm::Button2Click(TObject *Sender)
{
//��keydll.dll�У�RemoveHook����ִ�д���Ϣ����ж��Hook����
//����RemoveHook����
void (*RemoveHook)();
//����ͬһĿ¼�µ�ָ�������ļ�--keydll.dll
inst = ::LoadLibrary("keydll.dll");
//ȡ��dll��RemoveHook������ַ
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//ִ��ָ��dll�е�RemoveHook����
RemoveHook();
//�ͷ�dll
::FreeLibrary(inst);
//���Ϻ�ж��Hook�İ�ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//Ԥ���û�����Hookʱδж��Hook��
void __fastcall TKeyHookForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//��keydll.dll�У�RemoveHook����ִ�д���Ϣ����ж��Hook�г�
//������RemoveHook����
void (*RemoveHook)();
//����dll
inst = ::LoadLibrary("keydll.dll");
//ȡ��dll��RemoveHook������ַ
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//ִ��ָ��dll�е�RemoveHook����
RemoveHook();
//�ͷ�dll
::FreeLibrary(inst);
}
//---------------------------------------------------------------------------
//ȡ�������Լ����е��Զ�����Ϣ
void __fastcall TKeyHookForm::KeyHook(TMessage &Msg)
{
//ȡ���Զ�����Ϣ�еİ�������
char keytext[80];
::GetKeyNameText(Msg.LParam, keytext, 80);
//��ȡ���Զ�����Ϣ�еİ���״̬(�����..���岻��...)
AnsiString keystate;
keystate = ::GetKeyState((int)Msg.WParam);
keystate = (keystate == "1")?"����":"����";//C++����Ԫ����

//��ListBox�����ʾ���سɹ�
ListBox1->Items->Insert(0,
                        "�� "+AnsiString(++inthook) + " ����__" +
                        AnsiString(keytext)+ " ��״̬>>" + keystate
                        );
}
//---------------------------------------------------------------------------

