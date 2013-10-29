//---------------------------------------------------------------------------

#pragma hdrstop

#include "NormalFunction.h"
void NormalFunction::CreateColumnx(TADOQuery *qry, TcxGridDBTableView *cxgrdbtblvw)
{
    // 创建表中的列
	if (!qry->Active)
		qry->Open();
	cxgrdbtblvw->ClearItems();

	for (int i = 0; i < qry->FieldCount; ++i) {
//		if (qry->Fields->Fields[i]->FullName == L"id")
//			continue;
		TcxGridDBColumn *tempcol = cxgrdbtblvw->CreateColumn();
		tempcol->DataBinding->FieldName = qry->Fields->Fields[i]->FullName;

		tempcol->DataBinding->ValueType = qry->Fields->Fields[i]->DataType;
		tempcol->Caption = tempcol->DataBinding->FieldName;
		if (tempcol->Caption == L"")
			tempcol->Caption = tempcol->DataBinding->FieldName;
	}

	cxgrdbtblvw->ApplyBestFit();
}

void NormalFunction::ReOpen(const String &sTableName, TADOQuery *qry)
{
    qry->Close();
	qry->SQL->Clear();
	qry->SQL->Text = L"select * from "+sTableName;
	qry->Open();
}

void NormalFunction::Falsh(const String &sTableName, TADOQuery *qry,
			TcxGridDBTableView *cxgrdbtblvw)
{
	ReOpen(sTableName, qry);
	CreateColumnx(qry, cxgrdbtblvw);
}

void NormalFunction::AddcmbItems(TComboBox *cmbTab, TADOConnection *ADOCon)
{
	cmbTab->ClearSelection();
	cmbTab->Clear();
	ADOCon->Close();
	ADOCon->Open();
	ADOCon->Open();ADOCon->GetTableNames(cmbTab->Items,false);
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
