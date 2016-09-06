// CheckDll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <afx.h>
#include <minwindef.h>

//typedef与函数test01类型相同的函数指针为TESTDLL01
typedef int (_cdecl * TESTDLL01)(int ia, int ib, int ic);
typedef int (_cdecl * TESTDLL02)(int ia, int ib);

int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hmod;
	//加载动态链接库CreateDll.dll
	hmod = LoadLibrary(_TEXT("../Debug/CreateDll.dll"));
	if(NULL == hmod)
	{
		printf("加载CreateDll.dll失败");
		TRACE("加载CreateDll.dll失败");
	}

	//定义一个与函数TestFuction类型相同的函数指针lpproc
	TESTDLL01 lpproc01;
	TESTDLL02 lpproc02;
	//搜索CreateDll.dll中函数名为TestFuction的对外接口
	lpproc01 = (TESTDLL01)GetProcAddress(hmod, "test01");
	lpproc02 = (TESTDLL02)GetProcAddress(hmod, "test02");

	//如果搜索成功
	if(NULL != lpproc01 && NULL != lpproc02)
	{
		printf("Test DLL values: %d \n", lpproc01(1, 2, 3));
		printf("Test DLL values: %d \n\n", lpproc02(5, 2));
	}else{
		printf("Call function Test01 failed!\n\n");
		TRACE1("%d ", GetLastError());
	}

	//在恰当的时候释放动态链接库CreateDll.dll
	FreeLibrary(hmod);

	getchar();
	return 0;
}

