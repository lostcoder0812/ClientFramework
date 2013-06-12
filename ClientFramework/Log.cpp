#include "StdAfx.h"



#include <log4cplus/layout.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

#include "Log.h"


CLog::CLog(void)
{
}


CLog::~CLog(void)
{
}

BOOL CLog::UnInitialize()
{
	return TRUE;
}

BOOL CLog::Initialize( IModule* UpperFrame/*=NULL */ )
{
	// ��/MTģʽ����
#ifndef _DLL
	log4cplus::initialize();
#endif

	m_pLogger = new log4cplus::Logger();
	*m_pLogger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("Logger"));
	return TRUE;
}

int CLog::Run()
{
	return 0;
}

int CLog::Terminate()
{
	return 0;
}

void CLog::SetLogFile( TCHAR* szFilePath,int nPathLength )
{
	// ���������Appender��ֱ�Ӽ����µ�
	log4cplus::SharedAppenderPtr oldFileAppenderPtr = m_pLogger->getAppender(LOG4CPLUS_TEXT("FileAppender"));
	if (m_pLogger->getAppender(LOG4CPLUS_TEXT("FileAppender")) == NULL)
	{
		log4cplus::SharedAppenderPtr newAppenderPtr(new log4cplus::FileAppender(szFilePath));
		newAppenderPtr->setName(LOG4CPLUS_TEXT("FileAppender"));
		m_pLogger->addAppender(newAppenderPtr);
	}
	else
	{
		// ��ȡ��ʽ
		std::auto_ptr<log4cplus::Layout> LayoutPtr((oldFileAppenderPtr->getLayout()));

		// ���ð�����·����Appender��������ԭ���ĸ�ʽ
		log4cplus::SharedAppenderPtr newAppenderPtr(new log4cplus::FileAppender(szFilePath));
		newAppenderPtr->setName(LOG4CPLUS_TEXT("FileAppender"));
		newAppenderPtr->setLayout(LayoutPtr);

		// �Ƴ�ԭ����Appender������������·����Appender
		m_pLogger->removeAppender(LOG4CPLUS_TEXT("FileAppender"));
		m_pLogger->addAppender(newAppenderPtr);
	}
	
}

void CLog::SetLogLevel( int nLogLevel )
{
	m_pLogger->setLogLevel(nLogLevel);
}

int CLog::SetLogFormat( TCHAR* szFormatStr,int nStrLength )
{
	std::auto_ptr<log4cplus::Layout> newLayoutPtr(new log4cplus::PatternLayout(szFormatStr));
	m_pLogger->getAppender(LOG4CPLUS_TEXT("FileAppender"))->setLayout(newLayoutPtr);

	return 0;
}

int CLog::WriteLog( int nLogLevel, const TCHAR* szLogStr, int nLogLength )
{
	if (!m_pLogger)
	{
		return -1;
	}

	switch(nLogLevel)
	{
	case LogLevel_Trace:
		LOG4CPLUS_TRACE(*m_pLogger, szLogStr);
		break;
		
	case LogLevel_Debug:
		LOG4CPLUS_DEBUG(*m_pLogger, szLogStr);
		break;

	case LogLevel_Info:
		LOG4CPLUS_INFO(*m_pLogger, szLogStr);
		break;

	case LogLevel_Warn:
		LOG4CPLUS_WARN(*m_pLogger, szLogStr);
		break;

	case LogLevel_Error:
		LOG4CPLUS_ERROR(*m_pLogger, szLogStr);
		break;

	case LogLevel_Fatal:
		LOG4CPLUS_FATAL(*m_pLogger,szLogStr);
		break;
	default:
		break;
	}

	return 0;
}
