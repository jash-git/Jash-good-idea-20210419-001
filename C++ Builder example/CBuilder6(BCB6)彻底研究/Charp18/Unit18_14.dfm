object Grid: TGrid
  OldCreateOrder = False
  PageProducer = AdapterPageProducer
  Left = 143
  Top = 4
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
      object AdapterGrid1: TAdapterGrid
        Adapter = WebDataModule1.DataSetAdapter1
        object ColSpeciesNo: TAdapterDisplayColumn
          Caption = 'Species No'
          FieldName = 'SpeciesNo'
        end
        object ColCategory: TAdapterDisplayColumn
          FieldName = 'Category'
        end
        object ColCommon_Name: TAdapterDisplayColumn
          FieldName = 'Common_Name'
        end
        object ColSpeciesName: TAdapterDisplayColumn
          Caption = 'Species Name'
          FieldName = 'SpeciesName'
        end
        object ColLengthcm: TAdapterDisplayColumn
          Caption = 'Length (cm)'
          FieldName = 'Lengthcm'
        end
        object ColLength_In: TAdapterDisplayColumn
          FieldName = 'Length_In'
        end
        object ColGraphic: TAdapterDisplayColumn
          FieldName = 'Graphic'
        end
        object AdapterCommandColumn1: TAdapterCommandColumn
          object CmdEditRow: TAdapterActionButton
            ActionName = 'EditRow'
            PageName = 'Modify'
          end
        end
      end
    end
  end
end
