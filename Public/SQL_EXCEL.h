//---------------------------------------------------------------------------

#ifndef SQL_EXCELH
#define SQL_EXCELH
#include <Classes.hpp>
#include <map>
#include<vector>
#include <DB.hpp>	// Pascal unit
//#include <Excel_2k.h>
#include <ADODB.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
using namespace std;
//---------------------------------------------------------------------------

class TSqlExcel
{
	public :
	__fastcall TSqlExcel(map<String,TFieldType> Col,TADOConnection * con = NULL);
	__fastcall ~TSqlExcel();

	//打开需要导进的Excel文档，并用ColCount记录对应的列数，用RowCount记录行数
	//打开方式通过路径打开
	void __fastcall Open(String Path);

	//关闭打开的对应的Excel文档
	void __fastcall Close();

	bool __fastcall FilterCells(String TblName);//过滤掉数据库中没有的字段


	bool __fastcall Import(int row);   //提取Excel的内容,成功即返回true，否则返回false

	bool __fastcall Insert();     //往数据库提交sql语句
	int __fastcall GetRowCount();
	int __fastcall GetColCount();
	void __fastcall InitAllSql();

	private :
	Variant ExcelApp; // 应用对象
	Variant ExcWB; // 工作簿对象
	Variant ExcSh; // 工作表对象

	int RowCount, ColCount;   /*分别为Excel表格中有数据的总行数、列数*/

	String sFieldsSql;
	String sSameSql;//保存每一条Sql语句的共同部分，为了添加到 slImportSql里面
	TStringList *slImportSql; // 每通过一行的检查就添加一句插入数据库表的语句，最后执行

	//TStringList *slRowValues;    //记录读入表格的行的内容
	map<String, TFieldType> mapColumns;	//字段名+数据类型

	map<int,String> mapFields;//过滤掉数据库表中没有的字段,Excle中的序号+字段名

	TADOQuery * qryInsert;
};


#endif
