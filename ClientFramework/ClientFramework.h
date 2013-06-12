
// ClientFramework.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "IModule.h"

#include "ILog.h"
// CClientFrameworkApp:
// 有关此类的实现，请参阅 ClientFramework.cpp
//

class CClientFrameworkApp : public CWinApp ,public IModule
{
public:
	CClientFrameworkApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()

	virtual BOOL UnInitialize();
	virtual BOOL Initialize( IModule* UpperFrame=NULL );
	virtual int Run();
	virtual int Terminate();

private:
	ILog* m_pLog;
};

extern CClientFrameworkApp theApp;