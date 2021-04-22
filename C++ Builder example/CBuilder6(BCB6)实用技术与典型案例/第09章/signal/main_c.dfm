object Main_cForm: TMain_cForm
  Left = 75
  Top = 110
  Width = 696
  Height = 267
  Caption = 'Client'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 64
    Top = 202
    Width = 48
    Height = 13
    Caption = #37319#26679#28857#25968
  end
  object Label2: TLabel
    Left = 246
    Top = 202
    Width = 48
    Height = 13
    Caption = #37319#26679#39057#29575
  end
  object Chart1: TChart
    Left = 0
    Top = 0
    Width = 688
    Height = 183
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'TChart')
    Legend.Visible = False
    View3D = False
    Align = alTop
    TabOrder = 0
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = 8404992
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Button1: TButton
    Left = 474
    Top = 198
    Width = 60
    Height = 20
    Caption = 'Get Data'
    TabOrder = 1
    OnClick = Button1Click
  end
  object NumberBox: TComboBox
    Left = 126
    Top = 198
    Width = 95
    Height = 23
    Color = 15792127
    Font.Charset = ANSI_CHARSET
    Font.Color = clNavy
    Font.Height = -12
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ItemHeight = 15
    ParentFont = False
    TabOrder = 2
    Items.Strings = (
      '512'
      '1024'
      '2048'
      '4096'
      '8192'
      '16384')
  end
  object FreqBox: TComboBox
    Left = 311
    Top = 198
    Width = 95
    Height = 23
    Color = 15792127
    Font.Charset = ANSI_CHARSET
    Font.Color = clNavy
    Font.Height = -12
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ItemHeight = 15
    ParentFont = False
    TabOrder = 3
    Items.Strings = (
      '512'
      '1024'
      '2048'
      '3072'
      '4096'
      '5120'
      '10240'
      '15600'
      '20480'
      '30720')
  end
end
