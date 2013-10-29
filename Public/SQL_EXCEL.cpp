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
	mapColumns.clear();           //��������������

	/*�������StringList��ɾ��*/
	slImportSql->Clear();
	delete slImportSql;

	delete qryInsert;
}

// ---------------------------------------------------------------------------
void __fastcall TSqlExcel::Open(String Path)
{
	ExcelApp = Variant::CreateObject("Excel.Application");
	ExcelApp.OlePropertySet("Visible", false); // ����Ϊ���ɼ�
	WideString PathTmp(Path);

	ExcelApp.OlePropertyGet("WorkBooks").OleProcedure("Open", PathTmp);

	ExcWB = ExcelApp.OlePropertyGet("ActiveWorkBook");
	ExcSh = ExcWB.OlePropertyGet("ActiveSheet");

	ColCount = ExcSh.OlePropertyGet("UsedRange").OlePropertyGet("Columns")
		.OlePropertyGet("Count"); // ����
	RowCount = ExcSh.OlePropertyGet("UsedRange").OlePropertyGet("Rows")
		.OlePropertyGet("Count"); // ����
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
	return ColCount;   //���ص���ԭ��Excel���ֶ���
}
// ---------------------------------------------------------------------------


//----------------------------------------------------------------------------
bool __fastcall TSqlExcel::FilterCells(String TblName)
{
	//���˵����ݿ���û�е��ֶ�
	int flag(0);  //�����ж��Ƿ���û��һ���ֶ�ƥ�����ݿ��еı��
	String strValue;

	sSameSql = L"insert into "+TblName+L" ";
	for (int i = 1; i <= ColCount; ++i)
	{
		strValue = ExcSh.OlePropertyGet("Cells", 1, i).OlePropertyGet("Value");

		//������ݿ���û�д��ֶλ���ֶε���������Ϊ����������ô�͹��˵�
		if (mapColumns.count(strValue) == 0||mapColumns[strValue] == ftAutoInc)
		{
		   ++flag;
		   continue;
		}
		mapFields.insert(map<int, String>::value_type(i,strValue));
	}
	if(flag==ColCount) //���û��һ���ֶ������ݱ���ͬ ������ʧ�ܣ�����false
		return false;

	return true;
}
// ---------------------------------------------------------------------------
bool __fastcall TSqlExcel::Import(int row)  //��SQL��Values����Ĳ�����֯��
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
				/* �ֶ�����Ϊ�ɽ����ַ����� */
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

		/* �ֶ�����Ϊֻ�ܽ������͵� */
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

				/* �����͵����� */
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

				/* ����ʱ������ */
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

				/* �������� */
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

				/* �������ͣ��涨trueΪ��,falseΪ�� */
		case ftBoolean:
			{
				if (Value == "" ||Value == "false" || Value == "��")
					sql += "false,";

				else if (Value == "��" || Value =="true")
				{
					sql += "true,";
				}

				else
				{
					return false;
				}

				break;
			}

				/* ����Ҳ��ʱ�������� */
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
	slImportSql->Clear();    //��ȡ����������
	return true;
}
// ---------------------------------------------------------------------------

