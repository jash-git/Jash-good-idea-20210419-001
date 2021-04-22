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
    //自定义的整合主函数
    void __fastcall ColorChangeLoop();
    //取得图文件结构大小与取得图文件字节大小
    void __fastcall MyGetDIBSizes ( HBITMAP Bitmap, int &InfoHeaderSize,
                                    int &ImageSize );
    //取得和复制DIB图形数据至内存区块中
    bool __fastcall MyGetDIB(HBITMAP Bitmap, void *BitmapInfo, void *Bits );
    //设置在内存区块中DIB图像数据，再给予Image1
    bool __fastcall MySetDIB(HBITMAP Bitmap, void *BitmapInfo, void *Bits );
    //BITMAPINFO初始化--MyGetDIBSizes & MyGetDIB & MySetDIB副函数
    void __fastcall InitializeBitmapInfoHeader ( HBITMAP Bitmap,
                                   BITMAPINFOHEADER &BI, int Colors );
    //取得图像一列的字节--InitializeBitmapInfoHeader副函数
    long __fastcall BytesPerScanline ( long PixelsPerScanline,
                                       long BitsPerPixel, long Alignment );

    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
