// BookManage.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "BookManage.h"
#include "BookManageDlg.h"
#include "Login.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookManageApp



extern int PID;

BEGIN_MESSAGE_MAP(CBookManageApp, CWinApp)
	//{{AFX_MSG_MAP(CBookManageApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookManageApp construction

CBookManageApp::CBookManageApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBookManageApp object

CBookManageApp theApp;

BOOL loginflag = FALSE;
CString m_user;
MYSQL mysql;
/////////////////////////////////////////////////////////////////////////////
// CBookManageApp initialization

BOOL CBookManageApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	m_pMainWnd = NULL;	
	m_user = "";
	//先登陆系统...
	CLogin login;
	login.DoModal();
	if(loginflag)
	{
		CBookManageDlg dlg;
		m_pMainWnd = &dlg;
		dlg.DoModal();		
	}
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

/* 初始化ADO链接... */
void CBookManageApp::InitAdo()
{
	MYSQL mysql;//存储SQL语句
	mysql_init(&mysql);
	if (mysql_real_connect(&mysql, "localhost", "root", "1234", "booksalesmanagement", 3306, 0, 0))//用户名root，密码1234，数据库名booksalesmanagement，端口号3306
	{
		MessageBox(NULL,"数据库登陆成功！","提示！",NULL);
	}
	else
	{
		MessageBox(NULL, "数据库登陆失败！", "提示！", NULL);
	}
	
}
//字符串整型化为整形，将x变为s.GetAt(i)
int str_to_int(CString s)
{
	int x = 0;
	for(int i=0;i<s.GetLength();i++)
	{
		switch(s.GetAt(i))
		{
		case '0':x = 10*x;break;
		case '1':x = 10*x + 1;break;
		case '2':x = 10*x + 2;break;
		case '3':x = 10*x + 3;break;
		case '4':x = 10*x + 4;break;
		case '5':x = 10*x + 5;break;
		case '6':x = 10*x + 6;break;
		case '7':x = 10*x + 7;break;
		case '8':x = 10*x + 8;break;
		case '9':x = 10*x + 9;break;
		}
	}
	return x;
}
//获取格式化的日期
void GetDate(CString &s)
{
	s.Empty();
	CTime t = CTime::GetCurrentTime();
	CString m,d;
	if(t.GetMonth()<10)
		m.Format("0%d",t.GetMonth());//月份<10，则显示0X月
	else
		m.Format("%d",t.GetMonth());//月份>=10，则直接显示月份
	if(t.GetDay()<10)
		d.Format("0%d",t.GetDay());//天数<10，则显示0X日
	else
		d.Format("%d",t.GetDay());//天数>=10，则直接显示天数
	s.Format("%d",t.GetYear());//年份
	s = s+m+d;//年月日
}
//字符串浮点型化为浮点型
float	str_to_float(CString s)
{
	BOOL point = FALSE;
	float x=0,y=0;
	CString tmp;
	for(int i=0;i<s.GetLength();i++)
	{
		if(s.GetAt(i) == '.')
		{
			point = TRUE;
			x = (float)str_to_int(tmp);
			tmp.Empty();
		}
		else if(i == s.GetLength()-1)
		{
			tmp += s.GetAt(i);
			y = (float)str_to_int(tmp);
			if(point)
				y = y/(float)pow(10,tmp.GetLength());
			tmp.Empty();
			break;
		}
		else
			tmp += s.GetAt(i);
	}
	return x+y;
}
void processstring(CString & s)
{
	for (int i = 0; i<s.GetLength(); i++)
	{
		if (s[i] == '\\'||s[i]=='\'')
		{
			s.Insert(i, '\\');
			i++;
		}
	}
}