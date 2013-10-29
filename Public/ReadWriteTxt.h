//---------------------------------------------------------------------------

#ifndef ReadWriteTxtH
#define ReadWriteTxtH

#include <fstream>
#include <stdlib>
#include <System.Classes.hpp>
using std::ifstream;
using std::ofstream;
using std::string;

class ReadWriteTxt
{
	public:
		ReadWriteTxt():sFileName("_DataBaseAndTableSetting.txt"),PathSize(300),
					DBPath(new char[PathSize]),TabName(new char[PathSize]){}
		~ReadWriteTxt()
		{
			delete []DBPath;
			delete []TabName;
        }

		String GetDBPath();
		String GetTabName();
		bool SaveSetting(const String &DB, const String &Tab);
	private:
		void __OpenFile();

		ifstream ReadFile;
		ofstream WriteFile;
		const String sFileName;
		const int PathSize;
		char *DBPath;
		char *TabName;
};
//---------------------------------------------------------------------------
#endif
