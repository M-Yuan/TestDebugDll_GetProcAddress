// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include <iostream>
using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	printf("hModule.%p \n", hModule);
	printf("ul_reason_for_call.%d \n", ul_reason_for_call);
	printf("lpReserved.%p \n", lpReserved);
	printf("\n");

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("Process attach. \n\n");
		break;
	case DLL_PROCESS_DETACH:
		printf("Process detach. \n\n");
		break;
	case DLL_THREAD_ATTACH:
		printf("Thread attach. \n\n");
		break;
	case DLL_THREAD_DETACH:
		printf("Thread detach. \n\n");
		break;
	}
	return TRUE;
}

