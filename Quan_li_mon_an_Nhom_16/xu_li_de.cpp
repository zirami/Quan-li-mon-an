#pragma once
#include"pch.h"
#include"xu_li_de.h"
#include"ctdl.h"
void Chuan_hoa_chu(string& a)
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}

	}
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			i++;
			if (a[i] >= 97 && a[i] <= 122)
			{
				a[i] -= 32;
			}
		}
		else
		{
			if (a[i] >= 65 && a[i] <= 90)
			{
				a[i] += 32;
			}
		}
	}
}
MON_AN* Khoi_tao_node_mon_an()
{
	MON_AN* p = new MON_AN;
	p->pleft = NULL;
	p->pright = NULL;
	return p;
}

void Nhap_mon_an(DS_MON_AN& ds)
{

	MON_AN* p = Khoi_tao_node_mon_an();
	p->ma = Tao_ma_mon_an(ds.tree);
	cout << "\nNhap ten mon an: ";
	rewind(stdin);
	getline(cin, p->ten_mon);
	Chuan_hoa_chu(p->ten_mon);
	cout << "\nNhap don gia mon an: ";
	cin >> p->dongia;
	p->trangthai = 0;// =0 tức là  chưa được kích hoạt, chưa được thêm vào hóa đơn
	Them_mon_an(ds.tree, p);
	ds.soluong += 1;

}

void Them_mon_an(TREE_MON_AN& t, MON_AN* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->ma > t->ma)
		{
			Them_mon_an(t->pright, p);
		}
		else if (p->ma < t->ma)
		{
			Them_mon_an(t->pleft, p);
		}
	}
}

int Tao_ma_mon_an(TREE_MON_AN t)
{
	int a;
	srand(time(NULL));
	do
	{
		a = rand() % (999 - 100 + 1) + 100;
	} while (KT_trung_ma_mon_an(a, t) == 1);
	return a;

}
int Tao_ma_hoa_don(TREE_HOADON t)
{
	int a;
	srand(time(NULL));
	do
	{
		a = rand() % (999 - 100 + 1) + 100;
	} while (KT_trung_ma_hoa_don(a, t) == 1);
	return a;
}
int Tao_ma_km(TREE_KM t)
{
	int a;
	srand(time(NULL));
	do
	{
		a = rand() % (999 - 100 + 1) + 100;
	} while (KT_trung_ma_KM(a, t) == 1);
	return a;
}
int KT_trung_ma_mon_an(int ma_mon_an, TREE_MON_AN t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if (ma_mon_an > t->ma)
		{
			KT_trung_ma_mon_an(ma_mon_an, t->pright);
		}
		else if (ma_mon_an < t->ma)
		{
			KT_trung_ma_mon_an(ma_mon_an, t->pleft);
		}
		else
		{
			return 1;
		}
	}
}
int KT_trung_ma_hoa_don(int ma_hoa_don, TREE_HOADON t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if (ma_hoa_don > t->mahoadon)
		{
			KT_trung_ma_hoa_don(ma_hoa_don, t->pright);
		}
		else if (ma_hoa_don < t->mahoadon)
		{
			KT_trung_ma_hoa_don(ma_hoa_don, t->pleft);
		}
		else
		{
			return 1;
		}
	}
}
int KT_trung_ma_KM(int ma_km, TREE_KM t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if (ma_km > t->ma)
		{
			KT_trung_ma_KM(ma_km, t->p_right);
		}
		else if (ma_km < t->ma)
		{
			KT_trung_ma_KM(ma_km, t->p_left);
		}
		else
		{
			return 1;
		}
	}
}
void Xuat_mon_an(TREE_MON_AN mon)
{
	cout << "\n\t===========================";
	cout << "\nMa mon an: " << mon->ma;
	cout << "\nTen mon an: " << mon->ten_mon;
	cout << "\nDon gia: " << mon->dongia;
	cout << "\nTrang thai: " << mon->trangthai;

}

void Xuat_mon_an_theo_ma(TREE_MON_AN t)
{
	if (t != NULL)
	{
		Xuat_mon_an_theo_ma(t->pleft);
		Xuat_mon_an(t);
		Xuat_mon_an_theo_ma(t->pright);

	}
}

