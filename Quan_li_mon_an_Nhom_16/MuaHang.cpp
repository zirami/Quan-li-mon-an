// MuaHang.cpp : implementation file
#pragma once

//-----------------------------
#include "pch.h"
#include "Quan_li_mon_an_Nhom_16.h"
#include "MuaHang.h"
#include "afxdialogex.h"
//-----------------------------
#include"ctdl.h"
#include"xu_li_de.h"
#include"QL_MON_AN.h"
#include"QL_KHUYENMAI.h"
#include"ThanhToan.h"

DS_MON_AN ds;
DS_MON_AN ds_timkiemmonan;
DS_HOA_DON ds_hd;
HOA_DON* hd;
DS_KM ds_km_mh;
int index1 = 0, sl1 = 0;
int sl2 = 0;
int thanhtoan =0;

IMPLEMENT_DYNAMIC(MuaHang, CDialogEx)

MuaHang::MuaHang(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MUAHANG, pParent)
{

}

MuaHang::~MuaHang()
{
}
void MuaHang::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_VIEW_DS_MON_AN, list_ds_mon);
	DDX_Control(pDX, IDC_COMBO_LOAI_MON_AN, combo_loai_mon_an);
	DDX_Control(pDX, IDC_LIST_CTRL_DS_MONAN_USER, list_ds_mon_an_user);
	DDX_Control(pDX, IDC_EDT_HOTEN_USER, edt_hoten_);
	DDX_Control(pDX, IDC_EDT_DIACHI_USER, edt_diachi_);
	DDX_Control(pDX, IDC_EDT_SDT_USER, edt_sdt_);
	DDX_Control(pDX, IDC_EDT_TONGTHANHTOAN_, edt_tongthanhtoan_);
	DDX_Control(pDX, IDC_EDT_MAGIAMGIA, edt_magiamgia_);
	DDX_Control(pDX, IDC_COMBO_SX_MONAN_MH, combo_sxmonan_mh);
	DDX_Control(pDX, IDC_BTN_DATHANG, btn_muahang_);
	SetBackgroundImage(IDB_BITMAP15);
	Font1.CreateFont(
		25,                       // nHeight
		0,                        // nWidth
		0,                        // nEscapement
		0,                        // nOrientation
		FW_NORMAL,                // nWeight
		TRUE,                    // bItalic
		FALSE,                    // bUnderline
		0,                        // cStrikeOut
		ANSI_CHARSET,             // nCharSet
		OUT_DEFAULT_PRECIS,       // nOutPrecision
		CLIP_DEFAULT_PRECIS,      // nClipPrecision
		DEFAULT_QUALITY,          // nQuality
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily
		_T("Times New Roman"));            // lpszFacename 
	Font2.CreateFont(
		30,                       // nHeight
		0,                        // nWidth
		0,                        // nEscapement
		0,                        // nOrientation
		FW_NORMAL,                // nWeight
		FALSE,                    // bItalic
		FALSE,                    // bUnderline
		0,                        // cStrikeOut
		ANSI_CHARSET,             // nCharSet
		OUT_DEFAULT_PRECIS,       // nOutPrecision
		CLIP_DEFAULT_PRECIS,      // nClipPrecision
		DEFAULT_QUALITY,          // nQuality
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily
		_T("Cooper"));            // lpszFacename 
	GetDlgItem(IDC_STATIC_DS_MONAN_USER)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_HOTEN_USER)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_DIACHI_USER)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_SDT_USER)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_DS_MON_AN_USER)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_VOUCHER)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_TONGTHANHTOAN_)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_TTKH)->SetFont(&Font2);
	btn_muahang_.SetFont(&Font1);
	btn_muahang_.SetMouseCursorHand();

	
}
BOOL MuaHang::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	thanhtoan = 0;
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
		//--------------------------------------------------------------------------
	COLORREF a = RGB(177, 238, 232);
	list_ds_mon.SetTextBkColor(a);
	list_ds_mon.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	list_ds_mon.InsertColumn(0, _T("STT"), LVCFMT_CENTER, 70);
	list_ds_mon.InsertColumn(1, _T("Mã món ăn"), LVCFMT_CENTER, 100);
	list_ds_mon.InsertColumn(2, _T("Tên món ăn"), LVCFMT_LEFT, 280);
	list_ds_mon.InsertColumn(3, _T("Loại món"), LVCFMT_CENTER, 150);
	list_ds_mon.InsertColumn(4, _T("Đơn giá"), LVCFMT_CENTER, 100);
	list_ds_mon.InsertColumn(5, _T("Còn lại"), LVCFMT_CENTER, 100);
	combo_loai_mon_an.AddString(_T("Mon khai vi"));
	combo_loai_mon_an.AddString(_T("Mon chinh"));
	combo_loai_mon_an.AddString(_T("Mon an sang"));
	combo_loai_mon_an.AddString(_T("Mon trang mieng"));
	combo_loai_mon_an.AddString(_T("Banh - banh ngot"));
	combo_loai_mon_an.AddString(_T("Mon chay"));
	combo_loai_mon_an.AddString(_T("Mon nhau"));
	combo_loai_mon_an.AddString(_T("Mon an cho tre"));
	combo_loai_mon_an.AddString(_T("Hai san"));
	combo_loai_mon_an.AddString(_T("Nuoc uong"));
	combo_loai_mon_an.AddString(_T("khác"));

	combo_sxmonan_mh.AddString(_T("Tăng dần"));
	combo_sxmonan_mh.AddString(_T("Giảm dần"));
	combo_sxmonan_mh.SetCurSel(0);

	Xoa_cay_mon_an(ds.tree);
	ds.soluong = 0;
	
	In_danh_sach(ds);
	if (KT_FILE("DS_HOA_DON.TXT") == 1)
	{
		Doc_file_hoa_don(ds_hd, ds);
	}
	if (KT_FILE("DS_KHUYEN_MAI.TXT") == 1)
	{
		Doc_file_khuyen_mai(ds_km_mh);
	}
	hd = new HOA_DON;
	hd->pleft = NULL;
	hd->pright = NULL;

	//--------------------------------------------------------------------------
	//COLORREF a = RGB(177, 238, 232);
	list_ds_mon_an_user.SetTextBkColor(a);
	list_ds_mon_an_user.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	list_ds_mon_an_user.InsertColumn(0, _T("STT"), LVCFMT_CENTER, 45);
	list_ds_mon_an_user.InsertColumn(1, _T("Mã món"), LVCFMT_CENTER, 75);
	list_ds_mon_an_user.InsertColumn(2, _T("Tên món ăn"), LVCFMT_LEFT, 190);
	list_ds_mon_an_user.InsertColumn(3, _T("Loại món"), LVCFMT_CENTER, 100);
	list_ds_mon_an_user.InsertColumn(4, _T("Đơn giá"), LVCFMT_CENTER, 100);
	list_ds_mon_an_user.InsertColumn(5, _T("SL"), LVCFMT_CENTER, 50);

	

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void MuaHang::In_danh_sach(DS_MON_AN &ds)
{
	index1 = 0;
	//Hàm này cần đưa vào 1 hàm riêng.
	if (std::ifstream("DS_MON_AN.TXT"))
	{
		//Doc file cho Interface

		ifstream filein;
		filein.open("DS_MON_AN.TXT", ios_base::in);
		while (filein.eof() != true)
		{
			MON_AN* p = Khoi_tao_node_mon_an();
			rewind(stdin);
			filein >> p->ma;
			filein.seekg(1, 1);
			getline(filein, p->ten_mon, ',');
			Chuan_hoa_chu(p->ten_mon);
			getline(filein, p->ngaythang, ',');
			Chuan_hoa_chuoi(p->ngaythang);
			filein >> p->loaimon;
			filein.seekg(1, 1);
			filein >> p->dongia;
			filein.seekg(1, 1);
			filein >> p->trangthai;
			filein.seekg(1, 1);
			filein >> p->sl_ton;
			Them_mon_an(ds.tree, p);
			ds.soluong++; sl1++;
			//Tạo mấy thằng đệ
			CString str_mamonan1;
			CString str_loaimon;
			
			string s_dongia = Int_sang_string(p->dongia);
			s_dongia = giatien(s_dongia);
			CString str_dongia1(s_dongia.c_str(), s_dongia.length());

			CString str_sl_ton;
			str_sl_ton.Format(_T("%d"), p->sl_ton);
			CString soluong;
			soluong.Format(_T("%d"), ds.soluong);
			combo_loai_mon_an.GetLBText(p->loaimon, str_loaimon);

			//Chuyển từ int sang CString
			str_mamonan1.Format(_T("%d"), p->ma);
			CString str_tenmonan1(p->ten_mon.c_str(), p->ten_mon.length());
		
			list_ds_mon.InsertItem(index1, soluong);
			list_ds_mon.SetItemText(index1, 1, str_mamonan1);
			list_ds_mon.SetItemText(index1, 2, str_tenmonan1);
			list_ds_mon.SetItemText(index1, 3, str_loaimon);
			list_ds_mon.SetItemText(index1, 4, str_dongia1);
			list_ds_mon.SetItemText(index1, 5, str_sl_ton);
			index1++;
		}

		filein.close();

	}
}
HBRUSH MuaHang::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->GetDlgCtrlID() ==IDC_STATIC_DS_MONAN_USER)
	{
		//set the static text color to red      
		pDC->SetTextColor(RGB(255, 0, 0));
		pDC->SetBkMode(TRANSPARENT);
	}
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	default:
		return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
	return hbr;
}
BEGIN_MESSAGE_MAP(MuaHang, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST_VIEW_DS_MON_AN, &MuaHang::OnNMClickListViewDsMonAn)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_DS_MONAN_USER, &MuaHang::OnNMClickListCtrlDsMonanUser)
	ON_BN_CLICKED(IDC_BTN_DATHANG, &MuaHang::OnBnClickedBtnDathang)
	ON_EN_CHANGE(IDC_EDT_SDT_USER, &MuaHang::OnEnChangeEdtSdtUser)
	ON_EN_CHANGE(IDC_EDT_TONGTHANHTOAN_, &MuaHang::OnEnChangeEdtTongthanhtoan)
	ON_BN_CLICKED(IDC_BTN_TIM_KIEM, &MuaHang::OnBnClickedBtnTimKiem)
	ON_BN_CLICKED(IDC_BTN_HIENTHI_DS_MONAN_MH, &MuaHang::OnBnClickedBtnHienthiDsMonanMh)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()
