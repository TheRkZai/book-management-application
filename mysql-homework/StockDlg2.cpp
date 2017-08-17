// StockDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "StockDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern MYSQL mysql;
/////////////////////////////////////////////////////////////////////////////
// CStockDlg2 dialog


CStockDlg2::CStockDlg2(CWnd* pParent /*=NULL*/)//进货管理中的“ISBN，供货商，供货价，图书名，作者，供应数量”
	: CDialog(CStockDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStockDlg2)
	m_Author = _T("");
	m_Count = _T("");
	m_ISBN = _T("");
	m_Name = _T("");
	m_Price = _T("");
	m_Supply = _T("");
	//}}AFX_DATA_INIT
}


void CStockDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStockDlg2)
	DDX_Control(pDX, IDC_SUPPLY_LIST, m_StockSupplyList);
	DDX_Text(pDX, IDC_STOCK_AUTHOR, m_Author);
	DDX_Text(pDX, IDC_STOCK_COUNT, m_Count);
	DDX_Text(pDX, IDC_STOCK_ISBN, m_ISBN);
	DDX_Text(pDX, IDC_STOCK_NAME, m_Name);
	DDX_Text(pDX, IDC_STOCK_PRICE, m_Price);
	DDX_Text(pDX, IDC_STOCK_SUPPLY, m_Supply);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStockDlg2, CDialog)
	//{{AFX_MSG_MAP(CStockDlg2)
	ON_NOTIFY(NM_CLICK, IDC_SUPPLY_LIST, OnClickSupplyList)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_STOCK_ADD, &CStockDlg2::OnBnClickedButtonStockAdd)
	ON_BN_CLICKED(IDC_BUTTON_STOCK_SUB, &CStockDlg2::OnBnClickedButtonStockSub)
	ON_BN_CLICKED(IDC_BUTTON_STOCK_SAVE, &CStockDlg2::OnBnClickedButtonStockSave)
	ON_BN_CLICKED(IDC_BUTTON_STOCK_QUERY, &CStockDlg2::OnBnClickedButtonStockQuery)
	ON_BN_CLICKED(IDC_BUTTON_STOCK_CONFIRM, &CStockDlg2::OnBnClickedButtonStockConfirm)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CStockDlg2::OnBnClickedButtonClear)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockDlg2 message handlers
BOOL CStockDlg2::OnInitDialog()
{
	CDialog::OnInitDialog();

	DWORD dwStyle=GetWindowLong(m_StockSupplyList.GetSafeHwnd(),GWL_STYLE);
	dwStyle&=~LVS_TYPEMASK;
	dwStyle|=LVS_REPORT;
	SetWindowLong(m_StockSupplyList.GetSafeHwnd(),GWL_STYLE,dwStyle);
	m_StockSupplyList.InsertColumn(0, "供货记录", LVCFMT_LEFT, 80);
	m_StockSupplyList.InsertColumn(1,"ISBN",LVCFMT_LEFT,80);
	m_StockSupplyList.InsertColumn(2,"书名",LVCFMT_LEFT,130);
	m_StockSupplyList.InsertColumn(3,"作者",LVCFMT_LEFT,90);
	m_StockSupplyList.InsertColumn(4,"供货商",LVCFMT_LEFT,130);
	m_StockSupplyList.InsertColumn(5,"成本价",LVCFMT_LEFT,80);
	m_StockSupplyList.InsertColumn(6,"供应量",LVCFMT_LEFT,80);

	m_StockSupplyList.SetExtendedStyle(LVS_EX_GRIDLINES);
    ::SendMessage(m_StockSupplyList.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,
      LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	delIndex = -1;
	return TRUE;
}

void CStockDlg2::OnClickSupplyList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	delIndex = m_StockSupplyList.GetSelectionMark();
	*pResult = 0;
}

void CStockDlg2::OnBnClickedButtonStockAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_ISBN.IsEmpty() || m_Name.IsEmpty() || m_Author.IsEmpty()
		|| m_Price.IsEmpty() || m_Count.IsEmpty() || m_Supply.IsEmpty())
	{
		MessageBox("供应信息不能留空", "提示!");
		return;
	}
	int index = m_StockSupplyList.InsertItem
		(m_StockSupplyList.GetItemCount(),NULL);
	m_StockSupplyList.SetItemText(index, 1, m_ISBN);
	m_StockSupplyList.SetItemText(index, 2, m_Name);
	m_StockSupplyList.SetItemText(index, 3, m_Author);
	m_StockSupplyList.SetItemText(index, 4, m_Supply);
	m_StockSupplyList.SetItemText(index, 5, m_Price);
	m_StockSupplyList.SetItemText(index, 6, m_Count);
}


