#include "chucnang.h"
#include <fstream>

ChucNang::ChucNang(){
    docFile();
}

ChucNang::~ChucNang(){
     for(int i = 0; i < dsSV.size(); i++){
        delete dsSV[i];
    }

    for(int i = 0; i < dsLop.size(); i++){
        delete dsLop[i];
    }

    for(int i = 0; i < dsDK.size(); i++){
        delete dsDK[i];
    }
}

void ChucNang::themSinhVien(SinhVien *sv){
    dsSV.push_back(sv);
    ghifileSinhVien();
    cout<<"Them sinh vien thanh cong!\n";
}

void ChucNang::suaSinhVien(string maSV){
    for(int i=0; i<(int)dsSV.size(); i++){
        if(dsSV[i]->getMaSV()==maSV){
            string tenMoi;
            int tuoiMoi;

            cin.ignore();

            cout<<"Nhap ten moi: ";
            getline(cin, tenMoi);
            cout<<"Nhap tuoi moi: ";
            cin>>tuoiMoi;

            dsSV[i]->setHoTen(tenMoi);
            dsSV[i]->setTuoi(tuoiMoi);
            
            ghifileSinhVien();
            cout<<"Cap nhat thanh cong!"<<endl;
            return;
        }
    }
    cout<<"Khong ton tai sinh vien!\n";
}

void ChucNang::xoaSinhVien(string maSV){
    for(int i=0; i<dsDK.size(); i++){
        if(dsDK[i]->getMaSV()==maSV){
            cout<<"Khong the xoa sinh vien dang hoc!\n";
            return;
        }
    }
    for(int i=0; i<dsSV.size(); i++){
        if(dsSV[i]->getMaSV()==maSV){
            delete dsSV[i];
            dsSV[i]=dsSV.back();
            dsSV.pop_back();
            ghifileSinhVien();
            cout<<"Xoa thanh cong!\n";
            return;
        }
    }
    cout<<"Khong ton tai sinh vien!\n";
}

