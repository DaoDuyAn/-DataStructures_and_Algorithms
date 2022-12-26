#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
};

node *createNode(int val) {
    node *tmp = new node;
    tmp->next = NULL;
    tmp->data = val;
    return tmp;
}

void addHead(node *&F, int val) {
    node *q = createNode(val);
    q->next = F, F = q;
}

// void addAt(node *&F, int ele, int pos) {
//     node *q = createNode(ele);
//     if (pos == 0)
//         q->next = F, F = q;
//     else {
//         int cnt = 1;
//         node *i = F;
//         while (i->next != NULL && cnt < pos) i = i->next, cnt++;
//         q->next = i->next, i->next = q;
//     }
// }

// 5. Bổ sung 1 nút mới có giá trị trường Info bằng X vào cuối danh sách F.
void addTail(node *&F, int val) {
    node *tmp = createNode(val), *p;
    if (F == NULL) {
        F = tmp;
    } else {
        for (p = F; p->next != NULL; p = p->next)
            ;
        p->next = tmp;
    }
}

void addTailRecusrsion(node *&F, int X) {
    if (F == NULL) {
        node *p = new node;
        p->data = X;
        p->next = F;
        F = p;
    } else {
        addTailRecusrsion(F->next, X);
    }
}

void addTailRecusrsion2(node *&F, int val) {
    if (F == NULL) {
        node *tmp = createNode(val);
        F = tmp;
    } else {
        if (F->next != NULL) {
            addTailRecusrsion(F->next, val);
        } else {
            node *tmp = createNode(val);
            F->next = tmp;
        }
    }
}

void deleteHead(node *&F) {
    if (F != NULL) {
        node *q = F;
        F = F->next;
        delete q;
    }
}
// 6. Xoá nút cuối của danh sách F.
void deleteTail(node *&F) {
    if (F != NULL) {
        if (F->next == NULL) {
            node *q = F;
            F = F->next;
            delete q;
        } else {
            node *i;
            for (i = F; i->next->next != NULL; i = i->next)
                ;

            node *j = i->next;
            i->next = j->next;
            delete j;
        }
    }
}

void deleteTailRecursion(node *&F) {
    if (F != NULL) {
        if (F->next == NULL) {
            node *q = F;
            F = F->next;
            delete q;
        } else {
            if (F->next->next != NULL) {
                deleteTailRecursion(F->next);
            } else {
                node *j = F->next;
                F->next = j->next;
                delete j;
            }
        }
    }
}

void deleteAt(node *&F, int pos) {
    if (pos == 0) {
        if (F != NULL) {
            node *q = F;
            F = F->next;
            delete q;
        }
    } else {
        int cnt = 1;
        node *i = F;
        while (i != NULL && i->next != NULL) {
            if (cnt == pos) {
                node *j = i->next;
                i->next = j->next;
                delete j;
                break;
            }
            i = i->next, cnt++;
        }
    }
}

//	1. Tìm số nút trong danh sách F có giá trị trường Info bé hơn một số
// nguyên X cho trước.

int countLessThanX(node *F, int X) {
    int cnt = 0;
    for (node *p = F; p != NULL; p = p->next) {
        if (p->data < X) cnt++;
    }
    return cnt;
}

int cntLessThanXRecursion(node *F, int X, int cnt) {
    if (F == NULL) return cnt;
    if (F->data < X) cnt++;
    return cntLessThanXRecursion(F->next, X, cnt);
}

int Count(node *F, int X) {
    if (F == NULL) {
        return 0;
    } else {
        if (F->data < X)
            return 1 + Count(F->next, X);
        else
            return Count(F->next, X);
    }
}

void sortAsc(node *F) {
    for (node *t1 = F; t1->next != NULL; t1 = t1->next) {
        for (node *t2 = t1->next; t2->next != NULL; t2 = t2->next) {
            if (t1->data > t2->data) {
                swap(t1->data, t2->data);
            }
        }
    }
}

// 2. Chèn một nút có giá trị trường Info bằng X vào danh sách F đã được sắp
// xếp theo thứ tự tăng dần của trường Info.

void sortedInsert(node *&F, int X) {
    if (F == NULL or F->data >= X) {
        node *nodeX = createNode(X);
        nodeX->next = F;
        F = nodeX;
    } else {
        node *current = F;
        while (current->next != NULL and X > current->next->data) {
            current = current->next;
        }

        node *nodeX = createNode(X);
        nodeX->next = current->next;
        current->next = nodeX;
    }
}

