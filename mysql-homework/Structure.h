#ifndef __STRUCTURE_H
#define __STRUCTURE_H
//定义程序使用的数据结构...

//进货管理类信息结构
typedef struct bookstock
{
	int stocktime;
	CString ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	float cost;
	int bookcount;
}bookstock;

//退货管理类信息结构...
typedef struct bookrefund
{
	int refundtime;
	CString ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	float price;
	int refundcount;
}bookrefund;

//库存信息结构
typedef struct bookstorage
{
	CString ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	float price; //售价
	float cost;  //成本
	int storecount;
}bookstorage;

// 销售信息结构
typedef struct bookvend
{
	int vendtime;
	CString ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	float price;
	int vendcount;
}bookvend;

// 供应商信息...
typedef struct booksupply
{
	CString ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	float cost;
	int supplycount;
}booksupply;

#endif