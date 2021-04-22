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
    m_BufferSize=2048;
    m_ResultStream=new TMemoryStream;
    m_TempStream=new  TMemoryStream;
    SUDP->LocalPort=2222;
    SUDP->RemotePort=1111;
    SUDP->ReportLevel=Nmudp::Status_Basic;
    TDateTime NowTime;
    NowTime=Now();
    StatusBar1->Panels->Items[1]->Text=NowTime.DateTimeString();
  
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BtnTestEchoClick(TObject *Sender)
{
   if(!EdtSpyAddress->Text.IsEmpty())
        NMEcho1->Host=EdtSpyAddress->Text;
    NMEcho1->TimeOut=StrToInt(EdtTimeOut->Text);
    NMEcho1->Port=352;
    NMEcho1->Connect();
    ShowMessage(NMEcho1->Echo("您与远程机是连通的!"));
    NMEcho1->Disconnect();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NMEcho1Connect(TObject *Sender)
{
    StatusBar1->Panels->Items[0]->Text="连接成功!";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NMEcho1ConnectionFailed(TObject *Sender)
{
   StatusBar1->Panels->Items[0]->Text="连接失败";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NMEcho1InvalidHost(bool &Handled)
{
    AnsiString NewHost;
    if(InputQuery("无效的地址!","请指定一个新的地址:",NewHost))
    {
        EdtSpyAddress->Text=NewHost;
        NMEcho1->Host=NewHost;
        Handled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BtnTestDayTimeClick(TObject *Sender)
{
   NMDayTime1->Host=EdtSpyAddress->Text;
   NMDayTime1->TimeOut=StrToInt(EdtTimeOut->Text);
   NMDayTime1->Port=13;
   ShowMessage(AnsiString("当前日期和时间是:")+NMDayTime1->DayTimeStr);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NMDayTime1InvalidHost(bool &Handled)
{
   AnsiString NewHost;
   if(InputQuery("无效的地址!","请指定一个新的地址:",NewHost))
   {
       EdtSpyAddress->Text=NewHost;
       NMDayTime1->Host=NewHost;
       Handled=true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BtnTestTimeClick(TObject *Sender)
{
   NMTime1->Host=EdtSpyAddress->Text;
   NMTime1->TimeOut=StrToInt(EdtTimeOut->Text);
   NMTime1->Port=13;
   ShowMessage(AnsiString("当前时间是:")+NMTime1->TimeStr);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NMTime1InvalidHost(bool &Handled)
{
   AnsiString NewHost;
   if(InputQuery("无效的地址!","请指定一个新的地址:",NewHost))
   {
       EdtSpyAddress->Text=NewHost;
       NMTime1->Host=NewHost;
       Handled=true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    delete   m_ResultStream;
    delete   m_TempStream;    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnCaptureClick(TObject *Sender)
{
   int length;
   m_sCommand="Show,"+EdtCaptureSize->Text.Trim()+AnsiString(",");
   m_ResultStream->Clear();
   m_TempStream->Clear();
   SUDP->RemoteHost=EdtSpyAddress->Text;
   m_sCommand=m_sCommand.Trim();
   SUDP->SendBuffer(m_sCommand.c_str(),strlen(m_sCommand.c_str()),strlen(m_sCommand.c_str()));
   TDateTime NowTime;
   NowTime=Now();
   LabelTime->Caption=NowTime.DateTimeString();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SUDPDataReceived(TComponent *Sender,
      int NumberBytes, AnsiString FromIP, int Port)
{
   int number;
   AnsiString sTemp;
   SUDP->ReadStream(m_TempStream);
   m_ResultStream->CopyFrom(m_TempStream,NumberBytes);
   sTemp.sprintf("已经接收的数据量:%d",number);
   StatusBar1->Panels->Items[0]->Text=sTemp;
   if(NumberBytes<m_BufferSize)
   {
       sTemp.sprintf("已经接收的数据量:%d",m_ResultStream->Size);
       StatusBar1->Panels->Items[0]->Text=sTemp;
       m_ResultStream->Position=0;
       Image1->Picture->Bitmap->LoadFromStream(m_ResultStream);
       m_ResultStream->Clear();
       m_TempStream->Clear();
   }
   else
   {
        MainForm->Caption="IS Receiveing";
        m_TempStream->Clear();
        m_sCommand="Show,";
        SUDP->RemoteHost=EdtSpyAddress->Text ;
        SUDP->SendBuffer(m_sCommand.c_str(),strlen(m_sCommand.c_str()),strlen(m_sCommand.c_str()));
   }

}

//---------------------------------------------------------------------------


void TMainForm::GetCaptureSize(void)
{
    AnsiString sTempStr;
    AnsiString sPosStr;
    int pos;
    int iLength;
    sTempStr=EdtCaptureSize->Text+AnsiString(",");
   // iLength=sTempStr.Length();
    for(int i=0;i<4;i++)
    {
        sTempStr=sTempStr.Trim();
        pos=sTempStr.Pos(",");
        sPosStr=sTempStr.SubString(1,pos-1);
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
         sTempStr=sTempStr.SubString(pos+1,iLength-pos);
    }
}

void __fastcall TMainForm::BtnCloseClientClick(TObject *Sender)
{
    m_sCommand="Close,";
    SUDP->RemoteHost=EdtSpyAddress->Text;
    m_sCommand=m_sCommand.Trim();
    SUDP->SendBuffer(m_sCommand.c_str(),strlen(m_sCommand.c_str()),strlen(m_sCommand.c_str()));
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::BtnSetCaptureRecClick(TObject *Sender)
{
   AnsiString sTemp;
   InputQuery("设置截取区域:","0,0,100,100",sTemp);
   EdtCaptureSize->Text=sTemp;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
    BtnCaptureClick(this);
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::ChkBoxAutoCaptureClick(TObject *Sender)
{
   if(ChkBoxAutoCapture->Checked)
        Timer1->Enabled=true;
   else
        Timer1->Enabled=false;
}
//---------------------------------------------------------------------------

