// 3.3 a)
// We now have 3 pointers, pA, pB, pC.
// pA is before pB and pC, which are to be swapped.
void Swap(Position pA) {
    Position pB, pC;
    pB = pA->next;
    pC = pB->next;
    pA->next = pC;
    pB->next = pC->next;
    pC->next = pB;
}

// 3.3 b)
// We now have 2 pointers, pA, pB, which are to be swapped.
void Swap(Position pA) {
    Position pB = pA->next;
    pA->next = pB->next;
    pB->pre = pA->pre
    pA->pre = pB;
    pB->next = pA;
    
}

// 3.4
// The List is sorted in ascending order.
List Intersect(List L1, List L2) {
    List L3;
    L3 = MakeEmpty(L3);
    Position p1, p2, p3;
    p1 = First(L1), p2 = First(L2), p3 = First(L3);
    while (p1 && p2) {
        if (p1->data < p2->data) {
            p1 = p1->next;
        } else if (p2->data < p1->data) {
            p2 = p2->next;
        } else {
            Insert(p1->data, L3, p3);
            p1 = p1->next, p2 = p2->next, p3 = p3->next;
        }
    }
    return L3;
}

// 3.15 a)
Position Find(ElementTpye x, List L) {
    int index = 0;
    for (register int i = 1; i < L.size; i++) {
        if (x == L.Element[i]) {
            index = i;
            break;
        }
    }
    if (index) {
        for (register int i = index; i > 1; i--) {
            L.Element[i] = L.Element[i-1];
            L.Element[1] = x;
            return 1;
        }
    }
    return 0;
}

// 3.15 b)
Position Find(ElementTpye x, List L) {
    Position p1, p2;
    p1 = FindPrevious(x, L);
    if (p1) {
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = L->next;
        L->next = p2;
        return p2;
    }
    return NULL;
}

// 3.17 a)
// Its advantage is that it offers a way to keep datas supposed to 
// be deleted which are useful though they are deleted.
// Its disadvantage is very obious that is takes up mre storage.

// 3.17 b)
// In C++ we can use bool to identify if the node is deleted. 
struct node
{
    int data;
    node *next;
    bool flag = 1;
};
// If flag = 0, the node it belongs is deleted.
// When it comes to linked list, if the node's flag = 0, we should
// skip it.(p = p->next)
