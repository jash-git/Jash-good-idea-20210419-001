//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FlashingLabel.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TFlashingLabel *)
{
        new TFlashingLabel(NULL);
}
//---------------------------------------------------------------------------
__fastcall TFlashingLabel::TFlashingLabel(TComponent* Owner)
        : TCustomLabel(Owner)
{
        FFlashEnabled=true;
        FFlashRate=800;
        Timer=new TTimer(this);
        Timer->Interval=FFlashRate;
        Timer->OnTimer=OnTimer;
        FlashCount=0;
        FFlashLimit=0;
        FOnLimitReached=NULL;
}

__fastcall TFlashingLabel::~TFlashingLabel()
{
        delete Timer;
}

void  __fastcall TFlashingLabel::OnTimer(TObject *Sender)
{
        //if(ComponentState.Contains(csDesigning)) return;
        Visible=!Visible;
        if(FFlashLimit&&Visible)
          {
                FlashCount++;
                if(FlashCount>=FFlashLimit)
                  {
                   FlashCount=0;
                   MessageBeep(-1);
                   if(FOnLimitReached)
                     {
                      bool stop=false;
                      FOnLimitReached(this,stop);
                      FlashEnabled=!stop;
                     }
                  }
          }
}

void __fastcall TFlashingLabel::SetFlashRate(int AFlashRate)
{
        Timer->Interval=FFlashRate=AFlashRate;
}

void __fastcall TFlashingLabel::SetFlashEnabled(bool AFlashEnabled)
{
        Timer->Enabled=FFlashEnabled=AFlashEnabled;
        if(!FFlashEnabled)
           Visible=true;
}
//---------------------------------------------------------------------------
namespace Flashinglabel
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TFlashingLabel)};
                 RegisterComponents("Custom Controls", classes, 0);
        }
}
//---------------------------------------------------------------------------
 