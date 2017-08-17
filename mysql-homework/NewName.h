#pragma once


// CNewName 对话框

class CNewName : public CDialog
{
	DECLARE_DYNAMIC(CNewName)

public:
	CNewName(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewName();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW_USERNAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_UserName;
};
