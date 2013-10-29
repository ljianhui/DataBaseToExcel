object FrmMain: TFrmMain
  Left = 0
  Top = 0
  Caption = #25968#25454#24211#31649#29702
  ClientHeight = 522
  ClientWidth = 732
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
  object cxGrid: TcxGrid
    Left = 0
    Top = 28
    Width = 732
    Height = 494
    Align = alClient
    TabOrder = 4
    ExplicitHeight = 349
    object cxgrdbtblvw: TcxGridDBTableView
      DataController.DataSource = DataSource
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsView.GroupByBox = False
    end
    object cxGridLevel1: TcxGridLevel
      GridView = cxgrdbtblvw
    end
  end
  object qry: TADOQuery
    Connection = ADOConnection
    Parameters = <>
    Left = 560
    Top = 216
  end
  object DataSource: TDataSource
    DataSet = qry
    Left = 456
    Top = 184
  end
  object dxBarManager1: TdxBarManager
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #24494#36719#38597#40657
    Font.Style = []
    Categories.Strings = (
      'Default')
    Categories.ItemsVisibles = (
      2)
    Categories.Visibles = (
      True)
    PopupMenuLinks = <>
    UseSystemFont = True
    Left = 624
    Top = 176
    DockControlHeights = (
      0
      0
      28
      0)
    object dxBarManager1Bar1: TdxBar
      Caption = 'Custom 1'
      CaptionButtons = <>
      DockedDockingStyle = dsTop
      DockedLeft = 0
      DockedTop = 0
      DockingStyle = dsTop
      FloatLeft = 766
      FloatTop = 8
      FloatClientWidth = 0
      FloatClientHeight = 0
      IsMainMenu = True
      ItemLinks = <
        item
          Visible = True
          ItemName = 'btnLink'
        end
        item
          Visible = True
          ItemName = 'btnImport'
        end
        item
          Visible = True
          ItemName = 'btnExport'
        end
        item
          Visible = True
          ItemName = 'btnExit'
        end>
      MultiLine = True
      OneOnRow = True
      Row = 0
      UseOwnFont = False
      Visible = True
      WholeRow = True
    end
    object dxBarButton1: TdxBarButton
      Caption = 'New Button'
      Category = 0
      Hint = 'New Button'
      Visible = ivAlways
    end
    object dxBarButton2: TdxBarButton
      Caption = 'New Button'
      Category = 0
      Hint = 'New Button'
      Visible = ivAlways
    end
    object dxBarSubItem1: TdxBarSubItem
      Caption = 'New SubItem'
      Category = 0
      Visible = ivAlways
      ItemLinks = <>
    end
    object dxBarButton3: TdxBarButton
      Caption = 'New Button'
      Category = 0
      Hint = 'New Button'
      Visible = ivAlways
    end
    object dxBarButton4: TdxBarButton
      Caption = 'New Button'
      Category = 0
      Hint = 'New Button'
      Visible = ivAlways
    end
    object dxBarLargeButton1: TdxBarLargeButton
      Caption = 'New Button'
      Category = 0
      Hint = 'New Button'
      Visible = ivAlways
    end
    object dxBarLargeButton2: TdxBarLargeButton
      Caption = 'New Button'
      Category = 0
      Hint = 'New Button'
      Visible = ivAlways
    end
    object btnLink: TdxBarButton
      Action = Connection
      Category = 0
      LargeGlyph.Data = {
        C6070000424DC607000000000000360000002800000016000000160000000100
        2000000000009007000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000200080011
        00460024007400280074001500570004000F0000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000D0032005100BB009D00F600CB00FF00DC
        00FF00C400F9005900C100080022000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000D0027003B00C2004000AD0033007A00390082008500D800E700FE00E6
        00FE0051009C0001000200000000000000000000000000000000000000000000
        0000D47F35FFD79157FFD48C54FFD18851FFCE834EFFCA7E4BFF78702BFF886C
        30FFBB7040FFBE6C40FFA76936FF646B1FFF0ABB03FF00FB00FF11C805FF706B
        1FFF7C6123FFB05732FFB05732FFB05732FFB05732FFA73B0CFFDE9A5EFFFBFA
        FAFFFAF9F9FFF9F6F7FFF7F4F5FFF6F2F2FFF5F0F1FFE6E4E2FFD9DAD4FFF0E9
        EAFFCAD6C5FF1AAE19FF01F601FF02FF02FF02FD02FF02E902FF51A94EFFE7DC
        DCFFE6DBDBFFE6D9DAFFE0D3D4FFB05732FFDF9D60FFFFFFFFFFFFFFFFFFFEFD
        FDFFFDFBFBFFFCFAFAFFF1F0EEFF629C60FF258024FFC9D0C5FFF7F1F1FFC4DD
        BFFF21E020FF55FF55FF3FFC3FFF56D653FFE6E3DDFFEFE5E5FFEEE3E3FFEDE2
        E2FFE6D9DAFFB05732FFE19F61FFFFFFFFFFFFFFFFFFFFFFFFFFFEFDFDFFF3F4
        F1FF58A758FF01E001FF00EA00FF1B9F1AFFC5D1C2FFF7F1F1FFC6E4C2FF34E2
        37FF67E166FFE8E7E0FFF1E8E8FFF0E7E7FFEFE5E5FFEEE3E3FFE6DBDBFFB057
        32FFE1A062FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF59A059FF02D202FF00F4
        00FF00F900FF00E500FF1B8F1AFFD1DDCDFFF5F0F0FFDCEBD6FFE7ECE2FFF3EC
        ECFFF2EAEAFFF1E8E8FFF0E7E7FFEFE5E5FFE7DCDCFFB05732FFE2A262FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFB4D6B4FFA2D4A1FF19E319FF00FE00FF0ED3
        0EFF88C086FFDEE5DAFFF7F3F3FFEFEEEAFFABCFA6FF94C290FFF3ECECFFF2EA
        EAFFF1E8E8FFF0E7E7FFE8DDDEFFB05732FFE3A363FFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFDFEFDFF63DE62FF1BFC1BFF2EFD2EFF35E135FF7FE0
        7DFF85DF83FF50CB4FFF3AB139FFCFE0CAFFF4EDEDFFF3ECECFFF2EAEAFFF1E8
        E8FFE9DFDFFFB05732FFE4A564FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFDDF4DDFF48E548FF97FC99FFD2FFD5FFBBFDBCFF51F152FF49DF
        48FFC6E6C3FFF6F1F1FFF5EFEFFFF4EDEDFFF3ECECFFF2EAEAFFEAE1E1FFB058
        33FFE5A665FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFF0FBF0FFA7ECA7FF91EF97FF8CEC90FFB6EBB4FFF1F4EEFFF8F4F4FFF7F3
        F3FFF6F1F1FFF5EFEFFFF4EDEDFFF3ECECFFECE3E3FFB15833FFE6A766FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFEFDFDFFFDFBFBFFFCF9F9FFFBF8F8FFF9F6F6FFF8F4F4FFF7F3F3FFF6F1
        F1FFF5EFEFFFF4EDEDFFEDE5E5FFB25934FFE7A967FFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFFFEFD
        FDFFFDFBFBFFFBF9F9FFFBF8F8FFF9F6F6FFF8F4F4FFF7F3F3FFF6F1F1FFF5EF
        EFFFEEE7E7FFB25A35FFE8AA68FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFFFEFDFDFFFDFB
        FBFFFBF9F9FFFAF7F7FFF9F6F6FFF8F4F4FFF7F2F2FFF6F1F1FFF0E9E9FFB35B
        36FFE9AC69FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFFFEFDFDFFFDFBFBFFFBF9
        F9FFFAF7F7FFF9F6F6FFF8F4F4FFF7F2F2FFF2EBECFFB45C37FFEAAE69FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFFFEFDFDFFFCFBFBFFFBF9F9FFFAF7
        F7FFF9F6F6FFF8F4F4FFF3EDEEFFB45D38FFEBAF6AFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFEFEFFFEFDFDFFFCFBFBFFFBF9F9FFFAF7F7FFF9F6
        F6FFF4EFF0FFB55E38FFEBA85BFFFFE1BFFFFFDEBCFFFFDBB9FFFFD7B5FFFFD4
        B1FFFFD0AEFFFFCCAAFFFFC8A6FFFFC4A2FFFFC09DFFFFBC99FFFFB895FFFFB3
        90FFFFAF8CFFFFAA87FFFEA582FFFEA27FFFFDA17EFFFDA07DFFF59A7AFFB348
        1DFFECA34DFFFFC884FFFFC27EFFFFBB77FFFFB470FFFFAD68FFFFA560FFFF9D
        58FFFF9550FFFF8D48FFFF843FFFFF7B36FFFF732DFFFF6A24FFFF611CFFFF58
        13FFFF4F0AFFFF4903FFFF4903FFFF4903FFF64303FFB13201FFE89D44FFFFCF
        8BFFFFC984FFFFC17DFFFFBA75FFFFB26DFFFFAA65FFFFA15DFFFF9954FFFF90
        4BFFFF8742FFFF7F39FFFF7630FFFF6D27FFFF641EFFFF5B15FFFF520CFFFF4A
        04FFFF4903FFFF4903FFF14003FFAB3200FF8F5D249FE89D44FFEAA04BFFE79B
        47FFE59543FFE28F3FFFE0893AFFDD8336FFDB7D32FFD8772DFFD67129FFD36B
        24FFD16520FFCE5F1BFFCC5917FFC95312FFC74D0EFFC4470AFFC24207FFBF3F
        05FFB23802FF661F009F}
      LargeImageIndex = 52
    end
    object dxBarSubItem2: TdxBarSubItem
      Caption = 'New SubItem'
      Category = 0
      Visible = ivAlways
      ItemLinks = <>
    end
    object btnImport: TdxBarButton
      Action = Import
      Category = 0
    end
    object btnExport: TdxBarButton
      Action = Export
      Category = 0
    end
    object dxBarButton8: TdxBarButton
      Caption = 'New Button'
      Category = 0
      Hint = 'New Button'
      Visible = ivAlways
    end
    object btnSave: TdxBarButton
      Caption = #20445#23384#36830#25509
      Category = 0
      Hint = #20445#23384#36830#25509
      Visible = ivAlways
    end
    object btnExit: TdxBarButton
      Caption = #36864#20986
      Category = 0
      Hint = #36864#20986
      Visible = ivAlways
      OnClick = btnExitClick
    end
    object dxBarSubItem3: TdxBarSubItem
      Caption = 'New SubItem'
      Category = 0
      Visible = ivAlways
      ItemLinks = <>
    end
  end
  object ADOConnection: TADOConnection
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=goodsmag;Data Source=(local)'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 224
    Top = 120
  end
  object PopupMenu: TPopupMenu
    Left = 192
    Top = 440
    object pmConnect: TMenuItem
      Action = Connection
    end
    object pmExport: TMenuItem
      Action = Export
    end
    object pmImport: TMenuItem
      Action = Import
    end
  end
  object ActionList: TActionList
    Left = 304
    Top = 216
    object Connection: TAction
      Category = 'MainMenu'
      Caption = #36830#25509
      OnExecute = ConnectionExecute
    end
    object Import: TAction
      Category = 'MainMenu'
      Caption = #23548#20837#25968#25454
      OnExecute = ImportExecute
    end
    object Export: TAction
      Category = 'MainMenu'
      Caption = #23548#20986#25968#25454
      OnExecute = ExportExecute
    end
  end
end
