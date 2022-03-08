// QL_THONG_KE.cpp : implementation file
#pragma once
//----------------------------
#include "pch.h"
#include "Quan_li_mon_an_Nhom_16.h"
#include "QL_THONG_KE.h"
#include "afxdialogex.h"
//----------------------------
#include"xu_li_de.h"
#include"QL_HOA_DON.h"
#include"QL_KHUYENMAI.h"
#include"QL_MON_AN.h"
#include"ThongKeMonAn.h"

DS_MON_AN ds_mon_tk;
DS_HOA_DON ds_hd_tk;
DS_HOA_DON ds_hd_ma_tk;
DS_HOA_DON ds_hd_ngay_tk;
DS_HOA_DON ds_hd_ten_tk;
DS_HOA_DON ds_hd_sdt_tk;
DS_HOA_DON ds_hd_giatri_tk;

DS_HOA_DON ds_sdt_tk;
DS_HOA_DON ds_giatri_tk;
DS_HOA_DON ds_ten_tk;

int index_tk = 0;
int sl_tk = 0;
// QL_THONG_KE dialog

IMPLEMENT_DYNAMIC(QL_THONG_KE, CDialogEx)

QL_THONG_KE::QL_THONG_KE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QL_THONG_KE, pParent)
{

}

QL_THONG_KE::~QL_THONG_KE()
{
}

