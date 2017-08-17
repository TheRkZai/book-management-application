// SaveData.cpp : 实现文件
//

#include "stdafx.h"
#include "BookManage.h"
#include "SaveData.h"
#include "afxdialogex.h"

extern MYSQL mysql;
extern CString pathName;
// CSaveData 对话框

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


// CSaveData 消息处理程序


void CSaveData::OnBnClickedButtonSavePath()
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
		GetDlgItem(IDC_STATIC_PATH)->SetWindowText(tmp + pathName);
	}
	processstring(pathName);
}


void CSaveData::OnBnClickedButtonSaveStart()
{
	// TODO: 在此添加控件通知处理程序代码
	if (pathName.IsEmpty())
	{
		MessageBox("还没有选择路径！", "提示");
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
		MessageBox(err, "提示！");
		return;
	}

    sql.Format("select * into outfile '%s\\\\bookrefund.bak' from bookrefund", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//save bookreport
	sql.Format("LOCK TABLES bookreport READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("select * into outfile '%s\\\\bookreport.bak' from bookreport", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//save booksold
	sql.Format("LOCK TABLES booksold READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("select * into outfile '%s\\\\booksold.bak' from booksold", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//save bookstock
	sql.Format("LOCK TABLES bookstock READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("select * into outfile '%s\\\\bookstock.bak' from bookstock", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//save bookstorage
	sql.Format("LOCK TABLES bookstorage READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("select * into outfile '%s\\\\bookstorage.bak' from bookstorage", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//save supplier
	sql.Format("LOCK TABLES supplier READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("select * into outfile '%s\\\\supplier.bak' from supplier", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}

	//save usertable
	sql.Format("LOCK TABLES usertable READ");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("select * into outfile '%s\\\\usertable.bak' from usertable", pathName);
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	sql.Format("UNLOCK TABLES");
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return;
	}
	MessageBox("备份成功！", "提示！");
}


BOOL CSaveData::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString tmp = "当前路径为: ";
	GetDlgItem(IDC_STATIC_PATH)->SetWindowText(tmp + pathName);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
