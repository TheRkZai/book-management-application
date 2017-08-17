#if !defined(AFX_VENDDLG_H__F0CACB22_E161_41EE_81B0_1B29A934A5EF__INCLUDED_)
#define AFX_VENDDLG_H__F0CACB22_E161_41EE_81B0_1B29A934A5EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VendDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVendDlg dialog

class CVendDlg : public CDialog
{
// Construction
public:
	CVendDlg(CWnd* pParent = NULL);   // standard constructor

	BOOL getcount;
// Dialog Data
	//{{AFX_DATA(CVendDlg)
	enum { IDD = IDD_VEND_DIALOG1 };
	CString	m_PucheCount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVendDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVendDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnOk();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRefreshData();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VENDDLG_H__F0CACB22_E161_41EE_81B0_1B29A934A5EF__INCLUDED_)
