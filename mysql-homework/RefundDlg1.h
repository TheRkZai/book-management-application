#if !defined(AFX_REFUNDDLG1_H__0A1F4631_37D1_413A_A60A_E2FE2E82E85F__INCLUDED_)
#define AFX_REFUNDDLG1_H__0A1F4631_37D1_413A_A60A_E2FE2E82E85F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RefundDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRefundDlg1 dialog

class CRefundDlg1 : public CDialog
{
// Construction
public:
	CRefundDlg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRefundDlg1)
	enum { IDD = IDD_REFUND_DIALOG1 };
	CString	m_ISBN;
	CString	m_Count;
	//}}AFX_DATA

	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRefundDlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRefundDlg1)
	afx_msg void OnRefundEnter();
	afx_msg void OnRefundClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REFUNDDLG1_H__0A1F4631_37D1_413A_A60A_E2FE2E82E85F__INCLUDED_)
