// ThongKeMonAn.cpp : implementation file
#pragma once
//-------------------------
#include "pch.h"
#include "Quan_li_mon_an_Nhom_16.h"
#include "ThongKeMonAn.h"
#include "afxdialogex.h"
//----------------------
#include"ctdl.h"
#include"xu_li_de.h"
#include"QL_HOA_DON.h"
#include"QL_KHUYENMAI.h"
#include"QL_MON_AN.h"
#include"QL_THONG_KE.h"
// ThongKeMonAn dialog
DS_MON_AN ds_mon_an_all_tkma;

DS_MON_AN ds_monan_tn_tkma;

DS_MON_AN ds_monan_dg_tkma;

DS_MON_AN ds_monan_dg1_tkma;
DS_MON_AN ds_monan_loai_tkma;
int index_tkma = 0;
int sl_tkma = 0;
IMPLEMENT_DYNAMIC(ThongKeMonAn, CDialogEx)

ThongKeMonAn::ThongKeMonAn(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ThongKeMonAn::~ThongKeMonAn()
{
}


BOOL ThongKeMonAn::OnInitDialog()
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
	
	SetBackgroundImage(IDB_BITMAP18);
	COLORREF a = RGB(177, 238, 232);
	list_ds_monan_all.SetTextBkColor(a);
	list_ds_monan_all.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	list_ds_monan_all.InsertColumn(0, _T("STT"), LVCFMT_CENTER, 50);
	list_ds_monan_all.InsertColumn(1, _T("Mã món ăn"), LVCFMT_CENTER, 100);
	list_ds_monan_all.InsertColumn(2, _T("Tên món ăn"), LVCFMT_CENTER, 300);
	list_ds_monan_all.InsertColumn(3, _T("Loại món"), LVCFMT_CENTER, 100);
	list_ds_monan_all.InsertColumn(4, _T("Đơn giá"), LVCFMT_CENTER, 150);
	list_ds_monan_all.InsertColumn(5, _T("Còn lại"), LVCFMT_CENTER, 100);

	list_ds_monan_tkma.SetTextBkColor(a);
	list_ds_monan_tkma.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	list_ds_monan_tkma.InsertColumn(0, _T("STT"), LVCFMT_CENTER, 50);
	list_ds_monan_tkma.InsertColumn(1, _T("Mã món ăn"), LVCFMT_CENTER, 100);
	list_ds_monan_tkma.InsertColumn(2, _T("Ngày lập"), LVCFMT_CENTER, 100);
	list_ds_monan_tkma.InsertColumn(3, _T("Tên món ăn"), LVCFMT_CENTER, 300);
	list_ds_monan_tkma.InsertColumn(4, _T("Loại món"), LVCFMT_CENTER, 100);
	list_ds_monan_tkma.InsertColumn(5, _T("Đơn giá"), LVCFMT_CENTER, 150);
	list_ds_monan_tkma.InsertColumn(6, _T("Còn lại"), LVCFMT_CENTER, 100);

	combo_loaimon_tkma_.AddString(_T("Mon khai vi"));
	combo_loaimon_tkma_.AddString(_T("Mon chinh"));
	combo_loaimon_tkma_.AddString(_T("Mon an sang"));
	combo_loaimon_tkma_.AddString(_T("Mon trang mieng"));
	combo_loaimon_tkma_.AddString(_T("Banh - banh ngot"));
	combo_loaimon_tkma_.AddString(_T("Mon chay"));
	combo_loaimon_tkma_.AddString(_T("Mon nhau"));
	combo_loaimon_tkma_.AddString(_T("Mon an cho tre"));
	combo_loaimon_tkma_.AddString(_T("Hai san"));
	combo_loaimon_tkma_.AddString(_T("Nuoc uong"));
	combo_loaimon_tkma_.AddString(_T("khác"));

	cb_loaimon_tkma.AddString(_T("Mon khai vi"));
	cb_loaimon_tkma.AddString(_T("Mon chinh"));
	cb_loaimon_tkma.AddString(_T("Mon an sang"));
	cb_loaimon_tkma.AddString(_T("Mon trang mieng"));
	cb_loaimon_tkma.AddString(_T("Banh - banh ngot"));
	cb_loaimon_tkma.AddString(_T("Mon chay"));
	cb_loaimon_tkma.AddString(_T("Mon nhau"));
	cb_loaimon_tkma.AddString(_T("Mon an cho tre"));
	cb_loaimon_tkma.AddString(_T("Hai san"));
	cb_loaimon_tkma.AddString(_T("Nuoc uong"));
	cb_loaimon_tkma.AddString(_T("khác"));

	edt_dongia_tkma.AddString(_T("Tăng dần"));
	edt_dongia_tkma.AddString(_T("Giảm dần"));
	edt_dongia_tkma.SetCurSel(0);

	cb_sxntn_tkma.AddString(_T("Tăng dần"));
	cb_sxntn_tkma.AddString(_T("Giảm dần"));
	cb_sxntn_tkma.SetCurSel(0);

	CString str_ngay;
	for (int i = 1; i <= 31; i++)
	{
		str_ngay.Format(L"%d", i);
		cb_tungay_ngay.AddString(str_ngay);
		cb_denngay_ngay.AddString(str_ngay);
	}
	cb_tungay_ngay.SetCurSel(0);
	cb_denngay_ngay.SetCurSel(30);
	CString str_thang;
	for (int i = 1; i <= 12; i++)
	{
		str_thang.Format(L"%d", i);
		cb_tungay_thang.AddString(str_thang);
		cb_denngay_thang.AddString(str_thang);
	}
	cb_tungay_thang.SetCurSel(0);
	cb_denngay_thang.SetCurSel(11);
	CString str_nam;
	for (int i = 2000; i <= 2200; i++)
	{
		str_nam.Format(L"%d", i);
		cb_tungay_nam.AddString(str_nam);
		cb_denngay_nam.AddString(str_nam);
	}
	cb_tungay_nam.SetCurSel(0);
	cb_denngay_nam.SetCurSel(20);





	In_danh_sach_ma(ds_mon_an_all_tkma);

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void ThongKeMonAn::In_danh_sach_ma(DS_MON_AN& ds)
{
	index_tkma = 0;
	ds.soluong = 0;
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
			Chuan_hoa_chu((p->ten_mon));
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

			MON_AN* p1 = new MON_AN;
			p1->pleft = NULL;
			p1->pright = NULL;
			p1->dongia = p->dongia;
			p1->loaimon = p->loaimon;
			p1->ma = p->ma;
			p1->ngaythang = p->ngaythang;
			p1->sl_ton = p->sl_ton;
			p1->soluong = p->soluong;
			p1->ten_mon = p->ten_mon;
			p1->trangthai = p->trangthai;
			Them_mon_an_theo_giatri(ds_monan_dg1_tkma.tree, p1);
			ds_monan_dg1_tkma.soluong++;

		

			ds.soluong++;
			//Tạo mấy thằng đệ
			CString str_mamonan1;
			CString str_loaimon;
			CString str_sl_ton;
			str_sl_ton.Format(_T("%d"), p->sl_ton);
			CString soluong;
			soluong.Format(_T("%d"), ds.soluong);
			combo_loaimon_tkma_.GetLBText(p->loaimon, str_loaimon);

			str_mamonan1.Format(_T("%d"), p->ma);
			CString str_tenmonan1(p->ten_mon.c_str(), p->ten_mon.length());
			string dongia_1 = Int_sang_string(p->dongia);
			dongia_1 = giatien(dongia_1);
			CString str_dongia1(dongia_1.c_str(), dongia_1.length());
			list_ds_monan_all.InsertItem(index_tkma, soluong);
			list_ds_monan_all.SetItemText(index_tkma, 1, str_mamonan1);
			list_ds_monan_all.SetItemText(index_tkma, 2, str_tenmonan1);
			list_ds_monan_all.SetItemText(index_tkma, 3, str_loaimon);
			list_ds_monan_all.SetItemText(index_tkma, 4, str_dongia1);
			list_ds_monan_all.SetItemText(index_tkma, 5, str_sl_ton);
			index_tkma++;
		}

		filein.close();

	}
}

