#pragma once


// CDataBaseBackUp �Ի���

class CDataBaseBackUp : public CDialog
{
	DECLARE_DYNAMIC(CDataBaseBackUp)

public:
	CDataBaseBackUp(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDataBaseBackUp();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BACKUP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonRestore();
};
