#pragma once


// CVendDlg2 对话框

class CVendDlg2 : public CDialog
{
	DECLARE_DYNAMIC(CVendDlg2)

public:
	CVendDlg2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CVendDlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VEND_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strAuthor;
	CString m_strBookname;
	CString m_strC;
	afx_msg void OnRefreshData();
	afx_msg void OnBnClickedCancel();
};
