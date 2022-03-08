
// Quan_li_mon_an_Nhom_16.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CQuanlimonanNhom16App:
// See Quan_li_mon_an_Nhom_16.cpp for the implementation of this class
//

class CQuanlimonanNhom16App : public CWinApp
{
public:
	CQuanlimonanNhom16App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CQuanlimonanNhom16App theApp;