void sortedInsertRecursion(node *&F, int X) {
    if (F == NULL or F->data >= X) {
        node *nodeX = createNode(X);
        nodeX->next = F;
        F = nodeX;
    } else {
        if (F->next == NULL) {
            node *nodeX = createNode(X);
            F->next = nodeX;
        } else {
            if (X > F->next->data) {
                sortedInsertRecursion(F->next, X);
            } else {
                node *nodeX = createNode(X);
                nodeX->next = F->next;
                F->next = nodeX;
            }
        }
    }
}

int searchValue(node *F, int val) {
    int pos = 0;
    while (F != NULL) {
        if (F->data == val) {
            return pos;
        }
        pos++, F = F->next;
    }
    return -1;
}
// 7. Tìm địa chỉ của một nút thuộc danh sách F có giá trị trường Info
// bằng X (nếu có), hoặc trả về giá trị NULL nếu tìm không có, trong 2
// trường hợp sau:
node *findAdd(node *F, int val) {
    while (F != NULL) {
        if (F->data == val) {
            return F;
        }
        F = F->next;
    }
    return NULL;
}
node *findAddRecursion(node *F, int val) {
    if (F == NULL or F->data > val) return NULL;
    if (F->data == val) return F;
    return findAddRecursion(F->next, val);
}

// void sortedDelete(node *&F, int val) {
//     int pos = searchValue(F, val);
//     if (pos != -1) {
//         deleteAt(F, pos);
//     }
// }

// 3. Xoá một nút có giá trị trường Info bằng X của danh sách F đã được sắp
// xếp theo thứ tự tăng của trường Info.
void deleteNode(node *&F, node *q) {
    if (q == F) {
        F = F->next;
    } else {
        node *p;
        for (p = F; p->next != q; p = p->next)
            ;
        p->next = q->next;
    }
    delete q;
}

void deleteNodeRecursion(node *&F, node *q) {
    if (q == F) {
        F = F->next;
        delete q;

    } else {
        if (F->next == q) {
            F->next = q->next;
            delete q;
        } else {
            deleteNodeRecursion(F->next, q);
        }
    }
}

void Delete(node *&F, int X) {
    if ((F != NULL) or (F->data <= X)) {
        if (F->data == X) {
            node *q = F;
            F = F->next;
            delete q;
        } else
            Delete(F->next, X);
    }
}

// 4. Tìm giá trị lớn nhất của trường Info của các nút thuộc danh sách F,
// với giả thiết rằng danh sách F có ít nhất là một nút (F khác NULL).
int maxValueNode(node *F) {
    int max = INT_MIN;

    while (F != NULL) {
        if (max < F->data) max = F->data;
        F = F->next;
    }
    return max;
}

int maxValueNodeRecursion(node *F, int mx) {
    if (F == NULL) return mx;
    if (F->data > mx) mx = F->data;
    return maxValueNodeRecursion(F->next, mx);
}

// 9. Tạo ra một danh sách mới L (nút đầu trỏ bởi L) có dữ liệu trường Info
// lần lượt được sao chép từ danh sách F.
node *copyList(node *F) {
    node *copy = NULL;
    if (F == NULL) {
        return copy;
    } else {
        node *p;
        for (p = F; p != NULL; p = p->next) {
            addTail(copy, p->data);
        }
        return copy;
    }
}

void copyListRecursion(node *F, node *&L) {
    if (F == NULL) {
        L = NULL;
    } else {
        addHead(L, F->data);
        copyListRecursion(F->next, L->next);
    }
}

bool isPresent(node *F, int data) {
    node *p = F;
    while (p != NULL) {
        if (p->data == data) {
            return true;
        }
        p = p->next;
    }
    return false;
}

// 10. a) Hợp của 2 tập hợp F1 và F2.
node *getUnion(node *F1, node *F2) {
    node *res = NULL;
    while (F1 != NULL) {
        if (!(isPresent(res, F1->data))) {
            addTail(res, F1->data);
        }
        F1 = F1->next;
    }

    while (F2 != NULL) {
        if (!(isPresent(res, F2->data))) {
            addTail(res, F2->data);
        }
        F2 = F2->next;
    }

    return res;
}

