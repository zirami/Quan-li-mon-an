#pragma once
#include"ctdl.h"

// MuaHang dialog

class MuaHang : public CDialogEx 
{
	DECLARE_DYNAMIC(MuaHang)

public:
	MuaHang(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MuaHang();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MUAHANG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	 void In_danh_sach(DS_MON_AN& ds);
	 void Hien_thi_mon(MON_AN* p);
	 void Hien_thi_1_mon(MON_AN* p);
	 void Hien_thi_ds_mon(TREE_MON_AN t);
	 void Hien_thi_ds_mon_giam(TREE_MON_AN t);
	 void Hien_thi_ds_mon_tang(TREE_MON_AN t);
	DECLARE_MESSAGE_MAP()
	CListCtrl list_ds_mon;

public:
	CComboBox combo_loai_mon_an;
	CListCtrl list_ds_mon_an_user;
	
	afx_msg void OnNMClickListViewDsMonAn(NMHDR* pNMHDR, LRESULT* pResult);
protected:
	CEdit edt_mahoadon;
	CEdit edt_ngaylap;
public:
	afx_msg void OnNMClickListCtrlDsMonanUser(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedBtnDathang();
protected:
	CEdit edt_hoten_;
	CEdit edt_diachi_;
	CEdit edt_sdt_;
	CEdit edt_tongthanhtoan_;
	CEdit edt_magiamgia_;
public:
	afx_msg void OnEnChangeEdtSdtUser();
	afx_msg void OnEnChangeEdtTongthanhtoan();
	CButton btn_lay_ma_mh;
	afx_msg void OnBnClickedBtnTimKiem();
	CComboBox combo_sxmonan_mh;
	afx_msg void OnBnClickedBtnHienthiDsMonanMh();
	CFont Font1,Font2;
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBitmap c_bitmap_mh;
	CMFCButton btn_muahang_;
};
