#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class SinhVien{
    private:
    string maSV;
    string hoten;
    int tuoi;

    public:
    SinhVien();
    SinhVien(string, string, int);

    void setMaSV(string);
    void setHoTen(string);
    void setTuoi(int);

    string getMaSV()const;
    string getHoTen()const;
    int getTuoi()const;
    
    void display();
    void suaThongtin(); // in ra thong tin sinh vien moi

    void ghiFile(ofstream&)const;
    void docFile(ifstream&);
};

#endif