object FrmConnect: TFrmConnect
  Left = 0
  Top = 0
  Caption = #36830#25509
  ClientHeight = 141
  ClientWidth = 377
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
    Caption = #35831#36873#25321#25968#25454#24211
  end
  object Label2: TLabel
    Left = 8
    Top = 70
    Width = 72
    Height = 13
    Caption = #35831#36873#25321#25968#25454#34920
  end
  object edtDB: TEdit
    Left = 8
    Top = 27
    Width = 241
    Height = 21
    TabOrder = 0
  end
  object cmbTab: TComboBox
    Left = 8
    Top = 89
    Width = 241
    Height = 21
    TabOrder = 1
  end
  object btnDB: TButton
    Left = 280
    Top = 25
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 2
    OnClick = btnDBClick
  end
  object btnSelect: TButton
    Left = 280
    Top = 87
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 3
    OnClick = btnSelectClick
  end
end
