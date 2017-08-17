#pragma once


// CNewPass 对话框

class CNewPass : public CDialog
{
	DECLARE_DYNAMIC(CNewPass)

public:
	CNewPass(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewPass();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW_PASSWORD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_NewPass;
};
