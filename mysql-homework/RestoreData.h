#pragma once


// CRestoreData �Ի���

class CRestoreData : public CDialog
{
	DECLARE_DYNAMIC(CRestoreData)

public:
	CRestoreData(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRestoreData();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonLoadPath();
	afx_msg void OnBnClickedButtonLoadStart();
};
