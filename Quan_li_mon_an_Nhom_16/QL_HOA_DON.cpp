// QL_HOA_DON.cpp : implementation file
#pragma once
//-------------------------------------
#include "pch.h"
#include "Quan_li_mon_an_Nhom_16.h"
#include "QL_HOA_DON.h"
#include "afxdialogex.h"
//-------------------------------------
#include"xu_li_de.h";
#include"QL_MON_AN.h";
#include"QL_KHUYENMAI.h"
#include"QL_THONG_KE.h"
#include"ThongKeMonAn.h"
DS_HOA_DON ds;
DS_MON_AN ds_mon_;
int indexhd = 0; int sl3 = 0;
// QL_HOA_DON dialog

IMPLEMENT_DYNAMIC(QL_HOA_DON, CDialogEx)

QL_HOA_DON::QL_HOA_DON(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUAN_LI_HOA_DON, pParent)
{

}

QL_HOA_DON::~QL_HOA_DON()
{
}


BOOL QL_HOA_DON::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	combo_loai_mon_qlhd.AddString(_T("Dinh duong"));
	combo_loai_mon_qlhd.AddString(_T("Ga"));
	combo_loai_mon_qlhd.AddString(_T("Hai san"));

	COLORREF a = RGB(177, 238, 232);
	list_ds_hoa_don_qlhd.SetTextBkColor(a);
	list_ds_hoa_don_qlhd.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	list_ds_hoa_don_qlhd.InsertColumn(0, _T("STT"), LVCFMT_CENTER, 150);
	list_ds_hoa_don_qlhd.InsertColumn(1, _T("Mã hóa đơn"), LVCFMT_CENTER, 150);
	list_ds_hoa_don_qlhd.InsertColumn(2, _T("Tên khách hàng"), LVCFMT_LEFT, 300);
	list_ds_hoa_don_qlhd.InsertColumn(3, _T("Số điện thoại"), LVCFMT_CENTER, 150);
	Xoa_cay_mon_an(ds_mon_.tree);
	ds_mon_.soluong = 0;
	Doc_file_mon_an(ds_mon_);
	Xoa_cay_hd(ds.tree);
	ds.soluong = 0;
	In_danh_sach_HD(ds);
	list_ds_mon_an_qlhd.SetTextBkColor(a);
	list_ds_mon_an_qlhd.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	list_ds_mon_an_qlhd.InsertColumn(0, _T("STT"), LVCFMT_CENTER, 45);
	list_ds_mon_an_qlhd.InsertColumn(1, _T("Mã món"), LVCFMT_CENTER, 75);
	list_ds_mon_an_qlhd.InsertColumn(2, _T("Tên món ăn"), LVCFMT_LEFT, 190);
	list_ds_mon_an_qlhd.InsertColumn(3, _T("Loại món"), LVCFMT_LEFT, 100);
	list_ds_mon_an_qlhd.InsertColumn(4, _T("Đơn giá"), LVCFMT_CENTER, 100);
	list_ds_mon_an_qlhd.InsertColumn(5, _T("SL"), LVCFMT_CENTER, 50);
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void QL_HOA_DON::In_danh_sach_HD(DS_HOA_DON& ds)
{
	indexhd = 0;
	ds.soluong = 0;
	//Hàm này cần đưa vào 1 hàm riêng.
	if (std::ifstream("DS_HOA_DON.TXT"))
	{
		//Doc file cho Interface

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
			Chuan_hoa_chuoi(p->ngaylap);
			getline(fi, p->hoten, ',');
			Chuan_hoa_chuoi(p->hoten);
			getline(fi, p->diachi, ',');
			Chuan_hoa_chuoi(p->diachi);
			getline(fi, p->sdt, ',');
			Chuan_hoa_chuoi(p->sdt);
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
				t = Tim_kiem_mon_an(ds_mon_.tree, t->ma);
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
			ds.soluong++; //sl1++;
			//Tạo mấy thằng đệ
			CString str_mahoadon;
			CString str_ten(p->hoten.c_str(), p->hoten.length());
			CString str_sdt(p->sdt.c_str(), p->sdt.length());
			CString soluong;
			soluong.Format(_T("%d"), ds.soluong);
			str_mahoadon.Format(_T("%d"), p->mahoadon);
		list_ds_hoa_don_qlhd.InsertItem(indexhd, soluong);
		list_ds_hoa_don_qlhd.SetItemText(indexhd, 1, str_mahoadon);
		list_ds_hoa_don_qlhd.SetItemText(indexhd, 2, str_ten);
		list_ds_hoa_don_qlhd.SetItemText(indexhd, 3, str_sdt);
			indexhd++;
		}

		fi.close();

	}
}
void QL_HOA_DON::Hien_thi_mon(MON_AN* p)
{
	CString soluong;
	soluong.Format(_T("%d"), sl3 + 1);
	CString sl_mon;
	sl_mon.Format(_T("%d"), p->soluong);
	CString ma;
	ma.Format(_T("%d"), p->ma);
	Chuan_hoa_chu(p->ten_mon);
	CString ten(p->ten_mon.c_str(), p->ten_mon.length());
	CString loai;
	combo_loai_mon_qlhd.GetLBText(p->loaimon, loai);

	string gia_hd = Int_sang_string(p->dongia);
	gia_hd = giatien(gia_hd);
	CString gia(gia_hd.c_str(),gia_hd.length());
	list_ds_mon_an_qlhd.InsertItem(sl3, soluong);
	list_ds_mon_an_qlhd.SetItemText(sl3, 1, ma);
	list_ds_mon_an_qlhd.SetItemText(sl3, 2, ten);
	list_ds_mon_an_qlhd.SetItemText(sl3, 3, loai);
	list_ds_mon_an_qlhd.SetItemText(sl3, 4, gia);
	list_ds_mon_an_qlhd.SetItemText(sl3, 5, sl_mon);
	sl3++;
}
void QL_HOA_DON::Hien_thi_ds_mon(TREE_MON_AN t)
{
	if (t != NULL)
	{
		Hien_thi_mon(t);
		Hien_thi_ds_mon(t->pleft);
		Hien_thi_ds_mon(t->pright);
	}
}
void QL_HOA_DON::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_MA_QLHD, edt_qlhd_ma);
	DDX_Control(pDX, IDC_EDT_NGAYLAP_QLHD, edt_qlhd_ngaylap);
	DDX_Control(pDX, IDC_EDT_KH_QLHD, edt_qlhd_hoten);
	DDX_Control(pDX, IDC_EDT_DC_QLHD, edt_qlhd_diachi);
	DDX_Control(pDX, IDC_EDT_SDT_QLHD, edt_qlhd_sdt);
	DDX_Control(pDX, IDC_EDT_MAGIAMGIA_QLHD, edt_qlhd_magiamgia);
	DDX_Control(pDX, IDC_LIST_DS_QLHD, list_ds_hoa_don_qlhd);
	DDX_Control(pDX, IDC_LIST_DS_MON_1_HD_QLHD, list_ds_mon_an_qlhd);
	DDX_Control(pDX, IDC_EDT_TONG_QLHD, edt_tong_qlhd);
	DDX_Control(pDX, IDC_COMBO_LOAI_MON_AN_QLHD, combo_loai_mon_qlhd);
	SetBackgroundImage(IDB_BITMAP16);
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
		_T("Cooper"));
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
			_T("Times New Roman"));
	GetDlgItem(IDC_STATIC_DS_HOADON)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_TT_HOADON)->SetFont(&Font2);
	GetDlgItem(IDC_STACTIC_MAHOADON_QLHD)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_NL_QLHD)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_KHACHHANG_QLHD)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_DC_QLHD)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_MAVOUCHER_QLHD)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_TONG_QLHD)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_SDT_QLHD)->SetFont(&Font1);

}
BEGIN_MESSAGE_MAP(QL_HOA_DON, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_QL_MONAN_, &QL_HOA_DON::OnBnClickedBtnQlMonan)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_DS_QLHD, &QL_HOA_DON::OnLvnItemchangedListDsQlhd)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DS_QLHD, &QL_HOA_DON::OnNMClickListDsQlhd)
	ON_BN_CLICKED(IDC_BTN_QL_KHUYENMAI_QLHD, &QL_HOA_DON::OnBnClickedBtnQlKhuyenmaiQlhd)
	ON_BN_CLICKED(IDC_BTN_QLTK_HD, &QL_HOA_DON::OnBnClickedBtnQltkHd)
	ON_BN_CLICKED(IDC_BTN_CHINHSUAHD_QLHD, &QL_HOA_DON::OnBnClickedBtnChinhsuahdQlhd)
	ON_BN_CLICKED(IDC_BTN_XOAHD_QLHD, &QL_HOA_DON::OnBnClickedBtnXoahdQlhd)
	ON_BN_CLICKED(IDC_BTN_THONGKEMONAN_QLHD, &QL_HOA_DON::OnBnClickedBtnThongkemonanQlhd)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()
