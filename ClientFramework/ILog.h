#pragma once

#include "stdafx.h"
#include "IModule.h"

interface ILog : public IModule
{
	// ¼Ì³ÐIModule
	virtual BOOL Initialize(IModule* UpperFrame=NULL) = 0;
	virtual BOOL UnInitialize() = 0;
	virtual int Run() = 0;
	virtual int Terminate() = 0 ;

	// ILog½Ó¿Ú
	virtual void SetLogFile(TCHAR* szFilePath,int nPathLength) = 0;
	virtual void SetLogLevel(int nLogLevel) = 0;
	virtual int SetLogFormat(TCHAR* szFormatStr,int nStrLength) = 0;

	virtual int WriteLog(int nLogLevel, const TCHAR*  szLogStr, int nLogLength) = 0;
};