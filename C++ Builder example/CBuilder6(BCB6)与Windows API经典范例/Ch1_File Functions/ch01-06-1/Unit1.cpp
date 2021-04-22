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
nFile = nDir = 0;
AnsiString sd;
//若user忘记，则自动在后面加入"\"，显示为目录
if( ComboBox1->Text[ComboBox1->Text.Length()]!='\\')    
   sd = ComboBox1->Text + "\\";
else
   sd = ComboBox1->Text ;
   
ScanDirectory( sd.c_str(), NULL);
StaticText1->Caption =
        "共用" + AnsiString(nDir) + " 目录及 " + AnsiString(nFile) + " 文件";
StaticText1->Color = (TColor)0x0080FF80;
}
//---------------------------------------------------------------------------

void TForm1::ScanDirectory(char Directory[], TTreeNode *Node)
{
char CopyDir[1000];
strcpy(CopyDir, Directory);
WIN32_FIND_DATA Data;
char Name[1000];
lstrcpy(Name, CopyDir);
lstrcat(Name, "*.*");
HANDLE hFile = FindFirstFile(Name, &Data);
bool Res = true;
bool FirstFile = true;
if(hFile != INVALID_HANDLE_VALUE)
    {
    while(Res)
        {
        if(lstrcmp(Data.cFileName, "..") && lstrcmp(Data.cFileName,"."))
            {
            if(Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                {
                nDir++;
                char N[1000];
                lstrcpy(N, CopyDir); lstrcat(N, Data.cFileName);
                lstrcat(N, "\\");
                if(FirstFile)
                    {
                    Node = TreeView1->Items->AddChild(Node, Data.cFileName);
                    FirstFile = false;
                    }
                else
                    Node = TreeView1->Items->Add(Node,Data.cFileName);
                ScanDirectory(N, Node);
                }
            else
                {
                nFile++;
                if(FirstFile)
                    {
                    Node = TreeView1->Items->AddChild(Node,Data.cFileName);
                    FirstFile = false;
                    }
                else
                    TreeView1->Items->Add(Node, Data.cFileName);
                }
            }
        StaticText1->Caption = "工作中！";
        StaticText1->Color = (TColor)RGB(255,128,255);
        Res = FindNextFile(hFile, &Data);
        //容许用户中断此循环
        Application->ProcessMessages();
        }
    }
}