void MuaHang::Hien_thi_mon(MON_AN *p)
{
	CString soluong;
	soluong.Format(_T("%d"), sl2 + 1);
	CString sl_mon;
	sl_mon.Format(_T("%d"), p->soluong);
	CString ma;
	ma.Format(_T("%d"), p->ma);
	CString ten(p->ten_mon.c_str(), p->ten_mon.length());
	CString loai;
	combo_loai_mon_an.GetLBText(p->loaimon, loai);
	
	string s_gia = Int_sang_string(p->dongia);
	s_gia = giatien(s_gia);
	CString gia(s_gia.c_str(), s_gia.length());

	list_ds_mon_an_user.InsertItem(sl2, soluong);
	list_ds_mon_an_user.SetItemText(sl2, 1, ma);
	list_ds_mon_an_user.SetItemText(sl2, 2, ten);
	list_ds_mon_an_user.SetItemText(sl2, 3, loai);
	list_ds_mon_an_user.SetItemText(sl2, 4, gia);
	list_ds_mon_an_user.SetItemText(sl2, 5, sl_mon);
	sl2++;
}
void MuaHang::Hien_thi_1_mon(MON_AN* p)
{
	CString soluong;
	soluong.Format(_T("%d"), sl2 + 1);
	CString sl_ton;
	sl_ton.Format(_T("%d"), p->sl_ton);
	CString ma;
	ma.Format(_T("%d"), p->ma);
	CString ten(p->ten_mon.c_str(), p->ten_mon.length());
	CString loai;
	combo_loai_mon_an.GetLBText(p->loaimon, loai);
	
	
	string s_gia = Int_sang_string(p->dongia);
	s_gia = giatien(s_gia);
	CString gia(s_gia.c_str(), s_gia.length());

	list_ds_mon.InsertItem(sl2, soluong);
	list_ds_mon.SetItemText(sl2, 1, ma);
	list_ds_mon.SetItemText(sl2, 2, ten);
	list_ds_mon.SetItemText(sl2, 3, loai);
	list_ds_mon.SetItemText(sl2, 4, gia);
	list_ds_mon.SetItemText(sl2, 5, sl_ton);
	sl2++;
}