void Chuyen_cay_sang_mang(TREE_MON_AN t, MON_AN* ds[], int& nds)
{
	if (t != NULL)
	{

		ds[nds] = new MON_AN;
		ds[nds]->ma = t->ma;
		ds[nds]->dongia = t->dongia;
		ds[nds]->ten_mon = t->ten_mon;
		ds[nds]->trangthai = t->trangthai;
		nds++;
		Chuyen_cay_sang_mang(t->pleft, ds, nds);
		Chuyen_cay_sang_mang(t->pright, ds, nds);
	}
}
//--------Sắp xếp -------------
void Hoan_doi(MON_AN*& a, MON_AN*& b)
{
	MON_AN* temp = new MON_AN;
	temp->ma = a->ma;
	temp->ten_mon = a->ten_mon;
	temp->dongia = a->dongia;
	temp->trangthai = a->trangthai;
	----------------------------
		a->ma = b->ma;
	a->ten_mon = b->ten_mon;
	a->dongia = b->dongia;
	a->trangthai = b->trangthai;
	----------------------------
		b->ma = temp->ma;
	b->ten_mon = temp->ten_mon;
	b->dongia = temp->dongia;
	b->trangthai = temp->trangthai;
	delete temp;
}
void Sap_xep_mang_mon_an(MON_AN* ds[], int nds)				//Sắp xếp mảng món ăn theo tên tăng dần
{
	for (int i = 0; i < nds - 1; i++)
	{
		for (int j = i + 1; j < nds; j++)
		{
			if (ds[i]->ten_mon > ds[j]->ten_mon)
			{
				Hoan_doi(ds[i], ds[j]);
			}
		}
	}
}
void Sap_xep_mang_mon_an_theo_dg(MON_AN* ds[], int nds)				//Sắp xếp mảng món ăn theo đơn giá tăng dần
{
	for (int i = 0; i < nds - 1; i++)
	{
		for (int j = i + 1; j < nds; j++)
		{
			if (ds[i]->dongia > ds[j]->dongia)
			{
				Hoan_doi(ds[i], ds[j]);
			}
		}
	}
}
//--------In ra -----------
void Xuat_mon_an_theo_ten(MON_AN* ds[], int nds)
{
	cout << "\nCo " << nds << " mon an trong thuc don hien tai.";
	for (int i = 0; i < nds; i++)
	{
		cout << "\n\n========== Mon An thu " << i + 1 << ": ";
		cout << "\nMa mon: " << ds[i]->ma;
		cout << "\nTen mon: " << ds[i]->ten_mon;
		cout << "\nDon Gia: " << ds[i]->dongia;
		cout << "\nTrang thai: " << ds[i]->trangthai;
	}
}
//--------Giải phóng----------
void Giai_phong(MON_AN* ds[], int nds)
{
	for (int i = 0; i < nds; i++)
	{
		delete ds[i];
	}
}
void Cap_nhat_mon_an(TREE_MON_AN& t, int ma, string ten, int gia,int loai,int sl_ton)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (ma > t->ma)
			Cap_nhat_mon_an(t->pright, ma, ten, gia, loai, sl_ton);
		else if (ma < t->ma)
			Cap_nhat_mon_an(t->pleft, ma, ten, gia, loai, sl_ton);
		else if (ma == t->ma)
		{
			t->dongia = gia;
			t->ma = ma;
			t->ten_mon = ten;
			t->loaimon = loai;
			t->sl_ton = sl_ton;
		}
	}


}
void Cap_nhat_khuyen_mai(TREE_KM& t, int ma, string ten, int gia, string hsd)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (ma > t->ma)
			Cap_nhat_khuyen_mai(t->p_right, ma, ten, gia, hsd);
		else if (ma < t->ma)
			Cap_nhat_khuyen_mai(t->p_left, ma, ten, gia, hsd);
		else if (ma == t->ma)
		{
			t->giatri = gia;
			t->hsd = hsd;
			t->ma = ma;
			t->tenkm = ten;
		}
	}


}
void Cap_nhat_hoa_don(TREE_HOADON &t, int ma, string ngaylap, string ten, string diachi, string sdt)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (ma > t->mahoadon)
			Cap_nhat_hoa_don(t->pright, ma,ngaylap,ten,diachi,sdt);
		else if (ma < t->mahoadon)
			Cap_nhat_hoa_don(t->pleft, ma, ngaylap,ten,diachi,sdt);
		else if (ma == t->mahoadon)
		{
			t->diachi = diachi;
			t->hoten = ten;
			t->ngaylap = ngaylap;
			t->sdt = sdt;
		}
	}


}
void Tim_node_the_mang(TREE_MON_AN& t, MON_AN* &x)
{
	if (t->pleft != NULL)
	{
		Tim_node_the_mang(t->pleft, x);
	}
	else
	{
		Hoan_doi(t, x);
		x = t;
		t = t->pright;
	}
}
void Xoa_mon_an(TREE_MON_AN& t, int ma)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (ma > t->ma)
			Xoa_mon_an(t->pright, ma);
		else if (ma < t->ma)
			Xoa_mon_an(t->pleft, ma);
		else if(ma ==t->ma)
		{
			MON_AN* p = t;
			if (t->pleft == NULL)
			{
				t = t->pright;
			}
			else if (t->pright == NULL)
			{
				t = t->pleft;
			}
			else if (t->pleft != NULL && t->pright != NULL)
			{
				//tim node the mang;
				Tim_node_the_mang(t->pright, p);

			}
			delete p;

		}
	}

}
MON_AN* Tim_kiem_mon_an(TREE_MON_AN t, int ma)
{
	if (t == NULL)
	{
		return NULL;
	}
	if (ma > t->ma)
		Tim_kiem_mon_an(t->pright, ma);
	else if (ma < t->ma)
		Tim_kiem_mon_an(t->pleft, ma);
	else if(ma==t->ma)
	{
		MON_AN* p = new MON_AN;
		p->dongia = t->dongia;
		p->ma = t->ma;
		p->soluong = t->soluong;
		p->loaimon = t->loaimon;
		p->sl_ton = t->sl_ton;
		p->ten_mon = t->ten_mon;
		p->trangthai = t->trangthai;
		p->ngaythang = t->ngaythang;

		return p;
	}
}
HOA_DON* Tim_kiem_hoa_don(TREE_HOADON t, int ma)
{
	if (t == NULL)
	{
		return NULL;
	}
	if (ma > t->mahoadon)
		Tim_kiem_hoa_don(t->pright, ma);
	else if (ma < t->mahoadon)
		Tim_kiem_hoa_don(t->pleft, ma);
	else if(ma==t->mahoadon)
	{
		HOA_DON* p = new HOA_DON;
		p->diachi = t->diachi;
		p->hoten = t->hoten;
		p->mahoadon = t->mahoadon;
		p->ngaylap = t->ngaylap;
		p->sdt = t->sdt;
		p->ds.soluong = t->ds.soluong;
		p->ds.tree = t->ds.tree;
		p->tongtien = t->tongtien;
		p->magiamgia = t->magiamgia;
		p->pleft = NULL;
		p->pright = NULL;
		return p;
	}
}
//Tăng giảm số lượng tồn
void Tang_so_luong_ton(TREE_MON_AN& t, int ma)
{
	if (t == NULL)
	{
		return;
	}
	if (ma > t->ma)
		Tang_so_luong_ton(t->pright, ma);
	else if (ma < t->ma)
		Tang_so_luong_ton(t->pleft, ma);
	else
	{
		t->sl_ton = t->sl_ton + 1;;
	}
}
void Giam_so_luong_ton(TREE_MON_AN& t, int ma)
{
	if (t == NULL)
	{
		return;
	}
	if (ma > t->ma)
		Giam_so_luong_ton(t->pright, ma);
	else if (ma < t->ma)
		Giam_so_luong_ton(t->pleft, ma);
	else if (ma == t->ma)
	{
		t->sl_ton = t->sl_ton - 1;;
	}
}

void Tang_so_luong_mon(TREE_MON_AN& t, int ma)
{
	if (t == NULL)
	{
		return;
	}
	if (ma > t->ma)
		Tang_so_luong_mon(t->pright, ma);
	else if (ma < t->ma)
		Tang_so_luong_mon(t->pleft, ma);
	else
	{
		t->soluong++;
	}
}
void Giam_so_luong_mon(TREE_MON_AN& t, int ma)
{
	if (t == NULL)
	{
		return;
	}
	if (ma > t->ma)
		Giam_so_luong_mon(t->pright, ma);
	else if (ma < t->ma)
		Giam_so_luong_mon(t->pleft, ma);
	else if (ma == t->ma)
	{
		t->soluong -= 1;
	}
}
// Đọc file món ăn.
void Doc_file_mon_an(DS_MON_AN& ds)
{
	ifstream filein;
	filein.open("DS_MON_AN.TXT", ios_base::in);
	while (filein.eof() != true)
	{
		MON_AN* p = Khoi_tao_node_mon_an();
		rewind(stdin);
		filein >> p->ma;
		filein.seekg(1, 1);
		getline(filein, p->ten_mon, ',');
		getline(filein, p->ngaythang, ',');
		filein >> p->loaimon;
		filein.seekg(1, 1);
		filein >> p->dongia;
		filein.seekg(1, 1);
		filein >> p->trangthai;
		filein.seekg(1, 1);
		filein >> p->sl_ton;
		Them_mon_an(ds.tree, p);
		ds.soluong++;
	}
	filein.close();
}
//Ghi file món ăn
void Ghi_file_mon_an(DS_MON_AN ds)
{
	ofstream fo;
	fo.open("DS_MON_AN.TXT", ios_base::out);
	Ghi_file_mon_an(ds.tree, fo);
	fo.close();
}

