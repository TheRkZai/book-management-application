#pragma once


// CNewPass �Ի���

class CNewPass : public CDialog
{
	DECLARE_DYNAMIC(CNewPass)

public:
	CNewPass(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewPass();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW_PASSWORD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_NewPass;
};
