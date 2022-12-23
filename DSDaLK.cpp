#include <bits/stdc++.h>
using namespace std;

typedef char St25[25];
typedef char St8[8];

struct HocSinh {
    int MaHS;
    St25 HoTen;
    St8 NgaySinh;
    HocSinh *Next;
};

struct Lop {
    Lop *Down;
    St8 TenLop;
    HocSinh *DSHS;
};
Lop *F;

// a) DiaChi(Lop *F, St8 Blop) trả về địa chỉ của nút thuộc danh sách F có giá
// trị trường TenLop là Blop, hoặc trả về giá trị NULL nếu không có nút nào thoả
// mãn điều kiện này.

Lop *DiaChi(Lop *F, St8 Blop) {
    if (F == NULL or strcmp(F->TenLop, Blop) > 0) return NULL;
    if (strcmp(F->TenLop, Blop) == 0) return F;
    return DiaChi(F->Down, Blop);
}

// b) InDSHS(Lop *F, St8 Blop) nhằm in ra màn hình
// danh sách học sinh của lớp Blop theo mẫu:
// DANH SACH HOC SINH LOP …..
// Stt Ma hoc sinh Ho ten Ngay sinh
// -----------------------------------------------------------
// 1 12345 Le Van An 01/01/05
// 2 12346 Vo Thi Be 02/02/05
// …

void InDanhSach(HocSinh *hs, St8 Blop) {
    cout << "DANH SACH HOC SINH LOP " << Blop << endl;
    cout << "Stt"
         << "Ma hoc sinh"
         << "Ho ten"
         << "Ngay sinh" << endl;
    cout << "-----------------------------------------------------------"
         << endl;

    int stt = 1;
    for (HocSinh *p = hs; p != NULL; p = p->Next) {
        cout << stt << p->MaHS << p->HoTen << p->NgaySinh << endl;
        stt++;
    }

    cout << endl;
}

void InDSHS(Lop *F, St8 Blop) {
    Lop *p = DiaChi(F, Blop);
    if (p != NULL) {
        InDanhSach(F->DSHS, Blop);
    }
}

// c) SiSo(Lop *F, St8 Blop) trả về sĩ số của lớp Blop trong danh sách F. Nếu
// không tìm thấy lớp Blop thì trả về giá trị 0.

int TongSoHS(HocSinh *p) {
    int cnt = 0;
    while (p != NULL) {
        cnt++;
        p = p->Next;
    }
    return cnt;
}

int SiSo(Lop *F, St8 Blop) {
    Lop *p = DiaChi(F, Blop);
    if (p == NULL)
        return 0;
    else
        return TongSoHS(p->DSHS);
}

// d) InSiSoCacLop(Lop *F) thực hiện việc in sĩ số của tất cả các lớp trong danh
// sách F, theo mẫu:
// DANH SACH SI SO CAC LOP
// 1. Lop 10A: … HS
// 2. Lop 10B: … HS
// …
// --------------------------
// Tong cong: ….. HS

void InSiSoCacLop(Lop *F) {
    if (F != NULL) {
        cout << "\nDANH SACH SI SO CAC LOP\n";
        int stt = 1, tongSiSo = 0;
        for (Lop *p = F; p != NULL; p = p->Down) {
            int siSo = SiSo(F->DSHS, F->TenLop);
            cout << stt << "." << F->TenLop << ":" << siSo << endl;

            tongSiSo += siSo;
            stt++;
        }
        cout << "--------------------------\n";
        cout << "Tong cong: " << tongSiSo << " HS" << endl;
    }
}

// e) BoSung(Lop *&F, St8 Blop, int Bmahs, St25 Bhoten, St8 Bngaysinh) cho phép
// bổ sung một nút vào cuối danh sách học sinh của lớp Blop, sao cho nút đó có
// mã học sinh là Bmahs, họ tên là Bhoten và ngày sinh là Bngaysinh.
// Cụ thể ta xét các trường hợp:
//• Blop chưa có trong danh sách lớp thì chèn vào một lớp mới
//  gồm có 1 học sinh với thông tin đã cho.
//• Blop đã có trong danh sách lớp, nhưng:
//  o Bmahs chưa có trong danh sách học sinh thì chèn vào cuối danh sách 1
//    học sinh với thông tin đã cho.
//  o Bmahs đã có trong danh sách học sinh thì cập nhật lại thông tin của nút
//    này theo thông tin mới đã cho
//    (cập nhật lại trường HoTen và NgaySinh).

void BoSungDau(Lop *&F, St8 Blop, int Bmahs, St25 Bhoten, St8 Bngaysinh) {
    Lop *p = new Lop;
    strcpy(p->TenLop, Blop);
    p->DSHS->MaHS = Bmahs;
    strcpy(p->DSHS->HoTen, Bhoten);
    strcpy(p->DSHS->NgaySinh, Bngaysinh);
    p->DSHS->Next = NULL;
    p->Down = F;
    F = p;
}

