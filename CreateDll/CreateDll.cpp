// CreateDll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

extern "C" __declspec(dllexport) int test01(int a, int b, int c)
{
	return a+b+c;
}

extern "C" __declspec(dllexport) int test02(int a, int b)
{
	return a-b;
}

