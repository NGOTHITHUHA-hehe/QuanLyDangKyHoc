#include "sinhvien.h"
#include "lophoc.h"
#include "dangky.h"
#include "chucnang.h"
#include <iostream>
using namespace std;

int main(){
    ChucNang cn;
    int choice;
    do{
        cout<<"\n===== QUAN LY DANG KY HOC CUA SINH VIEN =====\n";
        cout<<"1. Them sinh vien\n";
        cout<<"2. Sua sinh vien\n";
        cout<<"3. Xoa sinh vien\n";
        cout<<"4. Tim sinh vien\n";
        cout<<"5. Them lop hoc\n";
        cout<<"6. Sua lop hoc\n";
        cout<<"7. Xoa lop hoc\n";
        cout<<"8. Tim lop hoc\n";
        cout<<"9. Dang ky hoc\n";
        cout<<"10. Huy dang ky hoc\n";
        cout<<"11. Danh sach sinh vien\n";
        cout<<"12. Danh sach lop hoc\n";
        cout<<"13. Danh sach lop hoc va sinh vien\n";
        cout<<"14. Thoat\n";
        cout<<"Nhap lua chon cua ban: ";
        cin>>choice;
        
        switch (choice)
        {
        case 1:
        {
            string maSV;
            string hoTen;
            int tuoi;
            cin.ignore();
            cout<<"Nhap ma sinh vien: ";
            getline(cin, maSV);
            cout<<"Nhap ho va ten: ";
            getline(cin, hoTen);
            cout<<"Nhap tuoi sinh vien: ";
            cin>>tuoi;
            cn.themSinhVien(new SinhVien(maSV, hoTen, tuoi));
            break;
        }

        case 2:
        {
            string maSV;
            cin.ignore();
            cout<<"Nhap ma sinh vien can sua: ";
            getline(cin, maSV);
            cn.suaSinhVien(maSV);
            break;
        }

        case 3:
        {
            string maSV;
            cin.ignore();
            cout<<"Nhap ma sinh vien can xoa: ";
            getline(cin, maSV);
            cn.xoaSinhVien(maSV);
            break;
        }

        case 4:
        {
            string maSV;
            cin.ignore();
            cout << "Nhap ma sinh vien can tim: ";
            getline(cin, maSV);
            cn.timSinhVien(maSV);
            break;
        }

        case 5:
        {
            string maLop;
            int siSo;
            cin.ignore();
            cout<<"Nhap ma lop: ";
            getline(cin, maLop);
            cout<<"Nhap si so lop: ";
            cin>> siSo;
            cn.themLopHoc(new LopHoc(maLop, siSo));
            break;
        }

        case 6:
        {
            string maLop;
            cin.ignore();
            cout<<"Nhap ma lop can sua: ";
            getline(cin, maLop);
            cn.suaLopHoc(maLop);
            break;
        }

        case 7:
        {
            string maLop;
            cin.ignore();
            cout<<"Nhap ma lop can xoa: ";
            getline(cin, maLop);
            cn.xoaLopHoc(maLop);
            break;
        }

        case 8:
        {
            string maLop;
            cin.ignore();
            cout<<"Nhap ma lop can tim: ";
            getline(cin, maLop);
            cn.timLopHoc(maLop);
            break;
        }

        case 9:
        {
            string maSV;
            string maLop;
            cin.ignore();
            cout<<"Nhap ma sinh vien: ";
            getline(cin, maSV);
            cout<<"Nhap ma lop: ";
            getline(cin, maLop);
            cn.dangKyhoc(maSV, maLop);
            break;
        }

        case 10: 
        {
            string maSV;
            string maLop;
            cin.ignore();
            cout<<"Nhap ma sinh vien: ";
            getline(cin, maSV);
            cout<<"Nhap ma lop: ";
            getline(cin, maLop);
            cn.huyDangKy(maSV, maLop);
            break;
        }

        case 11:
        {
            cn.danhsachSinhVien();
            break;
        }

        case 12:
        {
            cn.danhsachLopHoc();
            break;
        }

        case 13:
        {
            cn.danhsachLopvaSinhVien();
            break;
        }

        case 14:
        {
            cout<<"Thoat!\n";
            break;
        }

        default:
            cout<<"Lua chon khong hop le!\n";
            break;
        }

    }while(choice!=14);
    
    return 0;
}
