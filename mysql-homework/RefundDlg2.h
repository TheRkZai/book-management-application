#if !defined(AFX_REFUNDDLG2_H__0913A3D9_1FA9_4D0C_B015_0F9A1A11D60E__INCLUDED_)
#define AFX_REFUNDDLG2_H__0913A3D9_1FA9_4D0C_B015_0F9A1A11D60E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RefundDlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRefundDlg2 dialog

class CRefundDlg2 : public CDialog
{
// Construction
public:
	CRefundDlg2(CWnd* pParent = NULL);   // standard constructor
	void ShowRefund();

	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标
// Dialog Data
	//{{AFX_DATA(CRefundDlg2)
	enum { IDD = IDD_REFUND_DIALOG2 };
	CListCtrl	m_RefundList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRefundDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRefundDlg2)
	virtual BOOL OnInitDialog();
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedRefundList(NMHDR *pNMHDR, LRESULT *pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REFUNDDLG2_H__0913A3D9_1FA9_4D0C_B015_0F9A1A11D60E__INCLUDED_)
