// QL_MON_AN.cpp : implementation file
//
#pragma once
//----------------------------------
#include "pch.h"
#include "Quan_li_mon_an_Nhom_16.h"
#include "QL_MON_AN.h"
#include "afxdialogex.h"
//----------------------------------
#include"QL_HOA_DON.h"
#include"xu_li_de.h"
#include"ctdl.h"
#include"QL_KHUYENMAI.h"
#include"QL_THONG_KE.h"
#include"ThongKeMonAn.h"
DS_MON_AN ds_mon;
DS_HOA_DON ds_hd_qlma;
int index = 0, sl = 0;


IMPLEMENT_DYNAMIC(QL_MON_AN, CDialogEx)

QL_MON_AN::QL_MON_AN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUAN_LI_MON_AN, pParent)
{

}

QL_MON_AN::~QL_MON_AN()
{
}
BOOL QL_MON_AN::OnInitDialog()
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

	COLORREF a = RGB(177, 238, 232);
	list_mon_an.SetTextBkColor(a);
	list_mon_an.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	list_mon_an.InsertColumn(0, _T("STT"), LVCFMT_CENTER, 50);
	list_mon_an.InsertColumn(1, _T("Mã món ăn"), LVCFMT_CENTER, 100);
	list_mon_an.InsertColumn(2, _T("Tên món ăn"), LVCFMT_CENTER, 300);
	list_mon_an.InsertColumn(3, _T("Loại món"), LVCFMT_CENTER, 100);
	list_mon_an.InsertColumn(4, _T("Đơn giá"), LVCFMT_CENTER, 150);
	list_mon_an.InsertColumn(5, _T("Còn lại"), LVCFMT_CENTER, 100);

	combo_loai_mon_.AddString(_T("Mon khai vi"));
	combo_loai_mon_.AddString(_T("Mon chinh"));
	combo_loai_mon_.AddString(_T("Mon an sang"));
	combo_loai_mon_.AddString(_T("Mon trang mieng"));
	combo_loai_mon_.AddString(_T("Banh - banh ngot"));
	combo_loai_mon_.AddString(_T("Mon chay"));
	combo_loai_mon_.AddString(_T("Mon nhau"));
	combo_loai_mon_.AddString(_T("Mon an cho tre"));
	combo_loai_mon_.AddString(_T("Hai san"));
	combo_loai_mon_.AddString(_T("Nuoc uong"));
	combo_loai_mon_.AddString(_T("khác"));

	edt_thue_vat.SetWindowText(_T("10"));

	In_danh_sach(ds_mon);

	Doc_file_hoa_don(ds_hd_qlma, ds_mon);
	FontCo.CreateFont(
		28,                       // nHeight
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
	FontTimes.CreateFont(
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
	GetDlgItem(IDC_STATIC_DS_MONAN)->SetFont(&FontCo);
	GetDlgItem(IDC_STATIC_TT_MON_AN)->SetFont(&FontCo);

	GetDlgItem(IDC_STATIC_MA_MON_AN)->SetFont(&FontTimes);
	GetDlgItem(IDC_STATIC_LOAIMON)->SetFont(&FontTimes);
	GetDlgItem(IDC_STATIC_TEN_MON_AN)->SetFont(&FontTimes);
	GetDlgItem(IDC_STATIC_DON_GIA)->SetFont(&FontTimes);
	GetDlgItem(IDC_STATIC_SOLUONGTON)->SetFont(&FontTimes);
	GetDlgItem(IDC_STATIC_VAT_)->SetFont(&FontTimes);

	btn_themmonan_.SetFont(&FontTimes);
	btn_capnhatmonan_.SetFont(&FontTimes); 
	btn_xoamonan_.SetFont(&FontTimes);
	btn_layma_.SetFont(&FontTimes);
	btn_capnhatmonan_.SetMouseCursorHand();
	btn_themmonan_.SetMouseCursorHand(); 
	btn_xoamonan_.SetMouseCursorHand(); 
	btn_layma_.SetMouseCursorHand(); 





	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void QL_MON_AN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CTRL_DS_MON_AN, list_mon_an);
	DDX_Control(pDX, IDC_EDT_MA_MON_AN, edt_mamonan);
	DDX_Control(pDX, IDC_EDT_TEN_MON_AN, edt_tenmonan);
	DDX_Control(pDX, IDC_EDT_DONGIA, edt_dongia);
	DDX_Control(pDX, IDC_COMBO_LOAIMON_, combo_loai_mon_);
	DDX_Control(pDX, IDC_EDT_SOLUONGCON, edt_soluongcon_);
	DDX_Control(pDX, IDC_EDT_VAT_10, edt_thue_vat);
	SetBackgroundImage(IDB_BITMAP16);
	DDX_Control(pDX, IDC_BTN_SUA, btn_capnhatmonan_);
	DDX_Control(pDX, IDC_BTN_XOA, btn_xoamonan_);
	DDX_Control(pDX, IDC_BTN_THEM, btn_themmonan_);
	DDX_Control(pDX, IDC_BTN_LAYMA, btn_layma_);
	DDX_Control(pDX, IDC_BTN_QL_MON_AN, btn_qlhd_qlma_);
	DDX_Control(pDX, IDC_BTN_QLKM_QLMONAN, btn_qlkm_qlma_);
	DDX_Control(pDX, IDC_BTN_QLTHONGKE_MONAN, btn_tkhd_qlma_);
	DDX_Control(pDX, IDC_BTN_THONGKEMONAN_QLMA, btn_tkma_qlma_);
}

