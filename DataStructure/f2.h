#pragma once
#include"linear_list.h"


/************�㷨�����ݽṹ�������⾫��(�㷨�����)****************/

//2.1��������ҵ���kλ�õ�ֵ
int f2_1(LinkList L, int k);
void f2_1_test();

//2.2������Ϊn������Rѭ������p����λ��0 < p < n 
void f2_2(int* R, int n, int p);
void f2_2_test();

//2.3����������������λ��
void f2_3(int *A, int *B, int L);
void f2_3_test();

//2.4��������ͬ��׺��ʼλ��
void f2_4(LinkList str1, LinkList str2);
void f2_4_test();

//2.5�Ե��������ֵ��ȵĽ��ȥ��
void f2_5(LinkList head,int m,int n);
void f2_5_test();

//2.6�����������ĵ�����ϲ�Ϊһ���ݼ��ĵ�����
void f2_6(LinkList &La, LinkList &Lb);
void f2_6_test();

//2.7��һ��������һ�������ϲ�Ϊ�����
void f2_7(LinkList &La, LinkList &Lb);
void f2_7_test();

//2.8��һ��������һ�������ϲ�Ϊ�����
void f2_8(LinkList &La, LinkList &Lb);
void f2_8_test();

//2.9La��Lb������ͷ�ڵ㣬��Lb�鲢��La�У���lb���е�Ԫ��La��Ҳ�У��򲻽��й鲢
void f2_9(LinkList &La, LinkList &Lb);
void f2_9_test();

//2.10����������������Ĳ���������ҲΪ������
void f2_10(LinkList &La, LinkList &Lb);
void f2_10_test();

//2.11���������󽻼�
void f2_11(LinkList &La, LinkList &Lb);
void f2_11_test();

//2.12���������󽻼���������ǵ�������
void f2_12(LinkList &La, LinkList &Lb);
void f2_12_test();

//2.13�����������C��C���ٴ洢�ռ䣬�ҵ�������
void f2_13(LinkList &La, LinkList &Lb,LinkList &Lc);
void f2_13_test();

//2.14��֪������A,B,C����������A:=A��(B��C),������A��������
void f2_14(LinkList &La, LinkList &Lb, LinkList &Lc);
void f2_14_test();

//2.15��֪A��B����������A-B��ͬ����������
void f2_15(LinkList &La, LinkList &Lb);
void f2_15_test();