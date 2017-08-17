#if !defined(AFX_STOCKDLG2_H__7B987E53_91E1_4536_8931_F4A9380259EC__INCLUDED_)
#define AFX_STOCKDLG2_H__7B987E53_91E1_4536_8931_F4A9380259EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StockDlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStockDlg2 dialog

class CStockDlg2 : public CDialog
{
// Construction
public:
	CStockDlg2(CWnd* pParent = NULL);   // standard constructor
	int delIndex;
// Dialog Data
	//{{AFX_DATA(CStockDlg2)
	enum { IDD = IDD_STOCK_DIALOG2 };
	CListCtrl	m_StockSupplyList;
	CString	m_Author;
	CString	m_Count;
	CString	m_ISBN;
	CString	m_Name;
	CString	m_Price;
	CString	m_Supply;
	//}}AFX_DATA
	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStockDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStockDlg2)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickSupplyList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	afx_msg void OnBnClickedButtonStockAdd();
	afx_msg void OnBnClickedButtonStockSub();
	afx_msg void OnBnClickedButtonStockSave();
	afx_msg void OnBnClickedButtonStockQuery();
	afx_msg void OnBnClickedButtonStockConfirm();
	afx_msg void OnBnClickedButtonClear();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STOCKDLG2_H__7B987E53_91E1_4536_8931_F4A9380259EC__INCLUDED_)