void CStockDlg2::OnBnClickedButtonStockSub()
{
	// TODO: 在此添加控件通知处理程序代码
	if (delIndex < 0 || delIndex > m_StockSupplyList.GetItemCount())
	{
		MessageBox("请选择要删减的信息", "提示!");
		return;
	}
	m_StockSupplyList.DeleteItem(delIndex);
	delIndex = -1;
}


void CStockDlg2::OnBnClickedButtonStockSave()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_StockSupplyList.GetItemCount() == 0)
	{
		MessageBox("请先生成供货信息", "错误!");
		return;
	}
	CString time, sql;
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

	SYSTEMTIME   st;
	GetLocalTime(&st);
	time.Format("%d-%d-%d %d:%d:%d ", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	for (int row = 0; row < m_StockSupplyList.GetItemCount(); row++)
	{
		CString ISBN = m_StockSupplyList.GetItemText(row, 1);
		CString bookname = m_StockSupplyList.GetItemText(row, 2);
		CString author = m_StockSupplyList.GetItemText(row, 3);
		CString bookconcern = m_StockSupplyList.GetItemText(row, 4);
		processstring(bookname);
		processstring(author);
		processstring(bookconcern);
		float cost = str_to_float(m_StockSupplyList.GetItemText(row, 5));
		int supplycount = str_to_int(m_StockSupplyList.GetItemText(row, 6));

		//将供应商信息插入到供应表supplier
		sql.Format("insert into supplier (supplytime,ISBN,bookname,author,supplier,supplycost,supplycount) values ('%s','%s','%s','%s','%s',%f,%d)",
			time, ISBN, bookname, author, bookconcern, cost, supplycount);
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
	}

	sql.Format("commit");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	MessageBox("完成！", "提示!");
}


void CStockDlg2::OnBnClickedButtonStockQuery()
{
	// TODO: 在此添加控件通知处理程序代码
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

	sql.Format("select * from supplier");
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
	m_StockSupplyList.DeleteAllItems();
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		index = m_StockSupplyList.InsertItem(m_StockSupplyList.GetItemCount(),
			(TCHAR*)(_bstr_t)row[0]);
		for (int col = 2; col<8; col++)
			m_StockSupplyList.SetItemText(index, col - 1, (TCHAR*)(_bstr_t)row[col]);
	}
}


void CStockDlg2::OnBnClickedButtonStockConfirm()
{
	// TODO: 在此添加控件通知处理程序代码
	if (delIndex < 0 || delIndex > m_StockSupplyList.GetItemCount())
	{
		MessageBox("请选择要进货的商家", "提示!");
		return;
	}
	CString time, sql;
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

	SYSTEMTIME   st;
	GetLocalTime(&st);
	time.Format("%d-%d-%d %d:%d:%d ", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	int sno = str_to_int(m_StockSupplyList.GetItemText(delIndex, 0));
	CString ISBN = m_StockSupplyList.GetItemText(delIndex, 1);
	CString bookname = m_StockSupplyList.GetItemText(delIndex, 2);
	CString author = m_StockSupplyList.GetItemText(delIndex, 3);
	CString bookconcern = m_StockSupplyList.GetItemText(delIndex, 4);
	float cost = str_to_float(m_StockSupplyList.GetItemText(delIndex, 5));
	int supplycount = str_to_int(m_StockSupplyList.GetItemText(delIndex, 6));
	processstring(bookname);
	processstring(author);
	processstring(bookconcern);
	sql.Format("delete from supplier where sno = %d",sno);
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

	//保存到进货表bookStock
	sql.Format("insert into bookstock (stocktime,ISBN,bookname,author,bookconcern,cost,stockcount) values  ('%s','%s','%s','%s','%s',%f,%d)",
		time, ISBN, bookname, author, bookconcern, cost, supplycount);
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

	MessageBox("完成！", "提示!");
	sql.Format("commit");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	this->OnBnClickedButtonStockQuery();
	//在第一个对话框中回显信息
}


void CStockDlg2::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ISBN.Empty();
	m_Name.Empty();
	m_Author.Empty();
	m_Supply.Empty();
	m_Price.Empty();
	m_Count.Empty();
	UpdateData(FALSE);
}
