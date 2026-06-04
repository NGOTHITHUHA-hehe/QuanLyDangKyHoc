#ifndef DANGKY_H
#define DANGKY_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class DangKy{
    private:
    string maSV;
    string maLop;
    public:
    DangKy();
    DangKy(string, string);

    void setMaSV(string);
    void setMaLop(string);

    string getMaSV()const;
    string getMaLop()const;

    void ghiFile(ofstream&) const;
    void docFile(ifstream&);
};

#endif