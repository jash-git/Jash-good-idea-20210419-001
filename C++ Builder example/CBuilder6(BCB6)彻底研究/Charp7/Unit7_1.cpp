//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit7_1.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
     SYSTEM_INFO Si;
     int i;

     GetSystemInfo(&Si);
     Label10->Caption=IntToStr(Si.dwOemId);
     Label11->Caption=IntToStr(Si.dwPageSize);
     i=Integer(Si.lpMinimumApplicationAddress);

     Label12->Caption=IntToStr(i);
     i=Integer(Si.lpMaximumApplicationAddress);
     Label13->Caption=IntToStr(i);
     Label14->Caption=IntToHex(__int64(Si.dwActiveProcessorMask),8);
     Label15->Caption=IntToStr(Si.dwNumberOfProcessors);
     switch (Si.dwProcessorType) {
     	case 386:
     	case 486:
			Label16->Caption="Intel 80"+IntToStr(Si.dwProcessorType);
            break;
     	case 586:
        	Label16->Caption="Intel Pentium"+IntToStr(Si.dwProcessorType);
            break;
		default :
            Label16->Caption="·Ç Intel ´¦ÀíÆ÷";
	 }
     Label17->Caption=IntToStr(Si.dwAllocationGranularity);
     i=GetKeyboardType(0);
     switch (i) {
       case 1: Label18->Caption=" IBM PC/XT or compatible (83-key)"; break;
       case 2: Label18->Caption=" Olivetti 'ICO' (102-key)"; break;
       case 3: Label18->Caption=" IBM PC/AT (84-key) or similar"; break;
       case 4: Label18->Caption=" IBM enhanced (101/102 key)"; break;
       case 5: Label18->Caption=" Nokia?1050 and similar"; break;
       case 6: Label18->Caption=" Nokia 9140 and similar"; break;
       case 7: Label18->Caption=" Japanese keyboard"; break;
     }
}
//---------------------------------------------------------------------------