//Tim sinh vien
void ChucNang::timSinhVien(string maSV)const{
    for(int i = 0; i < dsSV.size(); i++){
        if(dsSV[i]->getMaSV() == maSV){
            cout << "\n--------------------------------------------------\n";
            cout << "                KET QUA TIM KIEM\n";
            dsSV[i]->display_info();
            cout << "---------------------------------------------------\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien!\n";
}

void ChucNang::danhsachSinhVien()const{
    if(dsSV.size() == 0){
        cout<<"Danh sach rong!\n";
        return;
    }
    cout<<"\n=============================================================\n";
    cout<<"                    DANH SACH SINH VIEN\n";
    cout<<"\n=============================================================\n";
    for(int i=0; i<dsSV.size(); i++){
        dsSV[i]->display_info();
        cout<<endl;
    }
}

void ChucNang::themLopHoc(LopHoc *lop){
    dsLop.push_back(lop);
    ghifileLopHoc();
    cout<<"Them lop hoc thanh cong!\n";
}

void ChucNang::suaLopHoc(string maLop){
    for(int i=0; i<dsLop.size(); i++){
        if(dsLop[i]->getMaLop()==maLop){
            string malopMoi;
            int sisoMoi;
            
            cin.ignore();

            cout<<"Nhap ma lop moi: ";
            getline(cin, malopMoi);
            cout<<"Nhap si so moi: ";
            cin>>sisoMoi;

            dsLop[i]->setMaLop(malopMoi);
            dsLop[i]->setSiSo(sisoMoi);

            ghifileLopHoc();
            cout<<"Cap nhat thanh cong!\n";
            return;
        }
    }
    cout<<"Khong ton tai lop hoc!\n";
}

//Xoa Lop hoc
void ChucNang::xoaLopHoc(string maLop){
    for(int i = 0; i < dsDK.size(); i++){
        if(dsDK[i]->getMaLop() == maLop){
            cout << "Khong the xoa lop hoc dang co sinh vien dang ky!\n";
            return;
        }
    }
    for(int i = 0; i < dsLop.size(); i++){
        if(dsLop[i]->getMaLop() == maLop){
            delete dsLop[i];

            dsLop[i] = dsLop.back();
            dsLop.pop_back();
            ghifileLopHoc();
            cout << "Xoa lop hoc thanh cong!\n";
            return;
        }
    }
    cout << "Khong ton tai lop hoc!\n";
}

//Danh sach lop hoc
void ChucNang::danhsachLopHoc()const{
    if(dsLop.empty()){
        cout << "Danh sach lop hoc rong!\n";
        return;
    }
    cout << "\n=============================================================\n";
    cout << "                    DANH SACH LOP HOC\n";
    cout << "==============================================================\n";
    for(int i = 0; i < dsLop.size(); i++){
        dsLop[i]->display_info();
        cout << endl;
    }
}

//Tim lop hoc
void ChucNang::timLopHoc(string maLop)const{
    for(int i = 0; i < dsLop.size(); i++){
        if(dsLop[i]->getMaLop() == maLop){
            cout << "\n========================================================\n";
            cout << "                     KET QUA TIM KIEM\n";
            cout << "=========================================================\n";
            dsLop[i]->display_info();
            cout << "=========================================================\n";
            return;
        }
    }
    cout << "Khong tim thay lop hoc nao!\n";
}

//Đăng Ký
void ChucNang::dangKyhoc(string maSV, string maLop){
    if(!tontaiSinhVien(maSV))
    {
        cout << "Khong ton tai sinh vien!\n";
        return;
    }

    if(!tontaiLopHoc(maLop))
    {
        cout << "Khong ton tai lop hoc!\n";
        return;
    }

    for(int i = 0; i < dsDK.size(); i++)
    {
        if(dsDK[i]->getMaSV() == maSV &&
           dsDK[i]->getMaLop() == maLop)
        {
            cout << "Sinh vien da dang ky lop nay!\n";
            return;
        }
    }
    DangKy* dk = new DangKy(maSV, maLop);
    dsDK.push_back(dk);
    ghifileDangKy();
    cout << "Dang ky thanh cong!\n";
}

//Huy dang ky lop 
void ChucNang::huyDangKy(string maSV, string maLop){
    for(int i = 0; i < dsDK.size(); i++)
    {
        if(dsDK[i]->getMaSV() == maSV &&
           dsDK[i]->getMaLop() == maLop)
        {
            delete dsDK[i];
            dsDK[i] = dsDK.back();
            dsDK.pop_back();
            ghifileDangKy();
            cout << "Huy dang ky thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay dang ky!\n";
}

//Thống Kê
void ChucNang::danhsachLopvaSinhVien() const
{
    if(dsLop.empty())
    {
        cout << "Khong co lop hoc!\n";
        return;
    }
    cout << "\n";
    cout << "========================================================\n";
    cout << "          DANH SACH LOP HOC VA SINH VIEN\n";
    cout << "========================================================\n";

    for(int i = 0; i < dsLop.size(); i++)
    {
        cout << "\nLOP: " << dsLop[i]->getMaLop() << endl;
        cout << "--------------------------------------------------------\n";
        bool found = false;

        for(int j = 0; j < dsDK.size(); j++)
        {
            if(dsDK[j]->getMaLop() == dsLop[i]->getMaLop())
            {
                string maSV = dsDK[j]->getMaSV();

                for(int k = 0; k < dsSV.size(); k++)
                {
                    if(dsSV[k]->getMaSV() == maSV)
                    {
                        cout << "Ma SV : "
                             << dsSV[k]->getMaSV()
                             << " | Ho Ten : "
                             << dsSV[k]->getHoTen()
                             << endl;

                        found = true;
                    }
                }
            }
        }

        if(!found)
        {
            cout << "Chua co sinh vien dang ky.\n";
        }
    }
}

//Kiểm tra tồn tại
bool ChucNang::tontaiSinhVien(string maSV)const{
    for(int i = 0; i < dsSV.size(); i++){
        if(dsSV[i]->getMaSV() == maSV)
        return true;
    }
    return false;
}
bool ChucNang::tontaiLopHoc(string maLop)const{
    for(int i = 0; i < dsLop.size(); i++){
        if(dsLop[i]->getMaLop() == maLop)
        return true;
    }
    return false;
}


void ChucNang::docfileSinhVien(){
    ifstream f;
    f.open("sinhvien.txt");
    if(f.is_open()){
        string maSV;
        string hoTen;
        int tuoi;
        while(getline(f, maSV)){
            getline(f, hoTen);
            f>>tuoi;
            f.ignore();
            dsSV.push_back(new SinhVien(maSV, hoTen, tuoi));
        }
        f.close();
    }
}

void ChucNang::ghifileSinhVien(){
    ofstream f;
    f.open("sinhvien.txt");
    if(f.is_open()){
        for(int i=0; i<dsSV.size(); i++){
            f<<dsSV[i]->getMaSV()<<endl;
            f<<dsSV[i]->getHoTen()<<endl;
            f<<dsSV[i]->getTuoi()<<endl;
        }
        f.close();
    }
}

void ChucNang::docfileLopHoc(){
    ifstream f;
    f.open("lophoc.txt");
    if(f.is_open()){
        string maLop;
        int siso;
        while(getline(f, maLop)){
            f>>siso;
            f.ignore();
            dsLop.push_back(new LopHoc(maLop, siso));
        }
        f.close();
    }
}

void ChucNang::ghifileLopHoc(){
    ofstream f;
    f.open("lophoc.txt");
    if(f.is_open()){
        for(int i=0; i<dsLop.size(); i++){
            f<<dsLop[i]->getMaLop()<<endl;
            f<<dsLop[i]->getSiSo()<<endl;
        }
        f.close();
    }
}

void ChucNang::docfileDangKy(){
    ifstream f;
    f.open("dangky.txt");
    if(f.is_open()){
        string maSV;
        string maLop;
        while(getline(f, maSV)){
            getline(f, maLop);
            dsDK.push_back(new DangKy(maSV, maLop));
        }
        f.close();
    }
}

void ChucNang::ghifileDangKy(){
    ofstream f;
    f.open("dangky.txt");
    if(f.is_open()){
        for(int i=0; i<dsDK.size(); i++){
            f<<dsDK[i]->getMaSV()<<endl;
            f<<dsDK[i]->getMaLop()<<endl;
        }
        f.close();
    }
}

void ChucNang::docFile(){
    docfileSinhVien();
    docfileLopHoc();
    docfileDangKy();
}

void ChucNang::ghiFile(){
    ghifileSinhVien();
    ghifileLopHoc();
    ghifileDangKy();
}
