object FrmLoadIn: TFrmLoadIn
  Left = 0
  Top = 0
  Caption = #23548#20837#25968#25454
  ClientHeight = 374
  ClientWidth = 414
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 27
    Top = 27
    Width = 77
    Height = 13
    Caption = #35831#36873#25321'.xls'#25991#20214
  end
  object Label2: TLabel
    Left = 8
    Top = 70
    Width = 96
    Height = 13
    Caption = #35831#36873#25321#34987#25554#20837#30340#34920
  end
  object Label3: TLabel
    Left = 59
    Top = 120
    Width = 252
    Height = 13
    Caption = #33509#27809#26377#36866#21512#30340#34920#65292#35831#28857#20987#21491#36793#30340#25353#38062#26032#24314#19968#24352#34920
  end
  object Label4: TLabel
    Left = 27
    Top = 152
    Width = 132
    Height = 13
    Caption = #36873#25321#30340#34920#30340#35814#32454#23383#27573#20449#24687
  end
  object edtSelect: TEdit
    Left = 110
    Top = 24
    Width = 201
    Height = 21
    TabOrder = 0
  end
  object cmbTab: TComboBox
    Left = 110
    Top = 67
    Width = 201
    Height = 21
    TabOrder = 1
    OnChange = cmbTabChange
  end
  object btnOpen: TButton
    Left = 328
    Top = 22
    Width = 75
    Height = 25
    Caption = #25171#24320'...'
    TabOrder = 2
    OnClick = btnOpenClick
  end
  object btnOK: TButton
    Left = 328
    Top = 65
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 3
    OnClick = btnOKClick
  end
  object btnNew: TButton
    Left = 328
    Top = 108
    Width = 75
    Height = 25
    Caption = #26032#24314
    TabOrder = 4
    OnClick = btnNewClick
  end
  object lstView: TListView
    Left = 27
    Top = 171
    Width = 376
    Height = 195
    Columns = <>
    TabOrder = 5
    ViewStyle = vsReport
  end
  object OpenDlg: TOpenDialog
    Left = 16
    Top = 104
  end
end
