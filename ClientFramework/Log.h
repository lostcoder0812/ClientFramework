#pragma once
#include "ILog.h"


namespace log4cplus
{
	class Logger;
}

enum enumLogLevel{LogLevel_Trace,LogLevel_Debug,LogLevel_Info,LogLevel_Warn,LogLevel_Error,LogLevel_Fatal};

class CLog :
	public ILog
{
public:
	CLog(void);
	~CLog(void);

	virtual BOOL Initialize( IModule* UpperFrame=NULL );
	virtual BOOL UnInitialize();
	
	virtual int Run();
	virtual int Terminate();

	void SetLogFile(TCHAR* szFilePath,int nPathLength);
	void SetLogLevel(int nLogLevel);
	int SetLogFormat(TCHAR* szFormatStr,int nStrLength);

	int WriteLog(int nLogLevel, const TCHAR*  szLogStr, int nLogLength);

private:
	log4cplus::Logger* m_pLogger;
};

