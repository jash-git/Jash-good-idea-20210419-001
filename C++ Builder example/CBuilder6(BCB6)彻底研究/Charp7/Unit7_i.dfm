object Form1: TForm1
  Left = 247
  Top = 417
  Width = 538
  Height = 261
  Caption = #21521'OLE Server'#21457#20986#35831#27714#25773#25918'AVI'#25991#20214#30340' OLE Controller'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object DriveComboBox1: TDriveComboBox
    Left = 16
    Top = 8
    Width = 249
    Height = 19
    DirList = DirectoryListBox1
    TabOrder = 0
  end
  object FileListBox1: TFileListBox
    Left = 272
    Top = 8
    Width = 249
    Height = 137
    ItemHeight = 13
    TabOrder = 1
    OnClick = FileListBox1Click
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 16
    Top = 32
    Width = 249
    Height = 137
    FileList = FileListBox1
    ItemHeight = 16
    TabOrder = 2
  end
  object FilterComboBox1: TFilterComboBox
    Left = 272
    Top = 148
    Width = 249
    Height = 21
    FileList = FileListBox1
    Filter = #25152#26377#25991#20214'(*.*)|*.*|AVI '#25991#20214'(*.AVI)|*.AVI'
    TabOrder = 3
  end
  object Button1: TButton
    Left = 48
    Top = 188
    Width = 113
    Height = 33
    Caption = #25773#25918' AVI'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 208
    Top = 188
    Width = 113
    Height = 33
    Caption = #20572#27490#25773#25918
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 360
    Top = 188
    Width = 113
    Height = 33
    Caption = #32467#26463
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button3Click
  end
end
