//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoadInForm.h"
#include "NewTabForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmLoadIn *FrmLoadIn;
//---------------------------------------------------------------------------
__fastcall TFrmLoadIn::TFrmLoadIn(TComponent* Owner, TADOConnection *c)
	: TForm(Owner),ADOCon(c),SqlExcel(NULL)
{
	qryTab = new TADOQuery(NULL);
	qryTab->Connection = c;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLoadIn::btnOpenClick(TObject *Sender)
{
    OpenDlg->Execute();
	edtSelect->Text = OpenDlg->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLoadIn::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLoadIn::FormDestroy(TObject *Sender)
{
	if(SqlExcel != NULL)
	{
		SqlExcel->Close();
		delete SqlExcel;
    }
	FrmLoadIn = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFrmLoadIn::__AddcmbItems()
{
	this->cmbTab->ClearSelection();
	this->cmbTab->Clear();
	this->ADOCon->Close();
	this->ADOCon->Open();
	this->ADOCon->GetTableNames(this->cmbTab->Items,false);
}

void __fastcall TFrmLoadIn::FormCreate(TObject *Sender)
{
	__AddcmbItems();
}

//---------------------------------------------------------------------------
void __fastcall TFrmLoadIn::__OpenDBTab()
{
	qryTab->Close();
	qryTab->SQL->Clear();
	qryTab->SQL->Text = L"select * from "+cmbTab->Text;
	qryTab->Open();
}
//---------------------------------------------------------------------------
bool __fastcall TFrmLoadIn::__ImportData()
{
	//__InitMapColumns();
	SqlExcel = new TSqlExcel(mapCol, ADOCon);
	SqlExcel->Open(edtSelect->Text);
	if(SqlExcel->FilterCells(cmbTab->Text) == true)
	{
		SqlExcel->InitAllSql();
		if(SqlExcel->Insert())
			return true;
	}
	return false;
}
//--------------------------------------------------------------------------
bool __fastcall TFrmLoadIn::__InitMapColumns()
{
	//初始化map
	if(!mapCol.empty())
		mapCol.clear();
	__OpenDBTab();
	for(int i = 0; i < qryTab->FieldCount; ++i)
	{
		mapCol.insert(map<String, TFieldType>::value_type(
				qryTab->Fields->Fields[i]->FullName,
				qryTab->Fields->Fields[i]->DataType));
	}

	return true;
}

void __fastcall TFrmLoadIn::btnOKClick(TObject *Sender)
{
	if(__ImportData())
		MessageBoxW(Handle,L"导入数据成功", L"温馨提示", MB_OK);
	else
		MessageBoxW(Handle,L"导入数据失败", L"温馨提示", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLoadIn::btnNewClick(TObject *Sender)
{
	if(FrmNewTab == NULL)
	{
		FrmNewTab = new TFrmNewTab(this,ADOCon);
		FrmNewTab->ShowModal();
		__AddcmbItems();
	}
	else
	{
		FrmNewTab->BringToFront();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmLoadIn::__ShowFields()
{
	__InitMapColumns();
	lstView->Clear();
	lstView->Columns->Clear();

	lstView->Columns->Add()->Caption = L"字段";
	lstView->Columns->Add()->Caption = L"数据类型";

	map<String,TFieldType>::iterator it(mapCol.begin());

	for(int i = 0; it != mapCol.end(); ++it,++i)
	{
		lstView->Items->Add()->Caption = it->first;
		lstView->Items->Item[i]->SubItems->Add(it->second);
	}
	lstView->Visible = true;

}

void __fastcall TFrmLoadIn::cmbTabChange(TObject *Sender)
{
	__ShowFields();
}
//---------------------------------------------------------------------------

