// QL_KHUYENMAI.cpp : implementation file
//
//------------------------
#include "pch.h"
#include "Quan_li_mon_an_Nhom_16.h"
#include "QL_KHUYENMAI.h"
#include "afxdialogex.h"
//------------------------
#include"QL_HOA_DON.h"
#include"QL_MON_AN.h"
#include"QL_THONG_KE.h"
#include"xu_li_de.h"
#include"ThongKeMonAn.h"
#include"ctdl.h"

DS_KM ds_km;
int index_km = 0;

IMPLEMENT_DYNAMIC(QL_KHUYENMAI, CDialogEx)

QL_KHUYENMAI::QL_KHUYENMAI(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QL_KHUYENMAI, pParent)
{

}

QL_KHUYENMAI::~QL_KHUYENMAI()
{
}

BOOL QL_KHUYENMAI::OnInitDialog()
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
	//cbitmap_.LoadBitmap(IDB_BITMAP3);
	//picture_monan_.SetBitmap((HBITMAP)cbitmap_.Detach());

	COLORREF a = RGB(177, 238, 232);
	list_ds_khuyenmai_.SetTextBkColor(a);
	list_ds_khuyenmai_.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	list_ds_khuyenmai_.InsertColumn(0, _T("STT"), LVCFMT_CENTER, 52);
	list_ds_khuyenmai_.InsertColumn(1, _T("Mã khuyến mãi"), LVCFMT_CENTER, 130);
	list_ds_khuyenmai_.InsertColumn(2, _T("Tên khuyến mãi"), LVCFMT_LEFT, 275);
	list_ds_khuyenmai_.InsertColumn(3, _T("Hạn sử dụng"), LVCFMT_LEFT, 170);
	In_ds_khuyen_mai(ds_km);
	SetBackgroundImage(IDB_BITMAP17);
	UpdateData(FALSE);
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
		10,                        // nWidth
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

	GetDlgItem(IDC_STATIC_DS_VOUCHER_QLKM)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_THONGTINVOUCHER_QLKM)->SetFont(&Font1); 

	GetDlgItem(IDC_STATIC_MAVOUCHER_QLKM)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_TENVOUCHER_QLKM)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_HSDVOUCHER_QLKM)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_TRIGIA_QLKM)->SetFont(&Font2);
	btn_add_.SetFont(&Font2);
	btn_update_.SetFont(&Font2);
	btn_del_.SetFont(&Font2);
	btn_layma_voucher_.SetFont(&Font2);
	btn_add_.SetMouseCursorHand(); 
	btn_update_.SetMouseCursorHand(); 
	btn_del_.SetMouseCursorHand();
	btn_layma_voucher_.SetMouseCursorHand();
	btn_qlhoadon.SetFont(&Font2);
	btn_quanli_.SetFont(&Font2); 
	btn_tkhoadon.SetFont(&Font2); 
	btn_tkmonan_.SetFont(&Font2);

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void QL_KHUYENMAI::In_ds_khuyen_mai(DS_KM &ds)
{
	index_km = 0;
	ds.soluong = 0;
	//Hàm này cần đưa vào 1 hàm riêng.
	if (KT_FILE("DS_KHUYEN_MAI.TXT")==1)
	{
		//Doc file cho Interface

		ifstream filein;
		filein.open("DS_KHUYEN_MAI.TXT", ios_base::in);
		rewind(stdin);
		while (filein.eof() != true)
		{
			KM* p = new KM;
			p->p_left = NULL;
			p->p_right = NULL;
			rewind(stdin);
			filein >> p->ma;
			filein.seekg(1, 1);
			getline(filein, p->tenkm, ',');
			Chuan_hoa_chu(p->tenkm);
			getline(filein, p->hsd, ',');
			Chuan_hoa_chuoi(p->hsd);
			filein >> p->giatri;
			Them_1_KM(ds.tree, p);
			ds.soluong++;
			//Tạo mấy thằng đệ
			CString str_makm;
			CString str_giatri;
			str_makm.Format(_T("%d"), p->ma);
			str_giatri.Format(_T("%d"), p->giatri);
			CString soluong;
			soluong.Format(_T("%d"), ds.soluong);
			CString str_tenkm(p->tenkm.c_str(), p->tenkm.length());
			CString str_hsd(p->hsd.c_str(), p->hsd.length());

			list_ds_khuyenmai_.InsertItem(index_km, soluong);
			list_ds_khuyenmai_.SetItemText(index_km, 1, str_makm);
			list_ds_khuyenmai_.SetItemText(index_km, 2, str_tenkm);
			list_ds_khuyenmai_.SetItemText(index_km, 3, str_hsd);
			list_ds_khuyenmai_.SetItemText(index_km, 4, str_giatri);
			index_km++;
		}

		filein.close();

	}
}
void QL_KHUYENMAI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_MAKM_QLKM, edt_makhuyenmai_);
	DDX_Control(pDX, IDC_EDT_TENKM_QLKM, edt_tenkhuyenmai_);
	DDX_Control(pDX, IDC_EDT_HSDKM_QLKM, edt_hsd_);
	DDX_Control(pDX, IDC_EDT_GIATRI_QLKM, edt_giatri_);
	DDX_Control(pDX, IDC_LIST_DS_KHUYENMAI_QLKM, list_ds_khuyenmai_);


	DDX_Control(pDX, IDC_BTN_THEMKM_QLKM, btn_add_);
	DDX_Control(pDX, IDC_BTN_CAPNHATKM_QLKM, btn_update_);
	DDX_Control(pDX, IDC_BTN_XOAKM_QLKM, btn_del_);
	DDX_Control(pDX, IDC_BTN_QLMONAN_QLKM, btn_quanli_);
	DDX_Control(pDX, IDC_BTN_QLHD_QLKM, btn_qlhoadon);
	DDX_Control(pDX, IDC_BTN_QLTK_KM, btn_tkhoadon);
	DDX_Control(pDX, IDC_BTN_THONGKEMONAN_QLKM, btn_tkmonan_);
	DDX_Control(pDX, IDC_BTN_LAYMA_QLKM, btn_layma_voucher_);
}


