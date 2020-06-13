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