//尝试用非递归杂糅递归失败 其原因是非递归必须做到显式地指出某个指针的改变，例如t=p，必须是p去指向某个域
//而不能是t去指向某个域。 递归其实就是记录当前节点与父节点之间的关系，（就不用像我原来那样笨拙地用troot，flag12这样）自下而上地改变树。
Position FindMin( BinTree BST ) {
    BinTree t = BST;
    if (t)
        while (t->Left) t = t->Left;
    return t;
}
Position FindMax( BinTree BST ) {
    BinTree t = BST;
    if (t)
        while (t->Right) t = t->Right;
    return t;
}
BinTree Insert( BinTree BST, ElementType X ){
	if (!BST) {  
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = NULL;
		BST->Right = NULL;
	} else {
		if(X < BST->Data)
			BST->Left = Insert(BST->Left,X);
		else if(BST->Data < X)
			BST->Right = Insert(BST->Right,X);
	}
	return BST; 
}
BinTree Delete( BinTree BST, ElementType X ){
	BinTree tmp;
	if (!BST) {
		printf("Not Found\n");
		return BST;
	} else {
		if(X < BST->Data)
			BST->Left = Delete(BST->Left,X);
		else if(BST->Data < X)
			BST->Right = Delete(BST->Right,X);
		else {  
			if (BST->Left && BST->Right) {  
				tmp = FindMin(BST->Right);
				BST->Data = tmp->Data;
				BST->Right = Delete(BST->Right,tmp->Data);
			} else {
				tmp = BST;
				if(BST->Left && !BST->Right)
					BST = BST->Left;
				else if(!BST->Left && BST->Right)
					BST = BST->Right;
				else
					BST = NULL;
				free(tmp);
			}
		}
	}
	return BST;
} 

Position Find( BinTree BST, ElementType X ) {
    BinTree t = BST;
    while (t) {
        int data = t->Data;
        if (X > data) t = t->Right;
        else if (X < data) t = t->Left;
        else return t;
    } 
    return NULL;
}