BOOL QL_THONG_KE::OnInitDialog()
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
	cbitmap_tk.LoadBitmap(IDB_BITMAP3);
	group_ma_tk.SetBitmap((HBITMAP)cbitmap_tk.Detach());

	Xoa_cay_hd(ds_hd_tk.tree);
	ds_hd_tk.soluong = 0;

	Xoa_cay_hd(ds_hd_ma_tk.tree);
	ds_hd_ma_tk.soluong = 0;

	Xoa_cay_hd(ds_hd_tk.tree);
	ds_hd_tk.soluong = 0;

	Xoa_cay_hd(ds_hd_ten_tk.tree);
	ds_hd_ten_tk.soluong = 0;

	Xoa_cay_hd(ds_hd_sdt_tk.tree);
	ds_hd_sdt_tk.soluong = 0;

	Xoa_cay_hd(ds_hd_giatri_tk.tree);
	ds_hd_giatri_tk.soluong = 0;

	Xoa_cay_hd(ds_sdt_tk.tree);
	ds_sdt_tk.soluong = 0;

	Xoa_cay_hd(ds_giatri_tk.tree);
	ds_giatri_tk.soluong = 0;

	Xoa_cay_hd(ds_ten_tk.tree);
	ds_ten_tk.soluong = 0;
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	/*combo_loai_mon_qlhd.AddString(_T("Dinh duong"));
	combo_loai_mon_qlhd.AddString(_T("Ga"));
	combo_loai_mon_qlhd.AddString(_T("Hai san"));*/
	cb_timtheoma_.AddString(_T("Tăng dần"));
	cb_timtheoma_.AddString(_T("Giảm dần"));
	cb_timtheoma_.SetCurSel(0);

	cb_timtheothoigian_tk.AddString(_T("Tăng dần"));
	cb_timtheothoigian_tk.AddString(_T("Giảm dần"));
	cb_timtheothoigian_tk.SetCurSel(0);

	cb_timtheosdt_.AddString(_T("Tăng dần"));
	cb_timtheosdt_.AddString(_T("Giảm dần"));
	cb_timtheosdt_.SetCurSel(0);

	cb_sxtheogiatri_tk.AddString(_T("Tăng dần"));
	cb_sxtheogiatri_tk.AddString(_T("Giảm dần"));
	cb_sxtheogiatri_tk.SetCurSel(0);

	cb_sxtheoten_tk.AddString(_T("Tăng dần"));
	cb_sxtheoten_tk.AddString(_T("Giảm dần"));
	cb_sxtheoten_tk.SetCurSel(0);

	COLORREF a = RGB(177, 238, 232);
	list_ds_hd_.SetTextBkColor(a);
	list_ds_hd_.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	list_ds_hd_.InsertColumn(0, _T("STT"), LVCFMT_CENTER, 150);
	list_ds_hd_.InsertColumn(1, _T("Mã hóa đơn"), LVCFMT_CENTER, 150);
	list_ds_hd_.InsertColumn(2, _T("Tên khách hàng"), LVCFMT_LEFT, 300);
	list_ds_hd_.InsertColumn(3, _T("Số điện thoại"), LVCFMT_CENTER, 150);
	list_ds_hd_.InsertColumn(4, _T("Giá tiền"), LVCFMT_RIGHT, 120);
	Doc_file_mon_an(ds_mon_tk);
	In_danh_sach_HD_TK(ds_hd_tk,ds_sdt_tk);
	list_tk_hd_.SetTextBkColor(a);
	list_tk_hd_.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	list_tk_hd_.InsertColumn(0, _T("STT"), LVCFMT_CENTER, 50);
	list_tk_hd_.InsertColumn(1, _T("Mã HĐ"), LVCFMT_CENTER, 100);
	list_tk_hd_.InsertColumn(2, _T("Ngày lập"), LVCFMT_CENTER, 150);
	list_tk_hd_.InsertColumn(3, _T("Tên khách hàng"), LVCFMT_LEFT, 210);
	list_tk_hd_.InsertColumn(4, _T("Địa chỉ"), LVCFMT_CENTER, 150);
	list_tk_hd_.InsertColumn(5, _T("Số điện thoại"), LVCFMT_CENTER, 120);
	list_tk_hd_.InsertColumn(6, _T("Giá tiền"), LVCFMT_RIGHT, 110);
	//dành cho combo box
	CString str_ngay;
	for (int i = 1; i <= 31; i++)
	{
		str_ngay.Format(L"%d", i);
		cb_tungay_ngay_.AddString(str_ngay);
		cb_denngay_ngay.AddString(str_ngay);
	}
	cb_tungay_ngay_.SetCurSel(0);
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
	//design
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
		23,                       // nHeight
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
	Font3.CreateFont(
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


	GetDlgItem(IDC_STATIC_DS_HOA_DON_TK)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_THONGKEHOADONTHEOTIMMKIEM_THONGKE)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_TINHTONGHD_TK)->SetFont(&Font1);

	GetDlgItem(IDC_STATIC_TKTM)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_TKTG)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_NGAYTHANGNAM_TU_NGAY_THONGKE)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_DENNGAY_NGAYTHANGNAM_TK)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_DENNGAY_TK)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_TKTKH)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_TKSDT)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_TKGTDH)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_TUNGAY_THONGKE)->SetFont(&Font2);

	btn_sx1_.SetFont(&Font3);
	btn_sx2_.SetFont(&Font3);
	btn_sx3_.SetFont(&Font3);
	btn_sx4_.SetFont(&Font3);
	btn_tk1_.SetFont(&Font3);
	btn_tk2_.SetFont(&Font3);
	btn_tk3_.SetFont(&Font3);
	btn_tk4_.SetFont(&Font3);
	btn_tk5_.SetFont(&Font3);

	btn_sx1_.SetMouseCursorHand();
	btn_sx2_.SetMouseCursorHand();
	btn_sx3_.SetMouseCursorHand();
	btn_sx4_.SetMouseCursorHand();
	btn_tk1_.SetMouseCursorHand();
	btn_tk2_.SetMouseCursorHand();
	btn_tk3_.SetMouseCursorHand();
	btn_tk4_.SetMouseCursorHand();
	btn_tk5_.SetMouseCursorHand();

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void QL_THONG_KE::In_danh_sach_HD_TK(DS_HOA_DON& ds,DS_HOA_DON& ds_sdt)
{
	index_tk = 0;
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
			getline(fi, p->hoten, ',');
			Chuan_hoa_chu(p->hoten);
			getline(fi, p->diachi, ',');
			getline(fi, p->sdt, ',');
			p->sdt.erase(p->sdt.begin() + 0);
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
				t = Tim_kiem_mon_an(ds_mon_tk.tree, t->ma);
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

			HOA_DON* p1 = new HOA_DON;
			p1->diachi = p->diachi;
			p1->ds = p->ds;
			p1->hoten = p->hoten;
			p1->magiamgia = p->magiamgia;
			p1->mahoadon = p->mahoadon;
			p1->ngaylap = p->ngaylap;
			p1->pleft = p->pleft;
			p1->pright = p->pright;
			p1->sdt = p->sdt;
			p1->tongtien = p->tongtien;
			Them_hoa_don_theo_sdt(ds_sdt.tree, p1);
			ds_sdt.tongtien += p1->tongtien;
			ds_sdt.soluong++;

			HOA_DON* p2 = new HOA_DON;
			p2->diachi = p->diachi;
			p2->ds = p->ds;
			p2->hoten = p->hoten;
			p2->magiamgia = p->magiamgia;
			p2->mahoadon = p->mahoadon;
			p2->ngaylap = p->ngaylap;
			p2->pleft = p->pleft;
			p2->pright = p->pright;
			p2->sdt = p->sdt;
			p2->tongtien = p->tongtien;
			Them_hoa_don_theo_gia_tri(ds_giatri_tk.tree, p2);
			ds_giatri_tk.soluong++;
			ds_giatri_tk.tongtien += p2->tongtien;

			HOA_DON* p3 = new HOA_DON;
			p3->diachi = p->diachi;
			p3->ds = p->ds;
			p3->hoten = p->hoten;
			p3->magiamgia = p->magiamgia;
			p3->mahoadon = p->mahoadon;
			p3->ngaylap = p->ngaylap;
			p3->pleft = p->pleft;
			p3->pright = p->pright;
			p3->sdt = p->sdt;
			p3->tongtien = p->tongtien;
			Them_hoa_don_theo_ten(ds_ten_tk.tree, p3);
			ds_ten_tk.soluong++;
			ds_ten_tk.tongtien += p3->tongtien;

			fi.seekg(1, 1);
			fi.ignore();
			ds.soluong++;
			ds.tongtien += p->tongtien;//sl1++;
			//Tạo mấy thằng đệ
			CString str_mahoadon;
			CString str_ten(p->hoten.c_str(), p->hoten.length());
			CString str_sdt(p->sdt.c_str(), p->sdt.length());
			CString soluong;
			soluong.Format(_T("%d"), ds.soluong);
			str_mahoadon.Format(_T("%d"), p->mahoadon);

			string str_giatri = Int_sang_string(p->tongtien);
			str_giatri = giatien(str_giatri);
			CString giatien(str_giatri.c_str(),str_giatri.length());
			list_ds_hd_.InsertItem(index_tk, soluong);
			list_ds_hd_.SetItemText(index_tk, 1, str_mahoadon);
			list_ds_hd_.SetItemText(index_tk, 2, str_ten);
			list_ds_hd_.SetItemText(index_tk, 3, str_sdt);
			list_ds_hd_.SetItemText(index_tk, 4, giatien);
			index_tk++;
		}

		fi.close();

	}
}
void QL_THONG_KE::Hien_thi_hoa_don(HOA_DON* p)
{
	CString soluong;
	soluong.Format(_T("%d"), sl_tk + 1);
	CString ma;
	ma.Format(_T("%d"), p->mahoadon);
	CString ten(p->hoten.c_str(), p->hoten.length());
	CString ngaylap(p->ngaylap.c_str(), p->ngaylap.length());
	CString diachi(p->diachi.c_str(), p->diachi.length());
	CString sdt(p->sdt.c_str(), p->sdt.length());
	string str_giatri = Int_sang_string(p->tongtien);
	str_giatri = giatien(str_giatri);
	CString giatri(str_giatri.c_str(),str_giatri.length());
	list_tk_hd_.InsertItem(sl_tk, soluong);
	list_tk_hd_.SetItemText(sl_tk, 1, ma);
	list_tk_hd_.SetItemText(sl_tk, 2, ngaylap);
	list_tk_hd_.SetItemText(sl_tk, 3, ten);
	list_tk_hd_.SetItemText(sl_tk, 4, diachi);
	list_tk_hd_.SetItemText(sl_tk, 5, sdt);
	list_tk_hd_.SetItemText(sl_tk, 6, giatri);
	sl_tk++;
}
void QL_THONG_KE::Hien_thi_ds_hoa_don_tang(TREE_HOADON t)
{
	if (t != NULL)
	{
		Hien_thi_ds_hoa_don_tang(t->pleft);
		Hien_thi_hoa_don(t);
		Hien_thi_ds_hoa_don_tang(t->pright);
	}
}
void QL_THONG_KE::Hien_thi_ds_hoa_don_giam(TREE_HOADON t)
{
	if (t != NULL)
	{
		Hien_thi_ds_hoa_don_giam(t->pright);
		Hien_thi_hoa_don(t);
		Hien_thi_ds_hoa_don_giam(t->pleft);
		
	}
}
void QL_THONG_KE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DS_HOADON_THONGKE, list_ds_hd_);
	DDX_Control(pDX, IDC_LIST_DS_HOADON_TIMKIEM_THONGKE, list_tk_hd_);
	DDX_Control(pDX, IDC_EDT_MA_THONGKE, edt_mahoadon_timkiem_tk);
	DDX_Control(pDX, IDC_COMBO_TUNGAY_NGAY_THONGKE, cb_tungay_ngay_);
	DDX_Control(pDX, IDC_COMBO_TUNGAY_THANG_TK, cb_tungay_thang);
	DDX_Control(pDX, IDC_COMBO_TUNGAY_NAM_TK, cb_tungay_nam);
	DDX_Control(pDX, IDC_COMBO_DENNGAY_NGAY_TK, cb_denngay_ngay);
	DDX_Control(pDX, IDC_COMBO_DENNGAY_THANG_TK, cb_denngay_thang);
	DDX_Control(pDX, IDC_COMBO_DENNGAY_NAM_TK, cb_denngay_nam);
	DDX_Control(pDX, IDC_EDIT_TENKH_TK, edt_tenkhachhang_tk);
	DDX_Control(pDX, IDC_EDT_SDT_TK, edt_sdt_tk);
	DDX_Control(pDX, IDC_EDT_GIATRI_TK, edt_giatri_tk);
	DDX_Control(pDX, IDC_COMBO_TIMTHEOMA_TK, cb_timtheoma_);
	DDX_Control(pDX, IDC_COMBO_TIMTHEOTHOIGIAN_TK, cb_timtheothoigian_tk);
	DDX_Control(pDX, IDC_COMBO_TIMTHEOSDT_TK, cb_timtheosdt_);
	DDX_Control(pDX, IDC_COMBO_SXTHEOGIATRI_TK, cb_sxtheogiatri_tk);
	DDX_Control(pDX, IDC_COMBO_SXTHEOTENKH_TK, cb_sxtheoten_tk);
	DDX_Control(pDX, IDC_EDT_TINHTONGHD_TK, edt_tinhtonghd_tk);
	DDX_Control(pDX, IDC_STATIC_GROUP_MA_TK, group_ma_tk);
	SetBackgroundImage(IDB_BITMAP19);
	DDX_Control(pDX, IDC_BTN_SAPXEPTHEOMA_TK, btn_sx1_);
	DDX_Control(pDX, IDC_BTN_TIMKIEM_TK, btn_tk1_);
	DDX_Control(pDX, IDC_BTN_TIMKIEM_THEONGAY, btn_tk2_);
	DDX_Control(pDX, IDC_BTN_TIMKIEM_THEOTEN_TK, btn_tk3_);
	DDX_Control(pDX, IDC_BTN_TIMTHEOSDT_TK, btn_tk4_);
	DDX_Control(pDX, IDC_BTN_TIMKIEM_GIATRI_TK, btn_tk5_);
	DDX_Control(pDX, IDC_BUTTON_SXTHEOTENKH_TK, btn_sx2_);
	DDX_Control(pDX, IDC_BTN_SXTHEOSDT_TK, btn_sx3_);
	DDX_Control(pDX, IDC_BUTTON_SXTHEOGIATRI_TK, btn_sx4_);
}


