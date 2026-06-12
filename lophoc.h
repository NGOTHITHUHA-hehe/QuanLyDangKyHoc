#ifndef LOPHOC_H
#define LOPHOC_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class LopHoc{
    private:
    string maLop;
    int siSo;
    public:
    LopHoc();
    LopHoc(string, int);

    void setMaLop(string);
    void setSiSo(int);

    string getMaLop()const;
    int getSiSo()const;

    
    void display_info();
    void suaThongtin(); //in ra thong tin lop moi

    void ghiFile(ofstream&) const;
    void docFile(ifstream&);
};

#endif