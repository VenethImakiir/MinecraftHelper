
// Minecraft Helper.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMinecraftHelperApp:
// See Minecraft Helper.cpp for the implementation of this class
//

class CMinecraftHelperApp : public CWinApp
{
public:
	CMinecraftHelperApp();

	unsigned int resTable[6];

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMinecraftHelperApp theApp;