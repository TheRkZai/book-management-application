// DataBaseBackUp.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BookManage.h"
#include "DataBaseBackUp.h"
#include "afxdialogex.h"
#include "SaveData.h"
#include "RestoreData.h"
// CDataBaseBackUp �Ի���

IMPLEMENT_DYNAMIC(CDataBaseBackUp, CDialog)
CString pathName;
CDataBaseBackUp::CDataBaseBackUp(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_BACKUP, pParent)
{

}

CDataBaseBackUp::~CDataBaseBackUp()
{
}

void CDataBaseBackUp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDataBaseBackUp, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CDataBaseBackUp::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_RESTORE, &CDataBaseBackUp::OnBnClickedButtonRestore)
END_MESSAGE_MAP()


// CDataBaseBackUp ��Ϣ�������


void CDataBaseBackUp::OnBnClickedButtonSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSaveData p_savedata;
	p_savedata.DoModal();
}


void CDataBaseBackUp::OnBnClickedButtonRestore()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRestoreData p_restoredata;
	p_restoredata.DoModal();
}
