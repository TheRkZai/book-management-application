#pragma once


// CDataBaseBackUp 对话框

class CDataBaseBackUp : public CDialog
{
	DECLARE_DYNAMIC(CDataBaseBackUp)

public:
	CDataBaseBackUp(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDataBaseBackUp();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BACKUP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonRestore();
};