void MuaHang::Hien_thi_ds_mon(TREE_MON_AN t)
{
	if (t != NULL)
	{
		Hien_thi_ds_mon(t->pleft);
		Hien_thi_mon(t);
		Hien_thi_ds_mon(t->pright);
	}
}
void MuaHang::Hien_thi_ds_mon_giam(TREE_MON_AN t)
{
	if (t != NULL)
	{
		Hien_thi_ds_mon_giam(t->pright);

		Hien_thi_1_mon(t);

		Hien_thi_ds_mon_giam(t->pleft);
	}
}
void MuaHang::Hien_thi_ds_mon_tang(TREE_MON_AN t)
{
	if (t != NULL)
	{
		Hien_thi_ds_mon_tang(t->pleft);
		Hien_thi_1_mon(t);
		Hien_thi_ds_mon_tang(t->pright);
	}
}
void MuaHang::OnNMClickListViewDsMonAn(NMHDR* pNMHDR, LRESULT* pResult)
{

	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	int idex = -1;
	sl2 = 0;
	if (pNMItemActivate != NULL)
	{
		idex = pNMItemActivate->iItem;
	}
	if (idex >= 0)
	{

		CString ma = list_ds_mon.GetItemText(idex, 1);
		CString ten = list_ds_mon.GetItemText(idex, 2);
		CString loai = list_ds_mon.GetItemText(idex, 3);
		CString gia = list_ds_mon.GetItemText(idex, 4);
		CString str_sl_ton = list_ds_mon.GetItemText(idex, 5);
		int ma_mon_an= _tstof(ma);
		MON_AN* p = Tim_kiem_mon_an(hd->ds.tree, ma_mon_an);
		MON_AN* t = Tim_kiem_mon_an(ds.tree, ma_mon_an);
		if (t->sl_ton >= 1)
		{
			if (p == NULL)
			{
				p = Khoi_tao_node_mon_an();
				p->ma = _tstof(ma);
				p->loaimon = combo_loai_mon_an.FindString(0, loai);
				p->dongia = t->dongia;
				p->sl_ton = _tstof(str_sl_ton);
				CT2A ct(ten);
				string tenmon(ct);
				Chuan_hoa_chu(tenmon);
				p->ten_mon = tenmon;
				p->trangthai = 0;
				p->soluong = 1;
				Them_mon_an(hd->ds.tree, p);
				hd->ds.soluong++;

			}
			else
			{
				Tang_so_luong_mon(hd->ds.tree, ma_mon_an);
			}
			//Tổng tiền
			thanhtoan += p->dongia;
			string s_thanhtoan = Int_sang_string(thanhtoan);
			s_thanhtoan = giatien(s_thanhtoan);
			CString tong(s_thanhtoan.c_str(), s_thanhtoan.length());
			edt_tongthanhtoan_.SetWindowText(tong);
			//GIảm số lượng món trong cây
			Giam_so_luong_ton(ds.tree, ma_mon_an);
			Ghi_file_mon_an(ds);
		}
		else
		{
			MessageBox(_T("Số lượng món ăn không đáp ứng đủ yêu cầu của bạn!"), _T("Thông báo"), MB_ICONWARNING);
		}
	}
	//Hiển thị ds món
	list_ds_mon_an_user.DeleteAllItems();
	Hien_thi_ds_mon(hd->ds.tree);
	list_ds_mon.DeleteAllItems();
	Xoa_cay_mon_an(ds.tree);
	ds.soluong = 0;
	In_danh_sach(ds);
	*pResult = 0;
}


