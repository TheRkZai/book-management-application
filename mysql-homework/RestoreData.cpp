// RestoreData.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BookManage.h"
#include "RestoreData.h"
#include "afxdialogex.h"

extern CString pathName;
extern MYSQL mysql;
// CRestoreData �Ի���

IMPLEMENT_DYNAMIC(CRestoreData, CDialog)

CRestoreData::CRestoreData(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_LOAD, pParent)
{

}

CRestoreData::~CRestoreData()
{
}

void CRestoreData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRestoreData, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_PATH, &CRestoreData::OnBnClickedButtonLoadPath)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_START, &CRestoreData::OnBnClickedButtonLoadStart)
END_MESSAGE_MAP()


// CRestoreData ��Ϣ�������


BOOL CRestoreData::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString tmp = "��ǰ·��Ϊ: ";
	GetDlgItem(IDC_STATIC_PATH_LOAD)->SetWindowText(tmp + pathName);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CRestoreData::OnBnClickedButtonLoadPath()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BROWSEINFO bBrowInfo;
	char Buffer[MAX_PATH];
	//��ʼ����ڲ�����ʼ
	bBrowInfo.hwndOwner = NULL;
	bBrowInfo.pidlRoot = NULL;
	bBrowInfo.pszDisplayName = Buffer;//�˲�����ΪNULL������ʾ�Ի���
	bBrowInfo.lpszTitle = "��ѡ�񱸷��ļ���·��";//ѡ��Ի�����ʾ����
	bBrowInfo.ulFlags = 0;
	bBrowInfo.lpfn = NULL;
	bBrowInfo.iImage = NULL;
	//��ʼ����ڲ���bi����
	LPITEMIDLIST pIDList = SHBrowseForFolder(&bBrowInfo);//������ʾѡ��Ի���
	if (pIDList)
	{
		SHGetPathFromIDList(pIDList, Buffer);
		pathName = Buffer;//��·��������һ��CString������
		CString tmp = "��ǰ·��Ϊ: ";
		GetDlgItem(IDC_STATIC_PATH_LOAD)->SetWindowText(tmp + pathName);
	}
	processstring(pathName);
}


void CRestoreData::OnBnClickedButtonLoadStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (pathName.IsEmpty())
	{
		MessageBox("��û��ѡ��·����", "��ʾ");
		return;
	}
	//restore bookrefund
	CString sql;
	sql.Format("delete from bookrefund");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	sql.Format("load data low_priority infile '%s\\\\bookrefund.bak' replace into table bookrefund", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//restore bookreport
	sql.Format("delete from bookreport");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\bookreport.bak' replace into table bookreport", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//restore booksold
	sql.Format("delete from booksold");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\booksold.bak' replace into table booksold", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//restore bookstock
	sql.Format("delete from bookstock");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\bookstock.bak' replace into table bookstock", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//restore bookstorage
	sql.Format("delete from bookstorage");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\bookstorage.bak' replace into table bookstorage", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//restore supplier
	sql.Format("delete from supplier");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\supplier.bak' replace into table supplier", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//restore usertable
	sql.Format("delete from usertable");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\usertable.bak' replace into table usertable", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	MessageBox("�ָ��ɹ���", "��ʾ��");
}
