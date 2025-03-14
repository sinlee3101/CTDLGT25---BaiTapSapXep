#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// (a) Dinh nghia cau truc du lieu de luu tru thong tin phong thi
struct PhongThi {
    int soPhong;
    char nha;
    int sucChua;
};

// (b) Sap xep giam dan theo suc chua
bool compareBySucChua(const PhongThi &a, const PhongThi &b) {
    return a.sucChua > b.sucChua;
}

// (b) Sap xep tang dan theo nha, cung nha thi tang dan theo so phong
bool compareByNhaSoPhong(const PhongThi &a, const PhongThi &b) {
    if (a.nha == b.nha)
        return a.soPhong < b.soPhong;
    return a.nha < b.nha;
}

// (b) Sap xep tang dan theo nha, cung nha thi giam dan theo suc chua
bool compareByNhaSucChua(const PhongThi &a, const PhongThi &b) {
    if (a.nha == b.nha)
        return a.sucChua > b.sucChua;
    return a.nha < b.nha;
}

int main() {
    int n;
    cout << "Nhap so luong phong thi: ";
    cin >> n;
    
    vector<PhongThi> danhSach(n);
    cout << "Nhap thong tin cac phong thi (so phong, nha, suc chua):\n";
    for (int i = 0; i < n; i++) {
        cout << "Phong thu " << i + 1 << ": ";
        cin >> danhSach[i].soPhong >> danhSach[i].nha >> danhSach[i].sucChua;
    }
    
    // Sap xep theo suc chua giam dan
    sort(danhSach.begin(), danhSach.end(), compareBySucChua);
    cout << "\nDanh sach phong thi sap xep theo suc chua giam dan:\n";
    for (const auto &phong : danhSach) {
        cout << phong.nha << phong.soPhong << " - " << phong.sucChua << " cho\n";
    }
    
    // Sap xep theo nha tang dan, cung nha thi tang dan so phong
    sort(danhSach.begin(), danhSach.end(), compareByNhaSoPhong);
    cout << "\nDanh sach phong thi sap xep theo nha tang dan, so phong tang dan:\n";
    for (const auto &phong : danhSach) {
        cout << phong.nha << phong.soPhong << " - " << phong.sucChua << " cho\n";
    }
    
    // Sap xep theo nha tang dan, cung nha thi giam dan suc chua
    sort(danhSach.begin(), danhSach.end(), compareByNhaSucChua);
    cout << "\nDanh sach phong thi sap xep theo nha tang dan, suc chua giam dan:\n";
    for (const auto &phong : danhSach) {
        cout << phong.nha << phong.soPhong << " - " << phong.sucChua << " cho\n";
    }
    
    return 0;
}