HBRUSH QL_MON_AN::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	default:
		return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
}



void QL_MON_AN::In_danh_sach(DS_MON_AN& ds)
{
	index=0;
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
			ds.soluong++; sl++;
			//Tạo mấy thằng đệ
			CString str_mamonan1;
			CString str_loaimon;
			CString str_dongia1;
			CString str_sl_ton;
			str_sl_ton.Format(_T("%d"), p->sl_ton);
			CString soluong;
			soluong.Format(_T("%d"), ds.soluong);
			combo_loai_mon_.GetLBText(p->loaimon, str_loaimon);

			str_mamonan1.Format(_T("%d"), p->ma);
			CString str_tenmonan1(p->ten_mon.c_str(), p->ten_mon.length());
			str_dongia1.Format(_T("%d"), p->dongia);
			list_mon_an.InsertItem(index, soluong);
			list_mon_an.SetItemText(index, 1, str_mamonan1);
			list_mon_an.SetItemText(index, 2, str_tenmonan1);
			list_mon_an.SetItemText(index, 3, str_loaimon);
			list_mon_an.SetItemText(index, 4, str_dongia1);
			list_mon_an.SetItemText(index, 5, str_sl_ton);
			index++;
		}

		filein.close();

	}
}

BEGIN_MESSAGE_MAP(QL_MON_AN, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_QL_MON_AN, &QL_MON_AN::OnBnClickedBtnQlMonAn)
	ON_BN_CLICKED(IDC_BTN_THEM, &QL_MON_AN::OnBnClickedBtnThem)
	ON_BN_CLICKED(IDC_BTN_LAYMA, &QL_MON_AN::OnBnClickedBtnLayma)
	ON_BN_CLICKED(IDC_BTN_SUA, &QL_MON_AN::OnBnClickedBtnSua)
	ON_BN_CLICKED(IDC_BTN_XOA, &QL_MON_AN::OnBnClickedBtnXoa)
	ON_CBN_SELCHANGE(IDC_COMBO_LOAIMON_, &QL_MON_AN::OnCbnSelchangeComboLoaimon)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL_DS_MON_AN, &QL_MON_AN::OnNMClickListCtrlDsMonAn)
	ON_BN_CLICKED(IDC_BTN_QLKM_QLMONAN, &QL_MON_AN::OnBnClickedBtnQlkmQlmonan)
	ON_BN_CLICKED(IDC_BTN_QLTHONGKE_MONAN, &QL_MON_AN::OnBnClickedBtnQlthongkeMonan)
	ON_BN_CLICKED(IDC_BTN_THONGKEMONAN_QLMA, &QL_MON_AN::OnBnClickedBtnThongkemonanQlma)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// QL_MON_AN message handlers

void QL_MON_AN::OnBnClickedBtnQlMonAn()
{
	QL_MON_AN::OnCancel();
	QL_HOA_DON hd;
	hd.DoModal();
}


