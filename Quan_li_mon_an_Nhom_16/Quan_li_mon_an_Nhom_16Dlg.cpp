
// Quan_li_mon_an_Nhom_16Dlg.cpp : implementation file
//
//-------------------------
#include "pch.h"
#include "framework.h"
#include "Quan_li_mon_an_Nhom_16.h"
#include "Quan_li_mon_an_Nhom_16Dlg.h"
#include "afxdialogex.h"
//-------------------------
#include"MuaHang.h"
#include"DangNhap.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CQuanlimonanNhom16Dlg dialog



CQuanlimonanNhom16Dlg::CQuanlimonanNhom16Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUAN_LI_MON_AN_NHOM_16_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQuanlimonanNhom16Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTRUE_MUANGAY, picture_monan_);
	DDX_Control(pDX, IDC_BTN_MUANGAY2, btn_muangay_);
	DDX_Control(pDX, IDC_BTN_DANGNHAP, btn_dangnhap_);
}

BEGIN_MESSAGE_MAP(CQuanlimonanNhom16Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_MUANGAY2, &CQuanlimonanNhom16Dlg::OnBnClickedBtnMuangay2)
	ON_BN_CLICKED(IDC_BTN_DANGNHAP, &CQuanlimonanNhom16Dlg::OnBnClickedBtnDangnhap)
	ON_STN_CLICKED(IDC_PICTRUE_MUANGAY, &CQuanlimonanNhom16Dlg::OnStnClickedPictrueMuangay)
END_MESSAGE_MAP()


// CQuanlimonanNhom16Dlg message handlers

BOOL CQuanlimonanNhom16Dlg::OnInitDialog()
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
	//SetIcon(m_hIcon,FALSE);			// Set big icon
	//SetIcon(m_hIcon, FALSE);		// Set small icon

	SetBackgroundImage(IDB_BITMAP4);
	Font1.CreateFont(
		25,                       // nHeight
		20,                        // nWidth
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
		_T("Allstar"));
	GetDlgItem(IDC_BTN_MUANGAY2)->SetFont(&Font1);

	btn_dangnhap_.SetTextColor(RGB(101, 147, 230));
	btn_muangay_.SetTextColor(RGB(0, 0, 0));
	btn_dangnhap_.SetMouseCursorHand();
	btn_muangay_.SetMouseCursorHand();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CQuanlimonanNhom16Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQuanlimonanNhom16Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQuanlimonanNhom16Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CQuanlimonanNhom16Dlg::OnBnClickedBtnMuangay2()
{
	MuaHang mh;
	mh.DoModal();
}


void CQuanlimonanNhom16Dlg::OnBnClickedBtnDangnhap()
{
	DangNhap dn;
	dn.DoModal();
}


void CQuanlimonanNhom16Dlg::OnStnClickedPictrueMuangay()
{
	// TODO: Add your control notification handler code here
}
