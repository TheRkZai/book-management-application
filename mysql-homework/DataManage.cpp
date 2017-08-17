// DataManage.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "DataManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataManage dialog
extern int PID;
extern MYSQL mysql;
CDataManage::CDataManage(CWnd* pParent /*=NULL*/)
	: CDialog(CDataManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDataManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataManage)
	DDX_Control(pDX, IDC_STASTIC_TAB, m_StasticTab);
	//}}AFX_DATA_MAP
}

CDataManage p_data;

BEGIN_MESSAGE_MAP(CDataManage, CDialog)
	//{{AFX_MSG_MAP(CDataManage)
	ON_NOTIFY(TCN_SELCHANGE, IDC_STASTIC_TAB, OnSelchangeStasticTab)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_MONTH, &CDataManage::OnMonth)
	ON_COMMAND(ID_RANK, &CDataManage::OnRank)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataManage message handlers
BOOL CDataManage::OnInitDialog()//图书销售统计管理
{
	CDialog::OnInitDialog();
	
	datadlg = new CDataDlg();
	datadlg1 = new CDataDlg1();
	//将对话框贴在标签上...
	datadlg->Create(IDD_STASTIC_DIALOG2,&m_StasticTab);
	datadlg1->Create(IDD_STASTIC_DIALOG3,&m_StasticTab);

	m_StasticTab.InsertItem(0,"月销售量",0);
	m_StasticTab.InsertItem(1,"销售排行榜",1);
	m_StasticTab.SetMinTabWidth(100);
	m_StasticTab.SetCurSel(PID);
	DoTab(PID);
	return TRUE;
}

void CDataManage::OnSelchangeStasticTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int select = m_StasticTab.GetCurSel();
	if(select >= 0)
		DoTab(select);
	*pResult = 0;
}

void CDataManage::SetDlgState(CWnd *pWnd, BOOL bShow)
{
	pWnd->EnableWindow(bShow);
	if(bShow)
	{
		pWnd->ShowWindow(SW_SHOW);
		pWnd->CenterWindow();
	}
	else
		pWnd->ShowWindow(SW_HIDE);
}

void CDataManage::DoTab(int nPid)
{
	if(nPid > 2) nPid = 2;
	if(nPid < 0) nPid =	0;
	
	BOOL iPid[2];
	iPid[0]=iPid[1]=FALSE;
	iPid[nPid]=TRUE;

	SetDlgState(datadlg,iPid[0]);
	SetDlgState(datadlg1,iPid[1]);
}


void CDataManage::OnMonth()
{
	// TODO: 在此添加命令处理程序代码
	this->DoTab(0);
}


void CDataManage::OnRank()
{
	// TODO: 在此添加命令处理程序代码
	this->DoTab(1);
}