BEGIN_MESSAGE_MAP(QL_THONG_KE, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_QUANLIMONAN_THONGKE, &QL_THONG_KE::OnBnClickedBtnQuanlimonanThongke)
	ON_BN_CLICKED(IDC_BTN_QLHOADON_THONGKE, &QL_THONG_KE::OnBnClickedBtnQlhoadonThongke)
	ON_BN_CLICKED(IDC_BTN_QLKM_THONGKE, &QL_THONG_KE::OnBnClickedBtnQlkmThongke)
	ON_BN_CLICKED(IDC_BTN_TIMKIEM_TK, &QL_THONG_KE::OnBnClickedBtnTimkiemTk)
	ON_BN_CLICKED(IDC_BTN_TIMKIEM_THEONGAY, &QL_THONG_KE::OnBnClickedBtnTimkiemTheongay)
	ON_BN_CLICKED(IDC_BTN_TIMKIEM_THEOTEN_TK, &QL_THONG_KE::OnBnClickedBtnTimkiemTheotenTk)
	ON_BN_CLICKED(IDC_BTN_TIMTHEOSDT_TK, &QL_THONG_KE::OnBnClickedBtnTimtheosdtTk)
	ON_BN_CLICKED(IDC_BTN_TIMKIEM_GIATRI_TK, &QL_THONG_KE::OnBnClickedBtnTimkiemGiatriTk)
	ON_BN_CLICKED(IDC_STATIC_GROUP_NGAYTHANGNAM_TK, &QL_THONG_KE::OnBnClickedStaticGroupNgaythangnamTk)
	ON_BN_CLICKED(IDC_BTN_SAPXEPTHEOMA_TK, &QL_THONG_KE::OnBnClickedBtnSapxeptheomaTk)
	ON_BN_CLICKED(IDOK, &QL_THONG_KE::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_SXTHEOSDT_TK, &QL_THONG_KE::OnBnClickedBtnSxtheosdtTk)
	ON_BN_CLICKED(IDC_BUTTON_SXTHEOGIATRI_TK, &QL_THONG_KE::OnBnClickedButtonSxtheogiatriTk)
	ON_BN_CLICKED(IDC_BUTTON_SXTHEOTENKH_TK, &QL_THONG_KE::OnBnClickedButtonSxtheotenkhTk)
	ON_BN_CLICKED(IDC_BTN_THONGKEMONAN_TKMA, &QL_THONG_KE::OnBnClickedBtnThongkemonanTkma)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()
