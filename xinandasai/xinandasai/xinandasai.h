
// xinandasai.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "houtai.h"

// CxinandasaiApp:
// �йش����ʵ�֣������ xinandasai.cpp
//

class CxinandasaiApp : public CWinApp
{
public:
	CxinandasaiApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CxinandasaiApp theApp;