
// ClientFramework.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "IModule.h"

interface ILog;
// CClientFrameworkApp:
// �йش����ʵ�֣������ ClientFramework.cpp
//

class CClientFrameworkApp : public CWinApp ,public IModule
{
public:
	CClientFrameworkApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()

	virtual BOOL UnInitialize();
	virtual BOOL Initialize( IModule* UpperFrame=NULL );
	virtual int Run();
	virtual int Terminate();

private:
	ILog* m_pLog;
};

extern CClientFrameworkApp theApp;