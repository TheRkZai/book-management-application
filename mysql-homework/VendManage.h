#if !defined(AFX_VENDMANAGE_H__4C5252A5_6D1A_44A6_848A_8119BE864F49__INCLUDED_)
#define AFX_VENDMANAGE_H__4C5252A5_6D1A_44A6_848A_8119BE864F49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VendManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVendManage dialog

class CVendManage : public CDialog
{
// Construction
public:
	CVendManage(CWnd* pParent = NULL);   // standard constructor
	void ShowStorage();

	int m_AddIndex;
	int m_DelIndex;
// Dialog Data
	//{{AFX_DATA(CVendManage)
	enum { IDD = IDD_VEND_DIALOG };
	CListCtrl	m_PucheList;
	CListCtrl	m_StorageList;
	CString	m_strAuthor;
	CString	m_strBookname;
	CString	m_strC;
	//}}AFX_DATA

	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVendManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVendManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnExitVend();
	afx_msg void OnAddbook();
	afx_msg void OnClickStorageList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickPucheList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMinusbook();
	afx_msg void OnPuche();
	afx_msg void OnClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedStorageList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnFind();
	afx_msg void OnRefreshData();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VENDMANAGE_H__4C5252A5_6D1A_44A6_848A_8119BE864F49__INCLUDED_)
