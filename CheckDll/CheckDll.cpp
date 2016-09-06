// CheckDll.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <afx.h>
#include <minwindef.h>

//typedef�뺯��test01������ͬ�ĺ���ָ��ΪTESTDLL01
typedef int (_cdecl * TESTDLL01)(int ia, int ib, int ic);
typedef int (_cdecl * TESTDLL02)(int ia, int ib);

int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hmod;
	//���ض�̬���ӿ�CreateDll.dll
	hmod = LoadLibrary(_TEXT("../Debug/CreateDll.dll"));
	if(NULL == hmod)
	{
		printf("����CreateDll.dllʧ��");
		TRACE("����CreateDll.dllʧ��");
	}

	//����һ���뺯��TestFuction������ͬ�ĺ���ָ��lpproc
	TESTDLL01 lpproc01;
	TESTDLL02 lpproc02;
	//����CreateDll.dll�к�����ΪTestFuction�Ķ���ӿ�
	lpproc01 = (TESTDLL01)GetProcAddress(hmod, "test01");
	lpproc02 = (TESTDLL02)GetProcAddress(hmod, "test02");

	//��������ɹ�
	if(NULL != lpproc01 && NULL != lpproc02)
	{
		printf("Test DLL values: %d \n", lpproc01(1, 2, 3));
		printf("Test DLL values: %d \n\n", lpproc02(5, 2));
	}else{
		printf("Call function Test01 failed!\n\n");
		TRACE1("%d ", GetLastError());
	}

	//��ǡ����ʱ���ͷŶ�̬���ӿ�CreateDll.dll
	FreeLibrary(hmod);

	/*************************************************
	printf("Simple DLL test start. \n\n");

	printf("Call DLL test01 function: \n");
	printf("Test DLL values: %d \n", test01(1, 2, 3));
	printf("Call DLL test01 function end. \n\n");

	printf("Call DLL test02 function: \n");
	printf("Test DLL test02 values: %d \n", test02(5, 2));
	printf("Call DLL test02 function end. \n\n");

	printf("Simple DLL test end. \n");
	*************************************************/
	getchar();
	return 0;
}

