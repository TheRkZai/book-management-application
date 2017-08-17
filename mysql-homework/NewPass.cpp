// NewPass.cpp : 实现文件
//

#include "stdafx.h"
#include "BookManage.h"
#include "NewPass.h"
#include "afxdialogex.h"


// CNewPass 对话框

IMPLEMENT_DYNAMIC(CNewPass, CDialog)

CNewPass::CNewPass(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_NEW_PASSWORD, pParent)
	, m_NewPass(_T(""))
{

}

CNewPass::~CNewPass()
{
}

void CNewPass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NEW_PASS, m_NewPass);
}


BEGIN_MESSAGE_MAP(CNewPass, CDialog)
END_MESSAGE_MAP()


// CNewPass 消息处理程序
