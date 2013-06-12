
// ClientFramework.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "ClientFramework.h"
#include "ClientFrameworkDlg.h"

#include "Log.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientFrameworkApp

BEGIN_MESSAGE_MAP(CClientFrameworkApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CClientFrameworkApp ����

CClientFrameworkApp::CClientFrameworkApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	m_pLog = new CLog;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CClientFrameworkApp ����

CClientFrameworkApp theApp;


// CClientFrameworkApp ��ʼ��

BOOL CClientFrameworkApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	Initialize();
	m_pLog->WriteLog(LogLevel_Info,_T("Exec Start!"),0);
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CClientFrameworkDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	UnInitialize();
	return FALSE;
}

BOOL CClientFrameworkApp::UnInitialize()
{
	m_pLog->UnInitialize();

	return TRUE;
}

BOOL CClientFrameworkApp::Initialize( IModule* UpperFrame/*=NULL */ )
{
	m_pLog->Initialize();
	m_pLog->SetLogFile(_T("log.txt"),0);
	m_pLog->SetLogFormat(_T("%D      %m"),0);

	return TRUE;
}

int CClientFrameworkApp::Run()
{
	return 0;
}

int CClientFrameworkApp::Terminate()
{
	return TRUE;
}

