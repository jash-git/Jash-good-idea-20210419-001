//---------------------------------------------------------------------------
#ifndef WinMainH
#define WinMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------

enum FilterType {HIGHPASS1, HIGHPASS2, HIGHPASS3,
                 LOWPASS1, LOWPASS2, LOWPASS3,
                 VERTICAL, HORIZONTAL, HORIZONTALVERTICAL,
                 LAPLACE1, LAPLACE2, LAPLACE3, LAPLACE4,
                 EAST, WEST, SOUTH, NORTH,
                 SOUTHEAST, NORTHEAST, SOUTHWEST, NORTHWEST};

struct RGBColor
{
   Byte Blue;
   Byte Green;
   Byte Red;
};
//---------------------------------------------------------------------------

class TMainForm : public TForm
{
__published:	// IDE-managed Components
   TMainMenu *MainMenu1;
   TMenuItem *File;
   TMenuItem *Open;
   TMenuItem *Save;
   TMenuItem *Exit;
   TMenuItem *Smooth;
   TMenuItem *Sharpen;
   TMenuItem *Detect;
   TMenuItem *Enhance;
   TMenuItem *Sobel;
   TMenuItem *Vertical;
   TMenuItem *Horizontal;
   TMenuItem *Laplace;
   TPanel *Panel1;
   TImage *Image1;
   TOpenPictureDialog *OpenPictureDialog1;
   TMenuItem *Smooth1;
   TMenuItem *Smooth2;
   TMenuItem *Smooth3;
   TMenuItem *Sharpen1;
   TMenuItem *Sharpen2;
   TMenuItem *Sharpen3;
   TMenuItem *Prewitt;
   TMenuItem *Detect1;
   TMenuItem *HorizontalVertical;
   TMenuItem *N1;
   TMenuItem *Grads;
   TMenuItem *East;
   TMenuItem *South;
   TMenuItem *West;
   TMenuItem *North;
   TMenuItem *NorthEast;
   TMenuItem *SouthEast;
   TMenuItem *NorthWest;
   TMenuItem *SouthWest;
   TMenuItem *N2;
   TMenuItem *Hough;
   TMenuItem *LAP1;
   TMenuItem *LAP2;
   TMenuItem *LAP3;
   TMenuItem *LAP4;
   TMenuItem *Media;
   TSavePictureDialog *SavePictureDialog1;
   void __fastcall FormDestroy(TObject *Sender);
   void __fastcall OpenClick(TObject *Sender);
   void __fastcall ExitClick(TObject *Sender);
   void __fastcall VerticalClick(TObject *Sender);
   void __fastcall HorizontalClick(TObject *Sender);
   void __fastcall Smooth1Click(TObject *Sender);
   void __fastcall Smooth2Click(TObject *Sender);
   void __fastcall Smooth3Click(TObject *Sender);
   void __fastcall Sharpen1Click(TObject *Sender);
   void __fastcall Sharpen2Click(TObject *Sender);
   void __fastcall Sharpen3Click(TObject *Sender);
   void __fastcall LAP1Click(TObject *Sender);
   void __fastcall LAP2Click(TObject *Sender);
   void __fastcall LAP3Click(TObject *Sender);
   void __fastcall LAP4Click(TObject *Sender);
   void __fastcall HorizontalVerticalClick(TObject *Sender);
   void __fastcall EastClick(TObject *Sender);
   void __fastcall SouthClick(TObject *Sender);
   void __fastcall WestClick(TObject *Sender);
   void __fastcall NorthClick(TObject *Sender);
   void __fastcall NorthEastClick(TObject *Sender);
   void __fastcall SouthEastClick(TObject *Sender);
   void __fastcall NorthWestClick(TObject *Sender);
   void __fastcall SouthWestClick(TObject *Sender);
   void __fastcall HoughClick(TObject *Sender);
   void __fastcall SobelClick(TObject *Sender);
   void __fastcall PrewittClick(TObject *Sender);
   void __fastcall Detect1Click(TObject *Sender);
   void __fastcall MediaClick(TObject *Sender);
   void __fastcall SaveClick(TObject *Sender);

private:	// User declarations
   Graphics::TBitmap*   m_pBitmap;
   
   Byte**      m_RedData;
   Byte**      m_GreenData;
   Byte**      m_BlueData;

   Byte**      m_TempRedData;
   Byte**      m_TempGreenData;
   Byte**      m_TempBlueData;

   int         m_Width, m_Height;
   bool        m_AllocFlag;

public:		// User declarations
   __fastcall TMainForm(TComponent* Owner);

   void ImageFilter(FilterType enFilter);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
