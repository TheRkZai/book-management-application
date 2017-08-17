#ifndef __STRUCTURE_H
#define __STRUCTURE_H
//�������ʹ�õ����ݽṹ...

//������������Ϣ�ṹ
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

//�˻���������Ϣ�ṹ...
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

//�����Ϣ�ṹ
typedef struct bookstorage
{
	CString ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	float price; //�ۼ�
	float cost;  //�ɱ�
	int storecount;
}bookstorage;

// ������Ϣ�ṹ
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

// ��Ӧ����Ϣ...
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