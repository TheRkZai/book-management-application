// datadlg1.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "DataDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern MYSQL mysql;
/////////////////////////////////////////////////////////////////////////////
// CDataDlg1 dialog

CDataDlg1::CDataDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CDataDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataDlg1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDataDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataDlg1)
	DDX_Control(pDX, IDC_VENDS_LIST, m_VendsList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataDlg1, CDialog)
	//{{AFX_MSG_MAP(CDataDlg1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataDlg1 message handlers
BOOL CDataDlg1::OnInitDialog()
{
	CDialog::OnInitDialog();

	DWORD dwStyle=GetWindowLong(m_VendsList.GetSafeHwnd(),GWL_STYLE);
	dwStyle&=~LVS_TYPEMASK;
	dwStyle|=LVS_REPORT;
	SetWindowLong(m_VendsList.GetSafeHwnd(),GWL_STYLE,dwStyle);

	m_VendsList.InsertColumn(0,"ISBN",LVCFMT_LEFT,80);
	m_VendsList.InsertColumn(1,"书名",LVCFMT_LEFT,130);
	m_VendsList.InsertColumn(2,"作者",LVCFMT_LEFT,90);
	m_VendsList.InsertColumn(3,"出版社",LVCFMT_LEFT,130);
	m_VendsList.InsertColumn(4,"单价",LVCFMT_LEFT,80);
	m_VendsList.InsertColumn(5,"销售本数",LVCFMT_LEFT,80);
	m_VendsList.InsertColumn(6,"销售额",LVCFMT_LEFT,80);

	m_VendsList.SetExtendedStyle(LVS_EX_GRIDLINES);
    ::SendMessage(m_VendsList.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,
      LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	ShowVends();
	return TRUE;
}

void CDataDlg1::ShowVends()
{
	CString sql;
	sql.Format("set @@tx_isolation='Serializable'");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
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


	sql.Format("select * from bookreport order by soldcount desc");
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
	int x=0;
	m_VendsList.DeleteAllItems();
	while((row = mysql_fetch_row(result)) != NULL && x<10)
	{
		++x;
		index = m_VendsList.InsertItem(m_VendsList.GetItemCount(),
			(TCHAR*)(_bstr_t)row[0]);
		for(int col = 1;col <7;col++)
			m_VendsList.SetItemText(index,col,(TCHAR*)(_bstr_t)row[col]);
	}
	
}
