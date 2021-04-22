//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef Unit10_42H
#define Unit10_42H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\DBTables.hpp>
#include <vcl\DB.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------

// Declare constants we're interested in.
//
const int eKeyViol = 9729;
const int eRequiredFieldMissing = 9732;
const int eForeignKey = 9733;
const int eDetailsExist = 9734;

class TDM : public TDataModule
{
__published:	// IDE-managed Components 
        TTable *Customer;
        TFloatField *CustomerCustNo;
        TStringField *CustomerCompany;
        TDataSource *CustomerSource;
        TTable *Orders;
        TFloatField *OrdersOrderNo;
        TFloatField *OrdersCustNo;
        TDateTimeField *OrdersSaleDate;
        TDateTimeField *OrdersShipDate;
        TIntegerField *OrdersEmpNo;
        TDataSource *OrdersSource;
        TTable *Items;
        TFloatField *ItemsOrderNo;
        TFloatField *ItemsItemNo;
        TFloatField *ItemsPartNo;
        TIntegerField *ItemsQty;
        TFloatField *ItemsDiscount;
        TDataSource *ItemsSource;
        void __fastcall CustomerPostError(TDataSet *DataSet,
           EDatabaseError *E, TDataAction &Action);
        void __fastcall CustomerDeleteError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action);
        void __fastcall CustomerCustNoChange(TField *Sender);
        void __fastcall CustomerAfterPost(TDataSet *DataSet);
        
        void __fastcall OrdersPostError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action);
        void __fastcall ItemsPostError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action);
        void __fastcall OrdersDeleteError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action);
private:	// User declarations
public:		// User declarations
        virtual __fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TDM *DM;
//---------------------------------------------------------------------------
#endif