void QL_MON_AN::OnBnClickedBtnThem()
{
	CString str_mamonan = _T("");
	CString str_tenmonan = _T("");
	CString str_dongia = _T("");
	CString str_sl_ton = _T("");
	int loaimon;
	string ngaylap = laytime();
	//Lấy dữ liệu
	edt_mamonan.GetWindowText(str_mamonan);
	edt_tenmonan.GetWindowText(str_tenmonan);
	edt_dongia.GetWindowText(str_dongia);
	edt_soluongcon_.GetWindowText(str_sl_ton);
	loaimon=combo_loai_mon_.GetCurSel();
	if (str_mamonan.CompareNoCase(_T("")) != 0 && str_tenmonan.CompareNoCase(_T("")) != 0 && str_dongia.CompareNoCase(_T("")) != 0&& loaimon>=0)
	{
		CT2A ct(str_tenmonan);
		string tenmon(ct);
		Chuan_hoa_chu(tenmon);

		CT2A dongia1(str_dongia);
		string dongia(dongia1);
		int kt_laso = KT_la_so(dongia);
		if(kt_laso==1)
		{
			int dongia = _tstof(str_dongia);
			if (dongia > 0)
			{

				//Để lưu giá trị cần chuyển thành string và int hoặc float
				int mamonan = _tstof(str_mamonan);

				dongia += dongia * 0.1;
				str_dongia.Format(_T("%d"), dongia);
				int sl_ton = _tstof(str_sl_ton);


				//Thêm vào cây;
				MON_AN* p = Khoi_tao_node_mon_an();
				p->ma = mamonan;
				p->ten_mon = tenmon;
				p->loaimon = loaimon;
				p->dongia = dongia;
				p->trangthai = 0;
				p->sl_ton = sl_ton;
				p->ngaythang = ngaylap;
				Them_mon_an(ds_mon.tree, p);
				sl++;

				//Lưu vào file
				ofstream fileout;
				fileout.open("DS_MON_AN.TXT", ios_base::app);
				fileout << "\n" << mamonan;
				fileout << ", ";
				fileout << tenmon << ", ";
				fileout << ngaylap << ", ";
				fileout << loaimon << ", ";
				fileout << dongia << ", ";
				fileout << 0 << ", ";
				fileout << sl_ton;
				fileout.close();
				CString str_tenmonan1(tenmon.c_str(), tenmon.length());
				//Hiển thị
				CString soluong;
				soluong.Format(_T("%d"), sl);
				CString str_loaimon;
				combo_loai_mon_.GetLBText(loaimon, str_loaimon);
				list_mon_an.InsertItem(index, soluong);
				list_mon_an.SetItemText(index, 1, str_mamonan);
				list_mon_an.SetItemText(index, 2, str_tenmonan1);
				list_mon_an.SetItemText(index, 3, str_loaimon);
				list_mon_an.SetItemText(index, 4, str_dongia);
				list_mon_an.SetItemText(index, 5, str_sl_ton);
				index++;
			}
			else
			{
				MessageBox(_T("Đơn giá phải lớn hơn 0!"), _T("Lưu ý"), MB_OK | MB_ICONERROR);
			}
		}
		else
		{
			MessageBox(_T("Đơn giá phải là số!"), _T("Lưu ý"), MB_OK | MB_ICONERROR);
		}
	}
}


void QL_MON_AN::OnBnClickedBtnLayma()
{
	int ma = Tao_ma_mon_an(ds_mon.tree);
	CString mamonan;
	mamonan.Format(_T("%d"), ma);
	edt_mamonan.SetWindowText(mamonan);
}


void QL_MON_AN::OnBnClickedBtnSua()
{
	CString str_mamonan = _T("");
	CString str_tenmonan = _T("");
	CString str_dongia = _T("");
	CString str_sl_ton = _T("");

	edt_mamonan.GetWindowText(str_mamonan);
	CString msb = _T("Bạn muốn sửa món ăn có mã: ");
	msb = msb + str_mamonan;
	msb = msb + _T("\n Chọn Yes - Sửa món ăn và những hóa đơn liên quan.");
	msb = msb + _T("\n Chọn No - Không sửa món ăn và những hóa đơn liên quan.");
	

	int Answer = MessageBox(msb, _T("Cập nhật món ăn"), MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2);
	if (Answer == IDYES)
	{

		int loai;
		//Lấy dữ liệu
		
		edt_tenmonan.GetWindowText(str_tenmonan);
		edt_dongia.GetWindowText(str_dongia);
		edt_soluongcon_.GetWindowText(str_sl_ton);
		loai = combo_loai_mon_.GetCurSel();
		//Để lưu giá trị cần chuyển thành string và int hoặc float
		if (str_mamonan.CompareNoCase(_T("")) != 0 && str_tenmonan.CompareNoCase(_T("")) != 0 && str_dongia.CompareNoCase(_T("")) != 0 && loai >= 0 && str_sl_ton.CompareNoCase(_T("")) != 0)
		{

			CT2A dongia1(str_dongia);
			string dongia(dongia1);
			int kt_laso = KT_la_so(dongia);
			if (kt_laso == 1)
			{
				int dongia = _tstof(str_dongia);
				if (dongia > 0)
				{
					int mamonan = _tstof(str_mamonan);
					int dongia = _tstof(str_dongia);
					dongia += dongia * 0.1;
					str_dongia.Format(_T("%d"), dongia);
					int sl_ton = _tstof(str_sl_ton);
					CT2A ct(str_tenmonan);
					string tenmon(ct);
					Chuan_hoa_chu(tenmon);
					Cap_nhat_mon_an(ds_mon.tree, mamonan, tenmon, dongia, loai, sl_ton);
					Ghi_file_mon_an(ds_mon);
					list_mon_an.DeleteAllItems();
					In_danh_sach(ds_mon);
					MessageBox(_T("Cập nhật thành công!"), _T("Thông báo"), MB_OK | MB_ICONINFORMATION);
				}
				else
				{
					MessageBox(_T("Đơn giá phải lớn hơn 0!"), _T("Lưu ý"), MB_OK | MB_ICONERROR);
				}
			}
			else
			{
				MessageBox(_T("Đơn giá phải là số!"), _T("Lưu ý"), MB_OK | MB_ICONERROR);
			}
		}
	}
	else if (Answer == IDNO)
	{
		MessageBox(_T("Đã hủy cập nhật món ăn!"), _T("Thông báo"), MB_OK | MB_ICONWARNING);
	}
	
}


