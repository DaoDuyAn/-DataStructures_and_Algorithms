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

node *addHead(node *F, int val) {
    node *q = CreateNode(val);
    q->next = head, head = q;
    return F;
}

node *addAt(node *F, int ele, int pos) {
    node *q = CreateNode(ele);
    if (pos == 0)
        q->next = F, F = q;
    else {
        int cnt = 1;
        node *i = F;
        while (i->next != NULL && cnt < pos) i = i->next, cnt++;
        q->next = i->next, i->next = q;
    }
    return F;
}

node *addTail(node *F, int val) {
    node *tmp = createNode(val), *p;

    if (F == NULL) {
        F = tmp;
    } else {
        p = F;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
    return F;
}

node *deleteHead(node *F) {
    if (F != NULL) {
        node *q = F;
        F = F->next;
        delete q;
    }
    return F;
}

node *deleteTail(node *F) {
    if (F != NULL) {
        if (F->next == NULL) {
            node *q = F;
            F = F->next;
            delete q;
            return F;
        } else {
            node *i = F;
            while (i->next->next != NULL) {
                i = i->next;
            }
            node *j = i->next;
            i->next = j->next;
            delete j;
            return F;
        }
    }
}

node *deleteAt(node *F, int pos) {
    if (pos == 0) {
        if (F != NULL) {
            node *q = F;
            F = F->next;
            delete q;
        }
        return F;
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
        return F;
    }
}

int countLessThanX(node *F, int X) {
    int cnt = 0;
    for (node *p = F; p != NULL; p = p->next) {
        if (p->data < X) cnt++;
    }
    return cnt;
}

void sortAsc(node *F) {
    for (node *t1 = F; t1 != NULL; t1 = t1->next) {
        for (node *t2 = t1->next; t2 != NULL; t2 = t2->next) {
            if (t1->data > t2->data) {
                int s = t1->data;
                t1->data = t2->data;
                t2->data = s;
            }
        }
    }
}

void sortedInsert(node *F, node *nodeX) {
    node *current;

    if (F == NULL or F->data >= nodeX->data) {
        nodeX->next = F;
        F = nodeX;
    } else {
        current = F;
        while (current->next != NULL and current->next->data < nodeX->data) {
            current = current->next;
        }

        nodeX->next = current->next;
        current->next = nodeX;
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

node *findAddress(node *F, int val) {
    while (F != NULL) {
        if (F->data == val) {
            return F;
        }
        F = F->next;
    }
    return NULL;
}

node *sortedDelete(node *F, int val) {
    int pos = searchValue(F, val);
    if (pos != -1) {
        F = deleteAt(F, pos);
    }
    return F;
}

int maxValueNode(node *F) {
    int max = INT_MIN;

    while (F != NULL) {
        if (max < F->data) max = F->data;
        F = F->next;
    }
    return max;
}

node *copyList(node *F) {
    node *copy = NULL;
    if (F == NULL) {
        return copy;
    } else {
        node *p = F;

        while (p != NULL) {
            copy = addTail(copy, p->data);
            p = p->next;
        }
        return copy;
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

node *getUnion(node *F1, node *F2) {
    node *res = NULL;
    while (F1 != NULL) {
        if (!(isPresent(res, F1->data))) {
            res = addTail(res, F1->data);
        }
        F1 = F1->next;
    }

    while (F2 != NULL) {
        if (!isPresent(res, F2->data)) {
            res = addTail(res, F2->data);
        }
        F2 = F2->next;
    }

    return res;
}

node *getIntersection(node *F1, node *F2) {
    node *res = NULL;

    while (F1 != NULL) {
        if (isPresent(F2, F1->data)) {
            res = addTail(res, F1->data);
        }
        F1 = F1->next;
    }

    return res;
}

void printReverse(node *F) {
    if (F == NULL) {
        return;
    }

    printReverse(F->next);
    cout << F->data << " ";
}

void printList(node *F) {
    for (node *p = F; p != NULL; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    node *F = NULL;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        F = addTail(F, val);
    }

    //	1. Tìm số nút trong danh sách F có giá trị trường Info bé hơn một số
    // nguyên X cho trước.
    // int X;
    // cout << "Nhap X: ";
    // cin >> X;
    // cout << "So nut be hon " << X << ": " << countLessThanX(F, X);

    // 2. Chèn một nút có giá trị trường Info bằng X vào danh sách F đã được sắp
    // xếp theo thứ tự tăng dần của trường Info.
    // https://www.geeksforgeeks.org/given-a-linked-list-which-is-sorted-how-will-you-insert-in-sorted-way/

    // int X2;
    // cout << "Nhap X2: ";
    // cin >> X2;
    // node *nodeX = createNode(X2);
    // sortAsc(F);
    // sortedInsert(F, nodeX);
    // printList(F);

    // 3. Xoá một nút có giá trị trường Info bằng X của danh sách F đã được sắp
    // xếp theo thứ tự tăng của trường Info.
    int X3;
    cout << "Nhap X3: ";
    cin >> X3;
    sortAsc(F);
    F = sortedDelete(F, X3);
    printList(F);

    // 4. Tìm giá trị lớn nhất của trường Info của các nút thuộc danh sách F,
    // với giả thiết rằng danh sách F có ít nhất là một nút (F khác NULL).
    // cout << "Gia tri lon nhat cua truong Info la: " << maxValueNode(F);

    // 5. Bổ sung 1 nút mới có giá trị trường Info bằng X vào cuối danh sách F.
    // int X5;
    // cout << "Nhap X5: ";
    // cin >> X5;
    // F = addTail(F, X5);
    // printList(F);

    // 6. Xoá nút cuối của danh sách F.
    // F = deleteTail(F);
    // printList(F);

    // 7. Tìm địa chỉ của một nút thuộc danh sách F có giá trị trường Info
    // bằng X (nếu có), hoặc trả về giá trị NULL nếu tìm không có, trong 2
    // trường hợp sau:
    // int X7;
    // cout << "Nhap X7: ";
    // cin >> X7;
    // a) Danh sách F không được sắp xếp
    // if (findAddress(F, X7) == NULL)
    //     cout << "NULL" << endl;
    // else
    //     cout << findAddress(F, X7) << endl;

    // b) Danh sách F được sắp xếp theo thứ tự tăng dần của trường Info.
    // sortAsc(F);
    // if (findAddress(F, X7) == NULL)
    //     cout << "NULL" << endl;
    // else
    //     cout << findAddress(F, X7);

    // 8. In giá trị trường Info các nút của danh sách F theo thứ tự ngược (từ
    // nút cuối đến nút đầu).
    // printReverse(F);

    // 9. Tạo ra một danh sách mới L (nút đầu trỏ bởi L) có dữ liệu trường Info
    // lần lượt được sao chép từ danh sách F.
    // node *L = copyList(F);
    // printList(L);

    // 10. Cho trước 2 danh sách F1 và F2 đã được sắp xếp theo thứ tự tăng của
    // trường Info và lần lượt biểu diễn cho 2 tập hợp các số nguyên F1 và F2.
    // Viết hàm nhằm tạo ra danh sách F3 để biểu diễn cho:
    // int n1;
    // cout << "Nhap so phan tu F1: ";
    // cin >> n1;
    // node *F1 = NULL;
    // int val;
    // for (int i = 0; i < n1; i++) {
    //     cin >> val;
    //     F1 = addTail(F1, val);
    // }

    // int n2;
    // cout << "Nhap so phan tu F2: ";
    // cin >> n2;
    // node *F2 = NULL;
    // for (int i = 0; i < n2; i++) {
    //     cin >> val;
    //     F2 = addTail(F2, val);
    // }

    // a) Hợp của 2 tập hợp F1 và F2. Ví dụ: Nếu F1={1,3,5} và F2={1,2,5} thì
    // F3 = {1,2,3,5}.
    // node *F3 = getUnion(F1, F2);
    // sortAsc(F3);
    // printList(F3);
    // b) Giao của 2 tập hợp F1 và F2. Ví dụ: Nếu F1={1,3,5} và F2={1,2,5} thì
    // F3 = {1,5}.
    // node *F4 = getIntersection(F1, F2);
    // sortAsc(F4);
    // printList(F4);

    return 0;
}
