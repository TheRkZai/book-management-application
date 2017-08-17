#if !defined(AFX_DataManage_H__84630933_D9C6_4D50_9A96_30D37ECB565C__INCLUDED_)
#define AFX_DataManage_H__84630933_D9C6_4D50_9A96_30D37ECB565C__INCLUDED_

#include "VendDlg1.h"
#include "DataDlg.h"	// Added by ClassView
#include "DataDlg1.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataManage dialog

class CDataManage : public CDialog
{
// Construction
public:
	void DoTab(int nPid);
	void SetDlgState(CWnd *pWnd, BOOL bShow);
	CDataDlg1 *datadlg1;
	CDataDlg *datadlg;
	CDataManage(CWnd* pParent = NULL);   // standard constructor
	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标
// Dialog Data
	//{{AFX_DATA(CDataManage)
	enum { IDD = IDD_STASTIC_DIALOG };
	CTabCtrl	m_StasticTab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeStasticTab(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMonth();
	afx_msg void OnRank();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DataManage_H__84630933_D9C6_4D50_9A96_30D37ECB565C__INCLUDED_)
