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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//����һ�ַ�����
char cd[MAX_PATH];
//ȡ�ñ���������Ŀ¼λ�ò�������ַ�����
::GetCurrentDirectory(MAX_PATH,cd);
//ȡ������Ŀ¼������ָ�����ı��ļ�����
AnsiString str = AnsiString(cd) + "\\" + Edit1->Text;
//��һ�ı��ļ�����������handle
HANDLE hFile=::CreateFile(str.c_str(),
                          GENERIC_WRITE,0,NULL,
                          OPEN_EXISTING,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
//��ʧ�ܣ�����������ִֹͣ��
if (hFile==INVALID_HANDLE_VALUE)
   {
    ShowMessage("�޷���ָ���ļ���");
    return;
   }

DWORD dpos[2];
long pos = 1555;
*(__int64*)dpos=pos;
//������ļ���ʱ��λλ��
DWORD moved=::SetFilePointer(hFile,dpos[0],(PLONG)&dpos[1],FILE_BEGIN);
//���޷�������ļ���ʱ��λλ�ã�������˳���
if (moved!=dpos[0])
   {
    ShowMessage("���ļ�ʱ���޷����µ�ָ��λ�ô�");
    ::CloseHandle(hFile);
    return;
   }
//���ɣ������½��ض�����д���ļ���
unsigned char c[100];
c[0]=0xB8; c[1]=0x01; c[2]=0x00; c[3]=0x00;
c[4]=0x00; c[5]=0xC3; c[6]=0x00; c[7]=0x00;
c[8]=0x00; c[9]=0x00; c[10]=0x00; c[11]=0x00;
c[12]=0x4C; c[13]=0x4A; c[14]=0x57; c[15]=0x00;
DWORD writ=0;
int res=::WriteFile(hFile,c,16,&writ,NULL);
//���޷�������д���ļ��У�������˳���
if (!res)
   {
   ShowMessage("�޷�������д���ļ���");
   ::CloseHandle(hFile);
   return;
   }
//���޷���16λ������ȫд�룬������˳���
if (writ!=16)
   {
   ShowMessage("�޷���16λ������ȫд��");
   ::CloseHandle(hFile);
   return;
   }
//����ļ�ָ��λ�õĸ�������
if(::CloseHandle(hFile))
   ShowMessage("���ļ�ָ��λ�ã��ɹ��ĸ������ݣ�");
}
//---------------------------------------------------------------------------
