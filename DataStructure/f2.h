#pragma once
#include"linear_list.h"


/************算法与数据结构考研试题精析(算法设计题)****************/

//2.1单链表查找倒数k位置的值
int f2_1(LinkList L, int k);
void f2_1_test();

//2.2将长度为n的数组R循环左移p个单位，0 < p < n 
void f2_2(int* R, int n, int p);
void f2_2_test();

//2.3两个升序序列找中位数
void f2_3(int *A, int *B, int L);
void f2_3_test();

//2.4单词找相同后缀起始位置
void f2_4(LinkList str1, LinkList str2);
void f2_4_test();

//2.5对单链表绝对值相等的结点去重
void f2_5(LinkList head,int m,int n);
void f2_5_test();

//2.6将两个递增的单链表合并为一个递减的单链表
void f2_6(LinkList &La, LinkList &Lb);
void f2_6_test();

//2.7将一个升序表和一个降序表合并为降序表
void f2_7(LinkList &La, LinkList &Lb);
void f2_7_test();

//2.8将一个升序表和一个降序表合并为升序表
void f2_8(LinkList &La, LinkList &Lb);
void f2_8_test();

//2.9La，Lb均不带头节点，将Lb归并到La中，若lb中有的元素La中也有，则不进行归并
void f2_9(LinkList &La, LinkList &Lb);
void f2_9_test();

//2.10求两个递增单链表的并集，并集也为递增表
void f2_10(LinkList &La, LinkList &Lb);
void f2_10_test();

//2.11递增链表求交集
void f2_11(LinkList &La, LinkList &Lb);
void f2_11_test();

//2.12递增链表求交集，结果仍是递增链表
void f2_12(LinkList &La, LinkList &Lb);
void f2_12_test();

//2.13求递增链表交集C，C另开辟存储空间，且递增有序
void f2_13(LinkList &La, LinkList &Lb,LinkList &Lc);
void f2_13_test();

//2.14已知单链表A,B,C递增有序，求A:=A∪(B∩C),并保持A递增有序
void f2_14(LinkList &La, LinkList &Lb, LinkList &Lc);
void f2_14_test();

//2.15已知A，B递增有序，求A-B，同样递增有序
void f2_15(LinkList &La, LinkList &Lb);
void f2_15_test();