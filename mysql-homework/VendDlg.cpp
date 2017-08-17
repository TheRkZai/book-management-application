// VendDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "VendDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVendDlg dialog


CVendDlg::CVendDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVendDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVendDlg)
	m_PucheCount = _T("");
	//}}AFX_DATA_INIT
}


void CVendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVendDlg)
	DDX_Text(pDX, IDC_PUCHECOUNT, m_PucheCount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVendDlg, CDialog)
	//{{AFX_MSG_MAP(CVendDlg)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_REFRESH_DATA, &CVendDlg::OnRefreshData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVendDlg message handlers
BOOL CVendDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	getcount = FALSE;
	return TRUE;
}

void CVendDlg::OnOk() //
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	getcount=TRUE;
	EndDialog(0);
}

void CVendDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	getcount=FALSE;
	EndDialog(0);
}


void CVendDlg::OnRefreshData()
{
	// TODO: 在此添加命令处理程序代码
}
