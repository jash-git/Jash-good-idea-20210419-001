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
      Caption = '�ļ�'
      object Open: TMenuItem
        Caption = '��'
        OnClick = OpenClick
      end
      object Save: TMenuItem
        Caption = '����'
        OnClick = SaveClick
      end
      object Exit: TMenuItem
        Caption = '�˳�'
        OnClick = ExitClick
      end
    end
    object Smooth: TMenuItem
      Caption = 'ͼ��ƽ��'
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
      Caption = 'ͼ����'
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
      Caption = '��Ե���'
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
        Caption = '��˹��������˹'
        OnClick = Detect1Click
      end
    end
    object Enhance: TMenuItem
      Caption = '��Ե��ǿ'
      object Vertical: TMenuItem
        Caption = '��ֱ��Ե'
        OnClick = VerticalClick
      end
      object Horizontal: TMenuItem
        Caption = 'ˮƽ��Ե'
        OnClick = HorizontalClick
      end
      object HorizontalVertical: TMenuItem
        Caption = 'ˮƽ�봹ֱ��Ե'
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
        Caption = '�ݶȷ���'
        object East: TMenuItem
          Caption = '��'
          OnClick = EastClick
        end
        object South: TMenuItem
          Caption = '��'
          OnClick = SouthClick
        end
        object West: TMenuItem
          Caption = '��'
          OnClick = WestClick
        end
        object North: TMenuItem
          Caption = '��'
          OnClick = NorthClick
        end
        object NorthEast: TMenuItem
          Caption = '����'
          OnClick = NorthEastClick
        end
        object SouthEast: TMenuItem
          Caption = '����'
          OnClick = SouthEastClick
        end
        object NorthWest: TMenuItem
          Caption = '����'
          OnClick = NorthWestClick
        end
        object SouthWest: TMenuItem
          Caption = '����'
          OnClick = SouthWestClick
        end
      end
    end
    object Media: TMenuItem
      Caption = '��ֵ�˲�'
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
