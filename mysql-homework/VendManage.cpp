// VendManage.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "VendManage.h"
#include "VendDlg.h"
#include "VendDlg2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVendManage dialog
extern MYSQL mysql;
extern int PID;

CVendManage::CVendManage(CWnd* pParent /*=NULL*/)
	: CDialog(CVendManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVendManage)
	m_strAuthor = _T("");
	m_strBookname = _T("");
	m_strC = _T("");
	//}}AFX_DATA_INIT
}


void CVendManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVendManage)
	DDX_Control(pDX, IDC_PUCHE_LIST, m_PucheList);
	DDX_Control(pDX, IDC_STORAGE_LIST, m_StorageList);
	//}}AFX_DATA_MAP
}

CVendManage p_vend;

BEGIN_MESSAGE_MAP(CVendManage, CDialog)
	//{{AFX_MSG_MAP(CVendManage)
	ON_COMMAND(ID_EXIT, OnExitVend)
	ON_COMMAND(ID_ADDBOOK, OnAddbook)
	ON_NOTIFY(NM_CLICK, IDC_STORAGE_LIST, OnClickStorageList)
	ON_NOTIFY(NM_CLICK, IDC_PUCHE_LIST, OnClickPucheList)
	ON_COMMAND(ID_MINUSBOOK, OnMinusbook)
	ON_COMMAND(ID_PUCHE, OnPuche)
	ON_COMMAND(ID_CLEAR, OnClear)
//	ON_BN_CLICKED(IDC_BUTTON_FIND, OnButtonFind)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_STORAGE_LIST, &CVendManage::OnLvnItemchangedStorageList)
	ON_COMMAND(ID_FIND, &CVendManage::OnFind)
	ON_COMMAND(ID_REFRESH_DATA, &CVendManage::OnRefreshData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVendManage message handlers
BOOL CVendManage::OnInitDialog()//图书销售管理
{
	CDialog::OnInitDialog();

	//初始化书单列表框...
	DWORD dwStyle=GetWindowLong(m_StorageList.GetSafeHwnd(),GWL_STYLE);
	dwStyle&=~LVS_TYPEMASK;
	dwStyle|=LVS_REPORT;
	SetWindowLong(m_StorageList.GetSafeHwnd(),GWL_STYLE,dwStyle);

	m_StorageList.InsertColumn(0,"ISBN",LVCFMT_LEFT,80);
	m_StorageList.InsertColumn(1,"书名",LVCFMT_LEFT,130);
	m_StorageList.InsertColumn(2,"作者",LVCFMT_LEFT,90);
	m_StorageList.InsertColumn(3,"出版社",LVCFMT_LEFT,130);
	m_StorageList.InsertColumn(4,"售价",LVCFMT_LEFT,80);
	m_StorageList.InsertColumn(5,"存货量",LVCFMT_LEFT,80);

	m_StorageList.SetExtendedStyle(LVS_EX_GRIDLINES);
    ::SendMessage(m_StorageList.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,
      LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	//初始化选书单...
	dwStyle=GetWindowLong(m_PucheList.GetSafeHwnd(),GWL_STYLE);
	dwStyle&=~LVS_TYPEMASK;
	dwStyle|=LVS_REPORT;
	SetWindowLong(m_PucheList.GetSafeHwnd(),GWL_STYLE,dwStyle);

	m_PucheList.InsertColumn(0,"ISBN",LVCFMT_LEFT,80);
	m_PucheList.InsertColumn(1,"书名",LVCFMT_LEFT,130);
	m_PucheList.InsertColumn(2,"作者",LVCFMT_LEFT,90);
	m_PucheList.InsertColumn(3,"出版社",LVCFMT_LEFT,130);
	m_PucheList.InsertColumn(4,"售价",LVCFMT_LEFT,80);
	m_PucheList.InsertColumn(5,"购买量",LVCFMT_LEFT,80);

	m_PucheList.SetExtendedStyle(LVS_EX_GRIDLINES);
	::SendMessage(m_PucheList.m_hWnd,LVM_SETEXTENDEDLISTVIEWSTYLE,
		LVS_EX_FULLROWSELECT,LVS_EX_FULLROWSELECT);
	//显示现有图书
	ShowStorage();
	m_AddIndex = -1;
	m_DelIndex = -1;
	return TRUE;
}

void CVendManage::OnExitVend() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}

void CVendManage::ShowStorage()
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

	sql.Format("select * from bookstorage");
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
	m_StorageList.DeleteAllItems();
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		index = m_StorageList.InsertItem(m_StorageList.GetItemCount(),
			(TCHAR*)(_bstr_t)row[0]);
		for (int col = 1;col <8;col++)
			m_StorageList.SetItemText(index,col,(TCHAR*)(_bstr_t)row[col]);
	}
	
}
//选书添加到选书单
void CVendManage::OnAddbook() 
{
	// TODO: Add your command handler code here
	if(m_AddIndex < 0)
		return;
	CVendDlg cv;
	cv.DoModal();
	if(!cv.getcount)
		return;
	if(str_to_int(cv.m_PucheCount) > str_to_int(m_StorageList.GetItemText(m_AddIndex,5)))
	{
		MessageBox("库存不够","错误!");
		return;
	}
	int index = m_PucheList.InsertItem(m_PucheList.GetItemCount(),
			m_StorageList.GetItemText(m_AddIndex,0));
	for(int i=1;i<5;i++)
		m_PucheList.SetItemText(index,i,m_StorageList.GetItemText(m_AddIndex,i));
	m_PucheList.SetItemText(index,5,cv.m_PucheCount);
}

