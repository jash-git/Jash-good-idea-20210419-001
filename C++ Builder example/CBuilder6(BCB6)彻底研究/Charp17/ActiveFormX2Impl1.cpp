//$$---- Active Form CPP ---- (stActiveFormSource)
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <atl\atlvcl.h>

#include "ActiveFormX2Impl1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TActiveFormX2 *ActiveFormX2;
//---------------------------------------------------------------------------
__fastcall TActiveFormX2::TActiveFormX2(HWND ParentWindow)
        : TActiveForm(ParentWindow)
{
}
//---------------------------------------------------------------------------

STDMETHODIMP TActiveFormX2Impl::_set_Font(IFontDisp** Value)
{
  try
  {
    const DISPID dispid = -512;
    if (FireOnRequestEdit(dispid) == S_FALSE)
      return S_FALSE;
    SetVclCtlProp(m_VclCtl->Font, Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_Active(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Active;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_AlignDisabled(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->AlignDisabled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_AutoScroll(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->AutoScroll;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_AutoSize(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->AutoSize;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_AxBorderStyle(
  TxActiveFormBorderStyle* Value)
{
  try
  {
   *Value = (TxActiveFormBorderStyle)(m_VclCtl->AxBorderStyle);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_BorderWidth(long* Value)
{
  try
  {
   *Value = (long)(m_VclCtl->BorderWidth);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_Caption(BSTR* Value)
{
  try
  {
    *Value = WideString(m_VclCtl->Caption).Copy();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_Color(::OLE_COLOR* Value)
{
  try
  {
   *Value = (::OLE_COLOR)(m_VclCtl->Color);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_DoubleBuffered(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->DoubleBuffered;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_DropTarget(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->DropTarget;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_Enabled(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Enabled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_Font(IFontDisp** Value)
{
  try
  {
    GetVclCtlProp(m_VclCtl->Font, Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_HelpFile(BSTR* Value)
{
  try
  {
    *Value = WideString(m_VclCtl->HelpFile).Copy();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_KeyPreview(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->KeyPreview;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_PixelsPerInch(long* Value)
{
  try
  {
   *Value = (long)(m_VclCtl->PixelsPerInch);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_PrintScale(TxPrintScale* Value)
{
  try
  {
   *Value = (TxPrintScale)(m_VclCtl->PrintScale);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_Scaled(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Scaled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_Visible(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Visible;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::get_VisibleDockClientCount(long* Value)
{
  try
  {
   *Value = (long)(m_VclCtl->VisibleDockClientCount);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_AutoScroll(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 2;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->AutoScroll = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_AutoSize(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 3;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->AutoSize = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_AxBorderStyle(
  TxActiveFormBorderStyle Value)
{
  try
  {
    const DISPID dispid = 4;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->AxBorderStyle = (TActiveFormBorderStyle)(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_BorderWidth(long Value)
{
  try
  {
    const DISPID dispid = 5;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->BorderWidth = (int)(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_Caption(BSTR Value)
{
  try
  {
    const DISPID dispid = -518;
    if (FireOnRequestEdit(dispid) == S_FALSE)
      return S_FALSE;
    m_VclCtl->Caption = AnsiString(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_Color(::OLE_COLOR Value)
{
  try
  {
    const DISPID dispid = -501;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->Color = (TColor)(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_DoubleBuffered(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 13;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->DoubleBuffered = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_DropTarget(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 11;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->DropTarget = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_Enabled(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = -514;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->Enabled = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_Font(IFontDisp* Value)
{
  try
  {
    const DISPID dispid = -512;
    if (FireOnRequestEdit(dispid) == S_FALSE)
      return S_FALSE;
    SetVclCtlProp(m_VclCtl->Font, Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_HelpFile(BSTR Value)
{
  try
  {
    const DISPID dispid = 12;
    if (FireOnRequestEdit(dispid) == S_FALSE)
      return S_FALSE;
    m_VclCtl->HelpFile = AnsiString(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_KeyPreview(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 6;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->KeyPreview = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_PixelsPerInch(long Value)
{
  try
  {
    const DISPID dispid = 7;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->PixelsPerInch = (int)(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_PrintScale(TxPrintScale Value)
{
  try
  {
    const DISPID dispid = 8;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->PrintScale = (TPrintScale)(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_Scaled(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 9;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->Scaled = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormX2Impl::set_Visible(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 1;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->Visible = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX2);
  }
  return S_OK;
};



void __fastcall TActiveFormX2Impl::ActivateEvent(TObject *Sender)
{
  Fire_OnActivate();
}


void __fastcall TActiveFormX2Impl::ClickEvent(TObject *Sender)
{
  Fire_OnClick();
}


void __fastcall TActiveFormX2Impl::CreateEvent(TObject *Sender)
{
  Fire_OnCreate();
}


void __fastcall TActiveFormX2Impl::DblClickEvent(TObject *Sender)
{
  Fire_OnDblClick();
}


void __fastcall TActiveFormX2Impl::DeactivateEvent(TObject *Sender)
{
  Fire_OnDeactivate();
}


void __fastcall TActiveFormX2Impl::DestroyEvent(TObject *Sender)
{
  Fire_OnDestroy();
}


void __fastcall TActiveFormX2Impl::KeyPressEvent(TObject *Sender,
  char &Key)
{
  short TempKey;
  TempKey = (short)Key;
  Fire_OnKeyPress(&TempKey);
  Key = (short)TempKey;
}


void __fastcall TActiveFormX2Impl::PaintEvent(TObject *Sender)
{
  Fire_OnPaint();
}



void __fastcall TActiveFormX2::ActiveFormCreate(TObject *Sender)
{
  SocketConnection1->Connected=True;
  ClientDataSet1->Open();
  SocketConnection1->Connected=False;
}
//---------------------------------------------------------------------------
 