#pragma once

#include "stdafx.h"
#include "IModule.h"



//	�����ļ������ӿ�
//	�����ļ���Ϊ����:File,Section,Item


interface IConfig : public IModule
{
public:
	// �̳�IModule
	virtual BOOL Initialize(IModule* UpperFrame=NULL) = 0;
	virtual BOOL UnInitialize() = 0;
	virtual int Run() = 0;
	virtual int Terminate() = 0 ;

	// IConfig�ӿ�

	// ����
	virtual BOOL FindConfig(const TCHAR* ConfigName);
	virtual BOOL FindSection(const TCHAR* szSectionName);
	virtual BOOL FindItem(const TCHAR* szItemName);


	// config����
	virtual int AddConfig(const TCHAR* szConfigPath,const TCHAR* szConfigName);
	virtual int SaveConfig(const TCHAR* szConfigName);

	// Section����
	virtual int SetSection(const TCHAR* szSectionName, const TCHAR* szConfigFilePath);
	virtual int ClearSection(const TCHAR* szSectionName);
	virtual int RemoveSection(const TCHAR* szSectionName);
	// ��ȡ����Section������
	virtual int GetSection(TCHAR* szSectionBuf, int nLen);

	// Item����
	// ���������,������������Ϊ��Ӧ��ֵ
	virtual int SetItem(const TCHAR* szSectionName,
		const TCHAR* szItemName, TCHAR* szVarBuf, int nVarLen);
	virtual int GetItem(const TCHAR* szSectionName,
		const TCHAR* szItemName, TCHAR* szVarBuf, int nVarLen);
	virtual int RemoveItem(const TCHAR* szSectionName, const TCHAR* szItemName);
};