void ThongKeMonAn::Hien_thi_mon_an(MON_AN* p)
{

	CString soluong;
	soluong.Format(_T("%d"), sl_tkma + 1);
	CString ma;
	ma.Format(_T("%d"), p->ma);
	CString ten(p->ten_mon.c_str(), p->ten_mon.length());
	CString ngaylap(p->ngaythang.c_str(), p->ngaythang.length());
	CString loaimon;
	combo_loaimon_tkma_.GetLBText(p->loaimon, loaimon);
	string str_dongia = Int_sang_string(p->dongia);
	str_dongia = giatien(str_dongia);
	CString dongia(str_dongia.c_str(), str_dongia.length());
	CString sl_ton;
	sl_ton.Format(_T("%d"), p->sl_ton);
	list_ds_monan_tkma.InsertItem(sl_tkma, soluong);
	list_ds_monan_tkma.SetItemText(sl_tkma, 1, ma);
	list_ds_monan_tkma.SetItemText(sl_tkma, 2, ngaylap);
	list_ds_monan_tkma.SetItemText(sl_tkma, 3, ten);
	list_ds_monan_tkma.SetItemText(sl_tkma, 4, loaimon);
	list_ds_monan_tkma.SetItemText(sl_tkma, 5, dongia);
	list_ds_monan_tkma.SetItemText(sl_tkma, 6, sl_ton);
	sl_tkma++;
}

