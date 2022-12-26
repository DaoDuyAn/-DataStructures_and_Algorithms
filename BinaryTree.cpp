#include <bits/stdc++.h>
using namespace std;

struct Nut {
    int Info;
    Nut *Left, *Right;
};

struct node {
    int data;
    node *next;
};

Nut *KhoiTao(int val) {
    Nut *q = new Nut;
    q->Info = val, q->Left = q->Right = NULL;
    return q;
}

// 1. Tìm chiều cao của cây T.
int ChieuCao(Nut *T) {
    if (T == NULL)
        return 0;
    else
        return max(ChieuCao(T->Left), ChieuCao(T->Right)) + 1;
}

// 2. Bổ sung một nút lá có giá trị trường Info bằng X vào cây T là cây nhị phân
// tìm kiếm theo trường khóa Info.
bool NutTrai(Nut *T, int val) { return val <= T->Info; }

bool NutPhai(Nut *T, int val) { return val > T->Info; }

void ThemNut(Nut *&T, int val) {
    if (T == NULL)
        T = KhoiTao(val);
    else if (NutTrai(T, val))
        ThemNut(T->Left, val);
    else if (NutPhai(T, val))
        ThemNut(T->Right, val);
}

// 3. Xoá tất cả các nút của cây T (giải phóng toàn bộ vùng nhớ
// của tất cả các nút để biến cây T thành cây rỗng).
void Xoa(Nut *&T) {
    if (T != NULL) {
        Xoa(T->Left);
        Xoa(T->Right);
        delete (T);
        T = NULL;
    }
}

// 4. Tìm giá trị lớn nhất của trường Info của các nút thuộc cây T,
// với giả thiết cây T có ít nhất một nút (T khác NULL), trong 2 trường hợp sau:
// a) Cây T là cây nhị phân tìm kiếm
int Max_BST(Nut *T) {
    if (T->Right != NULL) return Max_BST(T->Right);
    return T->Info;
}

int Min_BST(Nut *T) {
    if (T->Left != NULL) return Min_BST(T->Left);
    return T->Info;
}

int Max_BST_2(Nut *T) {
    Nut *p = T;
    while (p->Right != NULL) {
        p = p->Right;
    }
    return p->Info;
}
// b) Cây T không là cây nhị phân tìm kiếm.
int Max_BT(Nut *T) {
    int leftMax, rightMax;
    int mx = T->Info;

    if (T->Left != NULL) {
        leftMax = Max_BT(T->Left);
        mx = max(mx, leftMax);
    }

    if (T->Right != NULL) {
        rightMax = Max_BT(T->Right);
        mx = max(mx, rightMax);
    }
    return mx;
}

int Max_BT2(Nut *T) {
    int res = 0;
    if (T != NULL) {
        res = T->Info;
        int lres = Max_BT(T->Left);
        int rres = Max_BT(T->Right);
        if (lres > res) res = lres;
        if (rres > res) res = rres;
    }
    return res;
}
// int tongNut(Nut *T) {
//     if (T == NULL) return 0;

//     int l = tongNut(T->Left);
//     int r = tongNut(T->Right);

//     return 1 + l + r;
// }

int soNutLa(Nut *T) {
    if (T == NULL)
        return 0;
    else {
        if ((T->Left == NULL) and (T->Right == NULL))
            return 1;
        else
            return soNutLa(T->Left) + soNutLa(T->Right);
    }
}

// 5. Tìm số nút nhánh trong cây T.
int soNutNhanh(Nut *T) {
    if ((T == NULL) or (T->Left == NULL and T->Right == NULL))
        return 0;
    else
        return 1 + soNutNhanh(T->Left) + soNutNhanh(T->Right);
}

// Cách 2:
void DuyetSoNutNhanh(Nut *T, int &count) {
    if (T != NULL) {
        if (T->Left != NULL or T->Right != NULL) count++;
        DuyetSoNutNhanh(T->Left, count);
        DuyetSoNutNhanh(T->Right, count);
    }
}
int soNutNhanh2(Nut *T) {
    int count = 0;
    DuyetSoNutNhanh(T, count);
    return count;
}

// Cách khác:
//  int soNutKhacNutLa(Nut *root) {
//      if (root == NULL || (root->Left == NULL && root->Right == NULL)) return
//      0;

//     return 1 + soNutKhacNutLa(root->Left) + soNutKhacNutLa(root->Right);
// }

// int soNutNhanh(Nut *T) {
//     int cnt = soNutKhacNutLa(T);
//     if (cnt == 0) return 0;
//     return cnt - 1;
// }

