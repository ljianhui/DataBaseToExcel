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

	//����Ҫ������Excel�ĵ�������ColCount��¼��Ӧ����������RowCount��¼����
	//�򿪷�ʽͨ��·����
	void __fastcall Open(String Path);

	//�رմ򿪵Ķ�Ӧ��Excel�ĵ�
	void __fastcall Close();

	bool __fastcall FilterCells(String TblName);//���˵����ݿ���û�е��ֶ�


	bool __fastcall Import(int row);   //��ȡExcel������,�ɹ�������true�����򷵻�false

	bool __fastcall Insert();     //�����ݿ��ύsql���
	int __fastcall GetRowCount();
	int __fastcall GetColCount();
	void __fastcall InitAllSql();

	private :
	Variant ExcelApp; // Ӧ�ö���
	Variant ExcWB; // ����������
	Variant ExcSh; // ���������

	int RowCount, ColCount;   /*�ֱ�ΪExcel����������ݵ�������������*/

	String sFieldsSql;
	String sSameSql;//����ÿһ��Sql���Ĺ�ͬ���֣�Ϊ����ӵ� slImportSql����
	TStringList *slImportSql; // ÿͨ��һ�еļ������һ��������ݿ�����䣬���ִ��

	//TStringList *slRowValues;    //��¼��������е�����
	map<String, TFieldType> mapColumns;	//�ֶ���+��������

	map<int,String> mapFields;//���˵����ݿ����û�е��ֶ�,Excle�е����+�ֶ���

	TADOQuery * qryInsert;
};


#endif
