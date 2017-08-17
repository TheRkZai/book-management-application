// VendDlg2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BookManage.h"
#include "VendDlg2.h"
#include "afxdialogex.h"


// CVendDlg2 �Ի���

IMPLEMENT_DYNAMIC(CVendDlg2, CDialog)

CVendDlg2::CVendDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_VEND_DIALOG3, pParent)
	, m_strAuthor(_T(""))
	, m_strBookname(_T(""))
	, m_strC(_T(""))
{

}

CVendDlg2::~CVendDlg2()
{
}

void CVendDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_AUTHOR, m_strAuthor);
	DDX_Text(pDX, IDC_EDIT_BOOKNAME, m_strBookname);
	DDX_Text(pDX, IDC_EDIT_C, m_strC);
}


BEGIN_MESSAGE_MAP(CVendDlg2, CDialog)
	ON_COMMAND(ID_REFRESH_DATA, &CVendDlg2::OnRefreshData)
	ON_BN_CLICKED(IDCANCEL, &CVendDlg2::OnBnClickedCancel)
END_MESSAGE_MAP()


// CVendDlg2 ��Ϣ�������


void CVendDlg2::OnRefreshData()
{
	// TODO: �ڴ���������������
}


void CVendDlg2::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnCancel();
}
