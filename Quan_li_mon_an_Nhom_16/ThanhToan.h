#pragma once


// ThanhToan dialog

class ThanhToan : public CDialogEx
{
	DECLARE_DYNAMIC(ThanhToan)

public:
	ThanhToan(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ThanhToan();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_THANHTOANHD_TT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit edt_sohoadon_tt;
	CEdit edt_ngaylap_tt;
	CEdit edt_hoten_tt;
	CEdit edt_diachi_tt;
	CEdit edt_sdt_tt;
	CEdit edt_magiamgia_tt;
	CEdit edt_tongtien_tt;
	CButton radio_tttienmat_;
	CButton radio_ttbangthe_;
	afx_msg void OnBnClickedRadioTtsknhTt2();
	afx_msg void OnBnClickedRadioTtsknhTt();
	CMFCButton btn_huy_;
	CMFCButton btn_xacnhan_tt;
	afx_msg void OnBnClickedButtonHuyTt();
	afx_msg void OnBnClickedButtonXacdinhTt();
	CEdit edt_sothetindung_;
	CEdit edt_tenchuthe_tt;
	CEdit edt_ngayhethan_tt;
	CEdit edt_cvv_tt;
protected:
	CStatic bmp_logo_;
	CFont Font1, Font2;
	
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