void MuaHang::OnNMClickListCtrlDsMonanUser(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	int inndex=0;
	sl2 = 0;
	if (pNMItemActivate != NULL)
	{
		inndex = pNMItemActivate->iItem;
	}
	if (inndex >= 0)
	{
		CString ma=list_ds_mon_an_user.GetItemText(inndex, 1);
		CString ten = list_ds_mon_an_user.GetItemText(inndex, 2);
		CString loai = list_ds_mon_an_user.GetItemText(inndex, 3);
		CString gia = list_ds_mon_an_user.GetItemText(inndex, 4);
		CString str_sl = list_ds_mon_an_user.GetItemText(inndex, 5);
		int ma_mon_an = _tstof(ma);
		int sl = _tstof(str_sl);
		MON_AN* p = Tim_kiem_mon_an(hd->ds.tree, ma_mon_an);
		p->pleft = NULL;
		p->pright = NULL;
		p->soluong = sl;
		if (p != NULL)
		{
			if(p->soluong>1)
			{
				Giam_so_luong_mon(hd->ds.tree, ma_mon_an);
			}
			else if (p->soluong == 1)
			{
				Xoa_mon_an(hd->ds.tree, ma_mon_an);
				hd->ds.soluong--;
			}
			Tang_so_luong_ton(ds.tree, ma_mon_an);
			Ghi_file_mon_an(ds);

		}
		thanhtoan = thanhtoan - p->dongia;
	}
	string s_thanhtoan = Int_sang_string(thanhtoan);
	s_thanhtoan = giatien(s_thanhtoan);
	CString tong(s_thanhtoan.c_str(), s_thanhtoan.length());
	edt_tongthanhtoan_.SetWindowText(tong);
	list_ds_mon_an_user.DeleteAllItems();
	Hien_thi_ds_mon(hd->ds.tree);
	list_ds_mon.DeleteAllItems();
	In_danh_sach(ds);
	*pResult = 0;
}


