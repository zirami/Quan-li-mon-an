#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include <time.h>
using namespace std;

//============================= Khai bao mon an=======================================
struct monan
{
	//Đây là phần dữ liệu
	int ma;
	string ten_mon;
	string ngaythang;
	int dongia;
	bool trangthai;// trạng thái món ăn: 1 - món ăn đã được kích hoạt, 0 - chua kích hoạt
	int soluong;
	int sl_ton;
	int loaimon;
	//Đây là phần con trỏ
	struct monan* pleft;
	struct monan* pright;
};
typedef struct monan MON_AN;
typedef MON_AN* TREE_MON_AN;
struct ds_mon_an
{	//phần dữ liệu của ds_mon_an
	int soluong = 0;
	TREE_MON_AN tree = NULL;//Khởi tạo mặc định cây bằng NULL
};
typedef struct ds_mon_an DS_MON_AN;// danh sach mon an la mot cây nhị phân tìm kiếm để lưu trữ.


		//============================Khai bao hoa don=============================
struct hoadon
{
	//phần dữ liệu
	int mahoadon;
	string ngaylap;
	string hoten;
	string diachi;
	string sdt;
	int magiamgia;
	int tongtien;
	DS_MON_AN ds;
	//Phần con trỏ
	struct hoadon* pleft;
	struct hoadon* pright;
};
typedef struct hoadon HOA_DON;
typedef HOA_DON* TREE_HOADON;


//========================== Lưu trữ hóa đơn ===================================
struct ds_hoa_don
{
	TREE_HOADON tree = NULL;
	int soluong = 0;
	int tongtien = 0;
};
typedef struct ds_hoa_don DS_HOA_DON;

//--------------------------------------------- Khuyến mãi --------------------------------------------
struct km
{
	int ma;
	string tenkm;
	string hsd;
	int giatri;
	struct km* p_left;
	struct km* p_right;
};
typedef struct km KM;
typedef KM* TREE_KM;
struct ds_km
{
	TREE_KM tree = NULL;
	int soluong = 0;
};
typedef struct ds_km DS_KM;