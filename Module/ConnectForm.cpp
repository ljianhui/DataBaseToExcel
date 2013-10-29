//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConnectForm.h"
#include "NormalFunction.h"
//using namespace NormalFounction;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmConnect *FrmConnect;
//---------------------------------------------------------------------------
__fastcall TFrmConnect::TFrmConnect(TComponent* Owner,TADOConnection *c,
					TADOQuery *q, TcxGridDBTableView *cx,bool &isFrt)
	: TForm(Owner),ADOCon(c),qryTable(q),cxgrdbtblvw(cx),pRW(NULL),isFirst(&isFrt)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmConnect::btnDBClick(TObject *Sender)
{
	__ConnectDB();
}
//---------------------------------------------------------------------------
void __fastcall TFrmConnect::__ConnectDB()
{
	this->ADOCon->Close();
	this->ADOCon->ConnectionString=PromptDataSource(0, "")+";charset=gbk";
	this->ADOCon->Open();
	if (this->ADOCon->Connected)
	{
		Application->MessageBoxW(L"打开数据库成功", L"温馨提示", MB_OK);

//		this->cmbTab->ClearSelection();
//		this->cmbTab->Clear();
//		this->ADOCon->GetTableNames(this->cmbTab->Items,false);
		this->edtDB->Text=this->ADOCon->ConnectionString;
		NormalFunction::AddcmbItems(cmbTab,ADOCon);
		*isFirst = false;
	}
}
//--------------------------------------------------------------------------
bool __fastcall TFrmConnect::__SelectTab()
{
	if(this->edtDB->Text=="" || this->cmbTab->Text=="")
	{
		Application->MessageBoxW(L"请选择数据表", L"温馨提示", MB_OK);
		return false;
	}

//	qryTable->Close();
//	qryTable->SQL->Clear();
//	qryTable->SQL->Text = L"select * from "+cmbTab->Text;
//	qryTable->Open();
//	__CreateColumnx();
	NormalFunction::Falsh(cmbTab->Text,qryTable,cxgrdbtblvw);
	return true;
}
void __fastcall TFrmConnect::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFrmConnect::FormDestroy(TObject *Sender)
{
	FrmConnect = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFrmConnect::btnSelectClick(TObject *Sender)
{
	if(__SelectTab())
	{
//		if (MessageBoxW(NULL, L"是否要保存连接设置？", L"温馨提示", MB_OKCANCEL) == ID_OK)
//		{
//			pRW = new ReadWriteTxt;
//			pRW->SaveSetting(edtDB->Text, cmbTab->Text);
//			delete pRW;
//			pRW = NULL;
//		}
	}
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFrmConnect::__CreateColumnx()
{
    // 创建表中的列
	if (!qryTable->Active)
		qryTable->Open();
	cxgrdbtblvw->ClearItems();

	for (int i = 0; i < qryTable->FieldCount; ++i)
	{
//		if (qryTable->Fields->Fields[i]->FullName == L"id")
//			continue;
		TcxGridDBColumn *tempcol = cxgrdbtblvw->CreateColumn();
		tempcol->DataBinding->FieldName = qryTable->Fields->Fields[i]->FullName;

		tempcol->DataBinding->ValueType = qryTable->Fields->Fields[i]->DataType;
		tempcol->Caption = tempcol->DataBinding->FieldName;
		if (tempcol->Caption == L"")
			tempcol->Caption = tempcol->DataBinding->FieldName;
	}

	cxgrdbtblvw->ApplyBestFit();
}

void __fastcall TFrmConnect::FormCreate(TObject *Sender)
{
	if(!(*isFirst))
	{
		edtDB->Text = ADOCon->ConnectionString;
		NormalFunction::AddcmbItems(cmbTab, ADOCon);
	}
}
//---------------------------------------------------------------------------

