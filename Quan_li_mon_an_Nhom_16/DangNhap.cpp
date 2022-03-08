// DangNhap.cpp : implementation file
#pragma once
//-------------------------
#include "pch.h"
#include "Quan_li_mon_an_Nhom_16.h"
#include "DangNhap.h"
#include "afxdialogex.h"
//-------------------------
#include"QL_MON_AN.h"
#include"xu_li_de.h"
#include"ctdl.h"
#include"Doimk.h"

// DangNhap dialog

IMPLEMENT_DYNAMIC(DangNhap, CDialogEx)

DangNhap::DangNhap(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_DANGNHAP, pParent)
{

}

DangNhap::~DangNhap()
{
}
BOOL DangNhap::OnInitDialog()
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

	SetBackgroundImage(IDB_BITMAP1);

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void DangNhap::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_USERNAME, edt_username);
	DDX_Control(pDX, IDC_EDT_PASSWORD, edt_password);
	DDX_Control(pDX, IDC_BTN_LOGIN, m_mybutton);
	DDX_Control(pDX, IDC_BUTTON_DOIMATKHAU, btn_doimatkhau_);
	SetBackgroundImage(IDB_BITMAP5);
	Font1.CreateFont(
		30,                       // nHeight
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
		_T("Cooper"));
	Font2.CreateFont(
		24,                       // nHeight
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
		_T("Cooper"));
	GetDlgItem(IDC_STATIC_TENDANGNHAP)->SetFont(&Font1);
	GetDlgItem(IDC_STATIC_MATKHAU)->SetFont(&Font1);
	GetDlgItem(IDC_EDT_USERNAME)->SetFont(&Font1);
	m_mybutton.SetFont(&Font2); 
	m_mybutton.SetTextColor(RGB(101,147,230));
	btn_doimatkhau_.SetTextColor(RGB(101, 147, 230));
	btn_doimatkhau_.SetFont(&Font2);
	m_mybutton.SetMouseCursorHand();
	btn_doimatkhau_.SetMouseCursorHand();
}

HBRUSH DangNhap::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

BEGIN_MESSAGE_MAP(DangNhap, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &DangNhap::OnBnClickedBtnLogin)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_DOIMATKHAU, &DangNhap::OnBnClickedButtonDoimatkhau)
END_MESSAGE_MAP()


// DangNhap message handlers


void DangNhap::OnBnClickedBtnLogin()
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
	CString user(tk.c_str(),tk.length());
	CString pass(mk.c_str(),mk.length());
	CString username;
	CString password;
	edt_username.GetWindowText(username);
	edt_password.GetWindowText(password);
	if (user.CompareNoCase(username) == 0)
	{
		if (pass.Compare(password) == 0)
		{
			DangNhap::OnCancel();
			QL_MON_AN ql;
			ql.DoModal();
		}
		else
		{
			MessageBox(_T("Mật khẩu không đúng!"), _T("Đăng nhập thất bại"), MB_OK | MB_ICONQUESTION);
		}
	}
	else
	{
		MessageBox(_T("Tên đăng nhập hoặc mật khẩu không đúng"), _T("Đăng nhập thất bại"), MB_OK | MB_ICONQUESTION);
	}
}


void DangNhap::OnBnClickedButtonDoimatkhau()
{
	Doimk ql;
	ql.DoModal();
}
