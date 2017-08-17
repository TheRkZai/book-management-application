#pragma once
#include "afxcmn.h"


// CVendDlg1 对话框

class CVendDlg1 : public CDialog
{
	DECLARE_DYNAMIC(CVendDlg1)

public:
	CVendDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CVendDlg1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VEND_DIALOG_1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_VendList;

	MYSQL_RES *result;//结果集指针
	MYSQL_ROW row;//游标
	virtual BOOL OnInitDialog();
	void ShowVend();
};
