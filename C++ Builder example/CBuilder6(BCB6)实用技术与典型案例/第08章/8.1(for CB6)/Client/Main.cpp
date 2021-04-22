//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
    m_BmpStream=new TMemoryStream;
    m_Bufsize=2048;
    CUDP->ReportLevel=Nmudp::Status_Basic;
    m_pBuf =new Byte [m_Bufsize];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   delete m_BmpStream;
   delete m_pBuf;   
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CUDPDataReceived(TComponent *Sender,
      int NumberBytes, AnsiString FromIP, int Port)
{
    char *TempBuffer=new char[NumberBytes];

    int iLength;
    int iSendSize;
    int iPos;

    AnsiString sTempStr;
    CUDP->ReadBuffer(TempBuffer,NumberBytes,iLength);
    m_sReceiveData=AnsiString(TempBuffer);
    iLength=m_sReceiveData.Length();
    iPos=m_sReceiveData.Pos(",");
    m_sCommand=m_sReceiveData.SubString(1,iPos-1);
    sTempStr=m_sReceiveData;
    if(m_sCommand=="Close")
        Close();
    if(m_sCommand=="Show")
    {
        if(m_BmpStream->Size==0)
        {
           AnsiString sPosStr;
           for(int i=0;i<4;i++)
           {
                sTempStr=sTempStr.Trim();
                iPos=sTempStr.Pos(",");
                sTempStr=sTempStr.SubString(iPos+1,iLength-iPos);
                iPos=sTempStr.Pos(",");
                sPosStr=sTempStr.SubString(1,iPos-1);
                iLength=sTempStr.Length();
                switch(i)
                {
                    case 0:
                        m_LeftPos=sPosStr.ToInt();
                        break;
                    case 1:
                        m_TopPos=sPosStr.ToInt();
                        break;
                    case 2:
                        m_RightPos=sPosStr.ToInt();
                        break;
                    case 3:

                        m_BottomPos=sPosStr.ToInt();
                        break;
                }
            }
            ScreenCapture();
          }
           if(m_iLeftSize>m_Bufsize)
              iSendSize=m_Bufsize;
           else
               iSendSize=m_iLeftSize;
            m_BmpStream->ReadBuffer(m_pBuf,iSendSize);
            m_iLeftSize=m_iLeftSize-iSendSize;
            CUDP->RemoteHost=EdtRemoteAddress->Text;
            CUDP->SendBuffer(m_pBuf,iSendSize,iSendSize);
            if(m_iLeftSize<=0)
            {
                 m_BmpStream->Clear();
            }

    }

    delete TempBuffer;
}
//---------------------------------------------------------------------------
void TMainForm::ScreenCapture(void)
{
    AnsiString ExeFilePath;
    ExeFilePath=ExtractFileDir(Application->ExeName);
    RECT r;
    RECT DestR;
    RECT SourceR;
    int ImageWidth=m_RightPos-m_LeftPos;
    int ImageHeight=m_BottomPos-m_TopPos;
    DestR.top=0;
    DestR.left=0;
    DestR.right=ImageWidth;
    DestR.bottom=ImageHeight;
    SourceR.top=m_TopPos;
    SourceR.left=m_LeftPos;
    SourceR.right=ImageWidth+m_LeftPos;
    SourceR.bottom=ImageHeight+m_TopPos;

    GetWindowRect(GetDesktopWindow(),&r);
    TCanvas *Canvas=new TCanvas;
    Canvas->Handle=GetDC(NULL);
    Graphics::TBitmap  *Bitmap=new Graphics::TBitmap();
    Graphics::TBitmap  *DestBitmap=new Graphics::TBitmap();
    Bitmap->Height=r.bottom;
    Bitmap->Width=r.right;
    DestBitmap->Width=ImageWidth;
    DestBitmap->Height=ImageHeight;

    Bitmap->Canvas->CopyRect(r,Canvas,r);
    DestBitmap->Canvas->CopyRect(DestR,Bitmap->Canvas,SourceR);
    DestBitmap->SaveToStream(m_BmpStream);
    m_BmpStream->SaveToFile(ExeFilePath+AnsiString("\\Screen.bmp"));
    m_iLeftSize=m_BmpStream->Size;
    m_BmpStream->Position=0;
    delete Bitmap;
    delete DestBitmap;
    delete Canvas;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::ChkBoxHideClick(TObject *Sender)
{
   if(ChkBoxHide->Checked)
      this->Visible=false;
}
//---------------------------------------------------------------------------

