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
    StatusBar1->Panels->Items[1]->Text="�������ӣ����Ժ�....";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuConnectClick(TObject *Sender)
{

   InputQuery("�����������û���", "�û�����", m_sName);
   if(m_sName.IsEmpty())
   {
      ShowMessage("��������С�ӵ�¼");
      m_sName="����С��";
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
   sTemp.sprintf("%s��¼�ɹ���",m_sName);
   StatusBar1->Panels->Items[1]->Text=sTemp;
   LabelNotice->Caption=m_sName+AnsiString("��������˵....");
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
                LabelNotice->Caption="ι�����������ˣ�";
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
            LabelNotice->Caption="���ǰɣ�Ҫ���Լ�˵����";
        }
        else
        {
            sTemp.sprintf("%s��%s˵....",m_sName,ListUser->Items->Strings[ListUser->ItemIndex]);
            m_sSpeakTo=ListUser->Items->Strings[ListUser->ItemIndex];
            LabelNotice->Caption=sTemp;
        }
      }
      else
      {
         ShowMessage("�Բ������¼�ȣ�");
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
        sTemp+=AnsiString("( ")+m_sName+AnsiString("˵: )");
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
        sTemp.sprintf("%s��%s˵....",m_sName,"������");
        LabelNotice->Caption=sTemp;
      }
      else
      {
         ShowMessage("�Բ������¼�ȣ�");
      }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    StatusBar1->Panels->Items[1]->Text="�������Ѿ��Ͽ������ӣ�";
    ListUser->Items->Clear();
    LabelNotice->Caption="���� :o  ���Ͽ��ˣ�";
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
   InputQuery("�����","�����������IP",sIp);
   if(!sIp.IsEmpty())
   {
      m_sHostAddress=sIp;
      ClientSocket1->Address=m_sHostAddress;
   }
}
//---------------------------------------------------------------------------

