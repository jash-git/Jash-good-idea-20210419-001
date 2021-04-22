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
   m_sHostAddress="127.0.0.1";
   ClientSocket1->Active=false;
   ClientSocket1->Address=m_sHostAddress;
   ClientSocket1->Port=50;
   m_sSpeakTo="ALL";
   m_sIsName="NA";
   m_sIsChat="CT";
   m_sPart="#";
   m_HasConnected=false;
   TDateTime NowTime;
   NowTime=Now();
   StatusBar1->Panels->Items[2]->Text=NowTime.DateTimeString();;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClientSocket1Connecting(TObject *Sender,
      TCustomWinSocket *Socket)
{
    StatusBar1->Panels->Items[1]->Text="正在连接，请稍后....";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuConnectClick(TObject *Sender)
{

   InputQuery("请输入您的用户名", "用户名：", m_sName);
   if(m_sName.IsEmpty())
   {
      ShowMessage("您以无名小子登录");
      m_sName="无名小子";
    }
   if(ClientSocket1->Active==false)
         ClientSocket1->Open();
   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
   Socket->SendText(m_sIsName+m_sName);
   AnsiString  sTemp;
   sTemp.sprintf("%s登录成功！",m_sName);
   StatusBar1->Panels->Items[1]->Text=sTemp;
   LabelNotice->Caption=m_sName+AnsiString("对所有人说....");
   m_HasConnected=true;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{

     AnsiString sInfo;
     AnsiString sType;
     AnsiString sChat;
     sInfo=Socket->ReceiveText() ;
     sType=sInfo.SubString(1,2);
     if(sInfo==AnsiString("CLEAR"))
        ListUser->Items->Clear();
     else
     {
        if(sType!=m_sIsChat)
        {
           if(sInfo!=m_sName)
                LabelNotice->Caption="喂！新朋友来了！";
           ListUser->Items->Add(sInfo);
        }
        else
        {
            sChat=sInfo.SubString(4,sInfo.Length()-3);
            MemoReceive->Lines->Add(sChat);
        }    
     }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    ErrorCode=0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ListUserClick(TObject *Sender)
{
    if(m_HasConnected)
    {
        AnsiString  sTemp;
        if(m_sName==ListUser->Items->Strings[ListUser->ItemIndex])
        {
            LabelNotice->Caption="不是吧！要和自己说话？";
        }
        else
        {
            sTemp.sprintf("%s对%s说....",m_sName,ListUser->Items->Strings[ListUser->ItemIndex]);
            m_sSpeakTo=ListUser->Items->Strings[ListUser->ItemIndex];
            LabelNotice->Caption=sTemp;
        }
      }
      else
      {
         ShowMessage("对不起！请登录先！");
      }   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EdtSendKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if(Key==VK_RETURN)
    {
        AnsiString sTemp;
        sTemp=m_sIsChat+m_sSpeakTo+m_sPart+EdtSend->Text;
        sTemp+=AnsiString("( ")+m_sName+AnsiString("说: )");
        ClientSocket1->Socket->SendText(sTemp);
        EdtSend->Clear();
        Key=0;
    }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnToAllClick(TObject *Sender)
{
     if(m_HasConnected)
     {
        AnsiString sTemp;
        m_sSpeakTo="ALL";
        sTemp.sprintf("%s对%s说....",m_sName,"所有人");
        LabelNotice->Caption=sTemp;
      }
      else
      {
         ShowMessage("对不起！请登录先！");
      }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    StatusBar1->Panels->Items[1]->Text="服务器已经断开了连接！";
    ListUser->Items->Clear();
    LabelNotice->Caption="呜呜 :o  被断开了！";
    m_HasConnected=false;
    MemoReceive->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuDisconnectClick(TObject *Sender)
{
   if(ClientSocket1->Socket->Connected)
       ClientSocket1->Socket->Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuSetClick(TObject *Sender)
{
   AnsiString  sIp;
   InputQuery("输入框","输入服务器的IP",sIp);
   if(!sIp.IsEmpty())
   {
      m_sHostAddress=sIp;
      ClientSocket1->Address=m_sHostAddress;
   }
}
//---------------------------------------------------------------------------

