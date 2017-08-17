; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStockManage
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BookManage.h"

ClassCount=16
Class1=CBookManageApp
Class2=CBookManageDlg
Class3=CAboutDlg

ResourceCount=21
Resource1=IDD_STASTIC_DIALOG2
Resource2=IDR_MAINFRAME
Resource3=IDD_STOCK_DIALOG1
Class4=CLogin
Resource4=IDD_REFUND_DIALOG
Resource5=IDD_STASTIC_DIALOG3
Class5=CStockManage
Resource6=IDD_LOGIN_DIALOG
Resource7=IDD_REFUND_DIALOG1
Resource8=IDR_REFUNDMENU
Class6=CStockDlg1
Class7=CStockDlg2
Resource9=IDD_BOOKMANAGE_DIALOG
Class8=CRefundManage
Resource10=IDD_STOCK_DIALOG2
Resource11=IDD_STOCK_DIALOG
Class9=CRefundDlg1
Class10=CRefundDlg2
Resource12=IDD_VEND_DIALOG1
Class11=CStasticManage
Resource13=IDD_STASTIC_DIALOG1
Resource14=IDR_STOCKMENU
Resource15=IDD_STASTIC_DIALOG
Resource16=IDR_MAINMENU
Class12=CVendManage
Class13=CStasticDlg1
Class14=CStasticDlg2
Class15=CStasticDlg3
Resource17=IDD_VEND_DIALOG
Resource18=IDD_REFUND_DIALOG2
Resource19=IDD_ABOUTBOX
Resource20=IDR_STASTICMENU
Class16=CVendDlg
Resource21=IDR_VENDMENU

[CLS:CBookManageApp]
Type=0
HeaderFile=BookManage.h
ImplementationFile=BookManage.cpp
Filter=N

[CLS:CBookManageDlg]
Type=0
HeaderFile=BookManageDlg.h
ImplementationFile=BookManageDlg.cpp
Filter=D
LastObject=ID_VEND_CONSOLE
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=BookManageDlg.h
ImplementationFile=BookManageDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BOOKMANAGE_DIALOG]
Type=1
Class=CBookManageDlg
ControlCount=3
Control1=IDC_STATIC,static,1342177294
Control2=IDC_OPERA_STATIC,static,1342308352
Control3=IDC_TIME_STATIC,static,1342308352

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLogin
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_CODE,edit,1350631584
Control6=IDC_QUIT,button,1342242816
Control7=IDC_OK,button,1342242816

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_ABOUT

[DLG:IDD_STOCK_DIALOG]
Type=1
Class=CStockManage
ControlCount=1
Control1=IDC_STOCK_TAB,SysTabControl32,1342177280

[CLS:CStockManage]
Type=0
HeaderFile=StockManage.h
ImplementationFile=StockManage.cpp
BaseClass=CDialog
Filter=D
LastObject=CStockManage
VirtualFilter=dWC

[MNU:IDR_MAINMENU]
Type=1
Class=CBookManageDlg
Command1=ID_EXIT
Command2=ID_STOCK_RECORD
Command3=ID_SUPPLY_PRICE
Command4=ID_REFUND_OPERA
Command5=ID_REFUND_RECORD
Command6=ID_VEND_RECORD
Command7=ID_VEND_BYDAY
Command8=ID_VEND_LIST
Command9=ID_VEND_CONSOLE
Command10=ID_ABOUT
CommandCount=10

[MNU:IDR_STOCKMENU]
Type=1
Class=CStockManage
Command1=ID_ADD_SUPPLY
Command2=ID_MINU_SUPPLY
Command3=ID_CHOOSE_SUPPLY
Command4=ID_SAVE
Command5=ID_DISPLAY
Command6=ID_CLEAR
Command7=ID_EXIT
CommandCount=7

[DLG:IDD_STOCK_DIALOG1]
Type=1
Class=CStockDlg1
ControlCount=1
Control1=IDC_STOCK_LIST,SysListView32,1350633475

[DLG:IDD_STOCK_DIALOG2]
Type=1
Class=CStockDlg2
ControlCount=14
Control1=IDC_STATIC,button,1342177287
Control2=IDC_SUPPLY_LIST,SysListView32,1350633475
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STOCK_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STOCK_SUPPLY,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STOCK_PRICE,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STOCK_COUNT,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STOCK_ISBN,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STOCK_AUTHOR,edit,1350631552

[CLS:CStockDlg1]
Type=0
HeaderFile=StockDlg1.h
ImplementationFile=StockDlg1.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STOCK_LIST
VirtualFilter=dWC

