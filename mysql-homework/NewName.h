#pragma once


// CNewName �Ի���

class CNewName : public CDialog
{
	DECLARE_DYNAMIC(CNewName)

public:
	CNewName(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewName();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW_USERNAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_UserName;
};
