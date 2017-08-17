#if !defined(AFX_REFUNDMANAGE_H__8E1973A8_838E_44D0_81E0_85C42548AAE9__INCLUDED_)
#define AFX_REFUNDMANAGE_H__8E1973A8_838E_44D0_81E0_85C42548AAE9__INCLUDED_

#include "RefundDlg2.h"	// Added by ClassView
#include "RefundDlg1.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RefundManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRefundManage dialog

class CRefundManage : public CDialog
{
// Construction
public:
	void DoTab(int nPid);
	void SetDlgState(CWnd *pWnd, BOOL bShow);
	CRefundDlg2 *refunddlg2;
	CRefundDlg1 *refunddlg1;
	CRefundManage(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CRefundManage)
	enum { IDD = IDD_REFUND_DIALOG };
	CTabCtrl	m_RefundTab;
	//}}AFX_DATA
	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRefundManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRefundManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeRefundTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnExitRefund();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REFUNDMANAGE_H__8E1973A8_838E_44D0_81E0_85C42548AAE9__INCLUDED_)
