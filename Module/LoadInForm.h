//---------------------------------------------------------------------------

#ifndef LoadInFormH
#define LoadInFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>

#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>

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

#include "SQL_EXCEL.h"
#include <Vcl.ComCtrls.hpp>

#include <map>
//---------------------------------------------------------------------------
class TFrmLoadIn : public TForm
{
__published:	// IDE-managed Components
	TEdit *edtSelect;
	TComboBox *cmbTab;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *btnOpen;
	TButton *btnOK;
	TButton *btnNew;
	TOpenDialog *OpenDlg;
	TLabel *Label4;
	TListView *lstView;
	void __fastcall btnOpenClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnOKClick(TObject *Sender);
	void __fastcall btnNewClick(TObject *Sender);
	void __fastcall cmbTabChange(TObject *Sender);
private:	// User declarations
	bool __fastcall __ImportData();
	bool __fastcall __InitMapColumns();
	void __fastcall __OpenDBTab();
	void __fastcall __ShowFields();
	void __fastcall __AddcmbItems();

	TADOConnection *ADOCon;
	TADOQuery *qryTab;
	TSqlExcel *SqlExcel;
	map<String,TFieldType> mapCol;
public:		// User declarations
	__fastcall TFrmLoadIn(TComponent* Owner, TADOConnection *c);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmLoadIn *FrmLoadIn;
//---------------------------------------------------------------------------
#endif