// 6. a) Tìm địa chỉ nút cha của nút được trỏ bởi p thuộc cây T.
Nut *Cha(Nut *T, Nut *p) {
    if (T == NULL or T == p)
        return NULL;
    else {
        if (T->Left == p or T->Right == p)
            return T;
        else {
            if (Cha(T->Left, p) != NULL)
                return Cha(T->Left, p);
            else
                return Cha(T->Right, p);
        }
    }
}

// b) Từ đó tìm mức của nút được trỏ bởi p thuộc cây T.
int Muc(Nut *T, Nut *p) {
    if (T == NULL)
        return 0;
    else {
        if (p == T)
            return 1;
        else
            return Muc(T, Cha(T, p)) + 1;
    }
}

// 7. Tìm địa chỉ của một nút thuộc cây T có giá trị trường Info bằng X (nếu có)
//, hoặc trả về giá trị NULL nếu tìm không có, trong 2 trường hợp sau:
// a) Cây T là cây nhị phân tìm kiếm
Nut *TimKiem1(Nut *root, int val) {
    if (root == NULL) return NULL;
    if (root->Info == val) return root;
    if (root->Info > val) return TimKiem1(root->Left, val);
    if (root->Info < val) return TimKiem1(root->Right, val);
}

// b) Cây T không là cây nhị phân tìm kiếm.
Nut *TimKiem2(Nut *root, int val) {
    if (root != NULL) {
        if (root->Info == val) return root;
        TimKiem2(root->Left, val);
        TimKiem2(root->Right, val);
    } else {
        return NULL;
    }
}

// 8. In giá trị trường Info của các nút của cây T theo thứ tự giảm dần, biết
// rằng cây T là cây nhị phân tìm kiếm theo trường khóa Info.
void duyetPGT(Nut *T) {
    if (T != NULL) {
        duyetPGT(T->Right);
        cout << T->Info << ' ';
        duyetPGT(T->Left);
    }
}

// 9. Tạo ra một cây mới L (nút gốc trỏ bởi L) có dữ liệu trường Info lần lượt
// được sao chép từ cây T.
void SaoChepCay(Nut *T, Nut *&L) {
    if (T == NULL)
        L = NULL;
    else {
        L = new Nut;
        L->Info = T->Info;
        SaoChepCay(T->Left, L->Left);
        SaoChepCay(T->Right, L->Right);
    }
}

// 10. Kiểm tra một cây T bất kỳ có phải là cây nhị phân tìm kiếm hay không.
int Min_BT(Nut *T) {
    int leftMin, rightMin;
    int mn = T->Info;

    if (T->Left != NULL) {
        leftMin = Min_BT(T->Left);
        mn = min(mn, leftMin);
    }

    if (T->Right != NULL) {
        rightMin = Min_BT(T->Right);
        mn = min(mn, rightMin);
    }
    return mn;
}

int kiemTraCNPTK(Nut *T) {
    if (T == NULL) return 1;

    if (T->Left != NULL and Max_BT(T->Left) > T->Info) return 0;

    if (T->Right != NULL and Min_BT(T->Right) < T->Info) return 0;

    if (!kiemTraCNPTK(T->Left) or !kiemTraCNPTK(T->Right)) return 0;

    return 1;
}

// int isBST(Nut *T) {
//     if ((T == NULL) or (T->Left == NULL and T->Right == NULL))
//         return 1;
//     else {
//         if (T->Left == NULL) {
//             return (T->Info <= Min_BST(T->Right)) and isBST(T->Right);
//         } else {
//             if (T->Right == NULL) {
//                 return (T->Info > Max_BST(T->Left)) and isBST(T->Left);
//             } else {
//                 return (T->Info <= Min_BST(T->Right)) and
//                        (T->Info > Max_BST(T->Left)) and (isBST(T->Left)) and
//                        isBST(T->Right);
//             }
//         }
//     }
// }

// 11. Tìm cấp của cây T. Lưu ý rằng, cây T có cấp là 0 nếu cây T là cây rỗng
// hoặc cây có một nút.
int capCuaCay(Nut *T) {
    if ((T == NULL) or (T->Left == NULL and T->Right == NULL))
        return 0;
    else {
        if (T->Left != NULL and T->Right != NULL)
            return 2;
        else {
            return max(1, max(capCuaCay(T->Left), capCuaCay(T->Right)));
        }
    }
}

// Cách 2:
int capCuaNut(Nut *T) {
    if (T == NULL or (T->Left == NULL and T->Right == NULL))
        return 0;
    else {
        if (T->Left != NULL and T->Right != NULL)
            return 2;
        else
            return 1;
    }
}

void duyetCap(Nut *T, int &cap) {
    if (T != NULL) {
        if (cap < capCuaNut(T)) {
            cap = capCuaNut(T);
        }

        duyetCap(T->Left, cap);
        duyetCap(T->Right, cap);
    }
}

int capCuaCay_2(Nut *T) {
    int cap = 0;
    duyetCap(T, cap);
    return cap;
}

