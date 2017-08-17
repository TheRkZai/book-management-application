#pragma once
#include "afxwin.h"


// CNewUser 对话框

class CNewUser : public CDialog
{
	DECLARE_DYNAMIC(CNewUser)

public:
	CNewUser(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewUser();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CREATE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_UserName;
	CString m_PassWord;
	CComboBox m_RANK;
	virtual BOOL OnInitDialog();
	CString m_RANK_string;
};
