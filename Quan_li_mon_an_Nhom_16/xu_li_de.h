#pragma once
#include"ctdl.h"
///================================= Khai báo hàm =================================================
void Chuan_hoa_chu(string& a);
MON_AN* Khoi_tao_node_mon_an();
void Nhap_mon_an(DS_MON_AN& ds);
void Them_mon_an(TREE_MON_AN& t, MON_AN* p);
int Tao_ma_mon_an(TREE_MON_AN t);
int KT_trung_ma_mon_an(int ma_mon_an, TREE_MON_AN t);
void Xuat_mon_an(TREE_MON_AN mon);
void Xuat_mon_an_theo_ma(TREE_MON_AN t);
void Chuyen_cay_sang_mang(TREE_MON_AN t, MON_AN* ds[], int& nds);
void Hoan_doi(MON_AN*& a, MON_AN*& b);
void Sap_xep_mang_mon_an(MON_AN* ds[], int nds);
void Sap_xep_mang_mon_an_theo_dg(MON_AN* ds[], int nds);
void Xuat_mon_an_theo_ten(MON_AN* ds[], int nds);
void Giai_phong(MON_AN* ds[], int nds);


void Cap_nhat_mon_an(TREE_MON_AN& t, int ma, string ten, int gia,int loai,int sl_ton);
void Tim_node_the_mang(TREE_MON_AN& t, MON_AN* &x);
void Xoa_mon_an(TREE_MON_AN& t, int ma);
MON_AN* Tim_kiem_mon_an(TREE_MON_AN t, int ma);
void Tang_so_luong_ton(TREE_MON_AN& t, int ma);
void Giam_so_luong_ton(TREE_MON_AN& t, int ma);
void Tang_so_luong_mon(TREE_MON_AN& t, int ma);
void Giam_so_luong_mon(TREE_MON_AN& t, int ma);
void Doc_file_mon_an(DS_MON_AN& ds);
void Ghi_file_mon_an(DS_MON_AN ds);
void Ghi_file_mon_an(TREE_MON_AN t, ofstream& f);
///=================================== Hoa don==========================================
HOA_DON* Tim_kiem_hoa_don(TREE_HOADON t, int ma);
void Nhap_1_hoa_don(HOA_DON*& hd, DS_MON_AN ds_mon);
void Xuat_1_hd(HOA_DON* p);
void Them_hoa_don(TREE_HOADON& t, HOA_DON* p);
void Xuat_ds_hd(TREE_HOADON t);
void Chinh_sua_tt_hd_TREE(TREE_HOADON& t, int ma);
void Chinh_sua_tt_hd(HOA_DON*& hd);
void Doc_file_hoa_don(DS_HOA_DON& ds, DS_MON_AN ds_mon);
void Xuat_ds_mon_an_hd(TREE_MON_AN t, ofstream& f);
void Ghi_file_hoa_don(DS_HOA_DON ds);
void Ghi_file_hoa_don(TREE_HOADON t, ofstream& f);
int KT_trung_ma_hoa_don(int ma_hoa_don, TREE_HOADON t);
int Tao_ma_hoa_don(TREE_HOADON t);
void Cap_nhat_hoa_don(TREE_HOADON& t, int ma, string ngaylap, string ten, string diachi, string sdt);

//================================== Khuyen Mai ===============================
KM* Tim_kiem_KM(TREE_KM t, int ma);
void Them_1_KM(TREE_KM& t, KM* p);
int Tao_ma_km(TREE_KM t);
int KT_trung_ma_KM(int ma_km, TREE_KM t);
void Cap_nhat_khuyen_mai(TREE_KM& t, int ma, string ten, int gia, string hsd);
void Ghi_file_khuyen_mai1(TREE_KM t, ofstream& f);
void Ghi_file_khuyen_mai(DS_KM ds);
void Hoan_doi_km(KM*& a, KM*& b);
void Tim_node_the_mang_km(TREE_KM& t, KM* x);
void Xoa_khuyen_mai(TREE_KM& t, int ma);

bool KT_FILE(string path);
void Doc_file_khuyen_mai(DS_KM& ds);

string layngay(string time);
string laythang(string time);
string laynam(string time);
string layten(string a);
int String_sang_int(string a);
string Int_sang_string(int a);
int Tinh_so_ngay(int year, int month, int day);
void Tim_Kiem_theo_ngay(DS_HOA_DON& ds_hd, TREE_HOADON t, int tngay, int tthang, int tnam, int dngay, int dthang, int dnam);
void Tim_kiem_theo_ten(DS_HOA_DON& ds_hd, TREE_HOADON t, string hoten);
void Tim_kiem_theo_sdt(DS_HOA_DON& ds_hd, TREE_HOADON t, string sdt);
void Tim_kiem_hd_theo_gia_tri(DS_HOA_DON& ds_hd, TREE_HOADON t, int giatri);
void Xoa_cay_hd(TREE_HOADON& root);

void Them_hoa_don_theo_sdt(TREE_HOADON& t, HOA_DON* p);
void Them_hoa_don_theo_gia_tri(TREE_HOADON& t, HOA_DON* p);
void Them_hoa_don_theo_ten(TREE_HOADON& t1, HOA_DON* p1);
int so_sanh_2_ngay(string ngaythangnam1, string ngaythangnam2);
int so_sanh_2_ngay_(string ngaythangnam1, string ngaythangnam2);
void Them_hoa_don_theo_ngay(TREE_HOADON& t1, HOA_DON* p1);

string laytime();
string giatien(string tien);
void Xoa_cay_KM(TREE_KM& root);

void Tim_kiem_monan_theo_gia_tri(DS_MON_AN& ds_ma, TREE_MON_AN t, int giatri);

void Them_mon_an_theo_giatri(TREE_MON_AN& t, MON_AN* p);
void Xoa_cay_mon_an(TREE_MON_AN& root);

void Chuan_hoa_chuoi(string& a);
void Hoan_doi_hd(HOA_DON*& a, HOA_DON*& b);
void Tim_node_the_mang_hoa_don(TREE_HOADON& t, HOA_DON*& x);
void Xoa_hoa_don(TREE_HOADON& t, int ma);
MON_AN* Tim_kiem_mon_an1(TREE_MON_AN t, int ma);
void Tim_hd_theo_ma_mon_an(TREE_HOADON &t, int ma_ma,HOA_DON* &h);

int KiemTraNgayHopLe(string ngaythangnam);

void Tang_so_luong_ton_cay_mon_an(TREE_MON_AN& ds, TREE_MON_AN& t);
int KTsodienthoai(string a);

int KTsothe(string a);

int KT_la_so(string a);
int KT_la_ngay(string xau);
void Chuan_ngay_thang_nam(string& xau);
void Them_mon_an_theo_ngay(TREE_MON_AN& t1, MON_AN* p1);
void Tim_monan_theo_ngay(DS_MON_AN& ds_hd, TREE_MON_AN t, int tngay, int tthang, int tnam, int dngay, int dthang, int dnam);
void Them_mon_an_theo_gia_tri(TREE_MON_AN& t1, MON_AN* p1);
void Tim_monan_theo_gia(DS_MON_AN& ds_hd, TREE_MON_AN t, int giatri);
void Them_mon_an_theo_loai(TREE_MON_AN& t, MON_AN* p);
void Tim_kiem_monan_theo_loai(DS_MON_AN& ds_hd, TREE_MON_AN t, int giatri);