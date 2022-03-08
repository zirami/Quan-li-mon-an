#pragma once
#include"ctdl.h"

// QL_HOA_DON dialog

class QL_HOA_DON : public CDialogEx
{
	DECLARE_DYNAMIC(QL_HOA_DON)

public:
	QL_HOA_DON(CWnd* pParent = nullptr);   // standard constructor
	virtual ~QL_HOA_DON();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUAN_LI_HOA_DON };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual void In_danh_sach_HD(DS_HOA_DON& ds);
	virtual void Hien_thi_ds_mon(TREE_MON_AN t);
	virtual void Hien_thi_mon(MON_AN* p);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnQlMonan();
	CEdit edt_qlhd_ma;
	CEdit edt_qlhd_ngaylap;
	CEdit edt_qlhd_hoten;
	CEdit edt_qlhd_diachi;
	CEdit edt_qlhd_magiamgia;
	CListCtrl list_ds_hoa_don_qlhd;
	CListCtrl list_ds_mon_an_qlhd;
	CEdit edt_tong_qlhd;
	CComboBox combo_loai_mon_qlhd;
	afx_msg void OnLvnItemchangedListDsQlhd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMClickListDsQlhd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedBtnQlKhuyenmaiQlhd();
	CEdit edt_qlhd_sdt;
	afx_msg void OnBnClickedBtnQltkHd();
	afx_msg void OnBnClickedBtnChinhsuahdQlhd();
	afx_msg void OnBnClickedBtnXoahdQlhd();
	afx_msg void OnBnClickedBtnThongkemonanQlhd();
	CFont Font1,Font2;
	HBRUSH	OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
