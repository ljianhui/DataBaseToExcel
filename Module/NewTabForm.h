//---------------------------------------------------------------------------

#ifndef NewTabFormH
#define NewTabFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TFrmNewTab : public TForm
{
__published:	// IDE-managed Components
	TEdit *edtTabName;
	TLabel *Label1;
	TMemo *memFields;
	TLabel *Label2;
	TLabel *Label3;
	TButton *btnOK;
	TButton *btnCancel;
	TLabel *Label4;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnOKClick(TObject *Sender);
private:	// User declarations
	inline void __fastcall __ClearTxt();
	void __fastcall __CreateTab();
	TADOQuery *qryTab;
public:		// User declarations
	__fastcall TFrmNewTab(TComponent* Owner, TADOConnection *c);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmNewTab *FrmNewTab;
//---------------------------------------------------------------------------
#endif
