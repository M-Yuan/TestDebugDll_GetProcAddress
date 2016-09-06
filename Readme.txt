编译后：
1>------ 已启动生成: 项目: CheckDll, 配置: Debug Win32 ------
1>  stdafx.cpp
1>  CheckDll.cpp
1>c:\program files\microsoft visual studio 11.0\vc\atlmfc\include\afx.h(24): fatal error C1189: #error :  Building MFC application with /MD[d] (CRT dll version) requires MFC shared dll version. Please #define _AFXDLL or do not use /MD[d]
========== 生成: 成功 0 个，失败 1 个，最新 1 个，跳过 0 个 ==========


会出现该错误，修改方法：

在调用dll动态链接库的工程中（即CheckDll工程），选择属性，修改参数如下

工程--->设置--->常规--->然后选“使用mFC作为共享的DLL”

