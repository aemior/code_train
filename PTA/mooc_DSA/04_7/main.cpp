#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    std::freopen("test.txt", "r", stdin);
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        //printf("%d\n", X);
        BST = Delete(BST, X);
        //printf("Inorder:"); InorderTraversal(BST); printf("\n");
        //printf("Preorder:"); PreorderTraversal(BST); printf("\n");
        //printf("\n");
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");
	/*
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
	*/

    return 0;
}
/* 你的代码将被嵌在这里 */
/*
BinTree Insert( BinTree BST, ElementType X ) {
        BinTree root = BST;
    if (BST) {
        if (X < BST->Data) {
            BST->Left = Insert(BST->Left, X);
        } else if (X > BST->Data) {
            BST->Right = Insert(BST->Right, X);
        }
    } else {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
        root = BST;
    }
    return root;
};
*/

BinTree NewNode(ElementType X) {
	BinTree res = (BinTree)malloc(sizeof(struct TNode));
	res->Data = X;
	res->Left = NULL;
	res->Right = NULL;
	return res;
}

BinTree Insert(BinTree BST, ElementType X) {
	if (!(BST)) return NewNode(X);
	BinTree root = BST;
	while (BST) {
		if (BST->Data > X) {
			if (BST->Left) BST = BST->Left;
			else {
				BST->Left = NewNode(X);
				break;
			}
		} else if (BST->Data < X) {
			if (BST->Right) BST = BST->Right;
			else {
				BST->Right = NewNode(X);
				break;
			}
		} else {
			break;
		}
	}
	return root;
}

Position FindMin( BinTree BST ) {
    if (!(BST)) return BST;
    while (BST->Left) {
        BST = BST->Left;
    }
    return BST;
}
Position FindMax( BinTree BST ) {
    if (!(BST)) return BST;
    while (BST->Right) {
        BST = BST->Right;
    }
    return BST;
}

Position Find( BinTree BST, ElementType X ) {
    if (!(BST)) return BST;
    else if (X < BST->Data) {
        BST = Find(BST->Left, X);
    } else if (X > BST->Data) {
        BST = Find(BST->Right, X);
    } else {
        return BST;
    }
}

/*
BinTree LeftMost(BinTree BST) {
    while (BST->Left) {
        BST = BST->Left;
    }
    return BST;
}
BinTree RightMost(BinTree BST) {
    while (BST->Right) {
        BST = BST->Right;
    }
    return BST;
}


BinTree Delete( BinTree BST, ElementType X ) {
    BinTree root = BST;
    BinTree father = NULL;
    while (BST && BST->Data != X) {
        father = BST;
        if (X < BST->Data) BST = BST->Left;
        else BST = BST->Right;
    }
    if (BST) {
        if (father) {
            if (X < father->Data) {
                if (BST->Left && BST->Right) {
                    father->Left = BST->Right;
                    RightMost(BST->Left)->Right = BST->Right->Left;
                    BST->Right->Left = BST->Left;
                } else if (BST->Left) {
                    father->Left = BST->Left;
                } else if (BST->Right) {
                    father->Left = BST->Right;
                } else {
                    father->Left = NULL;
                }
            } else {
                if (BST->Left && BST->Right) {
                    father->Right = BST->Left;
                    LeftMost(BST->Right)->Left = BST->Left->Right;
                    BST->Left->Right = BST->Right;
                } else if (BST->Left) {
                    father->Right = BST->Left;
                } else if (BST->Right) {
                    father->Right = BST->Right;
                } else {
                    father->Right = NULL;
                }
            }
        } else {
            if (BST->Left && BST->Right) {
                root = BST->Left;
                LeftMost(BST->Right)->Left = BST->Left->Right;
                BST->Left->Right = BST->Right;
            } else if (BST->Left) {
                root = BST->Left;
            } else if (BST->Right) {
                root = BST->Right;
            } else {
                root = NULL;
            }
        }
        free(BST);
    } else {
        printf("Not Found\n");
    }
    return root;
} */
BinTree SetNode(BinTree BST, BinTree pos) {
	BinTree root = BST;
	BinTree father = NULL;
	while (BST != pos) {
        father = BST;
        if (pos->Data < BST->Data) BST = BST->Left;
        else BST = BST->Right;
	}
	if (father) {
		if (BST->Data < father->Data) {
			father->Left = NULL;
		} else {
			father->Right = NULL;
		}
	}
	return BST;
}

BinTree MoveNode(BinTree BST) {
	BinTree res = NULL;
	if (BST->Left) {
		res = SetNode(BST, FindMax(BST->Left));
	} else if (BST->Right) {
		res = SetNode(BST, FindMin(BST->Right));
	}
	if (res) {
		if (!(res->Left)) res->Left = BST->Left;
		if (!(res->Right)) res->Right = BST->Right;
	}
	return res;
}


BinTree Delete( BinTree BST, ElementType X ) {
    BinTree root = BST;
    BinTree father = NULL;
    while (BST && BST->Data != X) {
        father = BST;
        if (X < BST->Data) BST = BST->Left;
        else BST = BST->Right;
    }
	if (BST) {
		if (father) {
			if (BST->Data < father->Data) {
				father->Left = MoveNode(BST);
			}
			else {
				father->Right = MoveNode(BST);
			}
		} else {
			root = MoveNode(BST);
		}
		free(BST);
	} else {
        printf("Not Found\n");
	}
	return root;
}

void PreorderTraversal( BinTree BT ) {
    if (BT) {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    } else {
        return;
    }
}; /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT ) {
    if (BT) {
        InorderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InorderTraversal(BT->Right);
    } else {
        return;
    }
};  /* 中序遍历，由裁判实现，细节不表 */