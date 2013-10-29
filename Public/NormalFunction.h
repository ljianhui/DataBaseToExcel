//---------------------------------------------------------------------------

#ifndef NormalFunctionH
#define NormalFunctionH

#include <Data.Win.ADODB.hpp>
#include "cxGridDBTableView.hpp"

namespace NormalFunction
{

void CreateColumnx(TADOQuery *qry, TcxGridDBTableView *cxgrdbtblvw);

void ReOpen(const String &sTableName, TADOQuery *qry);

void Falsh(const String &sTableName, TADOQuery *qry,
			TcxGridDBTableView *cxgrdbtblvw);

void AddcmbItems(TComboBox *cmbTab, TADOConnection *ADOCon);

}
//---------------------------------------------------------------------------
#endif
