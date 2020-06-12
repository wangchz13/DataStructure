#pragma once

#include"global.h"


//2.2 线性表的顺序表示和实现

#define LIST_INIT_SIZE	100
#define LISTINCREMENT	10

typedef int	ElemType;

typedef struct {
	ElemType*	elem;
	int			length;
	int			listsize;
}SqList;


Status InitList_Sq(SqList &L);