#pragma once

#include"ctdl.h"
// QL_KHUYENMAI dialog

class QL_KHUYENMAI : public CDialogEx
{
	DECLARE_DYNAMIC(QL_KHUYENMAI)

public:
	QL_KHUYENMAI(CWnd* pParent = nullptr);   // standard constructor
	virtual ~QL_KHUYENMAI();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QL_KHUYENMAI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual void In_ds_khuyen_mai(DS_KM &ds);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnQlmonanQlkm();
	afx_msg void OnBnClickedBtnQlhdQlkm();
	CEdit edt_makhuyenmai_;
	CEdit edt_tenkhuyenmai_;
	CEdit edt_hsd_;
	CEdit edt_giatri_;
	CListCtrl list_ds_khuyenmai_;
	afx_msg void OnBnClickedBtnThemkmQlkm();
	afx_msg void OnBnClickedBtnLaymaQlkm();
	afx_msg void OnBnClickedBtnCapnhatkmQlkm();
	afx_msg void OnBnClickedBtnXoakmQlkm();
	afx_msg void OnNMClickListDsKhuyenmaiQlkm(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedBtnQltkKm();
	afx_msg void OnBnClickedBtnThongkemonanQlkm();
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CFont Font1, Font2; 
	
	CMFCButton btn_add_;
	CMFCButton btn_update_;
	CMFCButton btn_del_;
	CMFCButton btn_quanli_;
	CMFCButton btn_qlhoadon;
	CMFCButton btn_tkhoadon;
	CMFCButton btn_tkmonan_;
protected:
	CMFCButton btn_layma_voucher_;
};
