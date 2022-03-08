#pragma once


// DangNhap dialog

class DangNhap : public CDialogEx
{
	DECLARE_DYNAMIC(DangNhap)

public:
	DangNhap(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DangNhap();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DANGNHAP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	CEdit edt_username;
	CEdit edt_password;
public:
	afx_msg void OnBnClickedBtnLogin();
	CStatic picture_dn_;
	CMFCButton m_mybutton;
	CFont Font1,Font2;
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButtonDoimatkhau();
	CMFCButton btn_doimatkhau_;
};
