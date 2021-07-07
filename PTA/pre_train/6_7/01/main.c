#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

Position BinarySearch( List L, ElementType X ){
	int u = L->Last, l = 1, m = u/2;
	while (1){
		if (L->Data[m] == X) return m;
		else if (L->Data[u] == X) return u;
		else if (L->Data[l] == X) return l;
		if (u-m <= 1 && m-l <=1) return 0;
		if (L->Data[m] < X) {
			l = m;
			m = m + (u-m)/2;
		} else {
			u = m;
			m = m/2;
		}
	}
}