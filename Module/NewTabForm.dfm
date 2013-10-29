object FrmNewTab: TFrmNewTab
  Left = 0
  Top = 0
  Caption = #26032#24314#34920
  ClientHeight = 458
  ClientWidth = 258
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 72
    Height = 13
    Caption = #35831#20889#20837#34920#21517#65306
  end
  object Label2: TLabel
    Left = 8
    Top = 64
    Width = 84
    Height = 13
    Caption = #35831#20889#20837#23383#27573#21517#65306
  end
  object Label3: TLabel
    Left = 8
    Top = 375
    Width = 168
    Height = 13
    Caption = #27880#24847#65306#27599#20010#23383#27573#21450#38480#23450#21517#21344#19968#34892
  end
  object Label4: TLabel
    Left = 41
    Top = 394
    Width = 199
    Height = 13
    Caption = #20363#22914#19968#34892#20026#65306'id varchar(36) primary key'
  end
  object edtTabName: TEdit
    Left = 8
    Top = 27
    Width = 242
    Height = 21
    TabOrder = 0
  end
  object memFields: TMemo
    Left = 8
    Top = 83
    Width = 242
    Height = 286
    Lines.Strings = (
      'memFields')
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object btnOK: TButton
    Left = 94
    Top = 425
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 2
    OnClick = btnOKClick
  end
  object btnCancel: TButton
    Left = 175
    Top = 425
    Width = 75
    Height = 25
    Caption = #21462#28040
    TabOrder = 3
    OnClick = btnCancelClick
  end
end
