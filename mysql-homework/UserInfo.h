#pragma once
#include "afxwin.h"


// UserInfo �Ի���

class UserInfo : public CDialog
{
	DECLARE_DYNAMIC(UserInfo)

public:
	UserInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UserInfo();
	MYSQL_RES *result;//�����ָ��
	MYSQL_ROW row;//�α�
	CString password;
	CString rank;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonChangeUsername();
	afx_msg void OnBnClickedButtonPass();
	CString m_User;
	afx_msg void OnBnClickedButtonRegister();
};