void Ghi_file_mon_an(TREE_MON_AN t, ofstream& f)
{
	if (t != NULL)
	{
		f << "\n" << t->ma << ", " << t->ten_mon << ", " <<t->ngaythang<<", "<<t->loaimon<<", "<< t->dongia << ", " << t->trangthai<<", "<<t->sl_ton;
		Ghi_file_mon_an(t->pleft, f);
		Ghi_file_mon_an(t->pright, f);

	}

}

///===================================  Hoa don
void Xuat_mon_an_hd(TREE_MON_AN mon)
{
	cout << "\n------------------------------";
	cout << "\nMa mon an: " << mon->ma;
	cout << "\nTen mon an: " << mon->ten_mon;
	cout << "\nDon gia: " << mon->dongia;
	cout << "\nSo luong: " << mon->soluong << endl;

}
void Xuat_mon_an_hd_theo_ma(TREE_MON_AN t)
{
	if (t != NULL)
	{
		Xuat_mon_an_hd_theo_ma(t->pleft);
		Xuat_mon_an_hd(t);
		Xuat_mon_an_hd_theo_ma(t->pright);

	}
}

void Xuat_1_hd(HOA_DON* p)
{
	cout << "\n===========  HOA DON  ==============";
	cout << "\nMa hoa don: " << p->mahoadon;
	cout << "\nNgay lap hoa don: " << p->ngaylap;
	cout << "\nKhach hang: " << p->hoten;
	cout << "\nDia chi: " << p->diachi;
	cout << "\nSo dien thoai: " << p->sdt;
	cout << "\n== Tong so mon an: " << p->ds.soluong << " ==";
	Xuat_mon_an_hd_theo_ma(p->ds.tree);
}

//======================== HOA DON =============================
void Nhap_1_hoa_don(HOA_DON*& hd, DS_MON_AN ds_mon)
{
	cout << "\n\t================== HOA DON ====================";
	cout << "\nNhap ma hoa don: ";
	cin >> hd->mahoadon;
	rewind(stdin);
	cout << "\nNhap ngay lap hoa don (dd/mm/yyyy): ";
	getline(cin, hd->ngaylap);
	cout << "\nNhap ho ten khach hang: ";
	getline(cin, hd->hoten);
	cout << "\nNhap dia chi: ";
	getline(cin, hd->diachi);
	cout << "\nNhap so dien thoai: ";
	getline(cin, hd->sdt);
	while (true)
	{
		int lc;
		system("cls");
		cout << "\n========Lap hoa don=========";
		cout << "\n1. Nhap ma mon an muon them vao hoa don.";
		cout << "\n2. Xuat ds mon an.";
		cout << "\n3. Xoa hoac giam so luong mon an.";
		cout << "\n4. Xem thong tin 1 hoa don.";
		cout << "\n5. Chinh sua thong tin hoa don.";
		cout << "\n0. Dat hang.";
		cout << "\n========= MON AN ===========";
		cout << "\nNhap lua chon: ";
		cin >> lc;
		if (lc == 0) break;
		else if (lc == 1)
		{
			int ma_mon_an;
			Xuat_mon_an_theo_ma(ds_mon.tree);
			cout << "\nNhap ma mon an muon them vao hoa don:";
			cin >> ma_mon_an;
			MON_AN* p = Tim_kiem_mon_an(ds_mon.tree, ma_mon_an);
			if (p != NULL)
			{
				if (KT_trung_ma_mon_an(ma_mon_an, hd->ds.tree) == 1)
				{
					Tang_so_luong_mon(hd->ds.tree, ma_mon_an);
				}
				else
				{
					p->soluong = 1;
					p->pleft = NULL;
					p->pright = NULL;
					Them_mon_an(hd->ds.tree, p);
					hd->ds.soluong += 1;
				}

			}
		}
		else if (lc == 2)
		{
			Xuat_mon_an_hd_theo_ma(hd->ds.tree);
			system("pause");
		}
		else if (lc == 3)
		{
			int ma_mon_an;
			Xuat_mon_an_hd_theo_ma(hd->ds.tree);
			cout << "\nNhap ma mon an muon xoa hoac giam so luong di 1 khoi hoa don.";
			cin >> ma_mon_an;
			MON_AN* p = Tim_kiem_mon_an(hd->ds.tree, ma_mon_an);
			if (p != NULL)
			{
				if (p->soluong > 1)
				{
					Giam_so_luong_mon(hd->ds.tree, ma_mon_an);
				}
				else
				{
					Xoa_mon_an(hd->ds.tree, ma_mon_an);
					hd->ds.soluong -= 1;
				}
			}
		}
		else if (lc == 4)
		{
			Xuat_1_hd(hd);
			system("pause");
		}
		else if (lc == 5)
		{
			Chinh_sua_tt_hd(hd);
		}
	}
}
void Them_hoa_don(TREE_HOADON& t, HOA_DON* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->mahoadon > t->mahoadon)
		{
			Them_hoa_don(t->pright, p);
		}
		else if (p->mahoadon < t->mahoadon)
		{
			Them_hoa_don(t->pleft, p);
		}
	}
}
void Xuat_ds_hd(TREE_HOADON t)
{
	if (t != NULL)
	{
		Xuat_ds_hd(t->pleft);
		Xuat_1_hd(t);
		Xuat_ds_hd(t->pright);
	}
}
//console
void Chinh_sua_tt_hd_TREE(TREE_HOADON& t, int ma)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (ma > t->mahoadon)
		{
			Chinh_sua_tt_hd_TREE(t->pright, ma);
		}
		else if (ma < t->mahoadon)
		{
			Chinh_sua_tt_hd_TREE(t->pleft, ma);
		}
		else
		{
			int lc;
			cout << "\nBan co muon thay doi thong tin hoa don khong?";
			cout << "\n1. Co \t 0.Khong";
			cin >> lc;
			if (lc == 0) return;
			else
			{
				rewind(stdin);
				cout << "\nNhap ngay lap hoa don: ";
				getline(cin, t->ngaylap);
				cout << "\nNhap ten khach hang: ";
				getline(cin, t->hoten);
				cout << "\nNhap dia chi: ";
				getline(cin, t->diachi);
				cout << "\nNhap so dien thoai: ";
				getline(cin, t->sdt);

			}
		}
	}
} 
//console
void Chinh_sua_tt_hd(HOA_DON*& hd)
{
	int lc;
	cout << "\nBan co muon thay doi thong tin hoa don khong?";
	cout << "\n1. Co \t 0.Khong";
	cin >> lc;
	if (lc == 0) return;
	else if (lc == 1)
	{
		cout << "\nNhap ma hoa don moi: ";
		cin >> hd->mahoadon;
		rewind(stdin);
		cout << "\nNhap ngay lap hoa don: ";
		getline(cin, hd->ngaylap);
		cout << "\nNhap ten khach hang: ";
		getline(cin, hd->hoten);
		cout << "\nNhap dia chi: ";
		getline(cin, hd->diachi);
		cout << "\nNhap so dien thoai: ";
		getline(cin, hd->sdt);

	}
}
void Doc_file_hoa_don(DS_HOA_DON& ds, DS_MON_AN ds_mon)
{
	ifstream fi;
	fi.open("DS_HOA_DON.TXT", ios_base::in);
	while (fi.eof() != true)
	{

		HOA_DON* p = new HOA_DON;
		p->pleft = NULL;
		p->pright = NULL;
		fi >> p->mahoadon;
		fi.seekg(1, 1);
		getline(fi, p->ngaylap, ',');
		getline(fi, p->hoten, ',');
		getline(fi, p->diachi, ',');
		getline(fi, p->sdt, ',');
		fi >> p->tongtien;
		fi.seekg(1, 1);
		fi >> p->magiamgia;
		fi.seekg(1, 1);
		char x;
		do
		{
			MON_AN* t = new MON_AN;
			//Doc ma mon an vao
			fi >> t->ma;
			fi.seekg(1, 1);
			//Tim kiem trong ds_mon_an
			t = Tim_kiem_mon_an(ds_mon.tree, t->ma);
			fi >> t->soluong;
			t->pleft = NULL;
			t->pright = NULL;
			fi.seekg(1, 1);
			Them_mon_an(p->ds.tree, t);
			p->ds.soluong++;
			fi >> x;
			fi.seekg(-1, 1);
		} while (x != 'e');
		Them_hoa_don(ds.tree, p);
		fi.seekg(1, 1);
		fi.ignore();
		ds.soluong++;
	}
	fi.close();
}

