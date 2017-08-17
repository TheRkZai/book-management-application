// BookManageDlg.h : header file
//

#if !defined(AFX_BOOKMANAGEDLG_H__5147D4CF_0AA3_467B_A70A_FFDCF3058EC8__INCLUDED_)
#define AFX_BOOKMANAGEDLG_H__5147D4CF_0AA3_467B_A70A_FFDCF3058EC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBookManageDlg dialog

class CBookManageDlg : public CDialog
{
// Construction
public:
	CBookManageDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
	//{{AFX_DATA(CBookManageDlg)
	enum { IDD = IDD_BOOKMANAGE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBookManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbout();
	afx_msg void OnExit();
	afx_msg void OnStockRecord();
	afx_msg void OnSupplyPrice();
	afx_msg void OnRefundRecord();
	afx_msg void OnRefundOpera();
	afx_msg void OnVendRecord();
	afx_msg void OnVendList();
	afx_msg void OnVendConsole();
	afx_msg void OnAddopera();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void SetInfor();
	afx_msg void OnVendBymonth();
	afx_msg void OnStnClickedTimeStatic();
	afx_msg void OnBnClickedButtonStock();
	afx_msg void OnBnClickedButtonRefund();
	afx_msg void OnBnClickedButtonData();
	afx_msg void OnBnClickedButtonVend();
	afx_msg void OnUser();
	afx_msg void OnBnClickedButtonUser();
	afx_msg void OnBnClickedButtonBackup();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKMANAGEDLG_H__5147D4CF_0AA3_467B_A70A_FFDCF3058EC8__INCLUDED_)
