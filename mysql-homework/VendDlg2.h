#pragma once


// CVendDlg2 �Ի���

class CVendDlg2 : public CDialog
{
	DECLARE_DYNAMIC(CVendDlg2)

public:
	CVendDlg2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CVendDlg2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VEND_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strAuthor;
	CString m_strBookname;
	CString m_strC;
	afx_msg void OnRefreshData();
	afx_msg void OnBnClickedCancel();
};
