// RestoreData.cpp : 实现文件
//

#include "stdafx.h"
#include "BookManage.h"
#include "RestoreData.h"
#include "afxdialogex.h"

extern CString pathName;
extern MYSQL mysql;
// CRestoreData 对话框

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


// CRestoreData 消息处理程序


BOOL CRestoreData::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString tmp = "当前路径为: ";
	GetDlgItem(IDC_STATIC_PATH_LOAD)->SetWindowText(tmp + pathName);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CRestoreData::OnBnClickedButtonLoadPath()
{
	// TODO: 在此添加控件通知处理程序代码
	BROWSEINFO bBrowInfo;
	char Buffer[MAX_PATH];
	//初始化入口参数开始
	bBrowInfo.hwndOwner = NULL;
	bBrowInfo.pidlRoot = NULL;
	bBrowInfo.pszDisplayName = Buffer;//此参数如为NULL则不能显示对话框
	bBrowInfo.lpszTitle = "请选择备份文件夹路径";//选择对话框提示语言
	bBrowInfo.ulFlags = 0;
	bBrowInfo.lpfn = NULL;
	bBrowInfo.iImage = NULL;
	//初始化入口参数bi结束
	LPITEMIDLIST pIDList = SHBrowseForFolder(&bBrowInfo);//调用显示选择对话框
	if (pIDList)
	{
		SHGetPathFromIDList(pIDList, Buffer);
		pathName = Buffer;//将路径保存在一个CString对象里
		CString tmp = "当前路径为: ";
		GetDlgItem(IDC_STATIC_PATH_LOAD)->SetWindowText(tmp + pathName);
	}
	processstring(pathName);
}


void CRestoreData::OnBnClickedButtonLoadStart()
{
	// TODO: 在此添加控件通知处理程序代码
	if (pathName.IsEmpty())
	{
		MessageBox("还没有选择路径！", "提示");
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
		MessageBox(err, "提示！");
		return;
	}

	sql.Format("load data low_priority infile '%s\\\\bookrefund.bak' replace into table bookrefund", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//restore bookreport
	sql.Format("delete from bookreport");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\bookreport.bak' replace into table bookreport", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//restore booksold
	sql.Format("delete from booksold");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\booksold.bak' replace into table booksold", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//restore bookstock
	sql.Format("delete from bookstock");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\bookstock.bak' replace into table bookstock", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//restore bookstorage
	sql.Format("delete from bookstorage");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\bookstorage.bak' replace into table bookstorage", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//restore supplier
	sql.Format("delete from supplier");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\supplier.bak' replace into table supplier", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//restore usertable
	sql.Format("delete from usertable");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("load data low_priority infile '%s\\\\usertable.bak' replace into table usertable", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	MessageBox("恢复成功！", "提示！");
}
