object Form1: TForm1
  Left = 367
  Top = 137
  Width = 580
  Height = 476
  Caption = #25991#20214#31649#29702#33539#20363#31243#24207
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 572
    Height = 449
    Align = alClient
    TabOrder = 0
    object FileListBox1: TFileListBox
      Left = 312
      Top = 16
      Width = 249
      Height = 249
      FileEdit = Edit1
      ItemHeight = 13
      TabOrder = 0
    end
    object DirectoryListBox1: TDirectoryListBox
      Left = 8
      Top = 16
      Width = 297
      Height = 249
      FileList = FileListBox1
      ItemHeight = 16
      TabOrder = 1
    end
    object DriveComboBox1: TDriveComboBox
      Left = 8
      Top = 272
      Width = 297
      Height = 19
      DirList = DirectoryListBox1
      TabOrder = 2
    end
    object Edit1: TEdit
      Left = 312
      Top = 272
      Width = 249
      Height = 21
      TabOrder = 3
      Text = '*.*'
    end
    object GroupBox1: TGroupBox
      Left = 8
      Top = 297
      Width = 297
      Height = 141
      Caption = #25991#20214#23646#24615
      TabOrder = 4
      object CheckBox1: TCheckBox
        Left = 32
        Top = 24
        Width = 97
        Height = 17
        Caption = #21482#35835
        TabOrder = 0
      end
      object CheckBox2: TCheckBox
        Left = 32
        Top = 48
        Width = 97
        Height = 17
        Caption = #38544#34255
        TabOrder = 1
      end
      object CheckBox3: TCheckBox
        Left = 32
        Top = 72
        Width = 97
        Height = 17
        Caption = #31995#32479
        TabOrder = 2
      end
      object CheckBox4: TCheckBox
        Left = 32
        Top = 96
        Width = 97
        Height = 17
        Caption = #23384#26723
        TabOrder = 3
      end
    end
    object Button1: TButton
      Left = 344
      Top = 312
      Width = 185
      Height = 33
      Caption = #35835#21462#25991#20214#23646#24615
      Default = True
      TabOrder = 5
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 344
      Top = 352
      Width = 185
      Height = 33
      Caption = #20462#25913#25991#20214#23646#24615
      TabOrder = 6
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 344
      Top = 392
      Width = 185
      Height = 33
      Caption = #32467#26463
      TabOrder = 7
      OnClick = Button3Click
    end
  end
end
