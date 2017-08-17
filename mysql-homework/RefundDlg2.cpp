// RefundDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "RefundDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern MYSQL mysql;
/////////////////////////////////////////////////////////////////////////////
// CRefundDlg2 dialog

CRefundDlg2::CRefundDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CRefundDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRefundDlg2)
	//}}AFX_DATA_INIT
}


void CRefundDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRefundDlg2)
	DDX_Control(pDX, IDC_REFUND_LIST, m_RefundList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRefundDlg2, CDialog)
	//{{AFX_MSG_MAP(CRefundDlg2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_REFUND_LIST, &CRefundDlg2::OnLvnItemchangedRefundList)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRefundDlg2 message handlers
BOOL CRefundDlg2::OnInitDialog()
{
	CDialog::OnInitDialog();

	DWORD dwStyle=GetWindowLong(m_RefundList.GetSafeHwnd(),GWL_STYLE);
	dwStyle&=~LVS_TYPEMASK;
	dwStyle|=LVS_REPORT;
	SetWindowLong(m_RefundList.GetSafeHwnd(),GWL_STYLE,dwStyle);

	m_RefundList.InsertColumn(0,"序列号",LVCFMT_LEFT,80);
	m_RefundList.InsertColumn(1,"退货时间",LVCFMT_LEFT,110);
	m_RefundList.InsertColumn(2,"ISBN",LVCFMT_LEFT,100);
	m_RefundList.InsertColumn(3,"书名",LVCFMT_LEFT,130);
	m_RefundList.InsertColumn(4,"作者",LVCFMT_LEFT,90);
	m_RefundList.InsertColumn(5,"出版社",LVCFMT_LEFT,130);
	m_RefundList.InsertColumn(6,"出售价",LVCFMT_LEFT,80);
	m_RefundList.InsertColumn(7,"退货量",LVCFMT_LEFT,80);

	m_RefundList.SetExtendedStyle(LVS_EX_GRIDLINES);
    ::SendMessage(m_RefundList.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,
      LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	ShowRefund();
	return TRUE;
}

//显示进货记录...
void CRefundDlg2::ShowRefund()
{
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


	sql.Format("select * from bookrefund");
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
	m_RefundList.DeleteAllItems();
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		index = m_RefundList.InsertItem(m_RefundList.GetItemCount(),
			(TCHAR*)(_bstr_t)row[0]);
		for (int col = 1;col <8;col++)
			m_RefundList.SetItemText(index,col,(TCHAR*)(_bstr_t)row[col]);
	}
	
}

void CRefundDlg2::OnLvnItemchangedRefundList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
