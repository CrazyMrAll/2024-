List Merge( List L1, List L2 ){
	List L=(List)malloc(sizeof(struct Node));
	List head = L;
	List tmpL1 = L1->Next;
	List tmpL2 = L2->Next;
	while(tmpL1 && tmpL2){
		if(tmpL1->Data < tmpL2->Data){
			L->Next=tmpL1;
			tmpL1=tmpL1->Next;
		}else{
			L->Next=tmpL2;
			tmpL2=tmpL2->Next;
		}
		L=L->Next;
	}
	if(tmpL1)
		L->Next=tmpL1;
	if(tmpL2)
		L->Next=tmpL2;
	L1->Next = NULL;
	L2->Next = NULL;
	return head;
} 