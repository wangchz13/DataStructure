#include "linear_list.h"

Status InitList_Sq(SqList &L)
{//����һ���յ����Ա�L
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//	InitList_Sq