void Xuat_ds_mon_an_hd(TREE_MON_AN t, ofstream& f)
{
	if (t != NULL)
	{
		Xuat_ds_mon_an_hd(t->pleft, f);
		f << t->ma << ", " << t->soluong << ", ";
		Xuat_ds_mon_an_hd(t->pright, f);

	}
}
void Ghi_file_hoa_don(DS_HOA_DON ds)
{
	ofstream fo;
	fo.open("DS_HOA_DON.TXT", ios_base::out);
	Ghi_file_hoa_don(ds.tree, fo);
	fo.close();
}
void Ghi_file_hoa_don(TREE_HOADON t, ofstream& f)
{
	if (t != NULL)
	{
		f << "\n" << t->mahoadon << ", " << t->ngaylap << ", " << t->hoten << ", " << t->diachi << ", " << t->sdt << ", "<<t->tongtien<<", "<<t->magiamgia<<", ";
		Xuat_ds_mon_an_hd(t->ds.tree, f);
		f << "e";
		Ghi_file_hoa_don(t->pleft, f);
		Ghi_file_hoa_don(t->pright, f);

	}

}

//================================================ Khuyen Mai =======================================
KM* Tim_kiem_KM(TREE_KM t, int ma)
{
	if (t == NULL)
	{
		return NULL;
	}
	if(ma>t->ma)
		Tim_kiem_KM(t->p_right, ma);
	else if (ma < t->ma)
		Tim_kiem_KM(t->p_left, ma);
	else
	{
		KM* p = new KM;
		p->giatri = t->giatri;
		p->hsd = t->hsd;
		p->ma = t->ma;
		p->tenkm = t->tenkm;
		p->p_left = NULL;
		p->p_right = NULL;
		return p;
	}
}
void Them_1_KM(TREE_KM& t, KM* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->ma > t->ma)
		{
			Them_1_KM(t->p_right, p);
		}
		else if (p->ma < t->ma)
		{
			Them_1_KM(t->p_left, p);
		}
	}
}
void Doc_file_khuyen_mai(DS_KM& ds)
{
	ifstream fi;
	fi.open("DS_KHUYEN_MAI.TXT", ios_base::in);
	while (fi.eof() != true)
	{

		KM* p = new KM;
		p->p_left = NULL;
		p->p_right = NULL;
		fi >> p->ma;
		fi.seekg(1, 1);
		getline(fi, p->tenkm, ',');
		getline(fi, p->hsd, ',');
		fi >> p->giatri;
		Them_1_KM(ds.tree, p);
		fi.ignore();
		ds.soluong++;

	}
	fi.close();
}
void Ghi_file_khuyen_mai(DS_KM ds)
{
	ofstream fo;
	fo.open("DS_KHUYEN_MAI.TXT", ios_base::out);
	Ghi_file_khuyen_mai1(ds.tree, fo);
	fo.close();
}
void Ghi_file_khuyen_mai1(TREE_KM t, ofstream& f)
{
	if (t != NULL)
	{
		f << "\n" << t->ma << ", " << t->tenkm << ", " << t->hsd << ", " << t->giatri;
		Ghi_file_khuyen_mai1(t->p_left, f);
		Ghi_file_khuyen_mai1(t->p_right, f);

	}

}