HBRUSH QL_HOA_DON::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	default:
		return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
}

// QL_HOA_DON message handlers


void QL_HOA_DON::OnBnClickedBtnQlMonan()
{
	QL_HOA_DON::OnCancel();
	QL_MON_AN ql_mon;
	ql_mon.DoModal();
}


void QL_HOA_DON::OnLvnItemchangedListDsQlhd(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void QL_HOA_DON::OnNMClickListDsQlhd(NMHDR* pNMHDR, LRESULT* pResult)
{
	int index_qlhd=-1;
	sl3 = 0;
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	if (pNMItemActivate != NULL)
	{
		index_qlhd = pNMItemActivate->iItem;
	}
	if (index_qlhd >= 0)
	{
		CString str_mahoadon = list_ds_hoa_don_qlhd.GetItemText(index_qlhd, 1);
		int ma_hoa_don = _tstof(str_mahoadon);
		HOA_DON* p = Tim_kiem_hoa_don(ds.tree, ma_hoa_don);
		CString str_ngaylap(p->ngaylap.c_str(),p->ngaylap.length());
		CString str_hoten(p->hoten.c_str(), p->hoten.length());
		CString str_diachi(p->diachi.c_str(), p->diachi.length());
		CString str_sdt(p->sdt.c_str(), p->sdt.length());
		CString str_magiamgia;
		str_magiamgia.Format(_T("%d"), p->magiamgia);
		edt_qlhd_ma.SetWindowText(str_mahoadon);
		edt_qlhd_ngaylap.SetWindowText(str_ngaylap);
		edt_qlhd_hoten.SetWindowText(str_hoten);
		edt_qlhd_diachi.SetWindowText(str_diachi);
		edt_qlhd_sdt.SetWindowText(str_sdt);
		edt_qlhd_magiamgia.SetWindowText(str_magiamgia);
		list_ds_mon_an_qlhd.DeleteAllItems();
		Hien_thi_ds_mon(p->ds.tree);

		string tong_tien = Int_sang_string(p->tongtien);
		tong_tien = giatien(tong_tien);
		CString str_tong(tong_tien.c_str(),tong_tien.length());
		edt_tong_qlhd.SetWindowText(str_tong);
		
	}
	*pResult = 0;
}


void QL_HOA_DON::OnBnClickedBtnQlKhuyenmaiQlhd()
{
	QL_HOA_DON::OnCancel();
	QL_KHUYENMAI ql;
	ql.DoModal();
}


void QL_HOA_DON::OnBnClickedBtnQltkHd()
{
	QL_HOA_DON::OnCancel();
	QL_THONG_KE ql;
	ql.DoModal();
}


void QL_HOA_DON::OnBnClickedBtnChinhsuahdQlhd()
{
	CString ma_hd;
	CString ngay_lap;
	CString ho_ten;
	CString dia_chi;
	CString sd_t;
	CString ma_giam_gia;
	edt_qlhd_ma.GetWindowText(ma_hd);
	edt_qlhd_ngaylap.GetWindowText(ngay_lap);
	edt_qlhd_hoten.GetWindowText(ho_ten);
	edt_qlhd_diachi.GetWindowText(dia_chi);
	edt_qlhd_sdt.GetWindowText(sd_t);
	edt_qlhd_magiamgia.GetWindowText(ma_giam_gia);

	int ma = _tstof(ma_hd);
	CString msb = _T("Bạn muốn thay đổi hóa đơn có mã: ");
	msb = msb + ma_hd;
	int Answer = MessageBox(msb, _T("Cập nhật hóa đơn"), MB_YESNOCANCEL | MB_ICONWARNING | MB_DEFBUTTON3);
	if (Answer == IDYES)
	{
		
		CT2A sdt1(sd_t);
		string sdt(sdt1);
		Chuan_hoa_chuoi(sdt);
		int kt_laso = KT_la_so(sdt);
		if(kt_laso)
		{
			int kt_lasdt = KTsodienthoai(sdt);
			if(kt_lasdt)
			{ 
			CT2A ngaylap1(ngay_lap);
			string ngaylap(ngaylap1);
			Chuan_hoa_chuoi(ngaylap);

			CT2A hoten1(ho_ten);
			string hoten(hoten1);
			Chuan_hoa_chu(hoten);

			CT2A diachi1(dia_chi);
			string diachi(diachi1);
			Chuan_hoa_chuoi(diachi);

			Cap_nhat_hoa_don(ds.tree, ma, ngaylap, hoten, diachi, sdt);
			//ghi file
			Ghi_file_hoa_don(ds);
			//xoa cay hd, hien thi lai
			Xoa_cay_hd(ds.tree);
			ds.soluong = 0;
			list_ds_hoa_don_qlhd.DeleteAllItems();
			In_danh_sach_HD(ds);
			}
			else
			{
				MessageBox(_T("Số điện thoại không hợp lệ!"), _T("Lưu ý"), MB_ICONERROR | MB_OK);
			}
		}
		else
		{
			MessageBox(_T("Số điện thoại không hợp lệ!"), _T("Lưu ý"), MB_ICONERROR | MB_OK);
		}
	}
	
}


void QL_HOA_DON::OnBnClickedBtnXoahdQlhd()
{
	CString ma_hd;
	CString msb = _T("Bạn muốn xóa hóa đơn có mã là: ");
	edt_qlhd_ma.GetWindowText(ma_hd);
	msb = msb + ma_hd;
	int Answer = MessageBox(msb, _T("Xóa hóa đơn"), MB_YESNOCANCEL | MB_ICONWARNING | MB_DEFBUTTON3);
	if(Answer == IDYES)
	{
		int mahd = _tstof(ma_hd);
		Xoa_hoa_don(ds.tree, mahd);
		ds.soluong--;
		Ghi_file_hoa_don(ds);
		Xoa_cay_hd(ds.tree);
		list_ds_hoa_don_qlhd.DeleteAllItems();
		In_danh_sach_HD(ds);
	}
	
}


void QL_HOA_DON::OnBnClickedBtnThongkemonanQlhd()
{
	QL_HOA_DON::OnCancel();
	ThongKeMonAn ql;
	ql.DoModal();
}
