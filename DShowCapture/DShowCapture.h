
// DShowCapture.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDShowCaptureApp: 
// �йش����ʵ�֣������ DShowCapture.cpp
//

class CDShowCaptureApp : public CWinApp
{
public:
	CDShowCaptureApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDShowCaptureApp theApp;