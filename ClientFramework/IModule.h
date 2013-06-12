#pragma once
#include "stdafx.h"

interface IModule
{
public:
	// UpperFrame提供了上层的接口
	virtual BOOL Initialize(IModule* UpperFrame=NULL) = 0;
	virtual BOOL UnInitialize() = 0;

	// Run()提供给有独立线程的模块使用
	virtual int Run() = 0;
	//! Terminate之后的模块，应当可以通过Run再次启用。UnInitialize后的模块则不可
	virtual int Terminate() = 0 ;
	
};