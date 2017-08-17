#if !defined(AFX_STOCKDLG1_H__1E4C773D_998D_4FA7_AA5B_A8034BD53E2E__INCLUDED_)
#define AFX_STOCKDLG1_H__1E4C773D_998D_4FA7_AA5B_A8034BD53E2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StockDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStockDlg1 dialog

class CStockDlg1 : public CDialog
{
// Construction
public:
	CStockDlg1(CWnd* pParent = NULL);   // standard constructor
	void ShowStock();

	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标
// Dialog Data
	//{{AFX_DATA(CStockDlg1)
	enum { IDD = IDD_STOCK_DIALOG1 };
	CListCtrl	m_StockList;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStockDlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStockDlg1)
	virtual BOOL OnInitDialog();
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STOCKDLG1_H__1E4C773D_998D_4FA7_AA5B_A8034BD53E2E__INCLUDED_)
