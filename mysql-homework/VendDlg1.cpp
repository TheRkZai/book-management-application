// VendDlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BookManage.h"
#include "VendDlg1.h"
#include "afxdialogex.h"


// CVendDlg1 �Ի���
extern MYSQL mysql;
IMPLEMENT_DYNAMIC(CVendDlg1, CDialog)

CVendDlg1::CVendDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_VEND_DIALOG2, pParent)
{

}

CVendDlg1::~CVendDlg1()
{
}

void CVendDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VEND_LIST, m_VendList);
}


BEGIN_MESSAGE_MAP(CVendDlg1, CDialog)
END_MESSAGE_MAP()


// CVendDlg1 ��Ϣ�������


BOOL CVendDlg1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	DWORD dwStyle = GetWindowLong(m_VendList.GetSafeHwnd(), GWL_STYLE);
	dwStyle &= ~LVS_TYPEMASK;
	dwStyle |= LVS_REPORT;
	SetWindowLong(m_VendList.GetSafeHwnd(), GWL_STYLE, dwStyle);

	m_VendList.InsertColumn(0, "���к�", LVCFMT_LEFT, 80);
	m_VendList.InsertColumn(1, "����ʱ��", LVCFMT_LEFT, 110);
	m_VendList.InsertColumn(2, "ISBN", LVCFMT_LEFT, 100);
	m_VendList.InsertColumn(3, "����", LVCFMT_LEFT, 130);
	m_VendList.InsertColumn(4, "����", LVCFMT_LEFT, 90);
	m_VendList.InsertColumn(5, "������", LVCFMT_LEFT, 130);
	m_VendList.InsertColumn(6, "����", LVCFMT_LEFT, 80);
	m_VendList.InsertColumn(7, "���۱���", LVCFMT_LEFT, 80);

	m_VendList.SetExtendedStyle(LVS_EX_GRIDLINES);
	::SendMessage(m_VendList.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,
		LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	ShowVend();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void CVendDlg1::ShowVend()
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

	sql.Format("select * from booksold");
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
	m_VendList.DeleteAllItems();
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		index = m_VendList.InsertItem(m_VendList.GetItemCount(),
			(TCHAR*)(_bstr_t)row[0]);
		for (int col = 1; col <9; col++)
			m_VendList.SetItemText(index, col, (TCHAR*)(_bstr_t)row[col]);
	}
}
