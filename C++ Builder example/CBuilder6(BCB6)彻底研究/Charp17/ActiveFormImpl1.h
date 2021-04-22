//$$---- Active Form HDR ---- (stActiveFormHdr)
//---------------------------------------------------------------------------


#ifndef ActiveFormImpl1H
#define ActiveFormImpl1H
//---------------------------------------------------------------------------
#include <classes.hpp>
#include <controls.hpp>
#include <stdCtrls.hpp>
#include <forms.hpp>
#include "ActiveFormProj1_TLB.h"
#include <AxCtrls.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class TActiveFormX : public TActiveForm
{
__published:	// IDE-managed Components
        TListBox *ListBox1;
        TEdit *Edit1;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TActiveFormX(HWND ParentWindow);
    __fastcall TActiveFormX(TComponent* AOwner): TActiveForm(AOwner) {};
};
//---------------------------------------------------------------------------
extern PACKAGE TActiveFormX *ActiveFormX;
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
class ATL_NO_VTABLE TActiveFormXImpl:
  VCLCONTROL_IMPL(TActiveFormXImpl, ActiveFormX, TActiveFormX, IActiveFormX, DIID_IActiveFormXEvents)
{
  void __fastcall ActivateEvent(TObject *Sender);
  void __fastcall ClickEvent(TObject *Sender);
  void __fastcall CreateEvent(TObject *Sender);
  void __fastcall DblClickEvent(TObject *Sender);
  void __fastcall DeactivateEvent(TObject *Sender);
  void __fastcall DestroyEvent(TObject *Sender);
  void __fastcall KeyPressEvent(TObject *Sender, char &Key);
  void __fastcall PaintEvent(TObject *Sender);
public:

  void InitializeControl()
  {
    m_VclCtl->OnActivate = ActivateEvent;
    m_VclCtl->OnClick = ClickEvent;
    m_VclCtl->OnCreate = CreateEvent;
    m_VclCtl->OnDblClick = DblClickEvent;
    m_VclCtl->OnDeactivate = DeactivateEvent;
    m_VclCtl->OnDestroy = DestroyEvent;
    m_VclCtl->OnKeyPress = KeyPressEvent;
    m_VclCtl->OnPaint = PaintEvent;
  }

// The COM MAP entries declares the interfaces your object exposes (through
// QueryInterface). CComRootObjectEx::InternalQueryInterface only returns
// pointers for interfaces in the COM map. VCL controls exposed as OCXes
// have a minimum set of interfaces defined by the
// VCL_CONTROL_COM_INTERFACE_ENTRIES macro. Add other interfaces supported
// by your object with additional COM_INTERFACE_ENTRY[_xxx] macros.
//
BEGIN_COM_MAP(TActiveFormXImpl)
  VCL_CONTROL_COM_INTERFACE_ENTRIES(IActiveFormX)
END_COM_MAP()



// The PROPERTY map stores property descriptions, property DISPIDs,
// property page CLSIDs and IDispatch IIDs. You may use use
// IPerPropertyBrowsingImpl, IPersistPropertyBagImpl, IPersistStreamInitImpl,
// and ISpecifyPropertyPageImpl to utilize the information in you property
// map.
//
// NOTE: The BCB Wizard does *NOT* maintain your PROPERTY_MAP table. You must
//       add or remove entries manually.
//
BEGIN_PROPERTY_MAP(TActiveFormXImpl)
  // PROP_PAGE(CLSID_ActiveFormXPage)
END_PROPERTY_MAP()

/* DECLARE_VCL_CONTROL_PERSISTENCE(CppClass, VclClass) is needed for VCL
 * controls to persist via the VCL streaming mechanism and not the ATL mechanism.
 * The macro adds static IPersistStreamInit_Load and IPersistStreamInit_Save
 * methods to your implementation class, overriding the methods in IPersistStreamImpl. 
 * This macro must be manually undefined or removed if you port to C++Builder 4.0. */

DECLARE_VCL_CONTROL_PERSISTENCE(TActiveFormXImpl, TActiveFormX);

// The DECLARE_ACTIVEXCONTROL_REGISTRY macro declares a static 'UpdateRegistry' 
// routine which registers the basic information about your control. The
// parameters expected by the macro are the ProgId & the ToolboxBitmap ID of
// your control.
//
DECLARE_ACTIVEXCONTROL_REGISTRY("ActiveFormProj1.ActiveFormX", 1);

protected: 
  STDMETHOD(_set_Font(IFontDisp** Value));
  STDMETHOD(get_Active(VARIANT_BOOL* Value));
  STDMETHOD(get_AlignDisabled(VARIANT_BOOL* Value));
  STDMETHOD(get_AutoScroll(VARIANT_BOOL* Value));
  STDMETHOD(get_AutoSize(VARIANT_BOOL* Value));
  STDMETHOD(get_AxBorderStyle(TxActiveFormBorderStyle* Value));
  STDMETHOD(get_BorderWidth(long* Value));
  STDMETHOD(get_Caption(BSTR* Value));
  STDMETHOD(get_Color(::OLE_COLOR* Value));
  STDMETHOD(get_DoubleBuffered(VARIANT_BOOL* Value));
  STDMETHOD(get_DropTarget(VARIANT_BOOL* Value));
  STDMETHOD(get_Enabled(VARIANT_BOOL* Value));
  STDMETHOD(get_Font(IFontDisp** Value));
  STDMETHOD(get_HelpFile(BSTR* Value));
  STDMETHOD(get_KeyPreview(VARIANT_BOOL* Value));
  STDMETHOD(get_PixelsPerInch(long* Value));
  STDMETHOD(get_PrintScale(TxPrintScale* Value));
  STDMETHOD(get_Scaled(VARIANT_BOOL* Value));
  STDMETHOD(get_Visible(VARIANT_BOOL* Value));
  STDMETHOD(get_VisibleDockClientCount(long* Value));
  STDMETHOD(set_AutoScroll(VARIANT_BOOL Value));
  STDMETHOD(set_AutoSize(VARIANT_BOOL Value));
  STDMETHOD(set_AxBorderStyle(TxActiveFormBorderStyle Value));
  STDMETHOD(set_BorderWidth(long Value));
  STDMETHOD(set_Caption(BSTR Value));
  STDMETHOD(set_Color(::OLE_COLOR Value));
  STDMETHOD(set_DoubleBuffered(VARIANT_BOOL Value));
  STDMETHOD(set_DropTarget(VARIANT_BOOL Value));
  STDMETHOD(set_Enabled(VARIANT_BOOL Value));
  STDMETHOD(set_Font(IFontDisp* Value));
  STDMETHOD(set_HelpFile(BSTR Value));
  STDMETHOD(set_KeyPreview(VARIANT_BOOL Value));
  STDMETHOD(set_PixelsPerInch(long Value));
  STDMETHOD(set_PrintScale(TxPrintScale Value));
  STDMETHOD(set_Scaled(VARIANT_BOOL Value));
  STDMETHOD(set_Visible(VARIANT_BOOL Value));
};
//---------------------------------------------------------------------------
#endif
