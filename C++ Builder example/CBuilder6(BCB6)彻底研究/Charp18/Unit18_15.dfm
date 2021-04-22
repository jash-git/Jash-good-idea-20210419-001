object Modify: TModify
  OldCreateOrder = False
  PageProducer = AdapterPageProducer
  Left = 206
  Top = 1
  Height = 150
  Width = 215
  object AdapterPageProducer: TAdapterPageProducer
    HTMLDoc.Strings = (
      '<html>'
      '<head>'
      '</head>'
      '<body>'
      '<#STYLES><#WARNINGS><#SERVERSCRIPT>'
      '</body>'
      '</html>')
    Left = 48
    Top = 8
    object AdapterForm1: TAdapterForm
      object AdapterFieldGroup1: TAdapterFieldGroup
        Adapter = WebDataModule1.DataSetAdapter1
        object FldSpeciesNo: TAdapterDisplayField
          Caption = 'Species No'
          DisplayWidth = 10
          FieldName = 'SpeciesNo'
        end
        object FldCategory: TAdapterDisplayField
          DisplayWidth = 15
          FieldName = 'Category'
        end
        object FldCommon_Name: TAdapterDisplayField
          DisplayWidth = 30
          FieldName = 'Common_Name'
        end
        object FldSpeciesName: TAdapterDisplayField
          Caption = 'Species Name'
          DisplayWidth = 40
          FieldName = 'SpeciesName'
        end
        object FldLengthcm: TAdapterDisplayField
          Caption = 'Length (cm)'
          DisplayWidth = 10
          FieldName = 'Lengthcm'
        end
        object FldLength_In: TAdapterDisplayField
          DisplayWidth = 10
          FieldName = 'Length_In'
        end
      end
      object AdapterCommandGroup1: TAdapterCommandGroup
        DisplayComponent = AdapterFieldGroup1
      end
    end
  end
end
