// SaveData.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BookManage.h"
#include "SaveData.h"
#include "afxdialogex.h"

extern MYSQL mysql;
extern CString pathName;
// CSaveData �Ի���

IMPLEMENT_DYNAMIC(CSaveData, CDialog)

CSaveData::CSaveData(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_SAVE, pParent)
{

}

CSaveData::~CSaveData()
{
}

void CSaveData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSaveData, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_PATH, &CSaveData::OnBnClickedButtonSavePath)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_START, &CSaveData::OnBnClickedButtonSaveStart)
END_MESSAGE_MAP()


// CSaveData ��Ϣ�������


void CSaveData::OnBnClickedButtonSavePath()
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
		GetDlgItem(IDC_STATIC_PATH)->SetWindowText(tmp + pathName);
	}
	processstring(pathName);
}


void CSaveData::OnBnClickedButtonSaveStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (pathName.IsEmpty())
	{
		MessageBox("��û��ѡ��·����", "��ʾ");
		return;
	}
	//save bookrefund
	CString sql;
    sql.Format("LOCK TABLES bookrefund READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

    sql.Format("select * into outfile '%s\\\\bookrefund.bak' from bookrefund", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//save bookreport
	sql.Format("LOCK TABLES bookreport READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("select * into outfile '%s\\\\bookreport.bak' from bookreport", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//save booksold
	sql.Format("LOCK TABLES booksold READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("select * into outfile '%s\\\\booksold.bak' from booksold", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//save bookstock
	sql.Format("LOCK TABLES bookstock READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("select * into outfile '%s\\\\bookstock.bak' from bookstock", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//save bookstorage
	sql.Format("LOCK TABLES bookstorage READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("select * into outfile '%s\\\\bookstorage.bak' from bookstorage", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//save supplier
	sql.Format("LOCK TABLES supplier READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("select * into outfile '%s\\\\supplier.bak' from supplier", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}

	//save usertable
	sql.Format("LOCK TABLES usertable READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("select * into outfile '%s\\\\usertable.bak' from usertable", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "��ʾ��");
		return;
	}
	MessageBox("���ݳɹ���", "��ʾ��");
}


BOOL CSaveData::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CString tmp = "��ǰ·��Ϊ: ";
	GetDlgItem(IDC_STATIC_PATH)->SetWindowText(tmp + pathName);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
