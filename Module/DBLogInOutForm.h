//---------------------------------------------------------------------------

#ifndef DBLogInOutFormH
#define DBLogInOutFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdMessage.hpp>
#include <Vcl.Dialogs.hpp>
#include "cxCheckGroup.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
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

#include <IdAttachmentFile.hpp>
#include <Dialogs.hpp>
#include <IdBaseComponent.hpp>
#include <IdMessage.hpp>

#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp" 				//导出用到而另外添加的头文件
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "dxSkinscxPCPainter.hpp"
#include <DB.hpp>

//#include "cxGrid.hpp"               //导出用到而另外添加的头文件
//#include "cxGridDBTableView.hpp"
#include "cxGridExportLink.hpp"

//---------------------------------------------------------------------------
class TFrmDBLogInOut : public TForm
{
__published:	// IDE-managed Components
	TSaveDialog *SaveDlg;
	TIdMessage *IdMsg;
	TcxCheckGroup *chkgrp;
	TButton *btnCancel;
	TButton *btnExit;
	TButton *btnOk;
	TCheckBox *chkSelect;
	TLabel *Label1;
	TComboBox *cmbTab;
	void __fastcall chkSelectClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall btnExitClick(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnOkClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cmbTabChange(TObject *Sender);

private:	// User declarations
	bool __fastcall __IsNoneSelected();
	void __fastcall __ExportToExcel();
	void __fastcall __ExportToDataBase();
	void __fastcall __AddCheckItem();

	TADOQuery *qryTab;
	TADOConnection *ADOCon;
	TDBGrid *dbGrid;
	TcxGridDBTableView *cxgrdbtblvw;
	TcxGrid *cxGrid;
	String strXlsFile;
public:		// User declarations
	__fastcall TFrmDBLogInOut(TComponent* Owner,TADOConnection *c,
				TADOQuery *qry,TDBGrid *g,String p);
	__fastcall TFrmDBLogInOut(TComponent* Owner,TADOConnection *c,
					TADOQuery *qry,TcxGrid *cx,TcxGridDBTableView *cxg);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmDBLogInOut *FrmDBLogInOut;
//---------------------------------------------------------------------------
#endif
