//---------------------------------------------------------------------------

#ifndef FlashingLabelH
#define FlashingLabelH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TLimitReachedEvent)(TObject *Sender,bool &Stop);
class PACKAGE TFlashingLabel : public TCustomLabel
{
private:
         bool FFlashEnabled;
         int FFlashRate;
         TTimer *Timer;
         int FlashCount;
         int FFlashLimit;
         TLimitReachedEvent FOnLimitReached;
protected:
        void __fastcall OnTimer(TObject *Sender);
        void __fastcall SetFlashRate(int AFlashRate);
        void __fastcall SetFlashEnabled(bool AFlashEnabled);
public:
        __fastcall TFlashingLabel(TComponent* Owner);
        __fastcall ~TFlashingLabel();
__published:
        __property Align;
        __property Alignment;
        __property Anchors;
        __property AutoSize;
        __property BiDiMode;
        __property Caption;
        __property Color;
        __property Constraints;
        __property DragCursor;
        __property DragKind;
        __property DragMode;
        __property Enabled;
        __property FocusControl;
        __property Font;
        __property ParentBiDiMode;
        __property ParentColor;
        __property ParentFont;
        __property ParentShowHint;
        __property PopupMenu;
        __property ShowAccelChar;
        __property ShowHint;
        __property Transparent;
        __property Layout;
        __property Visible;
        __property WordWrap;
        __property OnClick;
        __property OnContextPopup;
        __property OnDblClick;
        __property OnDragDrop;
        __property OnDragOver;
        __property OnEndDock;
        __property OnEndDrag;
        __property OnMouseDown;
        __property OnMouseMove;
        __property OnMouseUp;
        __property OnStartDock;
        __property OnStartDrag;
        __property bool FlashEnabled={read=FFlashEnabled,write=SetFlashEnabled,default=true};
        __property int  FlashRate={read=FFlashRate,write=SetFlashRate,default=800};
        __property int FlashLimit={read=FFlashLimit,write=FFlashLimit,default=0};
        __property TLimitReachedEvent OnLimitReached={read=FOnLimitReached,write=FOnLimitReached,default=NULL};
};
//---------------------------------------------------------------------------
#endif
