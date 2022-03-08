// Doimk.cpp : implementation file
#pragma once
//----------------------------
#include "pch.h"
#include "Quan_li_mon_an_Nhom_16.h"
#include "Doimk.h"
#include "afxdialogex.h"
//-----------------------------
#include"xu_li_de.h"
#include"ctdl.h"
// Doimk dialog

IMPLEMENT_DYNAMIC(Doimk, CDialogEx)

Doimk::Doimk(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DOIMK, pParent)
{

}

Doimk::~Doimk()
{
}

BOOL Doimk::OnInitDialog()
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
	SetBackgroundImage(IDB_BITMAP16);
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
	GetDlgItem(IDC_STATIC_T_DOIMK)->SetFont(&Font1);

	GetDlgItem(IDC_STATIC_USERNAME_DMK)->SetFont(&Font2);
	GetDlgItem(IDC_MATKHAUCU_DMK)->SetFont(&Font2);
	GetDlgItem(IDC_MATKHAUMOI_DMK)->SetFont(&Font2);
	GetDlgItem(IDC_MATKHAUMOI2_DMK)->SetFont(&Font2);
	btn_huy_dmk.SetFont(&Font2);
	btn_xacnhan_dmk.SetFont(&Font2);
	return TRUE;
}
HBRUSH	Doimk::OnCtlColor(CDC* pDC, CWnd *pWnd, UINT nCtlColor)
{
    switch (nCtlColor)
    {
    case CTLCOLOR_STATIC:
		pDC->SetBkMode(TRANSPARENT);
        pDC->SetTextColor(RGB(255, 255, 255));
        return (HBRUSH)GetStockObject(NULL_BRUSH);
    default:
        return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
    }
}

void Doimk::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_USERNAME_DMK, edt_tk_dmk);
	DDX_Control(pDX, IDC_EDIT_MATKHACU_DMK, edt_mkc_dmk);
	DDX_Control(pDX, IDC_EDIT_MATKHACU_DMK2, edt_mkm_dmk);
	DDX_Control(pDX, IDC_EDIT_MATKHACU_DMK3, edt_nhaplaimkm_dmk);

	DDX_Control(pDX, IDC_BUTTON_HUY_DMK, btn_huy_dmk);
	DDX_Control(pDX, IDC_BUTTON_XACNHAN_DMK, btn_xacnhan_dmk);
}


BEGIN_MESSAGE_MAP(Doimk, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_MATKHACU_DMK3, &Doimk::OnEnChangeEditMatkhacuDmk3)
	ON_BN_CLICKED(IDC_BUTTON_XACNHAN_DMK, &Doimk::OnBnClickedButtonXacnhanDmk)
	ON_BN_CLICKED(IDC_BUTTON_HUY_DMK, &Doimk::OnBnClickedButtonHuyDmk)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Doimk message handlers


void Doimk::OnEnChangeEditMatkhacuDmk3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Doimk::OnBnClickedButtonXacnhanDmk()
{
	string tk;
	string mk;
	ifstream fi;
	fi.open("TAIKHOAN.TXT", ios_base::in);
	getline(fi, tk);
	Chuan_hoa_chuoi(tk);
	getline(fi, mk);
	Chuan_hoa_chuoi(mk);
	fi.close();
	CString user(tk.c_str(), tk.length());
	CString pass(mk.c_str(), mk.length());

	CString tendn;
	CString mkc;
	CString mkm;
	CString nhaplai;

	edt_tk_dmk.GetWindowText(tendn);
	edt_mkc_dmk.GetWindowText(mkc);
	edt_mkm_dmk.GetWindowText(mkm);
	edt_nhaplaimkm_dmk.GetWindowText(nhaplai);
	
	if (tendn.Compare(_T("")) != 0 && mkc.Compare(_T("")) != 0 && mkm.Compare(_T("")) != 0 && nhaplai.Compare(_T("")) != 0)
	{
		if (user.CompareNoCase(tendn) == 0)
		{
			if (pass.Compare(mkc) == 0)
			{
				if (mkm.Compare(nhaplai) == 0)
				{
					CT2A mkm1(mkm);
					string matkhaumoi(mkm1);
					CT2A tendn1(tendn);
					string tendangnhap(tendn1);
					ofstream fo;
					fo.open("TAIKHOAN.TXT", ios_base::out);
					fo << tendangnhap << endl;
					fo << matkhaumoi;
					fo.close();
					MessageBox(_T("Thay đổi mật khẩu thành công!"), _T("Chúc mừng"), MB_OK | MB_ICONINFORMATION);
					Doimk::OnCancel();
				}
				else
				{
					MessageBox(_T("Nhập lại mật khẩu không chính xác!"), _T("Thông báo"), MB_OK | MB_ICONERROR);
				}
			}
			else
			{
				MessageBox(_T("Mật khẩu hiện tại không đúng!"), _T("Thông báo"), MB_OK | MB_ICONERROR);
			}
		}
		else
		{
			MessageBox(_T("Tên đăng nhập hoặc mật khẩu hiện tại không đúng"), _T("Thông báo"), MB_OK | MB_ICONERROR);
		}
	}
	else
	{
		MessageBox(_T("Vui lòng nhập đầy đủ thông tin"), _T("Thông báo"), MB_OK | MB_ICONERROR);
	}
}


void Doimk::OnBnClickedButtonHuyDmk()
{

	Doimk::OnCancel();
}