void ThongKeMonAn::Hien_thi_ds_mon_an_tang(TREE_MON_AN t)
{
	if (t != NULL)
	{
		Hien_thi_ds_mon_an_tang(t->pleft);
		Hien_thi_mon_an(t);
		Hien_thi_ds_mon_an_tang(t->pright);
	}
}
void ThongKeMonAn::Hien_thi_ds_mon_an_giam(TREE_MON_AN t)
{
	if (t != NULL)
	{
		Hien_thi_ds_mon_an_giam(t->pright);
		Hien_thi_mon_an(t);
		Hien_thi_ds_mon_an_giam(t->pleft);
	}
}
void ThongKeMonAn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DS_MONAN_TKMA, list_ds_monan_all);
	DDX_Control(pDX, IDC_LIST_DS_MONANTHONGKE_TKMA, list_ds_monan_tkma);
	DDX_Control(pDX, IDC_CBB_LOAIMON_TKMA, combo_loaimon_tkma_);
	DDX_Control(pDX, IDC_COMBO_SXTANGGIAM_TKMA, cb_sxntn_tkma);
	DDX_Control(pDX, IDC_COMBO_TUNGAY_NGAY_TKMA, cb_tungay_ngay);
	DDX_Control(pDX, IDC_COMBO_TUNGAY_THANG_TKMA, cb_tungay_thang);
	DDX_Control(pDX, IDC_COMBO_TUNGAY_NAM_TKMA, cb_tungay_nam);
	DDX_Control(pDX, IDC_COMBO_DENNGAY_NGAY_TKMA, cb_denngay_ngay);
	DDX_Control(pDX, IDC_COMBO_DENNGAY_THANG_TKMA, cb_denngay_thang);
	DDX_Control(pDX, IDC_COMBO_DENNGAY_NAM_TKMA, cb_denngay_nam);
	DDX_Control(pDX, IDC_EDIT_DONGIA_TKMA, edtt_dongia_tkma);
	DDX_Control(pDX, IDC_COMBO_DONGIA_TKMA, edt_dongia_tkma);
	DDX_Control(pDX, IDC_BUTTON_TIMKIEMTHEODONGIA_TKMA, btn_timkiemtheodongia_tkma);
	DDX_Control(pDX, IDC_COMBO_LOAIMON_TKMA, cb_loaimon_tkma);
	DDX_Control(pDX, IDC_BTN_TIMKIEM_TKMA, btn_tk1_);
	DDX_Control(pDX, IDC_BUTTON_SXTHEODONGIA_TKMA, btn_sx1_);
	DDX_Control(pDX, IDC_BUTTON_LOAIMON_TKMA, btn_tk2_);
	Font1.CreateFont(
		25,                       // nHeight
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
	Font2.CreateFont(
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
	GetDlgItem(IDC_STATIC_NGAYTHANGNAM_TKMA)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_NGAYTHANGNAM_TKMA)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_TUNGAY_TKMA)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_DENNGAY_TKMA)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_DSMONAN_TKMA)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_TIMTHEODONGIA_TKMA)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_DS_THONGKEMONAN_TKMA)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_LOAIMON_TKMA)->SetFont(&Font1);
	btn_sx1_.SetFont(&Font2);
	btn_sx1_.SetMouseCursorHand(); 
	btn_timkiemtheodongia_tkma.SetFont(&Font2);
	btn_timkiemtheodongia_tkma.SetMouseCursorHand(); 
	btn_tk1_.SetFont(&Font2); 
	btn_tk1_.SetMouseCursorHand(); 
	btn_tk2_.SetFont(&Font2); 
	btn_tk2_.SetMouseCursorHand();

	
}

