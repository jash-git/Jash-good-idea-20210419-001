//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
typedef struct
{
        Byte Blue;
        Byte Green;
        Byte Red;
} RGBCOLOR;


class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TButton *btnCreate;
        TButton *btnSave;
        void __fastcall btnCreateClick(TObject *Sender);
        void __fastcall btnSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