void getUnionRecursion(node *F1, node *F2, node *&F3) {
    if (F1 == NULL) {
        copyListRecursion(F2, F3);
    } else {
        if (F2 == NULL) {
            copyListRecursion(F1, F3);
        } else {
            if (F1->data == F2->data) {
                addHead(F3, F1->data);
                getUnionRecursion(F1->next, F2->next, F3->next);
            }

            if (F1->data < F2->data) {
                addHead(F3, F1->data);
                getUnionRecursion(F1->next, F2, F3->next);
            }

            if (F1->data > F2->data) {
                addHead(F3, F2->data);
                getUnionRecursion(F1, F2->next, F3->next);
            }
        }
    }
}
// b) Giao của 2 tập hợp F1 và F2.
node *getIntersection(node *F1, node *F2) {
    node *res = NULL;

    while (F1 != NULL) {
        if (isPresent(F2, F1->data)) {
            if (!isPresent(res, F1->data)) {
                addTail(res, F1->data);
            }
        }
        F1 = F1->next;
    }

    return res;
}

void getIntersectionRecursion(node *F1, node *F2, node *&F3) {
    if (F1 == NULL or F2 == NULL) {
        F3 = NULL;
    } else {
        if (F1->data == F2->data) {
            addHead(F3, F1->data);
            getIntersectionRecursion(F1->next, F2->next, F3->next);
        } else {
            if (F1->data > F2->data)
                getIntersectionRecursion(F1, F2->next, F3);
            else
                getIntersectionRecursion(F1->next, F2, F3);
        }
    }
}
// 8. In giá trị trường Info các nút của danh sách F theo thứ tự ngược (từ
// nút cuối đến nút đầu).
void printReverse(node *F) {
    if (F == NULL) return;

    printReverse(F->next);
    cout << F->data << " ";
}

void push(node *&Top, int val) { addHead(Top, val); }

int pop(node *&Top) {
    if (Top != NULL) {
        int val = Top->data;
        node *p = Top;
        Top = Top->next;
        delete p;
        return val;
    }
}

void printReverseRecursion(node *F) {
    node *Top = NULL, *p;
    for (p = F; p != NULL; p = p->next) {
        push(Top, p->data);
    }

    while (Top != NULL) cout << pop(Top) << " ";
}

