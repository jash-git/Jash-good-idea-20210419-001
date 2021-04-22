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
    ServerSocket1->Port=50;
    ServerSocket1->Active=true;
    m_iClientNum=0;
    m_sIsName="NA";
    m_sIsChat="CT";
    m_sPart="#";
    m_sIsCommand="CO";
    m_sTo="ALL";
    MenuListen->Enabled=false;
    MenuClose->Enabled=true;
    Application->OnException=AppException;
    TDateTime NowTime;
    NowTime=Now();
    StatusBar1->Panels->Items[2]->Text=NowTime.DateTimeString();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ServerSocket1Accept(TObject *Sender,
      TCustomWinSocket *Socket)
{
   AnsiString sClientNum;
   m_iClientNum++;
   sClientNum.sprintf("有%d台客户连接",ServerSocket1->Socket->ActiveConnections);
   StatusBar1->Panels->Items[1]->Text="连接成功！";

   StatusBar1->Panels->Items[0]->Text=sClientNum;
   ListUserAddr->Items->Add(Socket->RemoteAddress);
   for(int i=0;i<ServerSocket1->Socket->ActiveConnections;i++)
       ServerSocket1->Socket->Connections[i]->SendText("CLEAR");

   Sleep(100);
   
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
     AnsiString sTemp;
     AnsiString sPre;
     AnsiString sWelcome;
     sTemp=Socket->ReceiveText();
     sPre=sTemp.SubString(1,2);
     if(sPre==m_sIsName)
     {
        AnsiString sName;
        sName=sTemp.SubString(3,sTemp.Length()-2);
        ListUserName->Items->Add(sName);
        for(int i=0;i<ServerSocket1->Socket->ActiveConnections;i++)
        {
            for(int j=0;j<ListUserName->Items->Count;j++)
            {
                AnsiString sName;
                sName=ListUserName->Items->Strings[j];
                ServerSocket1->Socket->Connections[i]->SendText(sName);
                Sleep(10);
            }
            sWelcome=m_sIsChat+m_sPart;
            sWelcome+=AnsiString("大家欢迎(")+sName+AnsiString(") :) 的光临！( 服务器说:)");
            ServerSocket1->Socket->Connections[i]->SendText(sWelcome);
         }

     }
     if(sPre==m_sIsChat)
     {
        AnsiString sTo,sChat;
        int iPos;
        iPos=sTemp.Pos(m_sPart);
        sTo=sTemp.SubString(3,iPos-3);
        sChat=m_sIsChat+sTemp.SubString(iPos,sTemp.Length()-iPos+1);
        if(sTo==AnsiString("ALL") )
           for(int i=0;i<ServerSocket1->Socket->ActiveConnections;i++)
                ServerSocket1->Socket->Connections[i]->SendText(sChat);
        if(sTo!=AnsiString("ALL") )
        {
           int iIndex=ListUserName->Items->IndexOf(sTo);
           ServerSocket1->Socket->Connections[iIndex]->SendText(sChat);
        }

     }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AppException(TObject *Sender, Exception *E)

{
    Application->ShowException(E);
    Application->Terminate();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::ServerSocket1ClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    AnsiString sTemp;
    sTemp.sprintf("%s断开连接！",Socket->RemoteAddress);
    StatusBar1->Panels->Items[1]->Text=sTemp;
    int iIndex;
    iIndex=ListUserAddr->Items->IndexOf(Socket->RemoteAddress);
    ListUserAddr->Items->Delete(iIndex);
    ListUserName->Items->Delete(iIndex);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
     ErrorCode=0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EdtSendKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key==VK_RETURN)
   {
       AnsiString sTemp;
       sTemp=m_sIsChat+m_sPart+EdtSend->Text+AnsiString("(服务器说:)");
       if(m_sTo==AnsiString("ALL") )
           for(int i=0;i<ServerSocket1->Socket->ActiveConnections;i++)
                ServerSocket1->Socket->Connections[i]->SendText(sTemp);
        if(m_sTo!=AnsiString("ALL") )
        {
           int iIndex=ListUserName->Items->IndexOf(m_sTo);
           ServerSocket1->Socket->Connections[iIndex]->SendText(sTemp);
        }
        EdtSend->Clear();

    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ListUserNameClick(TObject *Sender)
{
    m_sTo=ListUserName->Items->Strings[ListUserName->ItemIndex];
    LabelNotice->Caption=AnsiString("向")+m_sTo+AnsiString("发信息！");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnToAllClick(TObject *Sender)
{
    m_sTo="ALL";
    LabelNotice->Caption="向所有人发信息";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuDisConnectClick(TObject *Sender)
{
    if(m_sTo=="ALL")
    {
       AnsiString  sTemp;
       sTemp.sprintf("真的要断开与%s的连接吗？","所有人");
       if(MessageDlg(sTemp, mtConfirmation,
                      TMsgDlgButtons() << mbYes << mbNo, 0) ==mrYes)
           for(int i=0;i<ServerSocket1->Socket->ActiveConnections;i++)
                ServerSocket1->Socket->Connections[i]->Close();
    }
     if(m_sTo!="ALL")
     {
        AnsiString  sTemp;
        sTemp.sprintf("真的要断开与%s的连接吗？",m_sTo);
        if(MessageDlg(sTemp, mtConfirmation,
                      TMsgDlgButtons() << mbYes << mbNo, 0) ==mrYes)
        {
               int iIndex=ListUserName->Items->IndexOf(m_sTo);
                ServerSocket1->Socket->Connections[iIndex]->Close();
        }
     }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuCloseClick(TObject *Sender)
{
   if(ServerSocket1->Active)
        ServerSocket1->Close();
   MenuListen->Enabled=true;
   MenuClose->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuListenClick(TObject *Sender)
{
   if(!ServerSocket1->Active)
        ServerSocket1->Open();
   MenuListen->Enabled=false;
   MenuClose->Enabled=true;
}
//---------------------------------------------------------------------------


