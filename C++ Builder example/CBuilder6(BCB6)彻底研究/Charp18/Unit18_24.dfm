object WebDataModule4: TWebDataModule4
  OldCreateOrder = False
  Left = 190
  Top = 23
  Height = 193
  Width = 253
  object Session1: TSession
    Active = True
    AutoSessionName = True
    Left = 184
    Top = 32
  end
  object Table1: TTable
    Active = True
    DatabaseName = 'BCDEMOS'
    SessionName = 'Session1_2'
    TableName = 'employee.db'
    Left = 32
    Top = 32
  end
  object DataSetAdapter1: TDataSetAdapter
    DataSet = Table1
    Left = 104
    Top = 104
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
      object AdaptEmpNo: TDataSetAdapterField
        DataSetField = 'EmpNo'
      end
      object AdaptLastName: TDataSetAdapterField
        DataSetField = 'LastName'
      end
      object AdaptFirstName: TDataSetAdapterField
        DataSetField = 'FirstName'
      end
      object AdaptPhoneExt: TDataSetAdapterField
        DataSetField = 'PhoneExt'
      end
      object AdaptHireDate: TDataSetAdapterField
        DataSetField = 'HireDate'
      end
      object AdaptSalary: TDataSetAdapterField
        DataSetField = 'Salary'
      end
    end
  end
end