[CLS:CStockDlg2]
Type=0
HeaderFile=StockDlg2.h
ImplementationFile=StockDlg2.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SUPPLY_LIST
VirtualFilter=dWC

[DLG:IDD_REFUND_DIALOG]
Type=1
Class=CRefundManage
ControlCount=1
Control1=IDC_REFUND_TAB,SysTabControl32,1342177280

[CLS:CRefundManage]
Type=0
HeaderFile=RefundManage.h
ImplementationFile=RefundManage.cpp
BaseClass=CDialog
Filter=D
LastObject=CRefundManage
VirtualFilter=dWC

[DLG:IDD_REFUND_DIALOG1]
Type=1
Class=CRefundDlg1
ControlCount=9
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_REFUND_ISBN,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_REFUND_NAME,edit,1350631552
Control7=IDC_REFUND_COUNT,edit,1350631552
Control8=IDC_REFUND_ENTER,button,1342242816
Control9=IDC_REFUND_CLEAR,button,1342242816

[DLG:IDD_REFUND_DIALOG2]
Type=1
Class=CRefundDlg2
ControlCount=1
Control1=IDC_REFUND_LIST,SysListView32,1350633475

[CLS:CRefundDlg1]
Type=0
HeaderFile=RefundDlg1.h
ImplementationFile=RefundDlg1.cpp
BaseClass=CDialog
Filter=D
LastObject=CRefundDlg1
VirtualFilter=dWC

[CLS:CRefundDlg2]
Type=0
HeaderFile=RefundDlg2.h
ImplementationFile=RefundDlg2.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_REFUND_LIST
VirtualFilter=dWC

[DLG:IDD_STASTIC_DIALOG]
Type=1
Class=CStasticManage
ControlCount=1
Control1=IDC_STASTIC_TAB,SysTabControl32,1342177280

[CLS:CStasticManage]
Type=0
HeaderFile=StasticManage.h
ImplementationFile=StasticManage.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_STASTIC_TAB

[DLG:IDD_STASTIC_DIALOG1]
Type=1
Class=CStasticDlg1
ControlCount=1
Control1=IDC_VEND_LIST,SysListView32,1350633475

[DLG:IDD_STASTIC_DIALOG2]
Type=1
Class=CStasticDlg2
ControlCount=1
Control1=IDC_VENDBYDAY_LIST,SysListView32,1350633475

[DLG:IDD_STASTIC_DIALOG3]
Type=1
Class=CStasticDlg3
ControlCount=1
Control1=IDC_VENDS_LIST,SysListView32,1350633475

[DLG:IDD_VEND_DIALOG]
Type=1
Class=CVendManage
ControlCount=11
Control1=IDC_STORAGE_LIST,SysListView32,1350633475
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_PUCHE_LIST,SysListView32,1350633475
Control5=IDC_BUTTON_FIND,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_BOOKNAME,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_AUTHOR,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_C,edit,1350631552

[CLS:CVendManage]
Type=0
HeaderFile=VendManage.h
ImplementationFile=VendManage.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_ISBN
VirtualFilter=dWC

[CLS:CStasticDlg1]
Type=0
HeaderFile=StasticDlg1.h
ImplementationFile=StasticDlg1.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_VEND_LIST
VirtualFilter=dWC

[CLS:CStasticDlg2]
Type=0
HeaderFile=StasticDlg2.h
ImplementationFile=StasticDlg2.cpp
BaseClass=CDialog
Filter=D
LastObject=CStasticDlg2
VirtualFilter=dWC

[CLS:CStasticDlg3]
Type=0
HeaderFile=StasticDlg3.h
ImplementationFile=StasticDlg3.cpp
BaseClass=CDialog
Filter=D
LastObject=CStasticDlg3
VirtualFilter=dWC

[MNU:IDR_STASTICMENU]
Type=1
Class=CStasticManage
Command1=ID_EXIT
CommandCount=1

[MNU:IDR_REFUNDMENU]
Type=1
Class=CRefundManage
Command1=ID_EXIT
CommandCount=1

[MNU:IDR_VENDMENU]
Type=1
Class=CVendManage
Command1=ID_ADDBOOK
Command2=ID_MINUSBOOK
Command3=ID_PUCHE
Command4=ID_CLEAR
Command5=ID_EXIT
CommandCount=5

[DLG:IDD_VEND_DIALOG1]
Type=1
Class=CVendDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PUCHECOUNT,edit,1350631552
Control3=IDC_OK,button,1342242816
Control4=IDC_CANCEL,button,1342242816

[CLS:CVendDlg]
Type=0
HeaderFile=VendDlg.h
ImplementationFile=VendDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PUCHECOUNT
VirtualFilter=dWC

