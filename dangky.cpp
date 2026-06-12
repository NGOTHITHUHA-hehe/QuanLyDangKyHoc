#include "dangky.h"

DangKy::DangKy(){
    maSV = "";
    maLop = "";
}

DangKy::DangKy( string maSV,  string maLop)
{
    this -> maSV = maSV;
    this -> maLop = maLop;
}

void DangKy::setMaSV(string maSV)
{
    this -> maSV = maSV;
}
void DangKy::setMaLop(string maLop)
{
    this -> maLop = maLop;
}
string DangKy::getMaSV() const
{
    return this -> maSV;
}
string DangKy::getMaLop() const
{
    return this -> maLop;
}
void DangKy::display_info()
{
    cout << "\n====================================================================\n";
    cout << "                 THONG TIN DANG KY LOP HOC\n";
    cout << "=====================================================================\n";
    cout << "Ma sinh vien : " << maSV << endl;
    cout << "Ma lop hoc : " << maLop << endl;
    cout << "======================================================================\n";
}

void DangKy::ghiFile(ofstream& out) const
{
    out << maSV << " " << maLop << endl;
}

void DangKy::docFile(ifstream& in)
{
    in >> maSV >> maLop;
}