void Hoan_doi_km(KM*& a, KM*& b)
{
	KM* temp = new KM;
	temp->ma = a->ma;
	temp->tenkm = a->tenkm;
	temp->giatri = a->giatri;
	temp->hsd = a->hsd;
	----------------------------
		a->ma =b->ma;
	a->tenkm = b->tenkm;
	a->giatri = b->giatri;
	a->hsd = b->hsd;
	----------------------------
		b->ma = temp->ma;
	b->tenkm =temp->tenkm;
	b->giatri = temp->giatri;
	b->hsd = temp->hsd;
	delete temp;
}
void Tim_node_the_mang_km(TREE_KM& t, KM* x)
{
	if (t->p_left != NULL)
	{
		Tim_node_the_mang_km(t->p_left, x);
	}
	else
	{
		Hoan_doi_km(t, x);
		x = t;
		t = t->p_right;
	}
}
void Xoa_khuyen_mai(TREE_KM& t, int ma)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (ma > t->ma)
			Xoa_khuyen_mai(t->p_right, ma);
		else if (ma < t->ma)
			Xoa_khuyen_mai(t->p_left, ma);
		else
		{
			KM* p = t;
			if (t->p_left == NULL)
			{
				t = t->p_right;
			}
			else if (t->p_right == NULL)
			{
				t = t->p_left;
			}
			else if (t->p_left != NULL && t->p_right != NULL)
			{
				//tim node the mang;
				Tim_node_the_mang_km(t->p_right, p);

			}
			delete p;
		}
	}

}
bool KT_FILE(string path) {
	ifstream isf(path);
	return isf.good();
}
string layngay(string time)
{

	int i1 = 0;
	string tg;
	while (time[i1] != '/') i1++;
	for (int i = 0; i < i1; i++)
	{
		tg.push_back(time[i]);
	}
	return tg;
}
string laythang(string time)
{
	int i1 = 0, j1;
	string tg;
	while (time[i1] != '/') i1++;
	i1 = i1 + 1;
	j1 = i1;
	while (time[i1] != '/') i1++;
	for (int i = j1; i < i1; i++)
	{
		tg.push_back(time[i]);
	}
	return tg;
}
string laynam(string time)
{
	int i1 = 0, j1;
	string tg = "";
	while (time[i1] != '/') i1++;
	i1++;
	while (time[i1] != '/') i1++;
	for (int i = i1 + 1; i < time.length(); i++)
	{
		tg.push_back(time[i]);
	}
	return tg;
}
string layten(string a)
{
	int i = a.length();
	while (a[i] != ' ') i--;
	string tg;
	for (int j = i + 1; j < a.length(); j++)
	{
		tg.push_back(a[j]);
	}
	return tg;
}
int String_sang_int(string str)
{
	int kq;
	kq = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int a = str[i];
		kq = kq * 10 + ((int)str[i] - 48);
	}
	return kq;
}
string Int_sang_string(int a)
{
	int b;
	string i;
	string j = "";
	string kq;
	while (a != 0)
	{
		b = a % 10;
		a = a / 10;
		i = b + 48;
		kq = i + j;
		j = kq;
	}
	return kq;


}
int Tinh_so_ngay(int year, int month, int day) {
	if (month < 3) {
		year--;
		month += 12;
	}
	return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}
int KT_Time_Between_2time(string ngaythangnam, int tngay,int tthang,int tnam,int dngay,int dthang,int dnam)
{
	string ngay = layngay(ngaythangnam);
	ngay.erase(ngay.begin() + 0);
	string thang = laythang(ngaythangnam);
	string nam = laynam(ngaythangnam);

	int ngay1 = String_sang_int(ngay);
	int thang1 = String_sang_int(thang);
	int nam1 = String_sang_int(nam);
	int songay1 = Tinh_so_ngay(dnam, dthang, dngay) - Tinh_so_ngay(tnam, tthang, tngay);
	int songay2 = Tinh_so_ngay(dnam, dthang, dngay) - Tinh_so_ngay(nam1, thang1, ngay1);
	if (songay1 >= 0&&songay2>=0)
	{
		if ((songay1 - songay2) >= 0)
		{
			return 1;
		}
	}
	return 0;
}

void Tim_Kiem_theo_ngay(DS_HOA_DON &ds_hd,TREE_HOADON t, int tngay, int tthang, int tnam, int dngay, int dthang, int dnam)
{
	if (t != NULL)
	{
		int a = KT_Time_Between_2time(t->ngaylap, tngay, tthang, tnam, dngay, dthang, dnam);
		if (a==1)
		{
			HOA_DON* p = new HOA_DON;
			p->diachi = t->diachi;
			p->hoten = t->hoten;
			p->mahoadon = t->mahoadon;
			p->ngaylap = t->ngaylap;
			p->sdt = t->sdt;
			p->ds.soluong = t->ds.soluong;
			p->ds.tree = t->ds.tree;
			p->tongtien = t->tongtien;
			p->magiamgia = t->magiamgia;
			p->pleft = NULL;
			p->pright = NULL;
			Them_hoa_don_theo_ngay(ds_hd.tree, p);
			ds_hd.soluong++;
			ds_hd.tongtien += p->tongtien;

		}
		Tim_Kiem_theo_ngay(ds_hd, t->pleft, tngay, tthang, tnam, dngay, dthang, dnam);
		Tim_Kiem_theo_ngay(ds_hd, t->pright, tngay, tthang, tnam, dngay, dthang, dnam);
	}
}
void Tim_kiem_theo_ten(DS_HOA_DON& ds_hd, TREE_HOADON t, string hoten)
{
	if (t != NULL)
	{
		if (t->hoten==hoten)
		{
			HOA_DON* p = new HOA_DON;
			p->diachi = t->diachi;
			p->hoten = t->hoten;
			p->mahoadon = t->mahoadon;
			p->ngaylap = t->ngaylap;
			p->sdt = t->sdt;
			p->ds.soluong = t->ds.soluong;
			p->ds.tree = t->ds.tree;
			p->tongtien = t->tongtien;
			p->magiamgia = t->magiamgia;
			p->pleft = NULL;
			p->pright = NULL;
			Them_hoa_don_theo_ten(ds_hd.tree, p);
			ds_hd.soluong++;
			ds_hd.tongtien += p->tongtien;

		}
		Tim_kiem_theo_ten(ds_hd, t->pleft, hoten);
		Tim_kiem_theo_ten(ds_hd, t->pright, hoten);
	}
}

void Tim_kiem_theo_sdt(DS_HOA_DON& ds_hd1, TREE_HOADON t1, string sdt)
{
	if (t1 != NULL)
	{
		if (t1->sdt == sdt)
		{
			HOA_DON* p = new HOA_DON;
			p->diachi = t1->diachi;
			p->hoten = t1->hoten;
			p->mahoadon = t1->mahoadon;
			p->ngaylap = t1->ngaylap;
			p->sdt = t1->sdt;
			p->ds.soluong = t1->ds.soluong;
			p->ds.tree = t1->ds.tree;
			p->tongtien = t1->tongtien;
			p->magiamgia = t1->magiamgia;
			p->pleft = NULL;
			p->pright = NULL;
			Them_hoa_don(ds_hd1.tree, p);
			ds_hd1.soluong++;
			ds_hd1.tongtien += p->tongtien;
		}
		Tim_kiem_theo_sdt(ds_hd1, t1->pleft, sdt);
		Tim_kiem_theo_sdt(ds_hd1, t1->pright, sdt);
	}

}
void Tim_kiem_hd_theo_gia_tri(DS_HOA_DON& ds_hd, TREE_HOADON t, int giatri)
{
	if (t != NULL)
	{
		if (t->tongtien == giatri)
		{
			HOA_DON* p = new HOA_DON;
			p->diachi = t->diachi;
			p->hoten = t->hoten;
			p->mahoadon = t->mahoadon;
			p->ngaylap = t->ngaylap;
			p->sdt = t->sdt;
			p->ds.soluong = t->ds.soluong;
			p->ds.tree = t->ds.tree;
			p->tongtien = t->tongtien;
			p->magiamgia = t->magiamgia;
			p->pleft = NULL;
			p->pright = NULL;
			Them_hoa_don_theo_gia_tri(ds_hd.tree, p);
			ds_hd.soluong++;
			ds_hd.tongtien += p->tongtien;
		}
		Tim_kiem_hd_theo_gia_tri(ds_hd, t->pleft, giatri);
		Tim_kiem_hd_theo_gia_tri(ds_hd, t->pright, giatri);
	}
}
void Xoa_cay_hd(TREE_HOADON& root) 
{
	if (root == NULL) {
		return;
	}
	if (root->pleft) {
		Xoa_cay_hd(root->pleft);
	}
	if (root->pright) {
		Xoa_cay_hd(root->pright);
	}
	delete root;
	// them vao cuoi
	root = NULL;
}

