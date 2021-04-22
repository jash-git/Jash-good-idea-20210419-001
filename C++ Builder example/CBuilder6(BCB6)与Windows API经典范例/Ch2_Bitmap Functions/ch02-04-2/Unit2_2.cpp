//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2_2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNewform *Newform;
//---------------------------------------------------------------------------
__fastcall TNewform::TNewform(TComponent* Owner)
    : TForm(Owner)
{
//當Form1按下Button1時，
//引發Newform初始化，進行下列動作：
//去除Form2邊沿
Newform->BorderStyle = bsNone;
//禁止Form2再重繪Form2背景，
//而可將桌面影像留住Form2背景中
Newform->Brush->Style = bsClear;
//Form2放大至全螢幕
Newform->SetBounds(0, 0, Screen->Width, Screen->Height);
//故可讓User認為按下按鈕時，桌面仍維持原有畫面狀態，
//實際已經變成Newform背景底圖
}
//---------------------------------------------------------------------------
//捕捉&重設NewForm的訊息
void __fastcall TNewform::WndProc(TMessage &Msg)
{
//保持以下兩個區域變數存放位置，不隨執行訊息後變動
static bool Drawing = false;
static bool FirstRect = false;
//取得滑鼠在Newform上拖曳出來的虛框區域
switch (Msg.Msg)
    {
    case WM_LBUTTONDOWN:
        {
        //當滑鼠在Newform上按下時，
        //確定Newform在前景不變
        ::SetCapture(Handle);
        //虛框長寬皆為 0
        R.left = R.right = LOWORD(Msg.LParam);
        R.top = R.bottom = HIWORD(Msg.LParam);
        FirstRect = true;
        Drawing = true;
        Msg.Result = 0;
        return;
        }
    case WM_MOUSEMOVE:
        {
        if (Drawing)
            {
            HDC Hdc = ::GetDC(Handle);
            //反轉螢幕前景顏色
            int OldR2Mode = ::SetROP2(Hdc, R2_NOT);
            //換上無筆刷(透明)
            HBRUSH HOldBrush =
                ::SelectObject(Hdc, ::GetStockObject(NULL_BRUSH));
            //若非框架起點，則設此框範圍
            if (!FirstRect)
                ::Rectangle(Hdc, R.left, R.top, R.right, R.bottom);
            //再取得滑鼠移動最後訊息填入框架右邊&底邊
            R.right = LOWORD(Msg.LParam);
            R.bottom = HIWORD(Msg.LParam);
            ::Rectangle(Hdc, R.left, R.top, R.right, R.bottom);

            FirstRect = false;
            //回復螢幕前景顏色
            ::SelectObject(Hdc, HOldBrush);
            ::SetROP2(Hdc, OldR2Mode);
            ::ReleaseDC(Handle, Hdc);
            }
        Msg.Result = 0;
        return;
        }
    case WM_LBUTTONUP:
        {
        //釋放滑鼠按下時的捕捉狀態
        ::ReleaseCapture();
        FirstRect = false;
        Drawing = false;
        Close();

        Msg.Result = 0;
        return;
        }
    }
    TForm::WndProc(Msg);
}
//---------------------------------------------------------------------------
//將Form1範圍複製至NewForm中，作為依據參考
void __fastcall TNewform::GetRect(LPRECT lpRect)
{
::CopyRect(lpRect, &R);
}
//---------------------------------------------------------------------------
