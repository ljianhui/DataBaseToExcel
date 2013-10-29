// ---------------------------------------------------------------------------

#pragma hdrstop

#include "SQL_EXCEL.h"

// ---------------------------------------------------------------------------

#pragma package(smart_init)

__fastcall TSqlExcel::TSqlExcel(map<String, TFieldType> Col, TADOConnection * con)
{
	mapColumns = Col;
	qryInsert = new TADOQuery(NULL);
	qryInsert->Connection = con;
	slImportSql = new TStringList;
	sFieldsSql = "(";
	sSameSql = "";
}

// ---------------------------------------------------------------------------
__fastcall TSqlExcel::~TSqlExcel()
{
	mapColumns.clear();           //清空容器里的内容

	/*清空两个StringList并删除*/
	slImportSql->Clear();
	delete slImportSql;

	delete qryInsert;
}

// ---------------------------------------------------------------------------
void __fastcall TSqlExcel::Open(String Path)
{
	ExcelApp = Variant::CreateObject("Excel.Application");
	ExcelApp.OlePropertySet("Visible", false); // 设置为不可见
	WideString PathTmp(Path);

	ExcelApp.OlePropertyGet("WorkBooks").OleProcedure("Open", PathTmp);

	ExcWB = ExcelApp.OlePropertyGet("ActiveWorkBook");
	ExcSh = ExcWB.OlePropertyGet("ActiveSheet");

	ColCount = ExcSh.OlePropertyGet("UsedRange").OlePropertyGet("Columns")
		.OlePropertyGet("Count"); // 列数
	RowCount = ExcSh.OlePropertyGet("UsedRange").OlePropertyGet("Rows")
		.OlePropertyGet("Count"); // 行数
}

// ---------------------------------------------------------------------------
void __fastcall TSqlExcel::Close()
{
	ExcWB.OleFunction("Close");
	ExcelApp.OleFunction("Quit");
	ExcWB = Unassigned;
	ExcelApp = Unassigned;
}

// ---------------------------------------------------------------------------
int __fastcall TSqlExcel::GetRowCount()
{
	return RowCount;
}

// ---------------------------------------------------------------------------
int __fastcall TSqlExcel::GetColCount()
{
	return ColCount;   //返回的是原来Excel的字段数
}
// ---------------------------------------------------------------------------


//----------------------------------------------------------------------------
bool __fastcall TSqlExcel::FilterCells(String TblName)
{
	//过滤掉数据库中没有的字段
	int flag(0);  //用于判断是否是没有一个字段匹配数据库中的表的
	String strValue;

	sSameSql = L"insert into "+TblName+L" ";
	for (int i = 1; i <= ColCount; ++i)
	{
		strValue = ExcSh.OlePropertyGet("Cells", 1, i).OlePropertyGet("Value");

		//如果数据库中没有此字段或此字段的数据类型为自增类型那么就过滤掉
		if (mapColumns.count(strValue) == 0||mapColumns[strValue] == ftAutoInc)
		{
		   ++flag;
		   continue;
		}
		mapFields.insert(map<int, String>::value_type(i,strValue));
	}
	if(flag==ColCount) //如果没有一个字段与数据表相同 ，过滤失败，返回false
		return false;

	return true;
}
// ---------------------------------------------------------------------------
bool __fastcall TSqlExcel::Import(int row)  //把SQL中Values后面的部分组织好
{
	qryInsert->Close();
	String Value;
	String sql(L"(");

	map<int,String>::iterator iter = mapFields.begin();
	sFieldsSql = L"(";

	for(; iter != mapFields.end(); ++iter)
	{
		int i = iter->first;
		String f= iter->second;
		Value = ExcSh.OlePropertyGet("Cells", row,iter->first).OlePropertyGet("Value");

		if( Value == "" || Value == NULL)
			continue;

		sFieldsSql += (iter->second +L",");
		switch(mapColumns[ iter->second ])
		{
				/* 字段类型为可接收字符串的 */
		case ftWideString:
		case ftString:
		case ftWideMemo:
		case ftMemo:
			{
				sql += "'" + Value + "',";
				break;
			}
		case ftAutoInc:
			continue;
			break;

		/* 字段类型为只能接收整型的 */
		case ftInteger:
		case ftShortint:
			{
				try
				{
					if (Value == "")
					{
						sql += "0,";
					}
					else
					{
						StrToInt(Value);
						sql += Value + ",";
					}

				}
				catch(...)
				{
					return false;
				}
				break;
			}

				/* 浮点型的数据 */
		case ftFloat:
			{
				try
				{
					if (Value == "")
					{
						sql += "0,";
					}
					else
					{
						StrToFloat(Value);
						sql += Value + ",";
					}

				}
				catch(...)
				{
					return false;
				}
				break;
			}

				/* 日期时间类型 */
		case ftDateTime:
			{
				try
				{
					if (Value == "")
					{
						sql += "'',";
					}
					else
					{
						StrToDateTime(Value);
						sql += "'" + Value + "',";
					}

				}
				catch(...)
				{
					return false;
				}
				break;
			}

				/* 日期类型 */
		case ftDate:
			{
				try
				{
					if (Value == "")
					{
						sql += "'',";
					}
					else
					{
						StrToDate(Value);
						sql += "'" + Value + "',";
					}
				}
				catch(...)
				{
					return false;
				}
				break;
			}

				/* 布尔类型，规定true为是,false为否 */
		case ftBoolean:
			{
				if (Value == "" ||Value == "false" || Value == "否")
					sql += "false,";

				else if (Value == "是" || Value =="true")
				{
					sql += "true,";
				}

				else
				{
					return false;
				}

				break;
			}

				/* 其他也暂时不做处理 */
		default:
			{
				sql += "'',";
				break;
			}

		}
	}
	if(sFieldsSql == "(")
	{
        return false;
    }
	sFieldsSql = sFieldsSql.Delete(sFieldsSql.Length(),1);
	sFieldsSql += L") VALUES ";
	sql = sql.Delete(sql.Length(), 1);
	sql += ")";
	slImportSql->Add(sSameSql + sFieldsSql + sql);
	return true;
}
// ---------------------------------------------------------------------------
void __fastcall TSqlExcel::InitAllSql()
{
	this->slImportSql->Clear();
	for(int i = 2; i <= RowCount; ++i)
	{
		Import(i);
	}
}
//----------------------------------------------------------------------------
bool __fastcall TSqlExcel::Insert()
{

	int i;
	for (i = 0; i < slImportSql->Count; ++i)
	{
		try
		{
			qryInsert->Close();
			qryInsert->SQL->Clear();
			qryInsert->SQL->Text = slImportSql->Strings[i];
			qryInsert->ExecSQL();
		}
		catch(...)
		{
			  return false;
		}
	}
	slImportSql->Clear();    //读取完后，清空内容
	return true;
}
// ---------------------------------------------------------------------------

