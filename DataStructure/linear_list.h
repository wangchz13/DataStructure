#pragma once
//���Ա�
#include"global.h"


/***********2.2 ���Ա��˳���ʾ��ʵ��**********/

//----------���Ա�Ķ�̬����˳��洢�ṹ----------
#define LIST_INIT_SIZE	100
#define LISTINCREMENT	10

typedef int	ElemType;

typedef struct {
	ElemType*	elem;
	int			length;
	int			listsize;
}SqList;
//----------���Ա�Ķ�̬����˳��洢�ṹ----------

//----------����:���Ա�ľ�̬����˳��洢�ṹ----------
#define LIST_MAXSIZE 100
typedef struct {
	ElemType elem[LIST_MAXSIZE];
	int length;
}SqList2;
//----------����:���Ա�ľ�̬����˳��洢�ṹ----------

//����һ���յ�˳�����Ա�L
Status InitList_Sq(SqList &L);

//��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
Status ListInsert_Sq(SqList &L, int i, ElemType e);

//��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
Status ListDelete_Sq(SqList &L, int i, ElemType &e);

//��˳�����Ա�L�в��ҵ�1��ֵ��e����compar()��Ԫ�ص�λ��
int Locate_elem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));

//compare����
Status compare(ElemType i, ElemType j);

//˳���鲢
void ListMerge_Sq(SqList La, SqList Lb, SqList &Lc);

//����˳���鲢
void ListMerge_Sq_Od(SqList La, SqList Lb, SqList &Lc);

//˳�������
void ListReverse_Sq(SqList &L);

//˳�����������,l,rΪ�����±�
void ListReverse_Sq(SqList &L, int l, int r);

//ɾ��˳���������ֵΪe������Ԫ��
void ListDelete_Sq(SqList &L, ElemType e);
void ListDelete_Sq_2(SqList &L, ElemType e);

//ɾ��˳�����ֵ��s��t֮�������Ԫ��
void ListDelete_Sq(SqList &L, ElemType s, ElemType t);

//ɾ������˳�����ֵ��s��t֮�������Ԫ��
void ListDelete_Sq_Od(SqList &L, ElemType s, ElemType t);

//˳���ѭ������lλ
Status ListROL_Sq(SqList &L, int l);



/***************2.3���Ա����ʽ��ʾ��ʵ��*****************/

typedef struct Node {
	ElemType data;
	struct Node* next;
}LNode,*LinkList;

//��ʼ��������
void InitList_L(LinkList &L);

//�жϵ������Ƿ�Ϊ��
bool IsEmpty_L(LinkList L);

//��ȡ������L�е�i��Ԫ�أ���e����
Status GetElem_L(LinkList L, int i, ElemType &e);

//��ֵ���ұ���
LNode *LocateElem(LinkList L, ElemType e);

//�ڵ������i��λ��֮ǰ����Ԫ��e
Status ListInsert_L(LinkList &L, int i, ElemType e);

//���������׷���ַ���=�ַ������ָ��һ����Ԫ�ؽ���׷��
void ListAppend_L(LinkList L, const char *s);

//ɾ��������L�е�i��Ԫ�أ�����e������ֵ
Status ListDelete_L(LinkList &L, int i, ElemType &e);

//����������
void ListReverse_L(LinkList &L);

//��ӡ����
void PrintList_L(LinkList L);
//��ӡ����������ת��Ϊ�ַ�
void PrintList_L_c(LinkList L);

//��ӡ����
void PrintArray(int *A, int n);

