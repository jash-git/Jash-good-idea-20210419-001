object WebDataModule1: TWebDataModule1
  OldCreateOrder = False
  Left = 394
  Top = 65535
  Height = 109
  Width = 323
  object Session1: TSession
    Active = True
    AutoSessionName = True
    Left = 240
    Top = 16
  end
  object Table1: TTable
    Active = True
    DatabaseName = 'BCDEMOS'
    SessionName = 'Session1_2'
    TableName = 'biolife.db'
    Left = 152
    Top = 16
  end
  object DataSetAdapter1: TDataSetAdapter
    DataSet = Table1
    Left = 56
    Top = 16
    object TAdapterDefaultActions
      object ActionDeleteRow: TDataSetAdapterDeleteRowAction
      end
      object ActionFirstRow: TDataSetAdapterFirstRowAction
      end
      object ActionPrevRow: TDataSetAdapterPrevRowAction
      end
      object ActionNextRow: TDataSetAdapterNextRowAction
      end
      object ActionLastRow: TDataSetAdapterLastRowAction
      end
      object ActionEditRow: TDataSetAdapterEditRowAction
      end
      object ActionBrowseRow: TDataSetAdapterBrowseRowAction
      end
      object ActionNewRow: TDataSetAdapterNewRowAction
      end
      object ActionCancel: TDataSetAdapterCancelRowAction
      end
      object ActionApply: TDataSetAdapterApplyRowAction
      end
      object ActionRefreshRow: TDataSetAdapterRefreshRowAction
      end
    end
    object TAdapterDefaultFields
      object AdaptSpeciesNo: TDataSetAdapterField
        DataSetField = 'Species No'
      end
      object AdaptCategory: TDataSetAdapterField
        DataSetField = 'Category'
      end
      object AdaptCommon_Name: TDataSetAdapterField
        DataSetField = 'Common_Name'
      end
      object AdaptSpeciesName: TDataSetAdapterField
        DataSetField = 'Species Name'
      end
      object AdaptLengthcm: TDataSetAdapterField
        DataSetField = 'Length (cm)'
      end
      object AdaptLength_In: TDataSetAdapterField
        DataSetField = 'Length_In'
      end
      object AdaptGraphic: TDataSetAdapterImageField
        DataSetField = 'Graphic'
        FieldModes = [amInsert, amEdit, amBrowse]
      end
    end
  end
end
