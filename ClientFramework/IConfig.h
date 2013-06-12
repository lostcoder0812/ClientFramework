#pragma once

#include "stdafx.h"
#include "IModule.h"

interface IConfig : public IModule
{
public:
	// 继承IModule
	virtual BOOL Initialize(IModule* UpperFrame=NULL) = 0;
	virtual BOOL UnInitialize() = 0;
	virtual int Run() = 0;
	virtual int Terminate() = 0 ;

	// IConfig接口

	// Section操作
	virtual int AddSection(const TCHAR* szSectionName, const TCHAR* szConfigFilePath);
	virtual int ClearSection(const TCHAR* szSectionName);
	virtual int RemoveSection(const TCHAR* szSectionName);
	// 获取整个Section的配置
	virtual int GetSection(TCHAR* szSectionBuf, int nLen);

	// Item操作
	// 添加配置项,若存在则设置为相应的值
	virtual int SetItem(const TCHAR* szSectionName,
		const TCHAR* szItemName, TCHAR* szVarBuf, int nVarLen);
	virtual int GetItem(const TCHAR* szSectionName,
		const TCHAR* szItemName, TCHAR* szVarBuf, int nVarLen);
	virtual int RemoveItem(const TCHAR* szSectionName, const TCHAR* szItemName);
};