object Form1: TForm1
  Left = 238
  Top = 144
  Width = 679
  Height = 553
  Caption = 'TXMLDocument'#32452#20214#30340#24212#29992
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 145
    Height = 25
    Caption = #25226#25968#25454#34920#36716#25104'XML'#25991#20214
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 40
    Width = 321
    Height = 473
    TabOrder = 1
  end
  object TreeView1: TTreeView
    Left = 336
    Top = 40
    Width = 329
    Height = 473
    Indent = 19
    TabOrder = 2
  end
  object Button2: TButton
    Left = 336
    Top = 8
    Width = 169
    Height = 25
    Caption = #25226'XML'#25991#20214#35835#21040'TreeView'#32452#20214#20013
    TabOrder = 3
    OnClick = Button2Click
  end
  object Table1: TTable
    DatabaseName = 'BCDEMOS'
    TableName = 'employee.db'
    Left = 168
    Top = 8
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 248
    Top = 8
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Table1
    Constraints = True
    Left = 208
    Top = 8
  end
  object XMLDocument1: TXMLDocument
    Left = 288
    Top = 8
    DOMVendorDesc = 'MSXML'
  end
end
