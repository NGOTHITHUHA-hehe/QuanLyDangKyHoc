#include "sinhvien.h"


SinhVien::SinhVien(){
    this -> maSV = "###";
    this -> hoten = "###";
    this -> tuoi = 0;
}

SinhVien::SinhVien(string maSV, string hoten, int tuoi)
{
    this -> maSV = maSV;
    this -> hoten = hoten;
    this -> tuoi = tuoi;
}

void SinhVien::setMaSV(string maSV){
    this -> maSV = maSV;
}

void SinhVien::setHoTen(string hoten){
    this -> hoten = hoten;
}

void SinhVien::setTuoi(int tuoi){
    this -> tuoi = tuoi;
}

string SinhVien::getMaSV()const{
    return this -> maSV;
}

string SinhVien::getHoTen()const{
    return this -> hoten;
}

int SinhVien::getTuoi()const{
    return this -> tuoi;
}

void SinhVien::display_info(){
    cout << "Ma sinh vien: " << maSV <<endl;
    cout << "Ho ten sinh vien: " << hoten <<endl;
    cout << "Tuoi sinh vien: " << tuoi <<endl;
}

void SinhVien::suaThongtin(){
    cout << "Nhap ma sinh vien moi: ";
    cin.ignore();
    getline(cin, maSV);
    cout << "Nhap ho ten sinh vien moi: ";
    getline(cin, hoten);
    cout << "Nhap tuoi sinh vien moi: ";
    cin >> tuoi;
}

void SinhVien::ghiFile(ofstream& out) const
{
    out << maSV << ",";
    out << hoten << ",";
    out << tuoi << endl;
}

void SinhVien::docFile(ifstream& in)
{
    getline(in, maSV, ',');
    getline(in, hoten, ',');
    in >> tuoi;
    in.ignore();
}