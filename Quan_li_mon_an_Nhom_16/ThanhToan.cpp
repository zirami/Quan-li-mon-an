// ThanhToan.cpp : implementation file
//
//-----------------------------------
#include "pch.h"
#include "Quan_li_mon_an_Nhom_16.h"
#include "ThanhToan.h"
#include "afxdialogex.h"
//-------------------------------------
#include"xu_li_de.h"
#include"MuaHang.h"

// ThanhToan dialog
DS_MON_AN ds_ma_tt;
HOA_DON* p;
IMPLEMENT_DYNAMIC(ThanhToan, CDialogEx)

ThanhToan::ThanhToan(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_THANHTOANHD_TT, pParent)
{

}

ThanhToan::~ThanhToan()
{
}
BOOL ThanhToan::OnInitDialog()
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
	Xoa_cay_mon_an(ds_ma_tt.tree);
	ds_ma_tt.soluong = 0;
	Doc_file_mon_an(ds_ma_tt);
	ifstream fi;
	fi.open("HOA_DON_TAM.TXT", ios_base::in);
	while (fi.eof() != true)
	{

		p = new HOA_DON;
		p->pleft = NULL;
		p->pright = NULL;
		fi >> p->mahoadon;
		fi.seekg(1, 1);
		getline(fi, p->ngaylap, ',');
		getline(fi, p->hoten, ',');
		getline(fi, p->diachi, ',');
		getline(fi, p->sdt, ',');
		fi >> p->tongtien;
		Chuan_hoa_chu(p->hoten);
		Chuan_hoa_chu(p->diachi);
		Chuan_hoa_chuoi(p->ngaylap);
		Chuan_hoa_chuoi(p->sdt);
		string s_tongtien = Int_sang_string(p->tongtien);
		s_tongtien = giatien(s_tongtien);
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
			t = Tim_kiem_mon_an(ds_ma_tt.tree, t->ma);
			fi >> t->soluong;
			t->pleft = NULL;
			t->pright = NULL;
			fi.seekg(1, 1);
			Them_mon_an(p->ds.tree, t);
			p->ds.soluong++;
			fi >> x;
			fi.seekg(-1, 1);
		} while (x != 'e');
		fi.seekg(1, 1);
		fi.ignore();
		//sl1++;
		//Tạo mấy thằng đệ
		CString str_mahoadon;
		CString str_ten(p->hoten.c_str(), p->hoten.length());
		CString str_sdt(p->sdt.c_str(), p->sdt.length());
		str_mahoadon.Format(_T("%d"), p->mahoadon);
		CString str_ngaylap(p->ngaylap.c_str(), p->ngaylap.length());
		CString str_diachi(p->diachi.c_str(), p->diachi.length());
		CString str_tong(s_tongtien.c_str(), s_tongtien.length());
		CString str_magiamgia;
		str_magiamgia.Format(_T("%d"), p->magiamgia);
		edt_sohoadon_tt.SetWindowText(str_mahoadon);
		edt_hoten_tt.SetWindowText(str_ten);
		edt_ngaylap_tt.SetWindowText(str_ngaylap);
		edt_diachi_tt.SetWindowText(str_diachi);
		edt_sdt_tt.SetWindowText(str_sdt);
		edt_magiamgia_tt.SetWindowText(str_magiamgia);
		edt_tongtien_tt.SetWindowText(str_tong);
	}
	fi.close();
	
	radio_tttienmat_.SetCheck(1);
	edt_sothetindung_.EnableWindow(0);
	edt_tenchuthe_tt.EnableWindow(0);
	edt_ngayhethan_tt.EnableWindow(0);
	edt_cvv_tt.EnableWindow(0);
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void ThanhToan::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SHD_TT, edt_sohoadon_tt);
	DDX_Control(pDX, IDC_EDIT_NGAYLAP_TT, edt_ngaylap_tt);
	DDX_Control(pDX, IDC_EDIT_HOTEN_TT, edt_hoten_tt);
	DDX_Control(pDX, IDC_EDIT_DIACHI_TT, edt_diachi_tt);
	DDX_Control(pDX, IDC_EDIT_SDT_TT, edt_sdt_tt);
	DDX_Control(pDX, IDC_EDIT_MAGIAMGIA_TT, edt_magiamgia_tt);
	DDX_Control(pDX, IDC_EDIT_TONGGIATRI_TT, edt_tongtien_tt);
	DDX_Control(pDX, IDC_RADIO_TTSKNH_TT, radio_tttienmat_);
	DDX_Control(pDX, IDC_RADIO_TTSKNH_TT2, radio_ttbangthe_);
	DDX_Control(pDX, IDC_BUTTON_HUY_TT, btn_huy_);
	DDX_Control(pDX, IDC_BUTTON_XACDINH_TT, btn_xacnhan_tt);
	DDX_Control(pDX, IDC_EDIT_SOTHE_TT, edt_sothetindung_);
	DDX_Control(pDX, IDC_EDIT_TENTRENTHE_TT, edt_tenchuthe_tt);
	DDX_Control(pDX, IDC_EDIT_NGAYHETHAN_TT, edt_ngayhethan_tt);
	DDX_Control(pDX, IDC_EDIT_MACVV_TT, edt_cvv_tt);
	SetBackgroundImage(IDB_BITMAP20);
	Font1.CreateFont(
		35,                       // nHeight
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
		_T("Times New Roman"));            // lpszFacename 

	GetDlgItem(IDC_STATIC_THONGTINHD_TT)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_THANHTOAN_TT)->SetFont(&Font1);
	
	GetDlgItem(IDC_STATIC_MAHD_TT)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_NGAYLAPHD_TT)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_KH_TT)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_DIACHI_TT)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_SDT_TT)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_MAGIAMGIA_TT)->SetFont(&Font2);
	GetDlgItem(IDC_STATIC_TONGIATRI_TT)->SetFont(&Font2);
	btn_huy_.SetFont(&Font2); 
	btn_xacnhan_tt.SetFont(&Font2);
	radio_ttbangthe_.SetFont(&Font2);
	radio_tttienmat_.SetFont(&Font2);

}
HBRUSH ThanhToan::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetTextColor(RGB(255, 255,255));
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	default:
		return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
}


