object MainForm: TMainForm
  Left = 191
  Top = 130
  Width = 544
  Height = 375
  AutoSize = True
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 536
    Height = 329
    Align = alClient
    AutoSize = True
    BorderStyle = bsSingle
    TabOrder = 0
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 530
      Height = 323
      Align = alClient
      AutoSize = True
    end
  end
  object MainMenu1: TMainMenu
    Left = 424
    Top = 16
    object File: TMenuItem
      Caption = '文件'
      object Open: TMenuItem
        Caption = '打开'
        OnClick = OpenClick
      end
      object Save: TMenuItem
        Caption = '保存'
        OnClick = SaveClick
      end
      object Exit: TMenuItem
        Caption = '退出'
        OnClick = ExitClick
      end
    end
    object Smooth: TMenuItem
      Caption = '图像平滑'
      object Smooth1: TMenuItem
        Caption = 'LP1'
        OnClick = Smooth1Click
      end
      object Smooth2: TMenuItem
        Caption = 'LP2'
        OnClick = Smooth2Click
      end
      object Smooth3: TMenuItem
        Caption = 'LP3'
        OnClick = Smooth3Click
      end
    end
    object Sharpen: TMenuItem
      Caption = '图像锐化'
      object Sharpen1: TMenuItem
        Caption = 'HP1'
        OnClick = Sharpen1Click
      end
      object Sharpen2: TMenuItem
        Caption = 'HP2'
        OnClick = Sharpen2Click
      end
      object Sharpen3: TMenuItem
        Caption = 'HP3'
        OnClick = Sharpen3Click
      end
    end
    object Detect: TMenuItem
      Caption = '边缘检测'
      object Hough: TMenuItem
        Caption = 'Hough'
        OnClick = HoughClick
      end
      object Sobel: TMenuItem
        Caption = 'Sobel'
        OnClick = SobelClick
      end
      object Prewitt: TMenuItem
        Caption = 'Prewitt'
        OnClick = PrewittClick
      end
      object Detect1: TMenuItem
        Caption = '高斯－拉普拉斯'
        OnClick = Detect1Click
      end
    end
    object Enhance: TMenuItem
      Caption = '边缘增强'
      object Vertical: TMenuItem
        Caption = '垂直边缘'
        OnClick = VerticalClick
      end
      object Horizontal: TMenuItem
        Caption = '水平边缘'
        OnClick = HorizontalClick
      end
      object HorizontalVertical: TMenuItem
        Caption = '水平与垂直边缘'
        OnClick = HorizontalVerticalClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Laplace: TMenuItem
        Caption = 'Laplace'
        object LAP1: TMenuItem
          Caption = 'LAP1'
          OnClick = LAP1Click
        end
        object LAP2: TMenuItem
          Caption = 'LAP2'
          OnClick = LAP2Click
        end
        object LAP3: TMenuItem
          Caption = 'LAP3'
          OnClick = LAP3Click
        end
        object LAP4: TMenuItem
          Caption = 'LAP4'
          OnClick = LAP4Click
        end
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Grads: TMenuItem
        Caption = '梯度方向'
        object East: TMenuItem
          Caption = '东'
          OnClick = EastClick
        end
        object South: TMenuItem
          Caption = '南'
          OnClick = SouthClick
        end
        object West: TMenuItem
          Caption = '西'
          OnClick = WestClick
        end
        object North: TMenuItem
          Caption = '北'
          OnClick = NorthClick
        end
        object NorthEast: TMenuItem
          Caption = '东北'
          OnClick = NorthEastClick
        end
        object SouthEast: TMenuItem
          Caption = '东南'
          OnClick = SouthEastClick
        end
        object NorthWest: TMenuItem
          Caption = '西北'
          OnClick = NorthWestClick
        end
        object SouthWest: TMenuItem
          Caption = '西南'
          OnClick = SouthWestClick
        end
      end
    end
    object Media: TMenuItem
      Caption = '中值滤波'
      OnClick = MediaClick
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 450
    Top = 98
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 418
    Top = 162
  end
end
