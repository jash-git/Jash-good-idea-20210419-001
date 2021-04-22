//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit7_2.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GetSpecifyDiskInfor(char *DriverName)
{
	DWORD dwSectPerClust, dwBytePerClust, dwFreeClust, dwClust;

    if (GetDiskFreeSpace(DriverName, &dwSectPerClust,
                       &dwBytePerClust, &dwFreeClust, &dwClust)) {
			ProgressBar1->Max=dwClust;
      		ProgressBar1->Position=(dwClust-dwFreeClust);
    } else ProgressBar1->Position=0;
   Label12->Caption=IntToStr(dwClust * dwSectPerClust * dwBytePerClust / 1024)+"KB";
   Label14->Caption=IntToStr(dwFreeClust * dwSectPerClust * dwBytePerClust / 1024)+"KB";
}

void __fastcall TForm1::GetFullDriveInfor(char *DriverName)
{
   int nDriveType;
   char lpVolName[200],lpFSNameBuff[50];
   DWORD dwVolSer, lpMaxComLen, lpFSFlags;

   nDriveType=GetDriveType(DriverName);
   switch (nDriveType) {
        case 0:
        	Label3->Caption="不知道";
            break;
        case 1:
        	Label3->Caption="路径未知";
            break;
        case DRIVE_REMOVABLE:
        	Label3->Caption="软区";
            break;
        case DRIVE_FIXED:
        	Label3->Caption="硬盘";
            break;
        case DRIVE_REMOTE:
        	Label3->Caption="网络磁盘驱动器";
            break;
        case DRIVE_CDROM:
        	Label3->Caption="光驱";
            break;
        case DRIVE_RAMDISK:
        	Label3->Caption="虚拟磁盘驱动器";
            break;
        default :
        	Label3->Caption="不知道";
            break;
   }
   if (GetVolumeInformationA(DriverName, lpVolName, 200, &dwVolSer,
   			&lpMaxComLen, &lpFSFlags, lpFSNameBuff, 50)) {
        if (dwVolSer==0) Label5->Caption="";
      		else Label5->Caption=IntToHex(__int64(dwVolSer),8);
      	Label7->Caption=lpVolName;
      	Label9->Caption=lpFSNameBuff;
   } else {
         Label5->Caption="";
         Label7->Caption="no Volume Available";
         Label9->Caption="no Disk";
   }
   GetSpecifyDiskInfor(DriverName);
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   char lp[100];
   int i;

   GetLogicalDriveStrings(100, lp);
   i=0;
   while (true) {
      if (lp[i]==0) break;
      ComboBox1->Items->Add(strupr(lp+i));
      i+=4;
   }
   ComboBox1->Text="C:\\";
   GetFullDriveInfor(ComboBox1->Text.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
   GetFullDriveInfor(ComboBox1->Text.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if ((ComboBox1->Text!="A:\\") || (ComboBox1->Text!="B:\\"))
        GetSpecifyDiskInfor(ComboBox1->Text.c_str());
}
//---------------------------------------------------------------------------


