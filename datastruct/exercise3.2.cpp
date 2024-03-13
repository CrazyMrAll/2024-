void PrintLosts(List L, List P) {
    Position Lp, Pp;
    int cnt = 1;
    Lp = First(L), Pp = First(P);
    while (Lp && Pp) {
        if (Pp->Element == cnt) {
            printf("%(ElementType)", Lp->Elment);
            Pp = Pp->next;
        }
        cnt++;
        Lp = Lp->next;
    }
}

// Running time of my routine is O(L + P).