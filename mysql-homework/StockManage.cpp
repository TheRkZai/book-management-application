// StockManage.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "StockManage.h"
#include "StockDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockManage dialog


extern int PID;
extern MYSQL mysql;

CStockManage::CStockManage(CWnd* pParent /*=NULL*/)
	: CDialog(CStockManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStockManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CStockManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStockManage)
	DDX_Control(pDX, IDC_STOCK_TAB, m_StockTab);
	//}}AFX_DATA_MAP
}

//公共对象...
CStockManage p_stock;

BEGIN_MESSAGE_MAP(CStockManage, CDialog)
	//{{AFX_MSG_MAP(CStockManage)
	ON_NOTIFY(TCN_SELCHANGE, IDC_STOCK_TAB, OnSelchangeStockTab)

	//}}AFX_MSG_MAP
	ON_COMMAND(ID_REFRESH, &CStockManage::OnRefresh)
	ON_COMMAND(ID_EXIT, &CStockManage::OnExit)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockManage message handlers
BOOL CStockManage::OnInitDialog()//进货管理模块
{
	CDialog::OnInitDialog();

	stockdlg1 = new CStockDlg1();
	stockdlg2 = new CStockDlg2();
	//将对话框贴在标签上...
	stockdlg1->Create(IDD_STOCK_DIALOG1,&m_StockTab);
	stockdlg2->Create(IDD_STOCK_DIALOG2,&m_StockTab);

	m_StockTab.InsertItem(0,"进货记录",0);
	m_StockTab.InsertItem(1,"供货商报价",1);
	m_StockTab.SetMinTabWidth(100);
	m_StockTab.SetCurSel(PID);
	DoTab(PID);

	bit = 0;
	HasSupp = FALSE;
	return TRUE;
}

void CStockManage::SetDlgState(CWnd *pWnd, BOOL bShow)
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

void CStockManage::DoTab(int nPid)
{
	if(nPid > 1) nPid = 1;
	if(nPid < 0) nPid =	0;
	
	BOOL iPid[2];
	iPid[0]=iPid[1]=FALSE;
	iPid[nPid]=TRUE;

	SetDlgState(stockdlg1,iPid[0]);
	SetDlgState(stockdlg2,iPid[1]);
}
//单击标签触发换页...
void CStockManage::OnSelchangeStockTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int select = m_StockTab.GetCurSel();
	if(select >= 0)
		DoTab(select);
	*pResult = 0;
	stockdlg1->m_StockList.DeleteAllItems();
	stockdlg1->ShowStock();
}


void CStockManage::OnRefresh()
{
	// TODO: 在此添加命令处理程序代码
	stockdlg1->m_StockList.DeleteAllItems();
	stockdlg1->ShowStock();
}


void CStockManage::OnExit()
{
	// TODO: 在此添加命令处理程序代码
	EndDialog(0);
}
