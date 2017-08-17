// Login.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "BookManageDlg.h"
#include "Login.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog

extern BOOL loginflag;
extern CString m_user;
extern MYSQL mysql;

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogin)
	m_InputCode = _T("1234");
	m_InputName = _T("root");
	//}}AFX_DATA_INIT
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Text(pDX, IDC_CODE, m_InputCode);
	DDX_Text(pDX, IDC_NAME, m_InputName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
	ON_BN_CLICKED(IDC_OK, OnCollate)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers
/* ��½ȷ�� */
void CLogin::OnCollate() //��½����ġ���½����ť
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_InputName.IsEmpty() || m_InputCode.IsEmpty())//�ж��û����������Ƿ�Ϊ��
	{
		MessageBox("�û��������벻��Ϊ��...","��ʾ!");
		return;
	}
	mysql_init(&mysql_login);
	processstring(m_InputName);
	processstring(m_InputCode);
	mysql_real_connect(&mysql_login, "localhost", m_InputName, m_InputCode, "booksalesmanagement", 3306, 0, 0);
	mysql_set_character_set(&mysql_login, "gbk");

	if (mysql_errno(&mysql_login))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql_login));
		MessageBox(err, "��ʾ��");
		return;
	}
	else
	{
		loginflag = TRUE;//�����û��ѵ�¼
		m_user = m_InputName;//�û�����Ϊ��½��
		mysql = mysql_login;
		EndDialog(0);//�رյ�¼���ڽ���������	
	}
}

void CLogin::OnQuit() //��½����ġ��˳�����ť
{
	// TODO: Add your control notification handler code here
	loginflag = FALSE;
	CDialog::OnCancel();
}