void Them_hoa_don_theo_sdt(TREE_HOADON& t, HOA_DON* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->sdt >= t->sdt)
		{
			Them_hoa_don_theo_sdt(t->pright, p);
		}
		else if (p->sdt < t->sdt)
		{
			Them_hoa_don_theo_sdt(t->pleft, p);
		}
	}
}
void Them_hoa_don_theo_gia_tri(TREE_HOADON& t1, HOA_DON* p1)
{
	if (t1 == NULL)
	{
		t1 = p1;
	}
	else
	{
		if (p1->tongtien >= t1->tongtien)
		{
			Them_hoa_don_theo_gia_tri(t1->pright, p1);
		}
		else if (p1->tongtien < t1->tongtien)
		{
			Them_hoa_don_theo_gia_tri(t1->pleft, p1);
		}
	}
}
void Them_hoa_don_theo_ten(TREE_HOADON& t1, HOA_DON* p1)
{
	if (t1 == NULL)
	{
		t1 = p1;
	}
	else
	{
		string ten1 = layten(t1->hoten);
		string ten2 = layten(p1->hoten);
		if (ten2 >= ten1)
		{
			Them_hoa_don_theo_ten(t1->pright, p1);
		}
		else if (ten2<ten1)
		{
			Them_hoa_don_theo_ten(t1->pleft, p1);
		}
	}
}

int so_sanh_2_ngay(string ngaythangnam1, string ngaythangnam2)
{
	string s_ngay1 = layngay(ngaythangnam1);
	s_ngay1.erase(s_ngay1.begin() + 0);
	string s_thang1 = laythang(ngaythangnam1);
	string s_nam1 = laynam(ngaythangnam1);

	string s_ngay2 = layngay(ngaythangnam2);
	s_ngay2.erase(s_ngay2.begin() + 0);
	string s_thang2 = laythang(ngaythangnam2);
	string s_nam2 = laynam(ngaythangnam2);

	int ngay1 = String_sang_int(s_ngay1);
	int thang1 = String_sang_int(s_thang1);
	int nam1 = String_sang_int(s_nam1);

	int ngay2 = String_sang_int(s_ngay2);
	int thang2 = String_sang_int(s_thang2);
	int nam2 = String_sang_int(s_nam2);

	int songay1 = Tinh_so_ngay(nam1, thang1, ngay1) - Tinh_so_ngay(2000, 1, 1);
	int songay2 = Tinh_so_ngay(nam2, thang2, ngay2) - Tinh_so_ngay(2000, 1, 1);
	if (songay1 > songay2)
	{
		return 1;
	}
	else if (songay1 < songay2)
	{
		return -1;
	}
	else
	return 0;
}
int so_sanh_2_ngay_(string ngaythangnam1, string ngaythangnam2)
{
	string s_ngay1 = layngay(ngaythangnam1);
	s_ngay1.erase(s_ngay1.begin() + 0);
	string s_thang1 = laythang(ngaythangnam1);
	string s_nam1 = laynam(ngaythangnam1);

	string s_ngay2 = layngay(ngaythangnam2);
	string s_thang2 = laythang(ngaythangnam2);
	string s_nam2 = laynam(ngaythangnam2);

	int ngay1 = String_sang_int(s_ngay1);
	int thang1 = String_sang_int(s_thang1);
	int nam1 = String_sang_int(s_nam1);

	int ngay2 = String_sang_int(s_ngay2);
	int thang2 = String_sang_int(s_thang2);
	int nam2 = String_sang_int(s_nam2);

	int songay1 = Tinh_so_ngay(nam1, thang1, ngay1) - Tinh_so_ngay(2000, 1, 1);
	int songay2 = Tinh_so_ngay(nam2, thang2, ngay2) - Tinh_so_ngay(2000, 1, 1);
	if (songay1 > songay2)
	{
		return 1;
	}
	else if (songay1 < songay2)
	{
		return -1;
	}
	else
		return 0;
}

void Them_hoa_don_theo_ngay(TREE_HOADON& t1, HOA_DON* p1)
{
	if (t1 == NULL)
	{
		t1 = p1;
	}
	else
	{
		int a = so_sanh_2_ngay(p1->ngaylap, t1->ngaylap);
		if (a==1||a==0)
		{
			Them_hoa_don_theo_ngay(t1->pright, p1);
		}
		else if (a==-1)
		{
			Them_hoa_don_theo_ngay(t1->pleft, p1);
		}
	}
}

string giatien(string tien)
{
	string tg;
	int dai, dem = 0;
	dai = tien.length() - 1;
	if (tien.length() > 3)
	{
		while (dai >= 0)
		{
			dem++;
			tg = tg + tien[dai];
			if ((dem == 3) && (dai != 0))
			{
				tg = tg + '.';
				dem = 0;
			}
			dai--;
		}
	}
	else tg = tien;
	for (int i = 0; i < (tg.length() / 2); i++)
	{
		char tam = tg[i];
		tg[i] = tg[tg.length() - i - 1];
		tg[tg.length() - i - 1] = tam;
	}
	return tg;

}
string laytime() //Number of sec since January 1,1970 
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime,&now);
	string thoigian, ngay, thang, nam;
	ngay = Int_sang_string(newtime.tm_mday);
	if (ngay.length() == 1)
	{
		ngay.insert(ngay.begin() + 0, '0');
	}
	thang = Int_sang_string(newtime.tm_mon + 1);
	if (thang.length() == 1)
	{
		thang.insert(thang.begin() + 0, '0');
	}
	nam = Int_sang_string(newtime.tm_year + 1900);
	thoigian = ngay + "/" + thang + "/" + nam;
	return thoigian;

}