BEGIN_MESSAGE_MAP(QL_KHUYENMAI, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_QLMONAN_QLKM, &QL_KHUYENMAI::OnBnClickedBtnQlmonanQlkm)
	ON_BN_CLICKED(IDC_BTN_QLHD_QLKM, &QL_KHUYENMAI::OnBnClickedBtnQlhdQlkm)
	ON_BN_CLICKED(IDC_BTN_THEMKM_QLKM, &QL_KHUYENMAI::OnBnClickedBtnThemkmQlkm)
	ON_BN_CLICKED(IDC_BTN_LAYMA_QLKM, &QL_KHUYENMAI::OnBnClickedBtnLaymaQlkm)
	ON_BN_CLICKED(IDC_BTN_CAPNHATKM_QLKM, &QL_KHUYENMAI::OnBnClickedBtnCapnhatkmQlkm)
	ON_BN_CLICKED(IDC_BTN_XOAKM_QLKM, &QL_KHUYENMAI::OnBnClickedBtnXoakmQlkm)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DS_KHUYENMAI_QLKM, &QL_KHUYENMAI::OnNMClickListDsKhuyenmaiQlkm)
	ON_BN_CLICKED(IDC_BTN_QLTK_KM, &QL_KHUYENMAI::OnBnClickedBtnQltkKm)
	ON_BN_CLICKED(IDC_BTN_THONGKEMONAN_QLKM, &QL_KHUYENMAI::OnBnClickedBtnThongkemonanQlkm)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// QL_KHUYENMAI message handlers
HBRUSH QL_KHUYENMAI::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetTextColor(RGB(202,229,232));
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	default:
		return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
}

void QL_KHUYENMAI::OnBnClickedBtnQlmonanQlkm()
{
	QL_KHUYENMAI::OnCancel();
	QL_MON_AN ql;
	ql.DoModal();
}


void QL_KHUYENMAI::OnBnClickedBtnQlhdQlkm()
{
	QL_KHUYENMAI::OnCancel();
	QL_HOA_DON ql;
	ql.DoModal();
}


