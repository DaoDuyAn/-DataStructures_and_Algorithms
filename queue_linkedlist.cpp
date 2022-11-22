#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
};
typedef struct node *TroNut;

struct Queue {
    TroNut top, bottom;
};

void push(Queue &queue, int x) {
    TroNut p = new node;
    p->data = x;
    if (queue.top == NULL and queue.bottom == NULL) {
        queue.top = p;
        queue.bottom = p;
    } else {
        queue.top->next = p;
        queue.top = p;
    }
}

int pop(Queue &queue) {
    int x = queue.bottom->data;
    TroNut p = queue.bottom;
    queue.bottom = queue.bottom->next;
    delete p;
    return x;
}

int main() {
    Queue Q;
    Q.top = NULL;
    Q.bottom = NULL;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        push(Q, i);
    }

    while (Q.bottom != NULL) {
        cout << pop(Q) << endl;
    }
    
    return 0;
}