// NewName.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BookManage.h"
#include "NewName.h"
#include "afxdialogex.h"


// CNewName �Ի���

IMPLEMENT_DYNAMIC(CNewName, CDialog)

CNewName::CNewName(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_NEW_USERNAME, pParent)
	, m_UserName(_T(""))
{

}

CNewName::~CNewName()
{
}

void CNewName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NEW_NAME, m_UserName);
}


BEGIN_MESSAGE_MAP(CNewName, CDialog)
END_MESSAGE_MAP()


// CNewName ��Ϣ�������
