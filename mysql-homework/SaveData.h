#pragma once


// CSaveData 对话框

class CSaveData : public CDialog
{
	DECLARE_DYNAMIC(CSaveData)

public:
	CSaveData(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSaveData();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SAVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSavePath();
	afx_msg void OnBnClickedButtonSaveStart();
	virtual BOOL OnInitDialog();
};
