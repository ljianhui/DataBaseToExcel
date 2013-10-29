//---------------------------------------------------------------------------

#ifndef ConnectFormH
#define ConnectFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Menus.hpp>
#include <Vcl.Dialogs.hpp>

#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "dxSkinscxPCPainter.hpp"

#include "ReadWriteTxt.h"

//---------------------------------------------------------------------------
class TFrmConnect : public TForm
{
__published:	// IDE-managed Components
	TEdit *edtDB;
	TComboBox *cmbTab;
	TButton *btnDB;
	TButton *btnSelect;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall btnDBClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall btnSelectClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
	TADOQuery *qryTable;
	TADOConnection *ADOCon;
	TcxGridDBTableView *cxgrdbtblvw;
	ReadWriteTxt *pRW;
	bool *isFirst;
	String sTabName;

	void __fastcall __ConnectDB();
	bool __fastcall __SelectTab();
	void __fastcall __CreateColumnx();
public:		// User declarations
	__fastcall TFrmConnect(TComponent* Owner,TADOConnection *c,TADOQuery *q,
							TcxGridDBTableView *cx,bool &isFrt);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmConnect *FrmConnect;
//---------------------------------------------------------------------------
#endif
