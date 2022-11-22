#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
};
typedef struct node *TroNut;

struct Stack {
    TroNut top;
};

void push(Stack &stack, int x) {
    TroNut p = new node;
    p->data = x;
    p->next = stack.top;
    stack.top = p;
}

int pop(Stack &stack) {
    int x = stack.top->data;
    TroNut p = stack.top;
    stack.top = stack.top->next;
    delete p;
    return x;
}

int main() {
    Stack S;
    S.top = NULL;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        push(S, i);
    }

    while (S.top != NULL) {
        cout << pop(S) << endl;
    }
    
    return 0;
}
