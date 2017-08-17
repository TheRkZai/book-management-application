// datadlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "DataDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataDlg dialog
extern MYSQL mysql;
CDataDlg::CDataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataDlg)
	DDX_Control(pDX, IDC_VENDBYMONTH_LIST, m_VendMonthList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataDlg, CDialog)
	//{{AFX_MSG_MAP(CDataDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_VENDBYDAY_LIST, &CDataDlg::OnLvnItemchangedVendbydayList)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataDlg message handlers
BOOL CDataDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	DWORD dwStyle=GetWindowLong(m_VendMonthList.GetSafeHwnd(),GWL_STYLE);
	dwStyle&=~LVS_TYPEMASK;
	dwStyle|=LVS_REPORT;
	SetWindowLong(m_VendMonthList.GetSafeHwnd(),GWL_STYLE,dwStyle);

	m_VendMonthList.InsertColumn(0,"ISBN",LVCFMT_LEFT,80);
	m_VendMonthList.InsertColumn(1,"����",LVCFMT_LEFT,130);
	m_VendMonthList.InsertColumn(2,"����",LVCFMT_LEFT,90);
	m_VendMonthList.InsertColumn(3,"������",LVCFMT_LEFT,130);
	m_VendMonthList.InsertColumn(4,"����",LVCFMT_LEFT,80);
	m_VendMonthList.InsertColumn(5,"���۱���",LVCFMT_LEFT,80);
	m_VendMonthList.InsertColumn(6,"���۶�",LVCFMT_LEFT,80);

	m_VendMonthList.SetExtendedStyle(LVS_EX_GRIDLINES);
    ::SendMessage(m_VendMonthList.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,
      LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	ShowVendDay();
	return TRUE;
}

void CDataDlg::ShowVendDay()
{
	CString sql;
	sql.Format("set @@tx_isolation='Serializable'");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
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
		MessageBox(err, "��ʾ��");
		sql.Format("rollback");
		mysql_query(&mysql, sql);
		sql.Format("commit");
		mysql_query(&mysql, sql);
		return;
	}

	sql.Format("select * from bookreport");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
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
		MessageBox(err, "��ʾ��");
		return;
	}

	int index = 0;
	m_VendMonthList.DeleteAllItems();
	while((row = mysql_fetch_row(result)) != NULL)
	{
		index = m_VendMonthList.InsertItem(m_VendMonthList.GetItemCount(),
			(TCHAR*)(_bstr_t)row[0]);
		for(int col = 1;col <7;col++)
			m_VendMonthList.SetItemText(index,col,(TCHAR*)(_bstr_t)row[col]);
	}
	

}

void CDataDlg::OnLvnItemchangedVendbydayList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
