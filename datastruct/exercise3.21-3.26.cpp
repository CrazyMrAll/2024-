// 3.21
// Eletype is the type of element in array. MAXN-2 is the most elements 
// the stack can contain.
struct stackinonearray
{
    Eletype *stack = (*Eletype)malloc(sizeof(Eletype)*MAXN);
    Eletype *l = stack, *r = stack + MAXN - 1;
    Eletype *topl = l+1, topr = r-1;
}

int push_stack1(Eletype *topl, Eletype X) {
    if (topl == topr) return error;
    else {
        *topl = X;
        topr++;
        return suceess;
    }
}

int push_stack2(Eletype *topr, Eletype X) {
    if (topl == topr) return error;
    else {
        *topr = X;
        topr--;
    }
}

Eletype pop_stack1(Eletype *topl, Eletype *l) {
    if (topl == l) return error;
    else {
        Eletype t = *topl;
        topl--;
        return t;
    }
}

Eletype pop_stack2(Eletype *topr, Eletype *r) {
    if (topr == r) return error;
    else {
        Eletype t = *topr;
        topr++;
        return t;
    }
}

// 3.25
// a.linked lists
typedef struct node
{
    Eletype data;
    node* next;
}Node, *Queue;
Queue q, front, rear;

void queue_init(Queue q) {
    q = (Queue)malloc(sizeof(struct node));
    q->next = NULL;
    front = q;
    rear = q->next;
}

void queue_in(Queue rear, Eletype X) {
    rear->next = (Queue)malloc(sizeof(struct node));
    rear = rear->next;
    rear->data = X;
    rear->next = NULL;
}

Eletype queue_out(Queue front, Eletype X) {
    Queue tmp = front;
    Eletype t = front->data;
    front = front->next;
    free(tmp);
    return t;
}

int queue_empty(Queue front, Queue rear) {
    if (front->next == rear) return error;
    else return OK;
}

// b.arrays
Eletype queue[MAXN];
int front = -1, rear = -1;

int isfull(int front, int rear) {
    if ((rear+1)%MAXN == front) return error;
    else return OK;
}

int isempty(int front, int rear) {
    if (rear == front && rear == -1) return error;
    else return OK;
}

void queue_in(int front, int rear, Eletype X) {
    queue[++rear] = X;
    if (front == -1) 
        front = rear = 0;
}

void queue_out(int front, int rear, Eletype X) {
    Eletype t = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front+1) % MAXN;
    return t;
}

// 3.26
typedef struct node
{
    Eletype data;
    node *next;
    node *pre;
}*Node;

struct deque
{
    node *q = (Node)malloc(sizeof(struct node));
    node *front, *rear;
    front = rear = q;
};

void push(Eletype X, dequeu d) {
    Node t = (Node)malloc(sizeof(struct node));
    t->data = X;
    t->next = d.front;
    t->pre = NULL;
    d.front->pre = t;
    d.front = t;
}

void pop(equeu d) {
    Node t = d.front;
    Eletype t = d.front->data;
    d.front = d.front->next;
    free(t);
    return t;
}

void inject(Eletype X, dequeu d) {
    Node t = (Node)malloc(sizeof(struct node));
    t->data = X;
    t->pre = d.rear;
    t->next = NULL;
    d.rear->next = t;
    d.rear = t;
}

void eject(equeu d) {
    Node t = d.rear;
    Eletype t = d.rear->data;
    d.rear = d.rear->pre;
    free(t);
    return t;
}
