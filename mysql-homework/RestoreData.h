#pragma once


// CRestoreData 对话框

class CRestoreData : public CDialog
{
	DECLARE_DYNAMIC(CRestoreData)

public:
	CRestoreData(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRestoreData();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonLoadPath();
	afx_msg void OnBnClickedButtonLoadStart();
};
