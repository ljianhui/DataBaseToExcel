//---------------------------------------------------------------------------

#pragma hdrstop

#include "ReadWriteTxt.h"
//---------------------------------------------------------------------------
void ReadWriteTxt::__OpenFile()
{
	ReadFile.open(sFileName.c_str(),ifstream::binary | ifstream::in);
	if(!ReadFile)
	{
		WriteFile.open(sFileName.c_str(),ofstream::binary | ofstream::out);
		*DBPath = '\0';
		*TabName = '\0';
		WriteFile.close();
		WriteFile.clear();
	}
	else
	{
		ReadFile.read(DBPath, PathSize);
		ReadFile.read(TabName, PathSize);
	}
	ReadFile.close();
	ReadFile.clear();
}
//---------------------------------------------------------------------------
String ReadWriteTxt::GetDBPath()
{
	__OpenFile();
	String stmp(DBPath);
	return stmp;
}
//--------------------------------------------------------------------------
String ReadWriteTxt::GetTabName()
{
	__OpenFile();
	String stmp(TabName);
	return stmp;
}
//-------------------------------------------------------------------------
bool ReadWriteTxt::SaveSetting(const String &DB, const String &Tab)
{
	WriteFile.open(sFileName.c_str(), ofstream::out|ofstream::binary);
	if(!WriteFile)
	{
		return false;
	}
	else
	{
		strcmp(DBPath, AnsiString(DB).c_str());
		strcmp(TabName, AnsiString(Tab).c_str());

		WriteFile.write(DBPath,PathSize);
		WriteFile.write(TabName,PathSize);

		WriteFile.close();
		WriteFile.clear();
		return true;
    }
}
#pragma package(smart_init)
