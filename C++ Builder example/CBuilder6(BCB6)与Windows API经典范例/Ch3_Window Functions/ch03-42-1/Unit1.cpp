//---------------------------------------------------------------------------
//Ŀ�ģ���������ʱ����ϵͳ��¼�ļ�ȡ���ϴδ��ڹر�ʱ��Χ�ߴ����Ϣ������֮��ʾ
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//��"��¼�༭��"(Regedit.exe)�� HKEY_USERS\\.DEFAULT\\ ·����--------------
const char RegistryKey[] = "Software\\MyCompany\\MyApp" ;
const char RegExtents[] = "Extents" ;
//---------------------------------------------------------------------------
//����ʽ�У���ϵͳ��¼�ļ�ȡ���ϴγ���ر�ʱForm1��Χ�ߴ����Ϣ
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
WINDOWPLACEMENT wp;//���ڷ�Χ
//�½�һ��¼���
RegUser = new TRegistry;
//��ָ����¼·������������һָ����¼·��
RegUser->OpenKey( RegistryKey, true);
//����һ��¼Ŀ¼���ƣ�����ȡ��������ֵ���ؽ�Form1��Χ��λ��
if(RegUser->ValueExists(RegExtents))
  {//����¼��ֵ������WINDOWPLACEMENT�ṹ��
  RegUser->ReadBinaryData( RegExtents, &wp, sizeof(WINDOWPLACEMENT));
  //�ؽ�Form1��Χ��λ��
  ::SetWindowPlacement( Handle, &wp);
  }
//���ȡ����¼��ֵ��ɾ���˵�¼���
delete RegUser;
}
//---------------------------------------------------------------------------
//�⹹ʽ�У���ϵͳ��¼�ļ���¼Form1��Χ�ߴ����Ϣ
__fastcall TForm1::~TForm1()
{
WINDOWPLACEMENT wp;//����WINDOWPLACEMENT�ṹ
wp.length = sizeof(WINDOWPLACEMENT);//�����ṹ�ڴ�λ��
//�½�һ��¼���
RegUser = new TRegistry ;
//��ָ����¼·������������һָ����¼·��
RegUser->OpenKey( RegistryKey, true);
//ȡ��Form1��Χ��λ�ã�����ṹ��
::GetWindowPlacement( Handle, &wp);
//���ṹ�����Զ�������ֵ������ָ����¼Ŀ¼��
RegUser->WriteBinaryData( RegExtents, &wp, sizeof(WINDOWPLACEMENT));
//���д���¼��ֵ�󣬹رղ�ɾ���˵�¼���
RegUser->CloseKey();
delete RegUser;
}
//---------------------------------------------------------------------------


