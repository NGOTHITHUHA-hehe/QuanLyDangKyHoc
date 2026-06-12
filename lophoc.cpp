#include "lophoc.h"
#include <cstring>

LopHoc::LopHoc(){
    this -> maLop = "###";
    this -> siSo = 0;
}

LopHoc::LopHoc(string maLop, int siSo){
    this -> maLop = maLop;
    this -> siSo = siSo;
}

void LopHoc::setMaLop(string maLop)
{
    this -> maLop = maLop;
}

void LopHoc::setSiSo(int siSo)
{
    this -> siSo = siSo;
}

string LopHoc::getMaLop() const
{
    return this -> maLop;
}

int LopHoc::getSiSo() const
{
    return this -> siSo;
}

void LopHoc::display_info()
{
    cout << "Ma lop: " << maLop << '\n';
    cout << "Si so: " << siSo << '\n';
}

void LopHoc::suaThongtin()
{
    cout << "Nhap ma lop moi: ";
    getline(cin, maLop);
    cout << "Nhap si so moi: ";
    cin >> siSo;
}

void LopHoc::ghiFile(ofstream& out) const
{
    out << maLop << " " << siSo << endl;
}

void LopHoc::docFile(ifstream& in)
{
    in >> maLop >> siSo;
}
