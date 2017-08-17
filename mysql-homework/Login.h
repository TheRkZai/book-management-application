#if !defined(AFX_LOGIN_H__EFC62388_A7EC_4593_9F64_34FBAB65849A__INCLUDED_)
#define AFX_LOGIN_H__EFC62388_A7EC_4593_9F64_34FBAB65849A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog

class CLogin : public CDialog
{
// Construction
public:
	CLogin(CWnd* pParent = NULL);   // standard constructor
	MYSQL mysql_login;
	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标
// Dialog Data
	//{{AFX_DATA(CLogin)
	enum { IDD = IDD_LOGIN_DIALOG };
	CString	m_InputCode;
	CString	m_InputName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogin)
	afx_msg void OnCollate();
	afx_msg void OnQuit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__EFC62388_A7EC_4593_9F64_34FBAB65849A__INCLUDED_)
