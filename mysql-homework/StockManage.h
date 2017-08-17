#if !defined(AFX_STOCKMANAGE_H__8376CF4A_968C_4CE5_A74A_577B432D7C95__INCLUDED_)
#define AFX_STOCKMANAGE_H__8376CF4A_968C_4CE5_A74A_577B432D7C95__INCLUDED_

#include "StockDlg1.h"	// Added by ClassView
#include "StockDlg2.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StockManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStockManage dialog

class CStockManage : public CDialog
{
// Construction
public:
	void DoTab(int nPid);
	void SetDlgState(CWnd *pWnd,BOOL bShow);

	CStockDlg1 *stockdlg1;
	CStockDlg2 *stockdlg2;

	CStockManage(CWnd* pParent = NULL);   // standard constructor

	//供货商信息
	booksupply supply[50];
	int bit;
	//供货信息是否生成的信号量，true表示已生成
	BOOL HasSupp;
// Dialog Data
	//{{AFX_DATA(CStockManage)
	enum { IDD = IDD_STOCK_DIALOG };
	CTabCtrl	m_StockTab;
	//}}AFX_DATA

	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStockManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStockManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeStockTab(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnRefresh();
	afx_msg void OnExit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STOCKMANAGE_H__8376CF4A_968C_4CE5_A74A_577B432D7C95__INCLUDED_)
