//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Project1.res");
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit1a.cpp", Form1a);//�����½��ڶ�������ʱ�������Զ�����
//��Form1��ǰ������ʾ��̬��Ƭͷ����-------------------------------------------
#include "Unit1a.h"
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
try
  {//�½�����ʾƬͷ����
  TForm1a *Splash = new TForm1a(NULL);
  Splash->BorderStyle = bsNone;
  Splash->Show();
  Splash->Refresh();
  //Ƭͷ���ڵ�����ʱ5����
  int i=5;
  while(i)
     {
     Splash->Panel1->Color = (TColor)RGB(255,i*50,255-i*50);
     Splash->Panel1->Caption = "���� "+AnsiString(i--)+" ����";
     Splash->Refresh();
     Sleep(1000);//ÿ�γ���ֹͣ1����
     }

  Application->ProcessMessages();
  Application->Initialize();
  Application->Title = "����WinMain��������";
  Application->Hint = "����WinMain��������";
  Application->CreateForm(__classid(TForm1), &Form1);
        delete Splash;//�ڳ�����ʾִ��ǰ��ɾ��Ƭͷ����
  Application->Run();
  }
catch (Exception &exception)
  {
  Application->ShowException(&exception);
  }
return 0;
}
//---------------------------------------------------------------------------