BEGIN_MESSAGE_MAP(ThongKeMonAn, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_QLMONAN_TKMA, &ThongKeMonAn::OnBnClickedBtnQlmonanTkma)
	ON_BN_CLICKED(IDC_BTN_QLHOADON_TKMA, &ThongKeMonAn::OnBnClickedBtnQlhoadonTkma)
	ON_BN_CLICKED(IDC_BTN_QLKM_TKMA, &ThongKeMonAn::OnBnClickedBtnQlkmTkma)
	ON_BN_CLICKED(IDC_BTN_TKHD_TKMA, &ThongKeMonAn::OnBnClickedBtnTkhdTkma)
	ON_STN_CLICKED(IDC_STATIC_DSMONAN_TKMA, &ThongKeMonAn::OnStnClickedStaticDsmonanTkma)
	ON_BN_CLICKED(IDC_BTN_TIMKIEM_TKMA, &ThongKeMonAn::OnBnClickedBtnTimkiemTkma)
	ON_BN_CLICKED(IDC_BUTTON_TIMKIEMTHEODONGIA_TKMA, &ThongKeMonAn::OnBnClickedButtonTimkiemtheodongiaTkma)
	ON_BN_CLICKED(IDC_BUTTON_SXTHEODONGIA_TKMA, &ThongKeMonAn::OnBnClickedButtonSxtheodongiaTkma)
	ON_BN_CLICKED(IDC_BUTTON_LOAIMON_TKMA, &ThongKeMonAn::OnBnClickedButtonLoaimonTkma)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()




// ThongKeMonAn message handlers


HBRUSH ThongKeMonAn::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
void ThongKeMonAn::OnBnClickedBtnQlmonanTkma()
{
	ThongKeMonAn::OnCancel();
	QL_MON_AN ql;
	ql.DoModal();
}

void ThongKeMonAn::OnBnClickedBtnQlhoadonTkma()
{
	ThongKeMonAn::OnCancel();
	QL_HOA_DON ql;
	ql.DoModal();
}


void ThongKeMonAn::OnBnClickedBtnQlkmTkma()
{
	ThongKeMonAn::OnCancel();
	QL_KHUYENMAI ql;
	ql.DoModal();
}


void ThongKeMonAn::OnBnClickedBtnTkhdTkma()
{
	ThongKeMonAn::OnCancel();
	QL_THONG_KE ql;
	ql.DoModal();
}


void ThongKeMonAn::OnStnClickedStaticDsmonanTkma()
{
	// TODO: Add your control notification handler code here
}


