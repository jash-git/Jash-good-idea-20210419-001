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
inthook = 0;//�p����䦸���ܼ��k�s
//�NKeyHookForm�����b�����̤W��
FormStyle = fsStayOnTop;
//���W&���UHook�����s���A
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//���WHook��A�ó]�m�w�ɾ��q�@�ɰO���餤���^��L�T��
void __fastcall TKeyHookForm::Button1Click(TObject *Sender)
{
//�p����䦸���ܼ��k�s
inthook = 0;
//�bkeydll.dll���ASetHook�禡�O����`�gHook��{�ܰT���줤
//���ŧi���@SetHook�禡
void (*SetHook)();
//���J�P�@�ؿ��U�����w�s����--keydll.dll
inst = ::LoadLibrary("keydll.dll");
//���odll��SetHook�禡��}
(FARPROC &)SetHook = ::GetProcAddress(inst,"SetHook");
//������Vdll����SetHook�禡
SetHook();
//���W&���UHook�����s���A
Button1->Enabled = false;
Button2->Enabled = true;
}
//---------------------------------------------------------------------------
//���UHook��A�Ѱ��ۭq��hook
void __fastcall TKeyHookForm::Button2Click(TObject *Sender)
{
//�bkeydll.dll���ARemoveHook�禡�O����q�T���줤���UHook��{
//�ŧiRemoveHook�禡
void (*RemoveHook)();
//���J�P�@�ؿ��U�����w�s����--keydll.dll
inst = ::LoadLibrary("keydll.dll");
//���odll��RemoveHook�禡��}
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//������Vdll����RemoveHook�禡
RemoveHook();
//����dll
::FreeLibrary(inst);
//���W&���UHook�����s���A
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//�w���ϥΪ̵���Hook�ɡA�����UHook��
void __fastcall TKeyHookForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//�bkeydll.dll���ARemoveHook�禡�O����q�T���줤���UHook��{
//���ŧiRemoveHook�禡
void (*RemoveHook)();
//���Jdll
inst = ::LoadLibrary("keydll.dll");
//���odll��RemoveHook�禡��}
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//������Vdll����RemoveHook�禡
RemoveHook();
//����dll
::FreeLibrary(inst);
}
//---------------------------------------------------------------------------
//���o�d�I����L�����ۭq�T��
void __fastcall TKeyHookForm::KeyHook(TMessage &Msg)
{
//���o�ۭq�T����������W��
char keytext[80];
::GetKeyNameText(Msg.LParam, keytext, 80);
//���o�ۭq�T���������䪬�A(�˴���..�N�q���j...)
AnsiString keystate;
keystate = ::GetKeyState((int)Msg.WParam);
keystate = (keystate == "1")?"����":"����";//C++����Ԫ����

//��ListBox��������d�I���G
ListBox1->Items->Insert(0,
                        "�� "+AnsiString(++inthook) + "����__" +
                        AnsiString(keytext)+ " ��״̬>>" + keystate
                        );
}
//---------------------------------------------------------------------------

