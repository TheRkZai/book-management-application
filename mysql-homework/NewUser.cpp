// NewUser.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BookManage.h"
#include "NewUser.h"
#include "afxdialogex.h"


// CNewUser �Ի���

IMPLEMENT_DYNAMIC(CNewUser, CDialog)

CNewUser::CNewUser(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_CREATE, pParent)
	, m_UserName(_T(""))
	, m_PassWord(_T(""))
	, m_RANK_string(_T(""))
{

}

CNewUser::~CNewUser()
{
}

void CNewUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USER, m_UserName);
	DDX_Text(pDX, IDC_EDIT_PASS, m_PassWord);
	DDX_Control(pDX, IDC_COMBO_RANK, m_RANK);
	DDX_CBString(pDX, IDC_COMBO_RANK, m_RANK_string);
}


BEGIN_MESSAGE_MAP(CNewUser, CDialog)
END_MESSAGE_MAP()


// CNewUser ��Ϣ�������


BOOL CNewUser::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_RANK.AddString("������");
	m_RANK.AddString("ְ��");
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
