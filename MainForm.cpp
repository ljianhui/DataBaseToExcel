//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxRibbon"
#pragma link "dxRibbonSkins"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinValentine"
#pragma link "dxSkinXmas2008Blue"
#pragma link "dxBar"
#pragma link "dxSkinsdxBarPainter"
#pragma link "dxBarApplicationMenu"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "dxSkinscxPCPainter"
#pragma resource "*.dfm"
#include "ConnectForm.h"
#include "DBLogInOutForm.h"
#include "LoadInForm.h"
TFrmMain *FrmMain;
//---------------------------------------------------------------------------
__fastcall TFrmMain::TFrmMain(TComponent* Owner)
	: TForm(Owner),pRW(NULL),isFirst(true)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::__NewConnectionForm()
{
	if(FrmConnect == NULL)
	{
		FrmConnect = new TFrmConnect(this,ADOConnection,qry,cxgrdbtblvw,isFirst);
		FrmConnect->ShowModal();
		//isFirst = false;
	}
	else
	{
		FrmConnect->BringToFront();
	}
}
void __fastcall TFrmMain::__NewImportForm()
{
	if(!ADOConnection->Connected)
	{
		MessageBoxW(Handle,L"没有连接数据库,请先连接数据库", L"温馨提示", MB_OK);
		return;
	}
	if(FrmLoadIn == NULL)
	{
		FrmLoadIn = new TFrmLoadIn(this, ADOConnection);
		FrmLoadIn->Show();
	}
	else
	{
		FrmLoadIn->BringToFront();
    }
}
void __fastcall TFrmMain::__NewExportForm()
{
	//导出数据
	if(!ADOConnection->Connected)
	{
		MessageBoxW(Handle,L"没有连接数据库,请先连接数据库", L"温馨提示", MB_OK);
		return;
	}

	if(FrmDBLogInOut == NULL)
	{
		FrmDBLogInOut = new TFrmDBLogInOut(this,ADOConnection,qry,cxGrid,cxgrdbtblvw);
		FrmDBLogInOut->Show();
	}
	else
	{
		FrmDBLogInOut->BringToFront();
	}
	FrmDBLogInOut->BringToFront();
}


void __fastcall TFrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::FormDestroy(TObject *Sender)
{
	FrmMain = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::btnExitClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::FormCreate(TObject *Sender)
{
//	pRW = new ReadWriteTxt;
//	ADOConnection->ConnectionString = pRW->GetDBPath();
//	String TabName(pRW->GetTabName());
//
//	delete pRW;
//	pRW = NULL;
//
//	if(ADOConnection->ConnectionString == "" || TabName == "")
//	{
//		MessageBoxW(NULL, L"没有默认连接的数据库或没有默认连接的表", L"温馨提示",
//					MB_OK + MB_ICONWARNING);
//		return;
//	}
//	ShowMessage(ADOConnection->ConnectionString + ";" + TabName);
//	qry->Close();
//	qry->SQL->Clear();
//	qry->SQL->Text = L"select * from "+TabName;
//	qry->Open();
//	__CreateColumnx();

}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::__CreateColumnx()
{
    // 创建表中的列
	if (!qry->Active)
		qry->Open();
	cxgrdbtblvw->ClearItems();

	for (int i = 0; i < qry->FieldCount; ++i) {
		if (qry->Fields->Fields[i]->FullName == L"id")
			continue;
		TcxGridDBColumn *tempcol = cxgrdbtblvw->CreateColumn();
		tempcol->DataBinding->FieldName = qry->Fields->Fields[i]->FullName;

		tempcol->DataBinding->ValueType = qry->Fields->Fields[i]->DataType;
		tempcol->Caption = tempcol->DataBinding->FieldName;
		if (tempcol->Caption == L"")
			tempcol->Caption = tempcol->DataBinding->FieldName;
	}

	cxgrdbtblvw->ApplyBestFit();
}

//-------------------------------------------------------------------------
void __fastcall TFrmMain::ConnectionExecute(TObject *Sender)
{
	__NewConnectionForm();
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::ImportExecute(TObject *Sender)
{
	__NewImportForm();
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::ExportExecute(TObject *Sender)
{
	__NewExportForm();
}
//---------------------------------------------------------------------------





