//$$---- Active Form CPP ---- (stActiveFormSource)
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <atl\atlvcl.h>

#include "ActiveFormImpl1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TActiveFormX *ActiveFormX;
//---------------------------------------------------------------------------
__fastcall TActiveFormX::TActiveFormX(HWND ParentWindow)
        : TActiveForm(ParentWindow)
{
}
//---------------------------------------------------------------------------

STDMETHODIMP TActiveFormXImpl::_set_Font(IFontDisp** Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_Active(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Active;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_AlignDisabled(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->AlignDisabled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_AutoScroll(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->AutoScroll;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_AutoSize(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->AutoSize;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_AxBorderStyle(
  TxActiveFormBorderStyle* Value)
{
  try
  {
   *Value = (TxActiveFormBorderStyle)(m_VclCtl->AxBorderStyle);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_BorderWidth(long* Value)
{
  try
  {
   *Value = (long)(m_VclCtl->BorderWidth);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_Caption(BSTR* Value)
{
  try
  {
    *Value = WideString(m_VclCtl->Caption).Copy();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_Color(::OLE_COLOR* Value)
{
  try
  {
   *Value = (::OLE_COLOR)(m_VclCtl->Color);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_DoubleBuffered(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->DoubleBuffered;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_DropTarget(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->DropTarget;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_Enabled(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Enabled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_Font(IFontDisp** Value)
{
  try
  {
    GetVclCtlProp(m_VclCtl->Font, Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_HelpFile(BSTR* Value)
{
  try
  {
    *Value = WideString(m_VclCtl->HelpFile).Copy();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_KeyPreview(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->KeyPreview;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_PixelsPerInch(long* Value)
{
  try
  {
   *Value = (long)(m_VclCtl->PixelsPerInch);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_PrintScale(TxPrintScale* Value)
{
  try
  {
   *Value = (TxPrintScale)(m_VclCtl->PrintScale);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_Scaled(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Scaled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_Visible(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Visible;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::get_VisibleDockClientCount(long* Value)
{
  try
  {
   *Value = (long)(m_VclCtl->VisibleDockClientCount);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_AutoScroll(VARIANT_BOOL Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_AutoSize(VARIANT_BOOL Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_AxBorderStyle(
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_BorderWidth(long Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_Caption(BSTR Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_Color(::OLE_COLOR Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_DoubleBuffered(VARIANT_BOOL Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_DropTarget(VARIANT_BOOL Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_Enabled(VARIANT_BOOL Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_Font(IFontDisp* Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_HelpFile(BSTR Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_KeyPreview(VARIANT_BOOL Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_PixelsPerInch(long Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_PrintScale(TxPrintScale Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_Scaled(VARIANT_BOOL Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};


STDMETHODIMP TActiveFormXImpl::set_Visible(VARIANT_BOOL Value)
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
    return Error(e.Message.c_str(), IID_IActiveFormX);
  }
  return S_OK;
};



void __fastcall TActiveFormXImpl::ActivateEvent(TObject *Sender)
{
  Fire_OnActivate();
}


void __fastcall TActiveFormXImpl::ClickEvent(TObject *Sender)
{
  Fire_OnClick();
}


void __fastcall TActiveFormXImpl::CreateEvent(TObject *Sender)
{
  Fire_OnCreate();
}


void __fastcall TActiveFormXImpl::DblClickEvent(TObject *Sender)
{
  Fire_OnDblClick();
}


void __fastcall TActiveFormXImpl::DeactivateEvent(TObject *Sender)
{
  Fire_OnDeactivate();
}


void __fastcall TActiveFormXImpl::DestroyEvent(TObject *Sender)
{
  Fire_OnDestroy();
}


void __fastcall TActiveFormXImpl::KeyPressEvent(TObject *Sender, char &Key)
{
  short TempKey;
  TempKey = (short)Key;
  Fire_OnKeyPress(&TempKey);
  Key = (short)TempKey;
}


void __fastcall TActiveFormXImpl::PaintEvent(TObject *Sender)
{
  Fire_OnPaint();
}



void __fastcall TActiveFormX::Button1Click(TObject *Sender)
{
  ListBox1->Items->Add(Edit1->Text);        
}
//---------------------------------------------------------------------------
 