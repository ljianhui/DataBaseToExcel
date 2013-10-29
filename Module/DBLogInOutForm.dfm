object FrmDBLogInOut: TFrmDBLogInOut
  Left = 0
  Top = 0
  Caption = #23548#20986#25968#25454
  ClientHeight = 522
  ClientWidth = 377
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
    Left = 8
    Top = 11
    Width = 60
    Height = 13
    Caption = #35831#36873#25321#34920#65306
  end
  object chkgrp: TcxCheckGroup
    Left = 8
    Top = 40
    Caption = #35831#36873#25321#23548#20837'/'#23548#20986#23383#27573
    Properties.Items = <>
    TabOrder = 0
    Height = 433
    Width = 361
  end
  object btnCancel: TButton
    Left = 200
    Top = 489
    Width = 75
    Height = 25
    Caption = #21462#28040
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object btnExit: TButton
    Left = 294
    Top = 489
    Width = 75
    Height = 25
    Caption = #36864#20986
    TabOrder = 2
    OnClick = btnExitClick
  end
  object btnOk: TButton
    Left = 104
    Top = 489
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 3
    OnClick = btnOkClick
  end
  object chkSelect: TCheckBox
    Left = 8
    Top = 493
    Width = 97
    Height = 17
    Caption = #20840#36873
    TabOrder = 4
    OnClick = chkSelectClick
  end
  object cmbTab: TComboBox
    Left = 74
    Top = 8
    Width = 287
    Height = 21
    TabOrder = 5
    OnChange = cmbTabChange
  end
  object SaveDlg: TSaveDialog
    Left = 240
    Top = 48
  end
  object IdMsg: TIdMessage
    AttachmentEncoding = 'UUE'
    BccList = <>
    CCList = <>
    Encoding = meDefault
    FromList = <
      item
      end>
    Recipients = <>
    ReplyTo = <>
    ConvertPreamble = True
    Left = 176
    Top = 48
  end
end
