#include"f2.h"

int f2_1(LinkList L, int k) {
	LNode *p = L->next, *q = p;
	int i = k;
	while (q && i) {
		i--;
		q = q->next;
	}

	if (i != 0) return 0;
	while (q) {
		q = q->next;
		p = p->next;
	}
	printf("倒数第%d个元素值为：%d\n", k, p->data);
	return 1;
}

void f2_1_test() {
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0; i < 10; i++) ListInsert_L(L, i + 1, i + 1);
	PrintList_L(L);
	f2_1(L, 1);
}

void f2_2(int * R, int n, int p) {
	if (p < 1 || p > n - 1) return;
	int l1 = 0, r1 = n - p - 1, l2 = n - p, r2 = n - 1, temp, i = 0, j = n - 1;
	while (l1 < r1) {
		temp = R[l1]; R[l1] = R[r1]; R[r1] = temp;
		l1++;
		r1--;
	}
	while (l2 < r2) {
		temp = R[l2]; R[l2] = R[r2]; R[r2] = temp;
		l2++;
		r2--;
	}
	while (i < j) {
		temp = R[i]; R[i] = R[j]; R[j] = temp;
		i++;
		j--;
	}
}

void f2_2_test()
{
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int p = 1;
	printf("原数组:\n");
	PrintArray(A, 10);
	f2_2(A, 10, p);
	printf("循环左移%d个单位后:\n", p);
	PrintArray(A, 10);

}

void f2_3(int * A, int * B, int L)
{
	int mid = (L % 2 == 0) ? L / 2 : L / 2 + 1;
	if (A[mid] == B[mid]) {
		printf("A和B的中位数为: %d",A[mid]);
		return;
	}
	int a = 0, b = 0, k = L;
	while (k > 0) {
		if (k == 1) 
			printf("A和B的中位数为: %d", A[a] <= B[b] ? A[a] : B[b]);
		A[a] <= B[b] ? a++ : b++;
		k--;
	}
}

void f2_3_test()
{
	int A[] = { 1,2,3,4,5 };
	int B[] = { 1,3,3,3,6 };
	printf("A: ");
	PrintArray(A, 5);
	printf("B: ");
	PrintArray(B, 5);
	f2_3(A, B, 5);
}

