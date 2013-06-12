#pragma once
#include "stdafx.h"

interface IModule
{
public:
	// UpperFrame�ṩ���ϲ�Ľӿ�
	virtual BOOL Initialize(IModule* UpperFrame=NULL) = 0;
	virtual BOOL UnInitialize() = 0;

	// Run()�ṩ���ж����̵߳�ģ��ʹ��
	virtual int Run() = 0;
	//! Terminate֮���ģ�飬Ӧ������ͨ��Run�ٴ����á�UnInitialize���ģ���򲻿�
	virtual int Terminate() = 0 ;
	
};