HBRUSH QL_THONG_KE::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	default:
		return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
}

// QL_THONG_KE message handlers


void QL_THONG_KE::OnBnClickedBtnQuanlimonanThongke()
{
	QL_THONG_KE::OnCancel();
	QL_MON_AN ql;
	ql.DoModal();
}



void QL_THONG_KE::OnBnClickedBtnQlhoadonThongke()
{
	QL_THONG_KE::OnCancel();
	QL_HOA_DON ql;
	ql.DoModal();
}


void QL_THONG_KE::OnBnClickedBtnQlkmThongke()
{
	QL_THONG_KE::OnCancel();
	QL_KHUYENMAI ql;
	ql.DoModal();
}


void QL_THONG_KE::OnBnClickedBtnTimkiemTk()
{
	list_tk_hd_.DeleteAllItems();
	CString str_ma_tk;
	edt_mahoadon_timkiem_tk.GetWindowText(str_ma_tk);
	int flag_ma=0;
	int ma_tk = 0;
	if (str_ma_tk.Compare(L"") != 0)
	{
		ma_tk= _tstof(str_ma_tk);
		flag_ma = 1;
	}

	HOA_DON* p = Tim_kiem_hoa_don(ds_hd_tk.tree,ma_tk);
	if(p!=NULL)
	{
		list_tk_hd_.DeleteAllItems();
		sl_tk = 0;
		Hien_thi_hoa_don(p);
		string s_tinhtong = Int_sang_string(p->tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(),s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	else
	{
		CString tongtienhd_tk = _T("0");
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}


	



}


void QL_THONG_KE::OnBnClickedBtnTimkiemTheongay()
{
	list_tk_hd_.DeleteAllItems();
	ds_hd_ngay_tk.tongtien = 0;
	edt_tinhtonghd_tk.SetWindowText(_T("0"));

	CString tn_ngay;
	CString tn_thang;
	CString tn_nam;
	CString dn_ngay;
	CString dn_thang;
	CString dn_nam;

	int t_ngay, t_thang, t_nam, d_ngay, d_thang, d_nam;
	int sx_giam = cb_timtheothoigian_tk.GetCurSel();

	t_ngay = cb_tungay_ngay_.GetCurSel(); // ngay 6 ---> t_ngay ==5
	t_thang = cb_tungay_thang.GetCurSel();
	t_nam = cb_tungay_nam.GetCurSel();
	d_ngay = cb_denngay_ngay.GetCurSel();
	d_thang = cb_denngay_thang.GetCurSel();
	d_nam = cb_denngay_nam.GetCurSel();
	cb_tungay_ngay_.GetLBText(t_ngay, tn_ngay); // ngay 6 --> tn_ngay ==6
	cb_tungay_thang.GetLBText(t_thang, tn_thang);
	cb_tungay_nam.GetLBText(t_nam, tn_nam);
	cb_denngay_ngay.GetLBText(d_ngay, dn_ngay);
	cb_denngay_thang.GetLBText(d_thang, dn_thang);
	cb_denngay_nam.GetLBText(d_nam, dn_nam);

	Tim_Kiem_theo_ngay(ds_hd_ngay_tk, ds_hd_tk.tree, t_ngay + 1, t_thang + 1, t_nam + 2000, d_ngay + 1, d_thang + 1, d_nam + 2000);
	if (ds_hd_ngay_tk.soluong > 0)
	{
		if(sx_giam==0)
		{
			sl_tk = 0;
			Hien_thi_ds_hoa_don_tang(ds_hd_ngay_tk.tree);

			string s_tinhtong = Int_sang_string(ds_hd_ngay_tk.tongtien);
			s_tinhtong = giatien(s_tinhtong);
			CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
			edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
		}
		else
		{
			sl_tk = 0;
			Hien_thi_ds_hoa_don_giam(ds_hd_ngay_tk.tree);
			string s_tinhtong = Int_sang_string(ds_hd_ngay_tk.tongtien);
			s_tinhtong = giatien(s_tinhtong);
			CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
			edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
		}
		
	}
	Xoa_cay_hd(ds_hd_ngay_tk.tree);
	ds_hd_ngay_tk.soluong = 0;
	
}


void QL_THONG_KE::OnBnClickedBtnTimkiemTheotenTk()
{
	list_tk_hd_.DeleteAllItems();
	ds_hd_ten_tk.tongtien = 0;
	edt_tinhtonghd_tk.SetWindowTextW(_T("0"));

	CString str_ten_tk;
	edt_tenkhachhang_tk.GetWindowText(str_ten_tk);

	//int flag_ten = 0;
	string ten_tk;
	if (str_ten_tk.Compare(L"") != 0)
	{
		CT2A ten_(str_ten_tk);
		string ten_tk1(ten_);
		Chuan_hoa_chu(ten_tk1);
		ten_tk = ten_tk1;
	}
	Tim_kiem_theo_ten(ds_hd_ten_tk, ds_hd_tk.tree, ten_tk);
	if (ds_hd_ten_tk.soluong > 0)
	{
		sl_tk = 0;
		Hien_thi_ds_hoa_don_tang(ds_hd_ten_tk.tree);

		string s_tinhtong = Int_sang_string(ds_hd_ten_tk.tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	Xoa_cay_hd(ds_hd_ten_tk.tree);
	ds_hd_ten_tk.soluong = 0;
}
void QL_THONG_KE::OnBnClickedBtnTimtheosdtTk()
{
	list_tk_hd_.DeleteAllItems();
	CString str_sdt_tk;
	edt_sdt_tk.GetWindowText(str_sdt_tk);
	edt_tinhtonghd_tk.SetWindowText(_T("0"));
	ds_hd_sdt_tk.tongtien = 0;

	string sdt_tk;
	if (str_sdt_tk.Compare(L"") != 0)
	{
		CT2A sdt_(str_sdt_tk);
		string sdt_tk1(sdt_);
		Chuan_hoa_chu(sdt_tk1);
		sdt_tk = sdt_tk1;
	}
	Tim_kiem_theo_sdt(ds_hd_sdt_tk, ds_hd_tk.tree, sdt_tk);
	if (ds_hd_sdt_tk.soluong > 0)
	{
		sl_tk = 0;
		Hien_thi_ds_hoa_don_tang(ds_hd_sdt_tk.tree);

		string s_tinhtong = Int_sang_string(ds_hd_sdt_tk.tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	Xoa_cay_hd(ds_hd_sdt_tk.tree);
	ds_hd_sdt_tk.soluong = 0;
}
void QL_THONG_KE::OnBnClickedBtnTimkiemGiatriTk()
{
	list_tk_hd_.DeleteAllItems();
	CString str_giatri_tk;
	ds_hd_giatri_tk.tongtien = 0;
	edt_tinhtonghd_tk.SetWindowText(_T("0"));
	edt_giatri_tk.GetWindowText(str_giatri_tk);
	int flag_giatri = 0;
	int giatri_tk = 0;
	if (str_giatri_tk.Compare(L"") != 0)
	{
		giatri_tk = _tstof(str_giatri_tk);
	}
	if (giatri_tk != 0)
	{
		Tim_kiem_hd_theo_gia_tri(ds_hd_giatri_tk, ds_giatri_tk.tree, giatri_tk);
		if (ds_hd_giatri_tk.soluong > 0)
		{
			sl_tk = 0;
			Hien_thi_ds_hoa_don_tang(ds_hd_giatri_tk.tree);

			string s_tinhtong = Int_sang_string(ds_hd_giatri_tk.tongtien);
			s_tinhtong = giatien(s_tinhtong);
			CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
			edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
		}
		Xoa_cay_hd(ds_hd_giatri_tk.tree);
		ds_hd_giatri_tk.soluong = 0;
	}
}
void QL_THONG_KE::OnBnClickedStaticGroupNgaythangnamTk()
{
	// TODO: Add your control notification handler code here
}
void QL_THONG_KE::OnBnClickedBtnSapxeptheomaTk()
{
	int sapxep_giam = cb_timtheoma_.GetCurSel();
	if (sapxep_giam == 0)
	{
		list_tk_hd_.DeleteAllItems();
		sl_tk = 0;
		Hien_thi_ds_hoa_don_tang(ds_hd_tk.tree);

		string s_tinhtong = Int_sang_string(ds_hd_tk.tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	else if (sapxep_giam == 1)
	{
		list_tk_hd_.DeleteAllItems();
		sl_tk = 0;
		Hien_thi_ds_hoa_don_giam(ds_hd_tk.tree);

		string s_tinhtong = Int_sang_string(ds_hd_tk.tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	/*Xoa_cay_hd(ds_hd_ma_tk.tree);
	ds_hd_ma_tk.soluong = 0;*/
}
void QL_THONG_KE::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
void QL_THONG_KE::OnBnClickedBtnSxtheosdtTk()
{
	int sapxep_giam = cb_timtheosdt_.GetCurSel();
	if (sapxep_giam == 0)
	{
		list_tk_hd_.DeleteAllItems();
		sl_tk = 0;
		Hien_thi_ds_hoa_don_tang(ds_sdt_tk.tree);
		string s_tinhtong = Int_sang_string(ds_sdt_tk.tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	else if (sapxep_giam == 1)
	{
		list_tk_hd_.DeleteAllItems();
		sl_tk = 0;
		Hien_thi_ds_hoa_don_giam(ds_sdt_tk.tree);
		string s_tinhtong = Int_sang_string(ds_sdt_tk.tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	/*Xoa_cay_hd(ds_sdt_tk.tree);
	ds_sdt_tk.soluong = 0;*/
}
void QL_THONG_KE::OnBnClickedButtonSxtheogiatriTk()
{
	int sapxep_giam1 = cb_sxtheogiatri_tk.GetCurSel();
	if (sapxep_giam1 == 0)
	{
		list_tk_hd_.DeleteAllItems();
		sl_tk = 0;
		Hien_thi_ds_hoa_don_tang(ds_giatri_tk.tree);

		string s_tinhtong = Int_sang_string(ds_giatri_tk.tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	else if (sapxep_giam1 == 1)
	{
		list_tk_hd_.DeleteAllItems();
		sl_tk = 0;
		Hien_thi_ds_hoa_don_giam(ds_giatri_tk.tree);

		string s_tinhtong = Int_sang_string(ds_giatri_tk.tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	/*Xoa_cay_hd(ds_giatri_tk.tree);
	ds_giatri_tk.soluong = 0;*/
}
void QL_THONG_KE::OnBnClickedButtonSxtheotenkhTk()
{
	int sx_giam = cb_sxtheoten_tk.GetCurSel();
	if (sx_giam == 0)
	{
		list_tk_hd_.DeleteAllItems();
		sl_tk = 0;
		Hien_thi_ds_hoa_don_tang(ds_ten_tk.tree);
		
		string s_tinhtong = Int_sang_string(ds_ten_tk.tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	else if(sx_giam==1)
	{
		list_tk_hd_.DeleteAllItems();
		sl_tk = 0;
		Hien_thi_ds_hoa_don_giam(ds_ten_tk.tree);
		
		string s_tinhtong = Int_sang_string(ds_ten_tk.tongtien);
		s_tinhtong = giatien(s_tinhtong);
		CString tongtienhd_tk(s_tinhtong.c_str(), s_tinhtong.length());
		edt_tinhtonghd_tk.SetWindowText(tongtienhd_tk);
	}
	/*Xoa_cay_hd(ds_ten_tk.tree);
	ds_ten_tk.soluong = 0;*/
}
void QL_THONG_KE::OnBnClickedBtnThongkemonanTkma()
{
	QL_THONG_KE::OnCancel();
	ThongKeMonAn ql;
	ql.DoModal();

}