void f2_4(LinkList str1, LinkList str2)
{
	int m = -1, n = -1;
	LNode *p1 = str1, *p2 = str2;
	while (p1) { m++; p1 = p1->next; }
	while (p2) { n++; p2 = p2->next; }
	p1 = str1, p2 = str2;
	int k = m - n > 0 ? m - n : n - m;
	while (k > 0) {
		if(m > n) p1 = p1->next;
		if(m < n) p2 = p2->next;
		k--;
	}
	p1 = p1->next, p2 = p2->next;//p1,p2分别指向待比较的第一个元素
	int pos=-1;//pos为最后一次匹配相等时，元素在等长后缀中的位序
	k = m > n ? n : m;
	for (int i = 1; i <= k; i++) {
		if (p1->data == p2->data)
			pos = (pos == -1) ? i : pos;//如果pos为-1，说明前一个字符不等，pos重新标记。否则不做处理
		else
			pos = -1;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (pos == -1)
		printf("没有找到相同后缀.\n");
	else
		printf("相同后缀的起始位置为倒数第%d个位置.\n", k - pos + 1);
}

void f2_4_test()
{
	char s1[7] = { 'l','o','a','d','i','n','g' };
	char s2[5] = { 'b','e','i','n','g' };
	LinkList str1, str2;
	InitList_L(str1);
	InitList_L(str2);
	for (int i = 0; i < 7; i++) ListInsert_L(str1, i + 1, (ElemType)s1[i]);
	for (int i = 0; i < 5; i++) ListInsert_L(str2, i + 1, (ElemType)s2[i]);
	printf("str1:");
	PrintList_L_c(str1);
	printf("str2:");
	PrintList_L_c(str2);
	f2_4(str1, str2);
}


void f2_5(LinkList head,int m,int n)
{//m为链表长度
	if (n > 100) return;
	int c[100] = { 0 };
	LNode *q = head, *p = head->next;
	for (int i = 1; i <= m; i++) {
		int a = p->data > 0 ? p->data : -(p->data);
		if (c[a] == 0) {
			c[a]++;
			q = q->next;
			p = p->next;
		}	
		else {
			q->next = p->next;
			free(p);
			p = q->next;
		}
	}
}

void f2_5_test()
{
	LinkList L;
	InitList_L(L);
	ListInsert_L(L, 1, 21);
	ListInsert_L(L, 2, -15);
	ListInsert_L(L, 3, -15);
	ListInsert_L(L, 4, -7);
	ListInsert_L(L, 5, 15);
	printf("去重前:");
	PrintList_L(L);
	f2_5(L, 5, 100);
	printf("去重后:");
	PrintList_L(L);
}

void f2_6(LinkList &La, LinkList &Lb)
{
	LNode *p = La->next, *q = Lb->next,*r;
	La->next = NULL;
	while (p && q) {
		if (p->data <= q->data) {
			r = p->next;//头插法，链表是逆置的
			p->next = La->next;
			La->next = p;
			p = r;
		}
		else {
			r = q->next;
			q->next = La->next;
			La->next = q;
			q = r;
		}
	}
	if (p) q = p;
	while (q)
	{
		r = q->next;
		q->next = La->next;
		La->next = q;
		q = r;
	}
}

void f2_6_test()
{
	LinkList La, Lb;
	InitList_L(La), InitList_L(Lb);
	ListInsert_L(La, 1, 1);
	ListInsert_L(La, 2, 2);
	ListInsert_L(La, 3, 3);
	ListInsert_L(La, 4, 4);
	ListInsert_L(La, 5, 5);
	ListInsert_L(Lb, 1, 1);
	ListInsert_L(Lb, 2, 2);
	ListInsert_L(Lb, 3, 5);
	ListInsert_L(Lb, 4, 6);
	printf("合并前:\n");
	PrintList_L(La);
	PrintList_L(Lb);
	printf("合并后:\n");
	f2_6(La, Lb);
	PrintList_L(La);
}

void f2_7(LinkList &La, LinkList &Lb)
{	//La升序，Lb降序
	//先将Lb逆置为升序表，再与La头插法进行归并，得到一个降序表
	ListReverse_L(Lb);
	f2_6(La, Lb);
}

void f2_7_test()
{
	LinkList La, Lb;
	InitList_L(La), InitList_L(Lb);
	ListInsert_L(La, 1, 1);
	ListInsert_L(La, 2, 2);
	ListInsert_L(La, 3, 3);
	ListInsert_L(La, 4, 4);
	ListInsert_L(La, 5, 5);
	ListInsert_L(Lb, 1, 6);
	ListInsert_L(Lb, 2, 5);
	ListInsert_L(Lb, 3, 2);
	ListInsert_L(Lb, 4, 1);
	printf("合并前:\n");
	PrintList_L(La);
	PrintList_L(Lb);
	printf("合并后:\n");
	f2_7(La, Lb);
	PrintList_L(La);
}

void f2_8(LinkList & La, LinkList & Lb)
{
	//先将La逆置为降序表，再与Lb头插法归并，得到一个升序表
	//代码略
}

void f2_8_test()
{
}

void f2_9(LinkList & La, LinkList & Lb)
{
}

void f2_9_test()
{
}

void f2_10(LinkList & La, LinkList & Lb)
{
	//先去重，然后使用尾插法这样的到的链表就是递增有序的
	LNode*pa = La->next, *pb = Lb->next, *q,*r=NULL;//pa,pb为La Lb工作指针，q为临时指针，r为La表尾元素指针
	La->next = NULL;
	while (pa && pb) {
		if (pa->data <= pb->data) {//此时选择pa插入到表尾，当pa->data == r->data时，不进行插入
			if (!r) {//初始时r指向La->next,防止和La->data作比较
				q = pa->next;
				pa->next = La->next;
				La->next = pa;
				pa = q;
				r = La->next;
			}
			else {
				q = pa->next;
				if (r->data != pa->data) {
					pa->next = r->next;
					r->next = pa;
					r = r->next;
				}
				pa = q;
			}
		}
		else {
			if (!r) {//和上面代码逻辑一样
				q = pb->next;
				pb->next = La->next;
				La->next = pb;
				pb = q;
				r = La->next;
			}
			else {
				q = pb->next;
				if (r->data != pb->data) {
					pb->next = r->next;
					r->next = pb;
					r = r->next;
				}
				pb = q;
			}
		}
	}
	if (pb) pa = pb;
	while (pa) {
		q = pa->next;
		if (r->data != pa->data) {
			pa->next = r->next;
			r->next = pa;
			r = r->next;
		}
		pa = q;
	}
}

void f2_10_test()
{
	LinkList La, Lb;
	InitList_L(La), InitList_L(Lb);
	ListInsert_L(La, 1, 1);
	ListInsert_L(La, 2, 2);
	ListInsert_L(La, 3, 3);
	ListInsert_L(La, 4, 3);
	ListInsert_L(La, 5, 5);
	ListInsert_L(Lb, 1, 2);
	ListInsert_L(Lb, 2, 2);
	ListInsert_L(Lb, 3, 3);
	ListInsert_L(Lb, 4, 6);
	printf("合并前:\n");
	PrintList_L(La);
	PrintList_L(Lb);
	printf("合并后:\n");
	f2_10(La, Lb);
	PrintList_L(La);
}

void f2_11(LinkList & La, LinkList & Lb)
{
	LNode *pa = La->next, *pb = Lb->next, *q;
	La->next = NULL;
	while (pa && pb) {
		if (pa->data == pb->data) {
			ElemType e = pa->data;
			q = pa->next;
			pa->next = La->next;
			La->next = pa;
			pa = q;
			while (pa && pa->data == e) pa = pa->next;
			while (pb && pb->data == e) pb = pb->next;
		}
		else
			pa = pa->next;
	}
}

void f2_11_test()
{
	LinkList La, Lb;
	InitList_L(La), InitList_L(Lb);
	ListInsert_L(La, 1, 1);
	ListInsert_L(La, 2, 2);
	ListInsert_L(La, 3, 3);
	ListInsert_L(La, 4, 3);
	ListInsert_L(La, 5, 5);
	ListInsert_L(Lb, 1, 2);
	ListInsert_L(Lb, 2, 2);
	ListInsert_L(Lb, 3, 3);
	ListInsert_L(Lb, 4, 6);
	printf("原链表:\n");
	PrintList_L(La);
	PrintList_L(Lb);
	printf("求交集:\n");
	f2_11(La, Lb);
	PrintList_L(La);
}

void f2_12(LinkList & La, LinkList & Lb)
{
	f2_11(La, Lb);
	ListReverse_L(La);
}

void f2_12_test()
{
	LinkList La, Lb;
	InitList_L(La), InitList_L(Lb);
	ListInsert_L(La, 1, 1);
	ListInsert_L(La, 2, 2);
	ListInsert_L(La, 3, 3);
	ListInsert_L(La, 4, 3);
	ListInsert_L(La, 5, 5);
	ListInsert_L(Lb, 1, 2);
	ListInsert_L(Lb, 2, 2);
	ListInsert_L(Lb, 3, 3);
	ListInsert_L(Lb, 4, 6);
	printf("原链表:\n");
	PrintList_L(La);
	PrintList_L(Lb);
	printf("求交集:\n");
	f2_12(La, Lb);
	PrintList_L(La);
}

void f2_13(LinkList & La, LinkList & Lb, LinkList & Lc)
{
	LNode *pa = La->next, *pb = Lb->next, *q,*r=Lc;
	//La->next = NULL;
	while (pa && pb) {
		if (pa->data == pb->data) {
			ElemType e = pa->data;
			q = (LNode*)malloc(sizeof(LNode));
			q->data = pa->data;
			q->next = r->next;
			r->next = q;
			r = r->next;
			while (pa && pa->data == e) pa = pa->next;
			while (pb && pb->data == e) pb = pb->next;
		}
		else
			pa = pa->next;
	}
}

void f2_13_test()
{
	LinkList La, Lb, Lc;
	InitList_L(La), InitList_L(Lb), InitList_L(Lc);
	ListAppend_L(La, "12335"), ListAppend_L(Lb, "2236");
	printf("原链表:\n");
	PrintList_L(La); PrintList_L(Lb);
	printf("求交集后:\n");
	f2_13(La, Lb, Lc);
	PrintList_L(Lc);
}

void f2_14(LinkList & La, LinkList & Lb, LinkList & Lc)
{
	//先求 B∩C
	f2_12(Lb, Lc);
	//再求A∪(B∩C)
	f2_10(La, Lb);
}

void f2_14_test()
{
	LinkList La, Lb, Lc;
	InitList_L(La), InitList_L(Lb), InitList_L(Lc);
	ListAppend_L(La, "12335");
	ListAppend_L(Lb, "2236");
	ListAppend_L(Lc, "2367");
	printf("原链表:\n");
	PrintList_L(La);
	PrintList_L(Lb); 
	PrintList_L(Lc);
	printf("A∪(B∩C):\n");
	f2_14(La, Lb, Lc);
	PrintList_L(La);
}

void f2_15(LinkList & La, LinkList & Lb)
{
	LNode *pa = La->next, *pb = Lb->next,*q,*r = La;
	La->next = NULL;
	while (pa && pb) {
		if (pa->data == pb->data) {
			ElemType e = pa->data;
			while (pa && pa->data == e) pa = pa->next;
			while (pb && pb->data == e) pb = pb->next;
		}
		else {
			q = pa->next;
			pa->next = r->next;
			r->next = pa;
			r = r->next;
			pa = q;
		}
	}
	while (pa) {
		q = pa->next;
		pa->next = r->next;
		r->next = pa;
		r = r->next;
		pa = q;
	}
}

void f2_15_test()
{
	LinkList La, Lb;
	InitList_L(La), InitList_L(Lb);
	ListAppend_L(La, "123456789");
	ListAppend_L(Lb, "2223335");
	printf("原链表:\n");
	PrintList_L(La);
	PrintList_L(Lb);
	printf("A-B:\n");
	f2_15(La, Lb);
	PrintList_L(La);
}
