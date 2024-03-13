// Take LR rotation as an example.
Position DoubleRotation(Position p1) {
    Postion p2, p3;
    p2 = p1->left;
    p3 = p3->right;

    p2->right = p3->left;
    p1->left = p3->right;
    p3->left = p2;
    p1->right = p1
}