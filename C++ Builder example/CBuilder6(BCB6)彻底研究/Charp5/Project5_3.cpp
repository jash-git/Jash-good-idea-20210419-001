//---------------------------------------------------------------------------
#include <vcl.h>
#include "Unit5_32.h"
#pragma hdrstop
USEFORM("Unit5_31.cpp", Form1);
USEFORM("Unit5_32.cpp", Form2);
USEFORM("Unit5_33.cpp", Form3);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
           Application->Initialize();

           Form2=new TForm2(Application);
           Form2->Show();
           Form2->Update();

		   // �M�צ۰ʶ}�Ҥ@�몺Form
           Application->CreateForm(__classid(TForm1), &Form1);
           Application->CreateForm(__classid(TForm3), &Form3);

		   // ����Logo�����e�Ϊ��O�ЪŶ�
           Form2->Hide();
           Form2->Free();
           Application->Run();
        }
        catch (Exception &exception)
        {
           Application->ShowException(&exception);
        }
	// �۰ʶ}�Ҫ�Form�N�|�b�{�����浲����A�۰ʳQ����e�Ϊ��Ŷ�
        return 0;
}
//---------------------------------------------------------------------------