void Xoa_cay_KM(TREE_KM& root)
{
	if (root == NULL) {
		return;
	}
	if (root->p_left) {
		Xoa_cay_KM(root->p_left);
	}
	if (root->p_right) {
		Xoa_cay_KM(root->p_right);
	}
	delete root;
	// them vao cuoi
	root = NULL;
}

void Them_mon_an_theo_giatri(TREE_MON_AN& t, MON_AN* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->dongia >= t->dongia)
		{
			Them_mon_an_theo_giatri(t->pright, p);
		}
		else if (p->dongia < t->dongia)
		{
			Them_mon_an_theo_giatri(t->pleft, p);
		}
	}
}

void Tim_kiem_monan_theo_gia_tri(DS_MON_AN& ds_ma, TREE_MON_AN t, int giatri)
{
	if (t != NULL)
	{
		if (t->loaimon == giatri)
		{
			MON_AN* p = new MON_AN;
			p->dongia = t->dongia;
			p->loaimon = t->loaimon;
			p->ma = t->ma;
			p->sl_ton = t->sl_ton;
			p->soluong = t->soluong;
			p->pleft = NULL;
			p->pright = NULL;
			p->ten_mon = t->ten_mon;
			p->trangthai = t->trangthai;
			Them_mon_an_theo_giatri(ds_ma.tree, p);
			ds_ma.soluong++;

		}
		Tim_kiem_monan_theo_gia_tri(ds_ma, t->pleft, giatri);
		Tim_kiem_monan_theo_gia_tri(ds_ma, t->pright, giatri);
	}
}

void Xoa_cay_mon_an(TREE_MON_AN& root)
{
	if (root == NULL) {
		return;
	}
	if (root->pleft) {
		Xoa_cay_mon_an(root->pleft);
	}
	if (root->pright) {
		Xoa_cay_mon_an(root->pright);
	}
	delete root;
	// them vao cuoi
	root = NULL;
}

void Chuan_hoa_chuoi(string& a)
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
}

void Hoan_doi_hd(HOA_DON*& a, HOA_DON*& b)
{
	HOA_DON* temp = new HOA_DON;
	temp->mahoadon = a->mahoadon;
	temp->diachi = a->diachi;
	temp->ds = a->ds;
	temp->hoten = a->hoten;
	temp->magiamgia = a->magiamgia;
	temp->ngaylap = a->ngaylap;
	/*temp->pleft = a->pleft;
	temp->pright = a->pright;*/
	temp->sdt = a->sdt;
	temp->tongtien = a->tongtien;
	----------------------------
		a->mahoadon = b->mahoadon;
	a->diachi = b->diachi;
	a->ds = b->ds;
	a->hoten = b->hoten;
	a->magiamgia = b->magiamgia;
	a->ngaylap = b->ngaylap;
	/*a->pleft = b->pleft;
	a->pright = b->pright;*/
	a->sdt = b->sdt;
	a->tongtien = b->tongtien;
	----------------------------
		b->mahoadon = temp->mahoadon;
	b->diachi = temp->diachi;
	b->ds = temp->ds;
	b->hoten = temp->hoten;
	b->magiamgia = temp->magiamgia;
	b->ngaylap = temp->ngaylap;
	/*b->pleft = temp->pleft;
	b->pright = temp->pright;*/
	b->sdt = temp->sdt;
	b->tongtien = temp->tongtien;
	delete temp;
}

void Tim_node_the_mang_hoa_don(TREE_HOADON &t, HOA_DON*& x)
{
	if (t->pleft != NULL)
	{
		Tim_node_the_mang_hoa_don(t->pleft, x);
	}
	else
	{
		Hoan_doi_hd(t, x);
		x = t;
		t = t->pright;
	}
}

void Xoa_hoa_don(TREE_HOADON &t, int ma)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (ma > t->mahoadon)
			Xoa_hoa_don(t->pright, ma);
		else if (ma < t->mahoadon)
			Xoa_hoa_don(t->pleft, ma);
		else if (ma == t->mahoadon)
		{
			HOA_DON* p = t;
			if (t->pleft == NULL)
			{
				t = t->pright;
			}
			else if (t->pright == NULL)
			{
				t = t->pleft;
			}
			else if (t->pleft != NULL && t->pright != NULL)
			{
				//tim node the mang;
				Tim_node_the_mang_hoa_don(t->pright, p);

			}
			delete p;

		}
	}

}
MON_AN* Tim_kiem_mon_an1(TREE_MON_AN t, int ma)
{
	if (t == NULL)
	{
		return NULL;
	}
	if (ma > t->ma)
		Tim_kiem_mon_an1(t->pright, ma);
	else if (ma < t->ma)
		Tim_kiem_mon_an1(t->pleft, ma);
	else if(ma==t->ma)
	{
		MON_AN* p = new MON_AN;
		p->pleft = NULL;
		p->pright = NULL;
		p->dongia = t->dongia;
		p->ma = t->ma;
		p->soluong = t->soluong;
		p->loaimon = t->loaimon;
		p->sl_ton = t->sl_ton;
		p->ten_mon = t->ten_mon;
		p->trangthai = t->trangthai;
		return p;
	}
}
void Tim_hd_theo_ma_mon_an(TREE_HOADON& t, int ma_ma,HOA_DON*& h)
{
	if (t != NULL)
	{
		MON_AN* i = Tim_kiem_mon_an(t->ds.tree, ma_ma);
		if (i != NULL)
		{
			h->mahoadon = t->mahoadon;
			h->diachi = t->diachi;
			h->ds.soluong = t->ds.soluong;
			h->ds.tree = t->ds.tree;
			h->hoten = t->hoten;
			h->ngaylap = t->ngaylap;
			h->sdt = t->sdt;
			h->tongtien = t->tongtien;
			return;
		}
		Tim_hd_theo_ma_mon_an(t->pleft, ma_ma,h);
		Tim_hd_theo_ma_mon_an(t->pright, ma_ma,h);
	}
}

int KiemTraNgayHopLe(string ngaythangnam)
{
	string ngay1;
	string thang1;
	string nam1;
	ngay1 = layngay(ngaythangnam);
	thang1 = laythang(ngaythangnam);
	nam1 = laynam(ngaythangnam);
	int ngay = String_sang_int(ngay1);
	int thang = String_sang_int(thang1);
	int nam = String_sang_int(nam1);
	int kt = 0;
	if ((nam < 2000) || (nam > 2030))
	{
		return 3;
	}
	else
	{
		switch (thang)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if (ngay > 31 || ngay < 1)
			{
				kt = 1;
			}
		}
		break;
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (ngay > 30 || ngay < 1) kt = 1;

		}
		break;
		case 2:
		{
			if (nam % 4 == 0)
			{
				if (ngay > 29 || ngay < 1) kt = 1;
			}
			else
			{

				if (ngay > 28 || ngay < 1) kt = 1;
			}
		}break;
		default:
		{
			kt = 2;
		}
		}
	}
	return kt;
}