void printList(node *F) {
    for (node *p = F; p != NULL; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}

int main() {
    // int n;
    // cout << "Nhap so phan tu: ";
    // cin >> n;
    // node *F = NULL;
    // int val;
    // for (int i = 0; i < n; i++) {
    //     cin >> val;
    //     addTail(F, val);
    // }

    // printList(F);
    //	1. Tìm số nút trong danh sách F có giá trị trường Info bé hơn một số
    // nguyên X cho trước.

    // Cách 1:
    // int X;
    // cout << "Nhap X: ";
    // cin >> X;
    // cout << "So nut be hon " << X << ": " << countLessThanX(F, X);

    // Cách 2: Dùng đệ quy.
    // int X;
    // cout << "Nhap X: ";
    // cin >> X;
    // int cnt = 0;
    // cout << "So nut be hon " << X << ": " << cntLessThanXRecursion(F, X,
    // cnt);

    // 2. Chèn một nút có giá trị trường Info bằng X vào danh sách F đã được sắp
    // xếp theo thứ tự tăng dần của trường Info.

    // Cách 1:
    // int X2;
    // cout << "Nhap X2: ";
    // cin >> X2;
    // sortAsc(F);
    // sortedInsert(F, X2);
    // printList(F);

    // Cách 2: Dùng đệ quy.
    // int X2;
    // cout << "Nhap X2: ";
    // cin >> X2;
    // sortAsc(F);
    // sortedInsertRecursion(F, X2);
    // printList(F);

    // 3. Xoá một nút có giá trị trường Info bằng X của danh sách F đã được sắp
    // xếp theo thứ tự tăng của trường Info.

    // Cách 1:
    // int X3;
    // cout << "Nhap X3: ";
    // cin >> X3;
    // sortAsc(F);
    // node *q = findAdd(F, X3);
    // if (q != NULL) {
    //     deleteNode(F, q);
    // }
    // printList(F);

    // Cách 2: Dùng đệ quy.
    // int X3;
    // cout << "Nhap X3: ";
    // cin >> X3;
    // sortAsc(F);
    // node *q = findAddRecursion(F, X3);
    // if (q != NULL) {
    //     deleteNodeRecursion(F, q);
    // }
    // printList(F);

    // 4. Tìm giá trị lớn nhất của trường Info của các nút thuộc danh sách F,
    // với giả thiết rằng danh sách F có ít nhất là một nút (F khác NULL).

    // Cách 1:
    // cout << "Gia tri lon nhat cua truong Info la: " << maxValueNode(F);

    // Cách 2: Dùng đệ quy.
    // int mx = INT_MIN;
    // cout << "Gia tri lon nhat cua truong Info la: "
    //      << maxValueNodeRecursion(F, mx);

    // 5. Bổ sung 1 nút mới có giá trị trường Info bằng X vào cuối danh sách F.

    // Cách 1:
    // int X5;
    // cout << "Nhap X5: ";
    // cin >> X5;
    // addTail(F, X5);
    // printList(F);

    // Cách 2: Dùng đệ quy.
    // int X5;
    // cout << "Nhap X5: ";
    // cin >> X5;
    // addTailRecusrsion2(F, X5);
    // printList(F);

    // 6. Xoá nút cuối của danh sách F.

    // Cách 1:
    // deleteTail(F);
    // printList(F);

    // Cách 2: Dùng đệ quy.
    // deleteTailRecursion(F);
    // printList(F);

    // 7. Tìm địa chỉ của một nút thuộc danh sách F có giá trị trường Info
    // bằng X (nếu có), hoặc trả về giá trị NULL nếu tìm không có, trong 2
    // trường hợp sau:
    // int X7;
    // cout << "Nhap X7: ";
    // cin >> X7;
    // a) Danh sách F không được sắp xếp
    // if (findAdd(F, X7) == NULL)
    //     cout << "NULL" << endl;
    // else
    //     cout << findAdd(F, X7) << endl;

    // b) Danh sách F được sắp xếp theo thứ tự tăng dần của trường Info.
    // sortAsc(F);

    // Dùng đệ quy.
    // if (findAddRecursion(F, X7) == NULL)
    //     cout << "NULL" << endl;
    // else
    //     cout << findAddRecursion(F, X7);

    // 8. In giá trị trường Info các nút của danh sách F theo thứ tự ngược (từ
    // nút cuối đến nút đầu).

    // Cách 1:
    // printReverse(F);

    // Cách 2: Dùng đệ quy.
    // printReverseRecursion(F);

    // 9. Tạo ra một danh sách mới L (nút đầu trỏ bởi L) có dữ liệu trường Info
    // lần lượt được sao chép từ danh sách F.
    // Cách 1:
    // node *L = copyList(F);
    // printList(L);

    // Cách 2: Dùng đệ quy.
    // node *L;
    // copyListRecursion(F, L);
    // printList(L);

    // 10. Cho trước 2 danh sách F1 và F2 đã được sắp xếp theo thứ tự tăng của
    // trường Info và lần lượt biểu diễn cho 2 tập hợp các số nguyên F1 và F2.
    // Viết hàm nhằm tạo ra danh sách F3 để biểu diễn cho:
    int n1;
    cout << "Nhap so phan tu F1: ";
    cin >> n1;
    node *F1 = NULL;
    int val;
    for (int i = 0; i < n1; i++) {
        cin >> val;
        addTail(F1, val);
    }

    int n2;
    cout << "Nhap so phan tu F2: ";
    cin >> n2;
    node *F2 = NULL;
    for (int i = 0; i < n2; i++) {
        cin >> val;
        addTail(F2, val);
    }

    // a) Hợp của 2 tập hợp F1 và F2. Ví dụ: Nếu F1={1,3,5} và F2={1,2,5} thì
    // F3 = {1,2,3,5}.

    // Cách 1:
    // node *F3 = getUnion(F1, F2);
    // sortAsc(F3);
    // printList(F3);

    // Cách 2: Dùng đệ quy.
    node *F3 = NULL;
    getUnionRecursion(F1, F2, F3);
    printList(F3);
    // b) Giao của 2 tập hợp F1 và F2. Ví dụ: Nếu F1={1,3,5} và F2={1,2,5} thì
    // F3 = {1,5}.

    // Cách 1:
    // node *F4 = getIntersection(F1, F2);
    // sortAsc(F4);
    // printList(F4);

    // Cách 2: Dùng đệ quy.
    // node *F4 = NULL;
    // getIntersectionRecursion(F1, F2, F4);
    // printList(F4);
    return 0;
}
