#pragma once
#include "afxcmn.h"


// CVendDlg1 �Ի���

class CVendDlg1 : public CDialog
{
	DECLARE_DYNAMIC(CVendDlg1)

public:
	CVendDlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CVendDlg1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VEND_DIALOG_1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_VendList;

	MYSQL_RES *result;//�����ָ��
	MYSQL_ROW row;//�α�
	virtual BOOL OnInitDialog();
	void ShowVend();
};
