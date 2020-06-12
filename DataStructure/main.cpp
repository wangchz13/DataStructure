#include"global.h"

#include"linear_list.h"


int main()
{
	SqList L;
	InitList_Sq(L);
	if (ListInsert_Sq(L, 1, 99))
	{
		printf("%d\n", L.elem[0]);
		if (Locate_elem(L, 98, &compare)) {
			printf("find%d\n", L.elem[0]);
		}
	}
	return 0;
}