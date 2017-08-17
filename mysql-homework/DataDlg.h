#if !defined(AFX_datadlg_H__F3331EC2_BCEF_4BF9_B802_B4D96544C956__INCLUDED_)
#define AFX_datadlg_H__F3331EC2_BCEF_4BF9_B802_B4D96544C956__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataDlg dialog

class CDataDlg : public CDialog
{
// Construction
public:
	CDataDlg(CWnd* pParent = NULL);   // standard constructor
	void ShowVendDay();

// Dialog Data
	//{{AFX_DATA(CDataDlg)
	enum { IDD = IDD_STASTIC_DIALOG2 };
	CListCtrl	m_VendMonthList;
	//}}AFX_DATA
	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataDlg)
	virtual BOOL OnInitDialog();
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedVendbydayList(NMHDR *pNMHDR, LRESULT *pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_datadlg_H__F3331EC2_BCEF_4BF9_B802_B4D96544C956__INCLUDED_)