void Tang_so_luong_ton_cay_mon_an(TREE_MON_AN& ds,TREE_MON_AN& t)
{
	if (t != NULL)
	{
		do
		{
			Tang_so_luong_ton(ds, t->ma);
			t->soluong--;
		} while (t->soluong > 0);
		Tang_so_luong_ton_cay_mon_an(ds, t->pleft);
		Tang_so_luong_ton_cay_mon_an(ds, t->pright);
	}
}
int KTsodienthoai(string a)
{
	int leng = a.length();
	if (a[0] != '0') return 0;
	else
	{
		if ((leng < 10) || (leng > 10)) return 0;
		return 1;
	}
}
int KTsothe(string a)
{
	int leng = a.length();
	if ((leng < 12) || (leng > 12)) return 0;
		return 1;
}
int KT_la_so(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (!(a[i] >= 48 && a[i] <= 57))
		{
			return 0;
		}
	}
	return 1;
}
int KT_la_ngay(string xau)
{
	int dem = 0;
	int kt = 1;
	if (xau.length() < 3) return 0;
	for (int i = 0; i < xau.length(); i++)
	{
		if (xau[i] == '/') dem++;
	}
	if (dem == 2)
	{
		for (int i = 1; i < xau.length() - 1; i++)
		{
			if ((xau[i] == '/') && (xau[i + 1] == '/'))
			{
				return 0;
			}
		}
	}
	else kt = 0;
	return kt;
}
void Chuan_ngay_thang_nam(string &xau)
{
	string tg;
	int i1 = 0;
	while (xau[i1] != '/') i1++; //1/1/2020
	if (i1 == 1) tg = '0' + tg;
	i1++;
	for (int i = 0; i < i1; i++)
	{
		tg.push_back(xau[i]);
	}
	int j1 = i1;
	while (xau[j1] != '/') j1++;
	if (j1 - i1 == 1) tg = tg + '0';
	for (int i = i1; i <= j1; i++)
	{
		tg.push_back(xau[i]);
	}
	i1 = j1 + 1;
	for (int i = i1; i < xau.length(); i++)
	{
		tg.push_back(xau[i]);
	}
	xau = tg;
}
void Them_mon_an_theo_ngay(TREE_MON_AN& t1, MON_AN* p1)
{
	if (t1 == NULL)
	{
		t1 = p1;
	}
	else
	{
		int a = so_sanh_2_ngay(p1->ngaythang, t1->ngaythang);
		if (a == 1 || a == 0)
		{
			Them_mon_an_theo_ngay(t1->pright, p1);
		}
		else if (a == -1)
		{
			Them_mon_an_theo_ngay(t1->pleft, p1);
		}
	}
}
void Tim_monan_theo_ngay(DS_MON_AN& ds_hd, TREE_MON_AN t, int tngay, int tthang, int tnam, int dngay, int dthang, int dnam)
{
	if (t != NULL)
	{
		int a = KT_Time_Between_2time(t->ngaythang, tngay, tthang, tnam, dngay, dthang, dnam);
		if (a == 1)
		{
			MON_AN* p = new MON_AN;
			p->dongia = t->dongia;
			p->loaimon = t->loaimon;
			p->ma = t->ma;
			p->ngaythang = t->ngaythang;
			p->sl_ton = t->sl_ton;
			p->soluong = t->soluong;
			p->ten_mon = t->ten_mon;
			p->trangthai = t->trangthai;
			p->pleft = NULL;
			p->pright = NULL;
			Them_mon_an_theo_ngay(ds_hd.tree, p);
			ds_hd.soluong++;
		}
		Tim_monan_theo_ngay(ds_hd, t->pleft, tngay, tthang, tnam, dngay, dthang, dnam);
		Tim_monan_theo_ngay(ds_hd, t->pright, tngay, tthang, tnam, dngay, dthang, dnam);
	}
}

void Them_mon_an_theo_gia_tri(TREE_MON_AN& t1, MON_AN* p1)
{
	if (t1 == NULL)
	{
		t1 = p1;
	}
	else
	{
		if (p1->dongia >= t1->dongia)
		{
			Them_mon_an_theo_gia_tri(t1->pright, p1);
		}
		else if (p1->dongia < t1->dongia)
		{
			Them_mon_an_theo_gia_tri(t1->pleft, p1);
		}
	}
}

void Tim_monan_theo_gia(DS_MON_AN& ds_hd, TREE_MON_AN t, int giatri)
{
	if (t != NULL)
	{
		if (t->dongia == giatri)
		{
			MON_AN* p = new MON_AN;
			p->dongia = t->dongia;
			p->loaimon = t->loaimon;
			p->ma = t->ma;
			p->ngaythang = t->ngaythang;
			p->sl_ton = t->sl_ton;
			p->soluong = t->soluong;
			p->ten_mon = t->ten_mon;
			p->trangthai = t->trangthai;
			p->pleft = NULL;
			p->pright = NULL;
			Them_mon_an_theo_gia_tri(ds_hd.tree, p);
			ds_hd.soluong++;
		}
		Tim_monan_theo_gia(ds_hd, t->pleft, giatri);
		Tim_monan_theo_gia(ds_hd, t->pright, giatri);
	}
}
void Them_mon_an_theo_loai(TREE_MON_AN& t, MON_AN* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->loaimon >= t->loaimon)
		{
			Them_mon_an_theo_loai(t->pright, p);
		}
		else if (p->loaimon < t->loaimon)
		{
			Them_mon_an_theo_loai(t->pleft, p);
		}
	}
}


void Tim_kiem_monan_theo_loai(DS_MON_AN& ds_hd, TREE_MON_AN t, int giatri)
{
	if (t != NULL)
	{
		if (t->loaimon == giatri)
		{
			MON_AN* p = new MON_AN;
			p->dongia = t->dongia;
			p->loaimon = t->loaimon;
			p->ma = t->ma;
			p->ngaythang = t->ngaythang;
			p->sl_ton = t->sl_ton;
			p->soluong = t->soluong;
			p->ten_mon = t->ten_mon;
			p->trangthai= t->trangthai;
			p->pleft = NULL;
			p->pright = NULL;
			Them_mon_an_theo_loai(ds_hd.tree, p);
			ds_hd.soluong++;
		}
		Tim_kiem_monan_theo_loai(ds_hd, t->pleft, giatri);
		Tim_kiem_monan_theo_loai(ds_hd, t->pright, giatri);
	}
}
