#pragma once
#include "afxwin.h"


// CNewUser �Ի���

class CNewUser : public CDialog
{
	DECLARE_DYNAMIC(CNewUser)

public:
	CNewUser(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewUser();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CREATE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_UserName;
	CString m_PassWord;
	CComboBox m_RANK;
	virtual BOOL OnInitDialog();
	CString m_RANK_string;
};
