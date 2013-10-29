//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NewTabForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmNewTab *FrmNewTab;
//---------------------------------------------------------------------------
__fastcall TFrmNewTab::TFrmNewTab(TComponent* Owner, TADOConnection *c)
	: TForm(Owner)
{
	qryTab = new TADOQuery(NULL);
	qryTab->Connection = c;
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewTab::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewTab::FormDestroy(TObject *Sender)
{
	FrmNewTab = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewTab::FormCreate(TObject *Sender)
{
	__ClearTxt();
}
//---------------------------------------------------------------------------

void __fastcall TFrmNewTab::btnCancelClick(TObject *Sender)
{
	__ClearTxt();
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewTab::__ClearTxt()
{
	edtTabName->Clear();
	memFields->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewTab::__CreateTab()
{
	int LineCount = memFields->Lines->Count;
	String sSql(L"create table ");
	sSql += edtTabName->Text;
	sSql += L"(";
	for(int i = 0; i < LineCount; ++i)
	{
		String sTmp(memFields->Lines[i].Text.Trim());
		if(sTmp != L"")
			sSql += (sTmp + L",");
	}
	sSql = sSql.Delete(sSql.Length(),1);
	sSql += L")";
	qryTab->Close();
	qryTab->SQL->Clear();
	qryTab->SQL->Text = sSql;
	qryTab->ExecSQL();
}

void __fastcall TFrmNewTab::btnOKClick(TObject *Sender)
{
	__CreateTab();
	MessageBoxW(0, L"插入表成功", L"温馨提示", MB_OK);
	this->Close();
}
//---------------------------------------------------------------------------

