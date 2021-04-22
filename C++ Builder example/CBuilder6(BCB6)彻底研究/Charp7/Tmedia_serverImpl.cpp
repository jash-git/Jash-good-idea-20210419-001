// TMEDIA_SERVERIMPL : Implementation of TTmedia_serverImpl (CoClass: Tmedia_server, Interface: ITmedia_server)

#include <vcl.h>
#pragma hdrstop

#include "TMEDIA_SERVERIMPL.H"
#include "Unit7_h.h"
Variant FileNameString;
/////////////////////////////////////////////////////////////////////////////
// TTmedia_serverImpl

STDMETHODIMP TTmedia_serverImpl::get_FileStr(VARIANT* Value)
{
  try
  {
    *Value=Variant(FileNameString);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ITmedia_server);
  }
  return S_OK;
};


STDMETHODIMP TTmedia_serverImpl::set_FileStr(VARIANT Value)
{
  try
  {
    FileNameString=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ITmedia_server);
  }
  return S_OK;
};


STDMETHODIMP TTmedia_serverImpl::OpenFile()
{
  Form1->MediaPlayer1->FileName = FileNameString;


  Form1->MediaPlayer1->Open();


  Form1->MediaPlayer1->Display = Form1->Panel1;
  Form1->MediaPlayer1->DisplayRect =
    Rect(2,2, Form1->Panel1->Width-4, Form1->Panel1->Height-4);


  Form1->MediaPlayer1->Play();

}


STDMETHODIMP TTmedia_serverImpl::PlayFile()
{
  Form1->MediaPlayer1->Play();

}


STDMETHODIMP TTmedia_serverImpl::StopFile()
{
  Form1->MediaPlayer1->Stop();

}