void CapNhatHS(HocSinh *&q, int Bmahs, St25 Bhoten, St8 Bngaysinh) {
    HocSinh *p = q, *t;
    while (p != NULL) {
        t = p;
        if (p->MaHS == Bmahs) {
            strcpy(p->HoTen, Bhoten);
            strcpy(p->NgaySinh, Bngaysinh);
        } else {
            p = p->Next;
        }
    }

    t->Next = new HocSinh;
    p = t->Next;
    p->MaHS = Bmahs;
    strcpy(p->HoTen, Bhoten);
    srtcpy(p->NgaySinh, Bngaysinh);
    p->Next = NULL;
}

void BoSung(Lop *&F, St8 Blop, int Bmahs, St25 Bhoten, St8 Bngaysinh) {
    if (F == NULL or strcmp(Blop, F->TenLop) < 0) {
        BoSungDau(F, Blop, Bmahs, Bhoten, Bngaysinh);
    } else {
        if (strcmp(Blop, F->TenLop) == 0)
            CapNhatHS(F->DSHS, Bmahs, Bhoten, Bngaysinh);
        else
            BoSung(F->Down, Blop, Bmahs, Bhoten, Bngaysinh);
    }
}





// bool KiemtraHS(HocSinh *&L, int Bmahs) {
//     for (HocSinh *p = L; p != NULL; p = p->Next) {
//         if (p->MaHS == Bmahs) {
//             return true;
//         }
//     }
//     return false;
// }

// void BoSungHS(HocSinh *&L, int Bmahs, St25 Bhoten, St8 Bngaysinh) {
//     if (KiemtraHS(L, Bmahs)) {
//         for (HocSinh *p = L; p != NULL; p = p->Next) {
//             if (p->MaHS == Bmahs) {
//                 strcpy(p->HoTen, Bhoten);
//                 strcpy(p->NgaySinh, Bngaysinh);
//             }
//         }
//     } else {
//         HocSinh *p;
//         for (p = L; p->Next != NULL; p = p->Next)
//             ;

//         HocSinh *q = new HocSinh;
//         q->MaHS = Bmahs;
//         strcpy(q->HoTen, Bhoten);
//         strcpy(q->NgaySinh, Bngaysinh);
//         q->Next = NULL;

//         p->Next = q;
//     }
// }

// void BoSung(Lop *&F, St8 Blop, int Bmahs, St25 Bhoten, St8 Bngaysinh) {
//     Lop *l = DiaChi(F, Blop);
//     if (l == NULL) {
//         Lop *p = F;
//         while (strcmp(p->TenLop, Blop) < 0 and p->Down != NULL) {
//             p = p->Down;
//         }

//         Lop *q = new Lop;
//         q->TenLop = Blop;

//         HocSinh *hs = new HocSinh;
//         hs->MaHS = Bmahs;
//         strcpy(hs->HoTen, Bhoten);
//         strcpy(hs->NgaySinh, Bngaysinh);
//         hs->Next = NULL;

//         q->DSHS = hs;
//         q->Down = NULL;

//         q->Down = p->Down;
//         p->Down = p;

//     } else {
//         BoSungHS(l->DSHS, Bmahs, Bhoten, Bngaysinh);
//     }
// }
// g) Xét một danh sách học sinh L (nút đầu trỏ bởi L), viết hàm:
// XoaHS(HocSinh * &L, int Bmahs) nhằm xoá một nút thuộc danh sách học sinh L có
// mã học sinh là Bmahs.

void XoaHS(HocSinh *&L, int Bmahs) {
    if (L != NULL) {
        if (strcmp(L->MaHS, Bmahs) == 0) {
            HocSinh *q = L;
            L = L->Next;
            delete q;
        } else {
            XoaHS(L->Next, Bmahs);
        }
    }
}

// h) Xoa(Lop *&F, St8 Blop, int Bmahs) cho phép xoá một nút thuộc danh sách học
// sinh có mã học sinh là Bmahs thuộc lớp Blop. Trong trường hợp, sau khi xoá
// xong, lớp Blop không còn học sinh nào thì xoá tiếp lớp đó khỏi danh sách lớp.

void Xoa(Lop *&F, St8 Blop, int Bmahs) {
    if (F != NULL) {
        if (strcmp(F->TenLop, Blop) == 0) {
            XoaHS(F->DSHS, Bmahs);
            if (F->DSHS == NULL) {
                Lop *p = F;
                F = F->Down;
                delete p;
            }
        } else {
            if (strcmp(F->TenLop, Blop) < 0) {
                Xoa(F->Down, Blop, Bmahs);
            }
        }
    }
}

int main() { return 0; }