void CVendManage::OnClickStorageList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_AddIndex = m_StorageList.GetSelectionMark();
	*pResult = 0;
}

void CVendManage::OnClickPucheList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_DelIndex = m_PucheList.GetSelectionMark();
	*pResult = 0;
}

void CVendManage::OnMinusbook() 
{
	// TODO: Add your command handler code here
	if(m_DelIndex < 0)
		return;
	m_PucheList.DeleteItem(m_DelIndex);
}
//确定购买
void CVendManage::OnPuche() 
{
	// TODO: Add your command handler code here
	if(m_PucheList.GetItemCount() < 1)
	{
		MessageBox("请先选择书籍","提示!");
		return;
	}
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

	float cost = 0;
	for(int i=0;i<m_PucheList.GetItemCount();i++)
	{
		//更新销售表
		cost += str_to_float(m_PucheList.GetItemText(i, 4))*str_to_int(m_PucheList.GetItemText(i, 5));
		CString time;
		SYSTEMTIME   st;
		GetLocalTime(&st);
		CString ISBN = m_PucheList.GetItemText(i, 0);
		CString bookname = m_PucheList.GetItemText(i, 1);
		CString author = m_PucheList.GetItemText(i, 2);
		CString bookconcern = m_PucheList.GetItemText(i, 3);
		processstring(bookconcern);
		processstring(author);
		processstring(bookname);
		time.Format("%d-%d-%d %d:%d:%d ", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
		sql.Format("insert into booksold (soldtime,ISBN,bookname,author,bookconcern,price,soldcount) values ('%s','%s','%s','%s','%s',%f,%d)",
			time,ISBN,
			bookname,
			author,
			bookconcern,
			str_to_float(m_PucheList.GetItemText(i,4)),
			str_to_int(m_PucheList.GetItemText(i,5)));
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

	m_StorageList.DeleteAllItems();
	ShowStorage();
	sql.Format("%f",cost);
	sql.TrimRight();
	MessageBox("交易成功...\n应付款为："+sql+"元\n","提示!");
	
}

void CVendManage::OnClear() 
{
	// TODO: Add your command handler code here
	m_PucheList.DeleteAllItems();
}



void CVendManage::OnLvnItemchangedStorageList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}





void CVendManage::OnFind()
{
	// TODO: 在此添加命令处理程序代码
	CVendDlg2 venddlg2;
	if (venddlg2.DoModal() == IDOK)
	{
		m_strAuthor = venddlg2.m_strAuthor;
		processstring(m_strAuthor);
		m_strBookname = venddlg2.m_strBookname;
		processstring(m_strBookname);
		m_strC = venddlg2.m_strC;
		processstring(m_strC);
	}
	UpdateData();
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

	sql = "select * from bookstorage where bookname like '%" + m_strBookname + "%' and author like '%" + m_strAuthor
		+ "%' and bookconcern like '%" + m_strC + "%'";
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
	m_StorageList.DeleteAllItems();
	int i = 0;
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		m_StorageList.InsertItem(i, (TCHAR*)(_bstr_t)row[0]);
		m_StorageList.SetItemText(i, 1, (TCHAR*)(_bstr_t)row[1]);
		m_StorageList.SetItemText(i, 2, (TCHAR*)(_bstr_t)row[2]);
		m_StorageList.SetItemText(i, 3, (TCHAR*)(_bstr_t)row[3]);
		m_StorageList.SetItemText(i, 4, (TCHAR*)(_bstr_t)row[4]);
		m_StorageList.SetItemText(i, 5, (TCHAR*)(_bstr_t)row[5]);
		m_StorageList.SetItemText(i, 6, (TCHAR*)(_bstr_t)row[6]);
		i++;
	}
	
}


void CVendManage::OnRefreshData()
{
	// TODO: 在此添加命令处理程序代码
	this->ShowStorage();
}
