#pragma once


// CSaveData �Ի���

class CSaveData : public CDialog
{
	DECLARE_DYNAMIC(CSaveData)

public:
	CSaveData(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSaveData();
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SAVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSavePath();
	afx_msg void OnBnClickedButtonSaveStart();
	virtual BOOL OnInitDialog();
};
