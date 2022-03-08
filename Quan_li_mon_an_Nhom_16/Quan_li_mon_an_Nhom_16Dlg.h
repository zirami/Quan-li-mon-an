
// Quan_li_mon_an_Nhom_16Dlg.h : header file
//

#pragma once


// CQuanlimonanNhom16Dlg dialog
class CQuanlimonanNhom16Dlg : public CDialogEx
{
// Construction
public:
	CQuanlimonanNhom16Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUAN_LI_MON_AN_NHOM_16_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnMuangay2();
	afx_msg void OnBnClickedBtnDangnhap();
protected:
	CBitmap cbitmap_;
	CStatic picture_monan_;
public:
	afx_msg void OnStnClickedPictrueMuangay();
	CFont Font1;
	CMFCButton btn_muangay_;
	CMFCButton btn_dangnhap_;
};
