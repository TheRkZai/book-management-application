#pragma once
#include "afxwin.h"


// UserInfo 对话框

class UserInfo : public CDialog
{
	DECLARE_DYNAMIC(UserInfo)

public:
	UserInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UserInfo();
	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标
	CString password;
	CString rank;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonChangeUsername();
	afx_msg void OnBnClickedButtonPass();
	CString m_User;
	afx_msg void OnBnClickedButtonRegister();
};
