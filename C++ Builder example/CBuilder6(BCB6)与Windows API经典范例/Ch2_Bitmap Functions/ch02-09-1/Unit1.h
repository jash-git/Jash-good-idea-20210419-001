//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TStaticText *StaticText1;
    TToolBar *ToolBar1;
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    //�Զ��������������
    void __fastcall ColorChangeLoop();
    //ȡ��ͼ�ļ��ṹ��С��ȡ��ͼ�ļ��ֽڴ�С�j�p
    void __fastcall MyGetDIBSizes ( HBITMAP Bitmap, int &InfoHeaderSize,
                                    int &ImageSize );
    //ȡ�ú͸���DIBͼ���������ڴ�������
    bool __fastcall MyGetDIB(HBITMAP Bitmap, void *BitmapInfo, void *Bits );
    //�������ڴ�������DIBͼ�����ݣ��ٸ���Image1
    bool __fastcall MySetDIB(HBITMAP Bitmap, void *BitmapInfo, void *Bits );
    //BITMAPINFO��ʼ��--MyGetDIBSizes & MyGetDIB & MySetDIB������
    void __fastcall InitializeBitmapInfoHeader ( HBITMAP Bitmap,
                                   BITMAPINFOHEADER &BI, int Colors );
    //ȡ��ͼ��һ�е��ֽ�--InitializeBitmapInfoHeader������
    long __fastcall BytesPerScanline ( long PixelsPerScanline,
                                       long BitsPerPixel, long Alignment );

    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
