// BookManage.h : main header file for the BOOKMANAGE application
//

#if !defined(AFX_BOOKMANAGE_H__D2392840_CBF4_43C3_BB3C_AB060459C007__INCLUDED_)
#define AFX_BOOKMANAGE_H__D2392840_CBF4_43C3_BB3C_AB060459C007__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include <winsock.h>
#include "mysql.h"
/////////////////////////////////////////////////////////////////////////////
// CBookManageApp:
// See BookManage.cpp for the implementation of this class
//

class CBookManageApp : public CWinApp
{
public:
	CBookManageApp();

	void InitAdo();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookManageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBookManageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//¹«¹²¶¥²ãº¯Êý...
void	GetDate(CString &s);
int		str_to_int(CString s);
float	str_to_float(CString s);
void    processstring(CString &s);

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKMANAGE_H__D2392840_CBF4_43C3_BB3C_AB060459C007__INCLUDED_)
