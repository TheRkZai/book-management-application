#if !defined(AFX_datadlg1_H__2B36DB91_51C8_436F_BEFF_A99AFEFDFE86__INCLUDED_)
#define AFX_datadlg1_H__2B36DB91_51C8_436F_BEFF_A99AFEFDFE86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataDlg1 dialog

class CDataDlg1 : public CDialog
{
// Construction
public:
	CDataDlg1(CWnd* pParent = NULL);   // standard constructor
	void ShowVends();

// Dialog Data
	//{{AFX_DATA(CDataDlg1)
	enum { IDD = IDD_STASTIC_DIALOG3 };
	CListCtrl	m_VendsList;
	//}}AFX_DATA
	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataDlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataDlg1)
	virtual BOOL OnInitDialog();
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_datadlg1_H__2B36DB91_51C8_436F_BEFF_A99AFEFDFE86__INCLUDED_)
