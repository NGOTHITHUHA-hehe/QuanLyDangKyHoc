#ifndef CHUCNANG_H
#define CHUCNANG_H
#include <vector>
#include "sinhvien.h"
#include "lophoc.h"
#include "dangky.h"

class ChucNang{
    private:
    vector<SinhVien*> dsSV;
    vector<LopHoc*> dsLop;
    vector<DangKy*> dsDK;
    public:
    ChucNang();
    ~ChucNang();

    //Sinh viên
    void themSinhVien(SinhVien*);
    void suaSinhVien(string);
    void xoaSinhVien(string);
    void danhsachSinhVien()const;
    void timSinhVien(string)const;

    //Lớp học
    void themLopHoc(LopHoc*);
    void suaLopHoc(string);
    void xoaLopHoc(string);
    void danhsachLopHoc()const;
    void timLopHoc(string)const;

    //Đăng ký
    void dangKyhoc(string, string);
    void huyDangKy(string, string);

    //Thống kê
    void danhsachLopvaSinhVien()const;

    //Kiểm tra tồn tại
    bool tontaiSinhVien(string)const;
    bool tontaiLopHoc(string)const;

    //File
    void docfileSinhVien();
    void ghifileSinhVien();

    void docfileLopHoc();
    void ghifileLopHoc();

    void docfileDangKy();
    void ghifileDangKy();

    void docFile();
    void ghiFile();
};

#endif