void QL_MON_AN::OnBnClickedBtnXoa()
{

	CString str_mamonan = _T("");
	CString msb = _T("Bạn muốn xóa món ăn có mã: ");

	edt_mamonan.GetWindowText(str_mamonan);

	msb = msb + str_mamonan;
	msb = msb + _T("\n Chọn Yes - Xóa món ăn và những hóa đơn liên quan.");
	msb = msb + _T("\n Chọn No - Không xóa món ăn và những hóa đơn liên quan.");
	
	int Answer = MessageBox(msb, _T("Xóa món ăn"), MB_YESNO| MB_ICONWARNING | MB_DEFBUTTON2);
	if (Answer == IDYES)
	{
		//Để lưu giá trị cần chuyển thành string và int hoặc float
		int mamonan = _tstof(str_mamonan);
		//Xóa những hóa đơn chứa món ăn
		int flag = 0;
		do
		{
			HOA_DON* h = new HOA_DON;
			h->pleft = NULL;
			h->pright = NULL;
			Tim_hd_theo_ma_mon_an(ds_hd_qlma.tree, mamonan,h);
			if (h != NULL)
			{
				HOA_DON* p = Tim_kiem_hoa_don(ds_hd_qlma.tree, h->mahoadon);
				if (p != NULL)
				{
					Xoa_hoa_don(ds_hd_qlma.tree, p->mahoadon);
					flag = 1;
				}
				else
				{
					flag = 0;
				}
			}

		} while (flag==1);
		//Cập nhật cây hóa đơn vào file
		Ghi_file_hoa_don(ds_hd_qlma);
		//Xóa cây hóa đơn
		Xoa_cay_hd(ds_hd_qlma.tree);
		ds_hd_qlma.soluong = 0;
		//Đọc cây hóa đơn lại
		Doc_file_hoa_don(ds_hd_qlma, ds_mon);

		Xoa_mon_an(ds_mon.tree, mamonan);
		ds_mon.soluong--;
		Ghi_file_mon_an(ds_mon);
		list_mon_an.DeleteAllItems();
		In_danh_sach(ds_mon);
		MessageBox(_T("Xóa thành công!"), _T("Thông báo"), MB_OK | MB_ICONINFORMATION);
	}
	else if (Answer == IDNO)
	{
		MessageBox(_T("Đã hủy xóa món ăn!"), _T("Thông báo"), MB_OK | MB_ICONWARNING);
	}
}


void QL_MON_AN::OnCbnSelchangeComboLoaimon()
{
	// TODO: Add your control notification handler code here
}


void QL_MON_AN::OnNMClickListCtrlDsMonAn(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	int index_item = 0;
	if (pNMItemActivate != NULL)
	{
		index_item = pNMItemActivate->iItem;
	}
	if (index_item >= 0)
	{
		CString ma = list_mon_an.GetItemText(index_item, 1);
		CString ten = list_mon_an.GetItemText(index_item, 2);
		CString str_loai = list_mon_an.GetItemText(index_item, 3);
		CString gia = list_mon_an.GetItemText(index_item, 4);
		CString str_sl_ton= list_mon_an.GetItemText(index_item, 5);
		//con loai mon an nua.
		int loai = _tstof(str_loai);
		combo_loai_mon_.SelectString(loai, str_loai);
		edt_mamonan.SetWindowText(ma);
		edt_tenmonan.SetWindowText(ten);
		edt_dongia.SetWindowText(gia);
		edt_soluongcon_.SetWindowText(str_sl_ton);
	}
	*pResult = 0;
}



void QL_MON_AN::OnBnClickedBtnQlkmQlmonan()
{
	QL_MON_AN::OnCancel();
	QL_KHUYENMAI ql;
	ql.DoModal();
}


void QL_MON_AN::OnBnClickedBtnQlthongkeMonan()
{
	QL_MON_AN::OnCancel();
	QL_THONG_KE ql;
	ql.DoModal();
}


void QL_MON_AN::OnBnClickedBtnThongkemonanQlma()
{
	QL_MON_AN::OnCancel();
	ThongKeMonAn ql;
	ql.DoModal();
}