void MuaHang::OnBnClickedBtnDathang()
{
	CString str_hoten;
	CString str_diachi;
	CString str_sdt;
	CString str_magiamgia;
	edt_hoten_.GetWindowText(str_hoten);
	edt_diachi_.GetWindowText(str_diachi);
	edt_sdt_.GetWindowText(str_sdt);
	edt_magiamgia_.GetWindowText(str_magiamgia);
	int mahoadon = Tao_ma_hoa_don(ds_hd.tree);
	string ngaylap = laytime();
	if ( str_hoten.Compare(L"")==0 || str_diachi.Compare(L"")==0 || str_sdt.Compare(L"")==0)
	{
		MessageBox(_T("Vui lòng điền đầy đủ thông tin trước khi đặt hàng!"), _T("Thông Báo"), MB_OK||MB_COMPOSITE);
	}
	else if(hd->ds.soluong==0)
	{
		MessageBox(_T("Bạn chưa chọn món ăn!"), _T("Lưu ý"), MB_OK);

		
	}
	else if (str_magiamgia.Compare(L"") == 0)
	{
		CT2A sdt1(str_sdt);
		string sdt(sdt1);
		int ktlaso = KT_la_so(sdt);
		if (ktlaso == 1)
		{
			int ktsdt = KTsodienthoai(sdt);
			if (ktsdt == 1)
			{
				int magiamgia = 0;
				CT2A ct1(str_hoten);
				string hoten(ct1);
				Chuan_hoa_chu(hoten);
				CT2A ct2(str_diachi);
				string diachi(ct2);
				Chuan_hoa_chu(diachi);
				/*CT2A ct3(str_sdt);
				string sdt(ct3);*/
				Chuan_hoa_chuoi(sdt);

				hd->mahoadon = mahoadon;
				hd->ngaylap = ngaylap;
				hd->hoten = hoten;
				hd->diachi = diachi;
				hd->sdt = sdt;
				hd->tongtien = (thanhtoan);
				hd->magiamgia = magiamgia;

				Them_hoa_don(ds_hd.tree, hd);
				//Xuat file
				ofstream fo;
				fo.open("HOA_DON_TAM.TXT", ios_base::out);
				fo << "\n" << hd->mahoadon << ", " << hd->ngaylap << ", " << hd->hoten << ", " << hd->diachi << ", " << hd->sdt << ", " << hd->tongtien << ", " << hd->magiamgia << ", ";
				Xuat_ds_mon_an_hd(hd->ds.tree, fo);
				fo << "e";
				fo.close();
				MessageBox(_T("Vui lòng xem hóa đơn bạn vừa chọn và chọn phương thức thanh toán để hoàn tất đơn hàng!"), _T("Chúc mừng"), MB_OK | MB_ICONASTERISK);
				Ghi_file_mon_an(ds);
				MuaHang::OnCancel();
				ThanhToan tt;
			
				tt.DoModal();
			}
			else
			{
				MessageBox(_T("Số điện thoại không hợp lệ!"), _T("Lưu ý"), MB_OK | MB_ICONASTERISK);
			}
		}
		else
		{
			MessageBox(_T("Số điện thoại không hợp lệ!"), _T("Lưu ý"), MB_OK | MB_ICONASTERISK);
		}

	}
	else if (str_magiamgia.Compare(_T("")) == 1)
	{
		
		int magiamgia = _tstof(str_magiamgia);
		KM* p = Tim_kiem_KM(ds_km_mh.tree, magiamgia);
		if (p != NULL)
		{
			
			int ssma = so_sanh_2_ngay_(p->hsd, ngaylap);
			if (ssma >= 1)
			{
				CT2A sdt1(str_sdt);
				string sdt(sdt1);
				int ktlaso = KT_la_so(sdt);
				if (ktlaso == 1)
				{
					int ktsdt = KTsodienthoai(sdt);
					if (ktsdt == 1)
					{
						CT2A ct1(str_hoten);
						string hoten(ct1);
						Chuan_hoa_chu(hoten);
						CT2A ct2(str_diachi);
						string diachi(ct2);
						Chuan_hoa_chu(diachi);
						CT2A ct3(str_sdt);
						string sdt(ct3);
						Chuan_hoa_chuoi(sdt);
						hd->mahoadon = mahoadon;
						hd->ngaylap = ngaylap;
						hd->hoten = hoten;
						hd->diachi = diachi;
						hd->sdt = sdt;
						hd->tongtien = (thanhtoan - p->giatri);
						hd->magiamgia = magiamgia;

						Them_hoa_don(ds_hd.tree, hd);
						//Xuat file
						ofstream fo;
						fo.open("HOA_DON_TAM.TXT", ios_base::out);
						fo << "\n" << hd->mahoadon << ", " << hd->ngaylap << ", " << hd->hoten << ", " << hd->diachi << ", " << hd->sdt << ", " << hd->tongtien << ", " << hd->magiamgia << ", ";
						Xuat_ds_mon_an_hd(hd->ds.tree, fo);
						fo << "e";
						fo.close();
						MessageBox(_T("Vui lòng xem hóa đơn bạn vừa chọn và chọn phương thức thanh toán để hoàn tất đơn hàng!"), _T("Chúc mừng"), MB_OK | MB_ICONASTERISK);
						Ghi_file_mon_an(ds);
						ThanhToan tt;
						MuaHang::OnCancel();
						tt.DoModal();
					}
					else
					{
						MessageBox(_T("Số điện thoại không hợp lệ!"), _T("Lưu ý"), MB_OK | MB_ICONASTERISK);
					}
				}
				else
					MessageBox(_T("Số điện thoại không hợp lệ!"), _T("Lưu ý"), MB_OK | MB_ICONASTERISK);
			}
			else
			{
				MessageBox(_T("Mã giảm giá đã hết hạn hoặc không hợp lệ!"), _T("Lưu ý"), MB_OK | MB_ICONASTERISK);
			}
		}
		else
		{
			MessageBox(_T("Mã giảm giá không tồn tại!"), _T("Lưu ý"), MB_OK | MB_ICONERROR);
		}
	}

}


void MuaHang::OnEnChangeEdtSdtUser()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void MuaHang::OnEnChangeEdtTongthanhtoan()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}



void MuaHang::OnBnClickedBtnTimKiem()
{
	list_ds_mon.DeleteAllItems();
	int lm_tk = combo_loai_mon_an.GetCurSel();
	int sx_giam = combo_sxmonan_mh.GetCurSel();
	Tim_kiem_monan_theo_gia_tri(ds_timkiemmonan, ds.tree, lm_tk);
	if (ds_timkiemmonan.soluong > 0)
	{
		sl2 = 0;
		if (sx_giam == 0)
		{
			Hien_thi_ds_mon_tang(ds_timkiemmonan.tree);
		}
		else if(sx_giam ==1)
		{
			Hien_thi_ds_mon_giam(ds_timkiemmonan.tree);
		}

	}
	Xoa_cay_mon_an(ds_timkiemmonan.tree);
	ds_timkiemmonan.soluong = 0;
}


void MuaHang::OnBnClickedBtnHienthiDsMonanMh()
{
	list_ds_mon.DeleteAllItems();
	sl2 = 0;
	Hien_thi_ds_mon_tang(ds.tree);
}
