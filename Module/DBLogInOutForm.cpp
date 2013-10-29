//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DBLogInOutForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCheckGroup"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
#pragma resource "*.dfm"

#include "NormalFunction.h"
TFrmDBLogInOut *FrmDBLogInOut;
//---------------------------------------------------------------------------
__fastcall TFrmDBLogInOut::TFrmDBLogInOut(TComponent* Owner,TADOConnection *c,
					TADOQuery *qry,TDBGrid *g,String p)
	: TForm(Owner),ADOCon(c),qryTab(qry),dbGrid(g),strXlsFile(p)
{
}
__fastcall TFrmDBLogInOut::TFrmDBLogInOut(TComponent* Owner,TADOConnection *c,
					TADOQuery *qry,TcxGrid *cx,TcxGridDBTableView *cxg)
	: TForm(Owner),ADOCon(c),qryTab(qry),cxGrid(cx),cxgrdbtblvw(cxg)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmDBLogInOut::chkSelectClick(TObject *Sender)
{
	for (int i = 0; i < this->chkgrp->Properties->Items->Count; ++i)
		this->chkgrp->States[i] = this->chkSelect->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TFrmDBLogInOut::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFrmDBLogInOut::FormDestroy(TObject *Sender)
{
	FrmDBLogInOut = NULL;
}
//---------------------------------------------------------------------------


void __fastcall TFrmDBLogInOut::btnExitClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmDBLogInOut::btnCancelClick(TObject *Sender)
{
	chkSelect->Checked = false;
	for (int i = 0; i < this->chkgrp->Properties->Items->Count; ++i)
		this->chkgrp->States[i] = false;
}
//---------------------------------------------------------------------------
bool __fastcall TFrmDBLogInOut::__IsNoneSelected()
{
    //判断是否选择导出字段
   for(int i=0; i < this->chkgrp->Properties->Items->Count; ++i)
		if(this->chkgrp->States[i])
			return false  ;
   return true;
}
//---------------------------------------------------------------------------
void __fastcall TFrmDBLogInOut::__ExportToExcel()
{
	int sum = this->chkgrp->ActiveProperties->Items->Count;
	int i;
	String sAttFile;
	if (SaveDlg->Execute())
	{    //导出的前期工作
		TIdAttachmentFile *idAtta =
			new TIdAttachmentFile(IdMsg->MessageParts, sAttFile);
		sAttFile = SaveDlg->FileName;
		idAtta->ContentType = "Application / octet - stream";
		idAtta->ContentDisposition = "attachment";
		idAtta->ContentTransfer = "base64";
		//导出前隐藏不需要导的字段
		for (i = 0; i < sum; i++)
		{
			if (this->chkgrp->States[i] != cbsChecked)
				dynamic_cast<TcxGridDBTableView *>(this->cxGrid->ActiveView)
					->Columns[i]->Visible = false;
		}
		//导出
		ExportGridToExcel(sAttFile, this->cxGrid, True, True);
		//导出后还原cxGrid
		for (i = 0; i < sum; i++)
			dynamic_cast<TcxGridDBTableView *>(this->cxGrid->ActiveView)
				->Columns[i]->Visible = true;

		MessageBoxW(Handle, L"导出成功！", L"温馨提示", MB_OK + MB_ICONINFORMATION);
	}
}

void __fastcall TFrmDBLogInOut::btnOkClick(TObject *Sender)
{
	if(this->__IsNoneSelected())
	{
	   MessageBoxW(Handle,L"导出不能为空",L"温馨提示",MB_OK+MB_ICONWARNING);
		return;
	}

	this->__ExportToExcel();
	this->Close() ;
}
//---------------------------------------------------------------------------
void __fastcall TFrmDBLogInOut::__AddCheckItem()
{
	//为checkGroup添加选项
	int nCount = qryTab->FieldCount;
	chkgrp->Clear();
	chkgrp->Properties->Items->Clear();
	for(int i = 0; i < nCount; ++i)
	{
        chkgrp->Properties->Items->Add()->Caption = qryTab->Fields->Fields[i]->FullName;
    }
}

void __fastcall TFrmDBLogInOut::FormCreate(TObject *Sender)
{
//	NormalFunction::ReOpen(cmbTab->Text, qryTab);
	NormalFunction::AddcmbItems(cmbTab, ADOCon);
	__AddCheckItem();

}
//---------------------------------------------------------------------------

void __fastcall TFrmDBLogInOut::cmbTabChange(TObject *Sender)
{
	NormalFunction::Falsh(cmbTab->Text, qryTab, cxgrdbtblvw);
	__AddCheckItem();
}
//---------------------------------------------------------------------------

