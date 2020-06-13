#pragma once
//线性表
#include"global.h"


/***********2.2 线性表的顺序表示和实现**********/

//----------线性表的动态分配顺序存储结构----------
#define LIST_INIT_SIZE	100
#define LISTINCREMENT	10

typedef int	ElemType;

typedef struct {
	ElemType*	elem;
	int			length;
	int			listsize;
}SqList;
//----------线性表的动态分配顺序存储结构----------

//----------补充:线性表的静态分配顺序存储结构----------
#define LIST_MAXSIZE 100
typedef struct {
	ElemType elem[LIST_MAXSIZE];
	int length;
}SqList2;
//----------补充:线性表的静态分配顺序存储结构----------

//构造一个空的顺序线性表L
Status InitList_Sq(SqList &L);

//在顺序线性表L中第i个位置之前插入新的元素e
Status ListInsert_Sq(SqList &L, int i, ElemType e);

//在顺序线性表L中删除第i个元素，并用e返回其值
Status ListDelete_Sq(SqList &L, int i, ElemType &e);

//在顺序线性表L中查找第1个值与e满足compar()的元素的位序
int Locate_elem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));

//compare函数
Status compare(ElemType i, ElemType j);

//顺序表归并
void ListMerge_Sq(SqList La, SqList Lb, SqList &Lc);

//有序顺序表归并
void ListMerge_Sq_Od(SqList La, SqList Lb, SqList &Lc);

//顺序表逆置
void ListReverse_Sq(SqList &L);

//顺序表区间逆置,l,r为数组下标
void ListReverse_Sq(SqList &L, int l, int r);

//删除顺序表中所有值为e的数据元素
void ListDelete_Sq(SqList &L, ElemType e);
void ListDelete_Sq_2(SqList &L, ElemType e);

//删除顺序表中值在s与t之间的所有元素
void ListDelete_Sq(SqList &L, ElemType s, ElemType t);

//删除有序顺序表中值在s与t之间的所有元素
void ListDelete_Sq_Od(SqList &L, ElemType s, ElemType t);

//顺序表循环左移l位
Status ListROL_Sq(SqList &L, int l);



/***************2.3线性表的链式表示和实现*****************/

typedef struct Node {
	ElemType data;
	struct Node* next;
}LNode,*LinkList;

//初始化单链表
void InitList_L(LinkList &L);

//判断单链表是否为空
bool IsEmpty_L(LinkList L);

//获取单链表L中第i个元素，用e反回
Status GetElem_L(LinkList L, int i, ElemType &e);

//按值查找表结点
LNode *LocateElem(LinkList L, ElemType e);

//在单链表第i个位置之前插入元素e
Status ListInsert_L(LinkList &L, int i, ElemType e);

//在链表后面追加字符串=字符串被分割成一个个元素进行追加
void ListAppend_L(LinkList L, const char *s);

//删除单链表L中第i个元素，并由e返回其值
Status ListDelete_L(LinkList &L, int i, ElemType &e);

//单链表逆置
void ListReverse_L(LinkList &L);

//打印链表
void PrintList_L(LinkList L);
//打印链表：将数字转换为字符
void PrintList_L_c(LinkList L);

//打印数组
void PrintArray(int *A, int n);

