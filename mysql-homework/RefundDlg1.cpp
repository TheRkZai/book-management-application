// RefundDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "RefundDlg1.h"
#include "RefundManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRefundDlg1 dialog

extern CRefundManage p_refund;
extern MYSQL mysql;
CRefundDlg1::CRefundDlg1(CWnd* pParent /*=NULL*/)//Ҫ����ġ�ISBN��������������
	: CDialog(CRefundDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRefundDlg1)
	m_ISBN = _T("");
	m_Count = _T("");
	//}}AFX_DATA_INIT
}


void CRefundDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRefundDlg1)
	DDX_Text(pDX, IDC_REFUND_ISBN, m_ISBN);
	DDX_Text(pDX, IDC_REFUND_COUNT, m_Count);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRefundDlg1, CDialog)
	//{{AFX_MSG_MAP(CRefundDlg1)
	ON_BN_CLICKED(IDC_REFUND_ENTER, OnRefundEnter)
	ON_BN_CLICKED(IDC_REFUND_CLEAR, OnRefundClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRefundDlg1 message handlers

void CRefundDlg1::OnRefundEnter() //�˻������еġ�ȷ���˻�����ť
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_ISBN.IsEmpty()||m_Count.IsEmpty())
	{
		MessageBox("ISBN��������������","��ʾ!");
		return;
	}

	CString sql;
	sql.Format("set @@tx_isolation='Serializable'");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
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

	sql.Format("select * from booksold where ISBN='%s'",m_ISBN);
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

	//�������۱����ң��еĻ���ɾ��
	if((row = mysql_fetch_row(result)) == NULL)
	{
		MessageBox("����δ�۳�����","����!");
		sql.Format("rollback");
		mysql_query(&mysql, sql);
		sql.Format("commit");
		mysql_query(&mysql, sql);
		return;
	}

	//Ѱ�Ҵ洢���ж�Ӧ��
	sql.Format("select * from bookstorage where ISBN='%s'",m_ISBN);
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
	row = mysql_fetch_row(result);
	int tmp = str_to_int(m_Count) + 
			str_to_int((TCHAR*)(_bstr_t)row[5]);
	CString time;
	SYSTEMTIME   st;
	CString	m_strAuthor = (TCHAR*)(_bstr_t)row[1];
	CString	m_strBookname = (TCHAR*)(_bstr_t)row[2];
	CString	m_strC = (TCHAR*)(_bstr_t)row[3];
	processstring(m_ISBN);
	processstring(m_strAuthor);
	processstring(m_strBookname);
	processstring(m_strC);
	GetLocalTime(&st);
	time.Format("%d-%d-%d %d:%d:%d ", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	sql.Format("call insert_into_refund('%s','%s','%s','%s','%s',%f,%d)",
		time,
		m_ISBN,
		m_strAuthor,
		m_strBookname,
		m_strC,
		str_to_float((TCHAR*)(_bstr_t)row[4]),
		str_to_int(m_Count));
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

	sql.Format("commit");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	MessageBox("����˻�","��ʾ!");//���¿������bm_BookStorage
	OnRefundClear();
	p_refund.refunddlg2->ShowRefund();//�ػ�����
}


//����������Ϣ
void CRefundDlg1::OnRefundClear() //�˻������еġ��������ť
{
	// TODO: Add your control notification handler code here
	m_ISBN.Empty();
	m_Count.Empty();
	UpdateData(FALSE);
}
