//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <condefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SysUtils.hpp>
#include <WebBroker.hpp>
#include <CGIApp.hpp>
//---------------------------------------------------------------------------
#pragma hdrstop
USEFORM("Unit15_2.cpp", WebModule1);
//---------------------------------------------------------------------------
#define Application Webbroker::Application
#pragma link "cgiapp.obj"
#pragma link "webbroker.obj"
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TWebModule1), &WebModule1);
                 Application->Run();
	}
	catch (Exception &exception)
	{
		Sysutils::ShowException(&exception, System::ExceptAddr());
	}
	return 0;
}
//---------------------------------------------------------------------------
