#include "linear_list.h"

Status InitList_Sq(SqList &L) {
	//构造一个空的线性表L
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//	InitList_Sq

Status ListInsert_Sq(SqList & L, int i, ElemType e) {
	//在顺序线性表L中第i个位置之前插入新的元素e
	if (i < 1 || i > L.length + 1) return ERROR;
	if (L.length == L.listsize) {
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType* q = &L.elem[i - 1];
	for (ElemType* p = &L.elem[L.length - 1]; p >= q; p--) *(p+1) = *p;
	*q = e;
	++L.length;
	return OK;
}

Status ListDelete_Sq(SqList & L, int i, ElemType & e) {
	if (i < 1 || i > L.length) return ERROR;
	ElemType* p = &L.elem[i - 1];
	e = *p;
	ElemType* q = L.elem + L.length - 1;
	for (++p; p <= q; ++p) *(p - 1) = *p;
	--L.length;
	return OK;
}

int Locate_elem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length && !(*compare)(*p++, e)) ++i;
	if (i <= L.length) return i;
	else return 0;
}

Status compare(ElemType i, ElemType j) {
	if (i == j)return TRUE;
	else return FALSE;
}

void ListMerge_Sq(SqList La, SqList Lb, SqList & Lc)
{
	ElemType *pa = La.elem, *pb = Lb.elem, *pc;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem) exit(OVERFLOW);
	ElemType *pa_last = La.elem + La.length - 1, *pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last) *pc++ = *pa++;
	while (pb <= pb_last) *pc++ = *pb++;
}

void ListMerge_Sq_Od(SqList La, SqList Lb, SqList & Lc) {
	ElemType *pa = La.elem, *pb = Lb.elem, *pc;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem) exit(OVERFLOW);
	ElemType *pa_last = La.elem + La.length - 1, *pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while(pa <= pa_last) *pc++ = *pa++;
	while(pb <= pb_last) *pc++ = *pb++;
}

void ListReverse_Sq(SqList & L) {
	ElemType temp;
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.elem[i];
		L.elem[i] = L.elem[L.length - 1 - i];
		L.elem[L.length - 1 - i] = temp;
	}
}

void ListReverse_Sq(SqList & L, int l, int r) {
	if (l < 0 || l > L.length-1 || r < 0 || r > L.length-1|| l > r) return;
	ElemType temp;
	while(l++ <= r--) {
		temp = L.elem[l];
		L.elem[l] = L.elem[r];
		L.elem[r] = temp;
	}
}

void ListDelete_Sq(SqList & L, ElemType e) {
	//方法一：用k记录当前L中不等于e的个数，将当前元素放到第k位置
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (e != L.elem[i]) {
			k++;
			L.elem[k - 1] = L.elem[i];
		}
	}
	L.length = k;
}

void ListDelete_Sq_2(SqList & L, ElemType e) {
	//方法二：用k记录当前L中等于e的个数，将当前元素前移k个位置
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)
			k++;
		else
			L.elem[i - k] = L.elem[i];
	}
	L.length -= k;
}

void ListDelete_Sq(SqList & L, ElemType s, ElemType t) {
	if (L.length == 0 || s > t) return;
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] >= s && L.elem[i] <= t)
			k++;
		else
			L.elem[i - k] = L.elem[i];
	}
	L.elem -= k;
	return;
}

void ListDelete_Sq_Od(SqList& L, ElemType s, ElemType t) {
	if (s < t) return;
	if (s == t) ListDelete_Sq(L, s);
	int i, j;
	for (i = 0; i < L.length&&L.elem[i] < s; i++);
	if (i >= L.length) return;
	for (j = 0; j < L.length&&L.elem[j] <= t; j++);
	for (; j < L.length; i++, j++)
		L.elem[i] = L.elem[j];
	L.length = i + 1;
	return; 
}

Status ListROL_Sq(SqList & L, int l) {
	if (l < 0 || l > L.length) return ERROR;
	ListReverse_Sq(L, 0, l-1);
	ListReverse_Sq(L, l, L.length-1);
	ListReverse_Sq(L);
	return OK;
}

void InitList_L(LinkList & L) {
	if (!(L = (LinkList)malloc(sizeof(LNode)))) exit(OVERFLOW);
	L->next = NULL;
}

bool IsEmpty_L(LinkList L)
{
	return L->next != NULL;
}

Status GetElem_L(LinkList L, int i, ElemType & e) {
	LNode *p = L->next;
	int j = 1;
	while (p&&j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}

LNode * LocateElem(LinkList L, ElemType e)
{
	LNode *p = L->next;
	while (p &&p->data != e) p = p->next;
	return p;
}

Status ListInsert_L(LinkList & L, int i, ElemType e) {
	LNode *p = L;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

void ListAppend_L(LinkList L,const char * s)
{
	LNode *p = L,*q;
	while (p->next) { p = p->next; }
	for (int i = 0; s[i] != '\0'; i++) {
		q = (LNode*)malloc(sizeof(LNode));
		q->data = (s[i] >= '0'&&s[i] <= '9') ? (ElemType)(s[i] - '0') : s[i];
		q->next = p->next;
		p->next = q;
		p = p->next;
	}
}

Status ListDelete_L(LinkList & L, int i, ElemType & e)
{
	LNode *p = L,*q;
	int j = 0;
	while(p->next&&j < i - 1) {
		p = p->next;
		++j;
	}
	if (!p->next || j > i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

void ListReverse_L(LinkList & L)
{
	LNode *p = L->next, *q;
	L->next = NULL;
	while (p) {
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

void PrintList_L(LinkList L) {
	printf("[HEAD]->");
	LNode *p = L->next;
	while (p) {
		printf("[%d]->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void PrintList_L_c(LinkList L) {
	printf("HEAD->");
	LNode *p = L->next;
	while (p) {
		printf("[%c]->", (char)p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void PrintArray(int * A, int n) {
	printf("[");
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%d,", A[i]);
		else
			printf("%d", A[i]);
	}
	printf("]\n");
}



void zend()
{
	
}


