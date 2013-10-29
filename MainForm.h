//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "dxRibbon.hpp"
#include "dxRibbonSkins.hpp"
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ToolWin.hpp>
#include "dxBar.hpp"
#include "dxSkinsdxBarPainter.hpp"
#include "dxBarApplicationMenu.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "dxSkinscxPCPainter.hpp"
#include <DB.hpp>
#include <Vcl.ImgList.hpp>

#include "ReadWriteTxt.h"
#include <Vcl.Menus.hpp>
#include <Vcl.ActnList.hpp>
//---------------------------------------------------------------------------
class TFrmMain : public TForm
{
__published:	// IDE-managed Components
	TADOQuery *qry;
	TDataSource *DataSource;
	TdxBarManager *dxBarManager1;
//	TdxBarButton *dxBarButton1;
//	TdxBarButton *dxBarButton2;
//	TdxBarSubItem *dxBarSubItem1;
//	TdxBarButton *dxBarButton3;
//	TdxBarButton *dxBarButton4;
//	TdxBarLargeButton *dxBarLargeButton1;
//	TdxBarLargeButton *dxBarLargeButton2;
//	TdxBar *dxBarManager1Bar1;
	TdxBarButton *btnLink;
//	TdxBarSubItem *dxBarSubItem2;
	TdxBarButton *btnImport;
	TdxBarButton *btnExport;
	TcxGrid *cxGrid;
	TcxGridDBTableView *cxgrdbtblvw;
	TcxGridLevel *cxGridLevel1;
	TADOConnection *ADOConnection;
//	TdxBarButton *dxBarButton8;
	TdxBarButton *btnSave;
	TdxBarButton *btnExit;
	TPopupMenu *PopupMenu;
	TMenuItem *pmConnect;
	TMenuItem *pmExport;
	TMenuItem *pmImport;
	TActionList *ActionList;
	TAction *Connection;
	TAction *Import;
	TAction *Export;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall btnExitClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ConnectionExecute(TObject *Sender);
	void __fastcall ImportExecute(TObject *Sender);
	void __fastcall ExportExecute(TObject *Sender);
private:	// User declarations
	void __fastcall __CreateColumnx();
	void __fastcall __NewConnectionForm();
	void __fastcall __NewImportForm();
	void __fastcall __NewExportForm();

	ReadWriteTxt *pRW;
	bool isFirst;
public:		// User declarations
	__fastcall TFrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMain *FrmMain;
//---------------------------------------------------------------------------
#endif
