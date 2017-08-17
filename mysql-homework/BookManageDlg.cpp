// BookManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "BookManageDlg.h"
#include "StockManage.h"
#include "RefundManage.h"
#include "DataManage.h"
#include "VendManage.h"
#include "UserInfo.h"
#include "DataBaseBackUp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern BOOL loginflag;
extern CString m_user;

int PID = 0;

extern CStockManage p_stock;
extern CRefundManage p_refund;
extern CDataManage p_data;
extern CVendManage p_vend;

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookManageDlg dialog

CBookManageDlg::CBookManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBookManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBookManageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBookManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookManageDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBookManageDlg, CDialog)
	//{{AFX_MSG_MAP(CBookManageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_EXIT, OnExit)
	ON_COMMAND(ID_STOCK_RECORD, OnStockRecord)
	ON_COMMAND(ID_SUPPLY_PRICE, OnSupplyPrice)
	ON_COMMAND(ID_REFUND_RECORD, OnRefundRecord)
	ON_COMMAND(ID_REFUND_OPERA, OnRefundOpera)
	ON_COMMAND(ID_VEND_RECORD, OnVendRecord)
	ON_COMMAND(ID_VEND_LIST, OnVendList)
	ON_COMMAND(ID_VEND_CONSOLE, OnVendConsole)
	ON_COMMAND(ID_ADDOPERA, OnAddopera)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_VEND_BYMONTH,OnVendBymonth)
	ON_STN_CLICKED(IDC_TIME_STATIC, &CBookManageDlg::OnStnClickedTimeStatic)
	ON_BN_CLICKED(IDC_BUTTON_STOCK, &CBookManageDlg::OnBnClickedButtonStock)
	ON_BN_CLICKED(IDC_BUTTON_REFUND, &CBookManageDlg::OnBnClickedButtonRefund)
	ON_BN_CLICKED(IDC_BUTTON_DATA, &CBookManageDlg::OnBnClickedButtonData)
	ON_BN_CLICKED(IDC_BUTTON_VEND, &CBookManageDlg::OnBnClickedButtonVend)
	ON_COMMAND(ID_USER, &CBookManageDlg::OnUser)
	ON_BN_CLICKED(IDC_BUTTON_USER, &CBookManageDlg::OnBnClickedButtonUser)
	ON_BN_CLICKED(IDC_BUTTON_BACKUP, &CBookManageDlg::OnBnClickedButtonBackup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookManageDlg message handlers

BOOL CBookManageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetInfor();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBookManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBookManageDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBookManageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBookManageDlg::SetInfor()
{
	CString tmp = "��ǰ�����Ĺ���ԱΪ: ";
	GetDlgItem(IDC_OPERA_STATIC)->SetWindowText(tmp+m_user);
}

//���ڰ���--���...
void CBookManageDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg ca;
	ca.DoModal();
}
//�˳�ϵͳ--���...
void CBookManageDlg::OnExit() 
{
	// TODO: Add your command handler code here
	exit(0);
}
//��ʾ������¼
void CBookManageDlg::OnStockRecord() 
{
	// TODO: Add your command handler code here
	PID = 0;
	p_stock.DoModal();
}
//��Ӧ�̱���
void CBookManageDlg::OnSupplyPrice() 
{
	// TODO: Add your command handler code here
	PID = 1;
	p_stock.DoModal();
}
//�˻�ҵ�����
void CBookManageDlg::OnRefundOpera() 
{
	// TODO: Add your command handler code here
	PID = 0;
	p_refund.DoModal();
}
//��ʾ�˻���¼
void CBookManageDlg::OnRefundRecord() 
{
	// TODO: Add your command handler code here
	PID = 1;
	p_refund.DoModal();
}
//��ʾ���ۼ�¼
void CBookManageDlg::OnVendRecord() 
{
	// TODO: Add your command handler code here
	CVendDlg1 stasticdlg1;
	stasticdlg1.DoModal();
}

//��ʾ��������
void CBookManageDlg::OnVendBymonth()
{
	// TODO: �ڴ���������������
	PID = 0;
	p_data.DoModal();
}

//��ʾ�������а�
void CBookManageDlg::OnVendList() 
{
	// TODO: Add your command handler code here
	PID = 1;
	p_data.DoModal();
}
//�������ۿ���̨
void CBookManageDlg::OnVendConsole() 
{
	// TODO: Add your command handler code here
	p_vend.DoModal();
}

void CBookManageDlg::OnAddopera() 
{
	// TODO: Add your command handler code here
	
}




void CBookManageDlg::OnStnClickedTimeStatic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CBookManageDlg::OnBnClickedButtonStock()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	p_stock.DoModal();
}


void CBookManageDlg::OnBnClickedButtonRefund()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	p_refund.DoModal();
}


void CBookManageDlg::OnBnClickedButtonData()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	p_data.DoModal();
}


void CBookManageDlg::OnBnClickedButtonVend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	p_vend.DoModal();
}


void CBookManageDlg::OnUser()
{
	// TODO: �ڴ���������������
	UserInfo p_user;
	p_user.DoModal();
}





void CBookManageDlg::OnBnClickedButtonUser()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UserInfo p_user;
	p_user.DoModal();
}


void CBookManageDlg::OnBnClickedButtonBackup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDataBaseBackUp p_databackup;
	p_databackup.DoModal();
}
