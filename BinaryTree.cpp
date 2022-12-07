#include <bits/stdc++.h>
using namespace std;
struct Nut {
    int Info;
    Nut *Left, *Right;
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

// 3. Xoá tất cả các nút của cây T (giải phóng toàn bộ vùng nhớ của tất cả các
// nút để biến cây T thành cây rỗng).
void Xoa(Nut *T) {
    if (T != NULL) {
        Xoa(T->Left);
        Xoa(T->Right);
        delete (T);
    }
}

// 4. Tìm giá trị lớn nhất của trường Info của các nút thuộc cây T,
// với giả thiết cây T có ít nhất một nút (T khác NULL), trong 2 trường hợp sau:
// a) Cây T là cây nhị phân tìm kiếm
int Max(Nut *T) {
    if (T->Right != NULL) return Max(T->Right);
    return T->Info;
}
// b) Cây T không là cây nhị phân tìm kiếm.

// 5. Tìm số nút nhánh trong cây T.

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
    if (T == 0)
        return 0;
    else {
        if (p == T)
            return 1;
        else
            return Muc(T, Cha(T, p)) + 1;
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
        L = KhoiTao(T->Info);
        SaoChepCay(T->Left, L->Left);
        SaoChepCay(T->Right, L->Right);
    }
}

// 12. a) Thay thế giá trị trường Info của mỗi nút trên cây T 
// bằng mức của nút đó trên cây T. 

//b) Từ đó tìm số nút trên cây T có mức là x.

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

    duyetPGT(T);
    return 0;
}