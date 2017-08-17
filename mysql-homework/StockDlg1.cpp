// StockDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "StockDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern MYSQL mysql;
/////////////////////////////////////////////////////////////////////////////
// CStockDlg1 dialog

CStockDlg1::CStockDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CStockDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStockDlg1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CStockDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStockDlg1)
	DDX_Control(pDX, IDC_STOCK_LIST, m_StockList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStockDlg1, CDialog)
	//{{AFX_MSG_MAP(CStockDlg1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockDlg1 message handlers
BOOL CStockDlg1::OnInitDialog()
{
	CDialog::OnInitDialog();

	DWORD dwStyle=GetWindowLong(m_StockList.GetSafeHwnd(),GWL_STYLE);
	dwStyle&=~LVS_TYPEMASK;
	dwStyle|=LVS_REPORT;
	SetWindowLong(m_StockList.GetSafeHwnd(),GWL_STYLE,dwStyle);

	m_StockList.InsertColumn(0,"序列号",LVCFMT_LEFT,80);
	m_StockList.InsertColumn(1,"进货时间",LVCFMT_LEFT,80);
	m_StockList.InsertColumn(2,"ISBN",LVCFMT_LEFT,100);
	m_StockList.InsertColumn(3,"书名",LVCFMT_LEFT,130);
	m_StockList.InsertColumn(4,"作者",LVCFMT_LEFT,90);
	m_StockList.InsertColumn(5,"出版社",LVCFMT_LEFT,130);
	m_StockList.InsertColumn(6,"成本",LVCFMT_LEFT,80);
	m_StockList.InsertColumn(7,"进货量",LVCFMT_LEFT,80);

	m_StockList.SetExtendedStyle(LVS_EX_GRIDLINES);
    ::SendMessage(m_StockList.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,
      LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	ShowStock();
	return TRUE;
}

//显示进货记录...
void CStockDlg1::ShowStock(){

	CString sql;
	sql.Format("set @@tx_isolation='Serializable'");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		sql.Format("rollback");
		mysql_query(&mysql, sql);
		sql.Format("commit");
		mysql_query(&mysql, sql);
		return;
	}

	sql.Format("start transaction");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		sql.Format("rollback");
		mysql_query(&mysql, sql);
		sql.Format("commit");
		mysql_query(&mysql, sql);
		return;
	}

	sql.Format("select * from bookstock");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		sql.Format("rollback");
		mysql_query(&mysql, sql);
		sql.Format("commit");
		mysql_query(&mysql, sql);
		return;
	}
	result = mysql_store_result(&mysql);
	sql.Format("commit");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	int index = 0;
	m_StockList.DeleteAllItems();
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		index = m_StockList.InsertItem(m_StockList.GetItemCount(),
			(TCHAR*)(_bstr_t)row[0]);
		for(int col = 1;col <8;col++)
			m_StockList.SetItemText(index,col,(TCHAR*)(_bstr_t)row[col]);
	}
	
}