void ThongKeMonAn::OnBnClickedBtnTimkiemTkma()
{
		list_ds_monan_tkma.DeleteAllItems();
		CString tn_ngay;
		CString tn_thang;
		CString tn_nam;
		CString dn_ngay;
		CString dn_thang;
		CString dn_nam;

		int t_ngay, t_thang, t_nam, d_ngay, d_thang, d_nam;
		int sx_giam = cb_sxntn_tkma.GetCurSel();

		t_ngay = cb_tungay_ngay.GetCurSel(); // ngay 6 ---> t_ngay ==5
		t_thang = cb_tungay_thang.GetCurSel();
		t_nam = cb_tungay_nam.GetCurSel();
		d_ngay = cb_denngay_ngay.GetCurSel();
		d_thang = cb_denngay_thang.GetCurSel();
		d_nam = cb_denngay_nam.GetCurSel();
		cb_tungay_ngay.GetLBText(t_ngay, tn_ngay); // ngay 6 --> tn_ngay ==6
		cb_tungay_thang.GetLBText(t_thang, tn_thang);
		cb_tungay_nam.GetLBText(t_nam, tn_nam);
		cb_denngay_ngay.GetLBText(d_ngay, dn_ngay);
		cb_denngay_thang.GetLBText(d_thang, dn_thang);
		cb_denngay_nam.GetLBText(d_nam, dn_nam);

		Tim_monan_theo_ngay(ds_monan_tn_tkma, ds_mon_an_all_tkma.tree, t_ngay + 1, t_thang + 1, t_nam + 2000, d_ngay + 1, d_thang + 1, d_nam + 2000);
		if (ds_monan_tn_tkma.soluong > 0)
		{
			if (sx_giam == 0)
			{
				sl_tkma = 0;
				Hien_thi_ds_mon_an_tang(ds_monan_tn_tkma.tree);
			}
			else
			{
				sl_tkma = 0;
				Hien_thi_ds_mon_an_giam(ds_monan_tn_tkma.tree);
			}

		}
		Xoa_cay_mon_an(ds_monan_tn_tkma.tree);
		ds_monan_tn_tkma.soluong = 0;
}


void ThongKeMonAn::OnBnClickedButtonTimkiemtheodongiaTkma()
{
	list_ds_monan_tkma.DeleteAllItems();
	CString str_dongia_tkma;
	edtt_dongia_tkma.GetWindowText(str_dongia_tkma);
	int flag_giatri = 0;
	int giatri_tk = 0;
	if (str_dongia_tkma.Compare(L"") != 0)
	{
		giatri_tk = _tstof(str_dongia_tkma);
	}
	if (giatri_tk != 0)
	{
		Tim_monan_theo_gia(ds_monan_dg_tkma, ds_mon_an_all_tkma.tree, giatri_tk);
		if (ds_monan_dg_tkma.soluong > 0)
		{
			sl_tkma = 0;
			Hien_thi_ds_mon_an_tang(ds_monan_dg_tkma.tree);
		}
		Xoa_cay_mon_an(ds_monan_dg_tkma.tree);
		ds_monan_dg_tkma.soluong = 0;
	}
}


void ThongKeMonAn::OnBnClickedButtonSxtheodongiaTkma()
{
	int sapxep_giam1 = edt_dongia_tkma.GetCurSel();
	if (sapxep_giam1 == 0)
	{
		list_ds_monan_tkma.DeleteAllItems();
		sl_tkma = 0;
		Hien_thi_ds_mon_an_tang(ds_monan_dg1_tkma.tree);
	}
	else if (sapxep_giam1 == 1)
	{
		list_ds_monan_tkma.DeleteAllItems();
		sl_tkma = 0;
		Hien_thi_ds_mon_an_giam(ds_monan_dg1_tkma.tree);
	}
}


void ThongKeMonAn::OnBnClickedButtonLoaimonTkma()
{
	list_ds_monan_tkma.DeleteAllItems();
	CString str_giatri_tk;
	int loaimon_1 = cb_loaimon_tkma.GetCurSel();
	
	Tim_kiem_monan_theo_loai(ds_monan_loai_tkma,ds_mon_an_all_tkma.tree, loaimon_1);
	if (ds_monan_loai_tkma.soluong > 0)
		{
			sl_tkma = 0;
			Hien_thi_ds_mon_an_tang(ds_monan_loai_tkma.tree);
		}
		Xoa_cay_mon_an(ds_monan_loai_tkma.tree);
		ds_monan_loai_tkma.soluong = 0;
}