BEGIN_MESSAGE_MAP(ThanhToan, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_TTSKNH_TT2, &ThanhToan::OnBnClickedRadioTtsknhTt2)
	ON_BN_CLICKED(IDC_RADIO_TTSKNH_TT, &ThanhToan::OnBnClickedRadioTtsknhTt)
	ON_BN_CLICKED(IDC_BUTTON_HUY_TT, &ThanhToan::OnBnClickedButtonHuyTt)
	ON_BN_CLICKED(IDC_BUTTON_XACDINH_TT, &ThanhToan::OnBnClickedButtonXacdinhTt)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// ThanhToan message handlers


void ThanhToan::OnBnClickedRadioTtsknhTt2()
{
	radio_tttienmat_.SetCheck(0);
	edt_sothetindung_.EnableWindow(1);
	edt_tenchuthe_tt.EnableWindow(1);
	edt_ngayhethan_tt.EnableWindow(1);
	edt_cvv_tt.EnableWindow(1);

}


void ThanhToan::OnBnClickedRadioTtsknhTt()
{
	
	radio_ttbangthe_.SetCheck(0);
	edt_sothetindung_.EnableWindow(0);
	edt_tenchuthe_tt.EnableWindow(0);
	edt_ngayhethan_tt.EnableWindow(0);
	edt_cvv_tt.EnableWindow(0);
}


void ThanhToan::OnBnClickedButtonHuyTt()
{
	Tang_so_luong_ton_cay_mon_an(ds_ma_tt.tree, p->ds.tree);
	Ghi_file_mon_an(ds_ma_tt);
	ThanhToan::OnCancel();
	MuaHang mh;
	mh.DoModal();

}


void ThanhToan::OnBnClickedButtonXacdinhTt()
{
	int flag = radio_ttbangthe_.GetCheck();
	if (flag == 1)
	{
		CString masothe;
		CString tenthe;
		CString ngayhethan;
		CString CVV;
		edt_sothetindung_.GetWindowText(masothe);
		edt_tenchuthe_tt.GetWindowText(tenthe);
		edt_ngayhethan_tt.GetWindowText(ngayhethan);
		edt_cvv_tt.GetWindowText(CVV);
	
		if (masothe.Compare(_T("")) != 0 && tenthe.Compare(_T("")) != 0 && ngayhethan.Compare(_T("")) != 0 && CVV.Compare(_T("")) != 0)
		{
			CT2A ngayhet_han1(ngayhethan);
			string ngay_hethan(ngayhet_han1);
			CT2A sothe1(masothe);
			string sothe(sothe1);
			int kt = KiemTraNgayHopLe(ngay_hethan);
			int ktsothe = KTsothe(sothe);
			if (ktsothe == 1)
			{
				if (kt == 0)
				{
					ofstream fo;
					fo.open("DS_HOA_DON.TXT", ios_base::app);
					fo << "\n" << p->mahoadon << ", " << p->ngaylap << ", " << p->hoten << ", " << p->diachi << ", " << p->sdt << ", " << p->tongtien << ", " << p->magiamgia << ", ";
					Xuat_ds_mon_an_hd(p->ds.tree, fo);
					fo << "e";
					fo.close();
					MessageBox(_T("Đặt hàng thành công!"), _T("Cảm ơn Quý khách"), MB_ICONINFORMATION | MB_OK);
					ThanhToan::OnCancel();
					MuaHang mh;
					mh.DoModal();
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
				MessageBox(_T("Số thẻ không hợp lệ!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
			}
		}
		else
		{
			MessageBox(_T("Bạn phải nhập dữ liệu thẻ tín dụng trước khi xác nhận!"), _T("Lưu ý"), MB_ICONINFORMATION | MB_OK);
		}
		
	
	}
	else 
	{
		ofstream fo;
		fo.open("DS_HOA_DON.TXT", ios_base::app);
		fo << "\n" << p->mahoadon << ", " << p->ngaylap << ", " << p->hoten << ", " << p->diachi << ", " << p->sdt << ", " << p->tongtien << ", " << p->magiamgia << ", ";
		Xuat_ds_mon_an_hd(p->ds.tree, fo);
		fo << "e";
		fo.close();
		MessageBox(_T("Đặt hàng thành công!"), _T("Cảm ơn Quý khách"), MB_ICONINFORMATION | MB_OK);
		ThanhToan::OnCancel();
	}
	

}
