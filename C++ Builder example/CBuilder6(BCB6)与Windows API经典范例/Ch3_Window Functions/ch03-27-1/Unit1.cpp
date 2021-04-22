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
FHRgn = NULL;
FScreenCanvas = new TCanvas();
}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
{
::DeleteObject(FHRgn);
delete FScreenCanvas;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// grab a handle to the screen's device context
FScreenCanvas->Handle = ::GetDC(0);

// create and select the clipping area
if (FHRgn) ::DeleteObject(FHRgn);
RECT R = (RECT) BoundsRect;
FHRgn = ::CreateRectRgnIndirect(&R);
::SelectClipRgn(FScreenCanvas->Handle, FHRgn);

// change the raster operation mode
FScreenCanvas->Pen->Mode = pmNotXor;
FScreenCanvas->Brush->Style = bsClear;

// get the rectangles of the controls to move
::GetWindowRect(Panel1->Handle, &FRect[0]);
::GetWindowRect(Panel2->Handle, &FRect[1]);
::GetWindowRect(Panel3->Handle, &FRect[2]);
::GetWindowRect(Panel4->Handle, &FRect[3]);

// flag the dragging
FDragPoint = Point(X, Y);
FDragging = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
if(FDragging)
  {
  // draw the XOR rectangles
  for(int index = 0; index < 4; index++)
     {
     FScreenCanvas->Rectangle(FRect[index].left, FRect[index].top,
                              FRect[index].right, FRect[index].bottom);
     ::OffsetRect(&FRect[index], X - FDragPoint.x, Y - FDragPoint.y);
     FScreenCanvas->Rectangle(FRect[index].left, FRect[index].top,
                              FRect[index].right, FRect[index].bottom);
     }
  FDragPoint = Point(X, Y);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
// restore the defaults
FDragging = false;
FScreenCanvas->Pen->Mode = pmCopy;
FScreenCanvas->Brush->Style = bsSolid;
::ReleaseDC(0, FScreenCanvas);

for(int index = 0; index < 4; index++)
    OffsetRect(&FRect[index], -ClientOrigin.x, -ClientOrigin.y);

// move the Panels
Panel1->BoundsRect = FRect[0];
Panel2->BoundsRect = FRect[1];
Panel3->BoundsRect = FRect[2];
Panel4->BoundsRect = FRect[3];
                
Panel1->Invalidate();
Panel2->Invalidate();
Panel3->Invalidate();
Panel4->Invalidate();    
}
//---------------------------------------------------------------------------
