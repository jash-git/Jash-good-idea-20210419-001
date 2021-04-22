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

		   // 專案自動開啟一般的Form
           Application->CreateForm(__classid(TForm1), &Form1);
           Application->CreateForm(__classid(TForm3), &Form3);

		   // 釋放Logo視窗占用的記憶空間
           Form2->Hide();
           Form2->Free();
           Application->Run();
        }
        catch (Exception &exception)
        {
           Application->ShowException(&exception);
        }
	// 自動開啟的Form將會在程式執行結束後，自動被釋放占用的空間
        return 0;
}
//---------------------------------------------------------------------------
