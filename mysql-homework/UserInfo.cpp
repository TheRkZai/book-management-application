// UserInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "BookManage.h"
#include "UserInfo.h"
#include "afxdialogex.h"
#include "NewName.h"
#include "NewPass.h"
#include "NewUser.h"
extern CString m_user;
extern MYSQL mysql;

// UserInfo 对话框

IMPLEMENT_DYNAMIC(UserInfo, CDialog)

UserInfo::UserInfo(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_USER_INFO, pParent)
	, m_User(_T(""))
{

}

UserInfo::~UserInfo()
{
}

void UserInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserInfo, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE_USERNAME, &UserInfo::OnBnClickedButtonChangeUsername)
	ON_BN_CLICKED(IDC_BUTTON_PASS, &UserInfo::OnBnClickedButtonPass)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, &UserInfo::OnBnClickedButtonRegister)
END_MESSAGE_MAP()


// UserInfo 消息处理程序


BOOL UserInfo::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString tmp = "UserName: ";
	GetDlgItem(IDC_STATIC_NAME)->SetWindowText(tmp + m_user);
	CString sql;
	sql.Format("select * from usertable where username = '%s'",m_user);	
	mysql_query(&mysql, sql);
	if (mysql_errno(&mysql))
	{
		CString err;
		err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
		MessageBox(err, "提示！");
		return FALSE;
	}
	result = mysql_store_result(&mysql);
	if ((row = mysql_fetch_row(result)) == NULL)
	{
		MessageBox("不存在用户！", "提示!");
		return FALSE;
	}
	password = (TCHAR*)(_bstr_t)row[1];
	rank = (TCHAR*)(_bstr_t)row[2];
	tmp.Format("Password: ");
	GetDlgItem(IDC_STATIC_PASS)->SetWindowText(tmp + password);
	tmp.Format("RANK: ");
	GetDlgItem(IDC_STATIC_RANK)->SetWindowText(tmp + rank);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void UserInfo::OnBnClickedButtonChangeUsername()
{
	// TODO: 在此添加控件通知处理程序代码
	CNewName p_newname;
	if (p_newname.DoModal() == IDOK)
	{
		if (p_newname.m_UserName.IsEmpty())
		{
			MessageBox("用户名不能留空", "提示!");
			return;
		}
		CString sql;
		sql.Format("rename user %s to %s", m_user, p_newname.m_UserName);
		mysql_query(&mysql, sql);
		sql.Format("update usertable set username='%s' where username='%s'", m_user, p_newname.m_UserName);
		mysql_query(&mysql, sql);
		if (mysql_errno(&mysql))
		{
			CString err;
			err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
			MessageBox(err, "提示！");
			return;
		}
		m_user = p_newname.m_UserName;
		CString tmp = "UserName: ";
		GetDlgItem(IDC_STATIC_NAME)->SetWindowText(tmp + m_user);
	}
}


void UserInfo::OnBnClickedButtonPass()
{
	// TODO: 在此添加控件通知处理程序代码
	CNewPass p_password;
	if (p_password.DoModal() == IDOK)
	{
		if (p_password.m_NewPass.IsEmpty())
		{
			MessageBox("密码不能留空", "提示!");
			return;
		}
		CString sql;
		sql.Format("set password for %s = password('%s')", m_user,p_password.m_NewPass);
		mysql_query(&mysql, sql);
		sql.Format("update usertable set password='%s' where username='%s'", p_password.m_NewPass,m_user);
		mysql_query(&mysql, sql);
		if (mysql_errno(&mysql))
		{
			CString err;
			err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
			MessageBox(err, "提示！");
			return;
		}
		CString tmp;
		tmp.Format("Password: ");
		GetDlgItem(IDC_STATIC_PASS)->SetWindowText(tmp + p_password.m_NewPass);
	}
}




void UserInfo::OnBnClickedButtonRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	CNewUser p_newuser;
	if (p_newuser.DoModal()==IDOK)
	{
		CString username;
		CString password;
		CString rank;
		CString sql;
		if (p_newuser.m_UserName.IsEmpty())
		{
			MessageBox("用户名不能留空", "提示!");
			return;
		}
		if (p_newuser.m_PassWord.IsEmpty())
		{
			MessageBox("密码不能留空", "提示!");
			return;
		}
		rank = p_newuser.m_RANK_string;
		username = p_newuser.m_UserName;
		password = p_newuser.m_PassWord;
		if (rank == "职工")
		{
			sql.Format("create user %s identified by '%s'", username, password);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("insert into usertable values ('%s','%s','%s')", username, password, rank);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant all on booksalesmanagement.bookreport to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant execute on booksalesmanagement.* to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant all on booksalesmanagement.bookrefund to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant all on booksalesmanagement.booksold to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant all on booksalesmanagement.bookstock to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant all on booksalesmanagement.bookstorage to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant all on booksalesmanagement.usertable to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant select,delete on booksalesmanagement.supplier to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant create user on *.* to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant file on *.* to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}
		}
		else
		{
			sql.Format("create user %s identified by '%s'", username, password);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}
			sql.Format("insert into usertable values ('%s','%s','%s')", username, password, rank);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant execute on booksalesmanagement.* to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}


			sql.Format("grant all on booksalesmanagement.supplier to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant all on booksalesmanagement.usertable to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant select on booksalesmanagement.bookstock to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant create user on *.* to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}

			sql.Format("grant file on *.* to '%s' with grant option", username);
			mysql_query(&mysql, sql);
			if (mysql_errno(&mysql))
			{
				CString err;
				err.Format("Error: mysql_error(%s)\n", mysql_error(&mysql));
				MessageBox(err, "提示！");
				return;
			}
		}
		MessageBox("创建成功！", "提示！");
	}
}
