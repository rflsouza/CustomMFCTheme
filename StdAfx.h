// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#include <afxhtml.h>
#include <afxdisp.h>        // MFC Automation classes



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>	// MFC support for ribbon and control bars
#include <afxcontrolbars.h>

#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif



//Cores do Sistema.
enum SystemColors : COLORREF
{
	// #ffffff (Branco)
	WHITE = RGB(255, 255, 255),
	// #000000 (Preto)
	BLACK = RGB(0, 0, 0),
	// #ff0000 (Vermelho)
	RED = RGB(255, 0, 0),

	//// CORES AZUL
	//// #001A2D 
	//DarkPrimary = RGB(0, 51, 90),
	//// #00233C 
	//DarkSecundary = RGB(0, 69, 120),
	//// #00335A
	//DarkComplementary_1 = RGB(0, 101, 178),
	//// #0065B2
	//DarkComplementary_2 = RGB(0, 129, 228),
	////  #80A3BC
	//LightPrimary = RGB(128, 163, 188),
	//// #BFD1DD
	//LightSecundary = RGB(191, 209, 221)

	// Plataforma
	// #3E464E
	DarkPrimary = RGB(62, 70, 78),
	// #5d6d7d(azul opaco)
	DarkSecundary = RGB(93, 109, 125),
	// #5894a1(verde opaco)
	DarkComplementary_1 = RGB(88, 148, 161),
	// #9f9f9f(cinza)
	DarkComplementary_2 = RGB(159, 159, 159),
	// #ededed(cinza bem claro para fundos)
	LightPrimary = RGB(240, 240, 240),
	// #ededed(cinza bem claro para fundos)
	LightSecundary = RGB(250, 250, 250),
	// #ced4c5(cinza claro para abas selecionadas)
	LightComplementary_1 = RGB(206, 212, 225)
};