// 12. a) Thay thế giá trị trường Info của mỗi nút trên cây T
// bằng mức của nút đó trên cây T.
void thayMuc(Nut *T, int x) {
    if (T != NULL) {
        T->Info = x;
        thayMuc(T->Left, x + 1);
        thayMuc(T->Right, x + 1);
    }
}
// b) Từ đó tìm số nút trên cây T có mức là x.
void duyetCay(Nut *T, int x, int &cnt) {
    if (T != NULL) {
        if (T->Info == x) cnt++;
        duyetCay(T->Left, x, cnt);
        duyetCay(T->Right, x, cnt);
    }
}

int soNut(Nut *T, int x) {
    int cnt = 0;
    duyetCay(T, x, cnt);
    return cnt;
}

// 13. a) Tạo mới một danh sách liên kết đơn có nút đầu trỏ bởi F (được khai báo
// như trong nội dung của Bài tập 3) bằng cách sao chép giá trị trường Info của
// tất cả các nút thuộc cây T vào danh sách F.
void chuyenDL(Nut *T, node *&F) {
    if (T != NULL) {
        node *p = new node;
        p->data = T->Info;
        // Chèn đầu
        p->next = F;
        F = p;

        chuyenDL(T->Left, F);
        chuyenDL(T->Right, F);
    }
}

// b) Sắp xếp giá trị trường Info của các nút
// thuộc danh sách F theo thứ tự tăng dần.
void sapXepTangDan(node *F) {
    for (node *t1 = F; t1->next != NULL; t1 = t1->next) {
        for (node *t2 = t1->next; t2 != NULL; t2 = t2->next) {
            if (t1->data > t2->data) {
                swap(t1->data, t2->data);
            }
        }
    }
}

// c) Thay đổi giá trị trường Info của các nút trong cây T để nhận được một
//  cây nhị phân tìm kiếm.
void duyetGiua(Nut *T) {
    if (T != NULL) {
        duyetGiua(T->Left);
        cout << T->Info << endl;
        duyetGiua(T->Right);
    }
}

void thayDoiGT(Nut *T, node *&F) {
    if (T != NULL) {
        thayDoiGT(T->Left, F);
        T->Info = F->data;
        F = F->next;
        thayDoiGT(T->Right, F);
    }
}

void dieuChinh(Nut *T) {
    node *F = NULL;
    chuyenDL(T, F);
    sapXepTangDan(F);
    thayDoiGT(T, F);
    duyetGiua(T);
}

// 14. Cây T gọi là một “đống” nếu giá trị trường Info của nút cha
// lớn hơn nút con.

// a) Kiểm tra cây T có phải là một đống hay không.
int laDong(Nut *T) {
    if ((T == NULL) or (T->Left == NULL and T->Right == NULL))
        return 1;
    else {
        if (T->Left == NULL)
            return (T->Info > T->Right->Info) and laDong(T->Right);
        else {
            if (T->Right == NULL)
                return (T->Info > T->Left->Info) and laDong(T->Left);
            else
                return (T->Info > T->Left->Info) and laDong(T->Left) and
                       (T->Info > T->Right->Info) and laDong(T->Right);
        }
    }
}

// b) Tráo đổi giá trị trường Info của các nút để biến cây T thành một đống.
void traoDoi(Nut *T) {
    if ((T != NULL) and (T->Left != NULL or T->Right != NULL)) {
        if (T->Left == NULL) {
            traoDoi(T->Right);
            if (T->Info < T->Right->Info) swap(T->Info, T->Right->Info);
            traoDoi(T->Right);
        } else if (T->Right == NULL) {
            traoDoi(T->Left);
            if (T->Info < T->Left->Info) swap(T->Info, T->Left->Info);
            traoDoi(T->Left);
        } else {  // T->Left != NULL and T->Right != NULL
            traoDoi(T->Left);
            traoDoi(T->Right);
            if (T->Left->Info > T->Right->Info) {
                if (T->Info < T->Left->Info) {
                    swap(T->Info, T->Left->Info);
                    traoDoi(T->Left);
                }
            } else {  // T->Left->Info <= T->Right->Info
                if (T->Info < T->Right->Info) {
                    swap(T->Info, T->Right->Info);
                    traoDoi(T->Right);
                }
            }
        }
    }
}

int main() {
    Nut *T = NULL;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        ThemNut(T, val);
    }

    // Nut *L = NULL;
    // SaoChepCay(T, L);
    // duyetPGT(L);
    // cout << Max_BT(T) << endl << Min_BT(T);
    // duyetPGT(T);

    // cout << Cap(T);
    dieuChinh(T);

    // thayMuc(T, 1);
    // cout << soNut(T, 2);

    // traoDoi(T);
    // duyetGiua(T);
    return 0;
}