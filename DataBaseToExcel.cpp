//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------


































USEFORM("Module\NewTabForm.cpp", FrmNewTab);
USEFORM("Module\LoadInForm.cpp", FrmLoadIn);
USEFORM("MainForm.cpp", FrmMain);
USEFORM("Module\DBLogInOutForm.cpp", FrmDBLogInOut);
USEFORM("Module\ConnectForm.cpp", FrmConnect);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFrmMain), &FrmMain);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