void QL_KHUYENMAI::OnBnClickedBtnThemkmQlkm()
{
	CString str_makhuyenmai;
	CString str_tenkhuyenmai;
	CString str_hsd;
	CString str_giatri;
	edt_makhuyenmai_.GetWindowText(str_makhuyenmai);
	edt_tenkhuyenmai_.GetWindowText(str_tenkhuyenmai);
	edt_hsd_.GetWindowText(str_hsd);
	edt_giatri_.GetWindowText(str_giatri);
	if (str_makhuyenmai.CompareNoCase(_T("")) != 0 && str_tenkhuyenmai.CompareNoCase(_T("")) != 0 && str_hsd.CompareNoCase(_T("")) != 0 && str_giatri.CompareNoCase(_T("")) != 0)
	{
		CT2A hansd1(str_hsd);
		string hansd(hansd1);
		Chuan_hoa_chuoi(hansd);
		int kt_langay = KT_la_ngay(hansd);

		CT2A giatri1(str_giatri);
		string s_giatri(giatri1);
		int kt_laso = KT_la_so(s_giatri);
		if (kt_langay == 1)
		{
			if(kt_laso==1)
			{
				int kt = KiemTraNgayHopLe(hansd);
				if (kt == 0)
				{
					int makhuyenmai = _tstof(str_makhuyenmai);
					int giatri = _tstof(str_giatri);
					CT2A ten(str_tenkhuyenmai);
					string tenkhuyenmai(ten);
					Chuan_hoa_chu(tenkhuyenmai);

					CT2A han_su_dung(str_hsd);
					string hsd(han_su_dung);
					Chuan_hoa_chuoi(hsd);
					Chuan_ngay_thang_nam(hsd);

					KM* p = new KM;
					p->giatri = giatri;
					p->hsd = hsd;
					p->ma = makhuyenmai;
					p->tenkm = tenkhuyenmai;
					p->p_left = NULL;
					p->p_right = NULL;
					Them_1_KM(ds_km.tree, p);
					ds_km.soluong++;

					ofstream fo;
					fo.open("DS_KHUYEN_MAI.TXT", ios_base::app);
					fo << "\n" << makhuyenmai << ", " << tenkhuyenmai << ", " << hsd << ", " << giatri;
					fo.close();
					CString stt;
					stt.Format(_T("%d"), index_km + 1);
					list_ds_khuyenmai_.InsertItem(index_km, stt);
					list_ds_khuyenmai_.SetItemText(index_km, 1, str_makhuyenmai);
					list_ds_khuyenmai_.SetItemText(index_km, 2, str_tenkhuyenmai);
					list_ds_khuyenmai_.SetItemText(index_km, 3, str_hsd);
					list_ds_khuyenmai_.SetItemText(index_km, 4, str_giatri);
					index_km++;
				}
				else if (kt == 1)
				{
					MessageBox(_T("Ngày không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
				}
				else if (kt == 2)
				{
					MessageBox(_T("Tháng không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
				}
				else if (kt == 3)
				{
					MessageBox(_T("Năm không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
				}
			}
			else
			{
				MessageBox(_T("Giá trị không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
			}
		}
		else
		{
			MessageBox(_T("Ngày tháng năm không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
		}
	}

	else
	{
		MessageBox(_T("Vui lòng nhập dữ liệu!"), _T("Lưu ý"), MB_OK);
	}

	
}


void QL_KHUYENMAI::OnBnClickedBtnLaymaQlkm()
{
	int a = Tao_ma_km(ds_km.tree);
	CString str;
	str.Format(_T("%d"), a);
	edt_makhuyenmai_.SetWindowText(str);
}


void QL_KHUYENMAI::OnBnClickedBtnCapnhatkmQlkm()
{
	CString str_makhuyenmai;
	CString str_tenkhuyenmai;
	CString str_hsd;
	CString str_giatri;
	edt_makhuyenmai_.GetWindowText(str_makhuyenmai);
	edt_tenkhuyenmai_.GetWindowText(str_tenkhuyenmai);
	edt_hsd_.GetWindowText(str_hsd);
	edt_giatri_.GetWindowText(str_giatri);
	CString msb = _T("Bạn muốn cập nhật khuyến mãi có mã: ");
	msb = msb + str_makhuyenmai;
	msb = msb + _T("\n Chọn Yes - Có");
	msb = msb + _T("\n Chọn No - không");


	int Answer = MessageBox(msb, _T("Cập nhật món ăn"), MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2);
	if (Answer == IDYES)
	{
		if (str_makhuyenmai.CompareNoCase(_T("")) != 0 && str_tenkhuyenmai.CompareNoCase(_T("")) != 0 && str_hsd.CompareNoCase(_T("")) != 0 && str_giatri.CompareNoCase(_T("")) != 0)
		{
			CT2A hansd1(str_hsd);
			string hansd(hansd1);
			Chuan_hoa_chuoi(hansd);
			int kt_langay = KT_la_ngay(hansd);
			CT2A giatri1(str_giatri);
			string s_giatri(giatri1);
			int kt_laso = KT_la_so(s_giatri);
			if (kt_langay == 1)
			{
				if (kt_laso == 1)
				{
					int kt = KiemTraNgayHopLe(hansd);
					if (kt == 0)
					{
						int makhuyenmai = _tstof(str_makhuyenmai);
						int giatri = _tstof(str_giatri);
						CT2A ten(str_tenkhuyenmai);
						string tenkhuyenmai(ten);
						Chuan_hoa_chu(tenkhuyenmai);
						CT2A han_su_dung(str_hsd);
						string hsd(han_su_dung);
						Chuan_ngay_thang_nam(hsd);
						Cap_nhat_khuyen_mai(ds_km.tree, makhuyenmai, tenkhuyenmai, giatri, hsd);
						Ghi_file_khuyen_mai(ds_km);
						list_ds_khuyenmai_.DeleteAllItems();
						In_ds_khuyen_mai(ds_km);
						MessageBox(_T("Cập nhật thành công!"), _T("Thông báo"), MB_OK | MB_ICONINFORMATION);
					}
					else if (kt == 1)
					{
						MessageBox(_T("Ngày không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
					}
					else if (kt == 2)
					{
						MessageBox(_T("Tháng không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
					}
					else if (kt == 3)
					{
						MessageBox(_T("Năm không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
					}
				}
				else
				{
					MessageBox(_T("Giá trị không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
				}
			}
			else
			{
				MessageBox(_T("Ngày tháng năm không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
			}
		}
	}
	else if (Answer == IDNO)
	{
		MessageBox(_T("Đã hủy xóa khuyến mãi!"), _T("Thông báo"), MB_OK | MB_ICONWARNING);
	}
}


void QL_KHUYENMAI::OnBnClickedBtnXoakmQlkm()
{
	CString str_makhuyenmai = _T("");
	//Lấy dữ liệu
	edt_makhuyenmai_.GetWindowText(str_makhuyenmai);

	CString msb = _T("Bạn muốn xóa khuyến mãi có mã: ");
	msb = msb + str_makhuyenmai;
	msb = msb + _T("\n Chọn Yes - Có");
	msb = msb + _T("\n Chọn No - không");

	int Answer = MessageBox(msb, _T("Cập nhật món ăn"), MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2);
	if (Answer == IDYES)
	{
		//Để lưu giá trị cần chuyển thành string và int hoặc float
		int makhuyenmai = _tstof(str_makhuyenmai);
		Xoa_khuyen_mai(ds_km.tree, makhuyenmai);
		ds_km.soluong--;
		Ghi_file_khuyen_mai(ds_km);
		list_ds_khuyenmai_.DeleteAllItems();
		In_ds_khuyen_mai(ds_km);
		MessageBox(_T("Xóa thành công!"), _T("Thông báo"), MB_OK | MB_ICONINFORMATION);
	}
	else if (Answer == IDNO)
	{
		MessageBox(_T("Đã hủy xóa khuyến mãi!"), _T("Thông báo"), MB_OK | MB_ICONWARNING);
	}
}


void QL_KHUYENMAI::OnNMClickListDsKhuyenmaiQlkm(NMHDR* pNMHDR, LRESULT* pResult)
{
	int index1_km = -1;
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	if (pNMItemActivate != NULL)
	{
		index1_km = pNMItemActivate->iItem;
	}
	if (index1_km >= 0)
	{
		CString str_makm = list_ds_khuyenmai_.GetItemText(index1_km, 1);
		CString str_tenkm = list_ds_khuyenmai_.GetItemText(index1_km, 2);
		CString str_hsd = list_ds_khuyenmai_.GetItemText(index1_km, 3);
		int makm= _tstof(str_makm);
		KM* p = Tim_kiem_KM(ds_km.tree, makm);
		CString str_giatri;
		str_giatri.Format(_T("%d"), p->giatri);

		edt_makhuyenmai_.SetWindowText(str_makm);
		edt_tenkhuyenmai_.SetWindowText(str_tenkm);
		edt_hsd_.SetWindowText(str_hsd);
		edt_giatri_.SetWindowText(str_giatri);
	}
	*pResult = 0;
}


void QL_KHUYENMAI::OnBnClickedBtnQltkKm()
{
	QL_KHUYENMAI::OnCancel();
	QL_THONG_KE ql;
	ql.DoModal();
}


void QL_KHUYENMAI::OnBnClickedBtnThongkemonanQlkm()
{
	QL_KHUYENMAI::OnCancel();
	ThongKeMonAn ql;
	ql.DoModal();
}
