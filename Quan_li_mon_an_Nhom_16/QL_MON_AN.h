#pragma once
#include"ctdl.h"
// QL_MON_AN dialog

class QL_MON_AN : public CDialogEx
{
	DECLARE_DYNAMIC(QL_MON_AN)

public:
	QL_MON_AN(CWnd* pParent = nullptr);   // standard constructor
	virtual ~QL_MON_AN();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUAN_LI_MON_AN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual void In_danh_sach(DS_MON_AN& ds);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnQlMonAn();
protected:
	CListCtrl list_mon_an;
public:
	afx_msg void OnBnClickedBtnThem();
protected:
	CEdit edt_mamonan;
	CEdit edt_tenmonan;
	CEdit edt_dongia;
public:
	afx_msg void OnBnClickedBtnLayma();
	afx_msg void OnBnClickedBtnSua();
	afx_msg void OnBnClickedBtnXoa();
	CComboBox combo_loai_mon;
	CComboBox combo_loai_mon_;
	afx_msg void OnCbnSelchangeComboLoaimon();
	afx_msg void OnNMClickListCtrlDsMonAn(NMHDR* pNMHDR, LRESULT* pResult);
protected:
	CEdit edt_soluongcon_;
	CEdit edt_thue_vat;
	
public:
	afx_msg void OnBnClickedBtnQlkmQlmonan();
	afx_msg void OnBnClickedBtnQlthongkeMonan();
	afx_msg void OnBnClickedBtnThongkemonanQlma();
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CFont FontCo, FontTimes;
	
protected:
	
	CMFCButton btn_capnhatmonan_;
	CMFCButton btn_xoamonan_;
	CMFCButton btn_themmonan_;
public:
	CMFCButton btn_layma_;
protected:
	CMFCButton btn_qlhd_qlma_;
	CMFCButton btn_qlkm_qlma_;
	CMFCButton btn_tkhd_qlma_;
	CMFCButton btn_tkma_qlma_;
};
