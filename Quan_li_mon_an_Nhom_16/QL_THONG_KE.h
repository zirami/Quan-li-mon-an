#pragma once
#include"ctdl.h"
// QL_THONG_KE dialog

class QL_THONG_KE : public CDialogEx
{
	DECLARE_DYNAMIC(QL_THONG_KE)

public:
	QL_THONG_KE(CWnd* pParent = nullptr);   // standard constructor
	virtual ~QL_THONG_KE();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QL_THONG_KE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual void In_danh_sach_HD_TK(DS_HOA_DON& ds, DS_HOA_DON& ds_sdt);
	virtual void Hien_thi_hoa_don(HOA_DON* p);
	virtual void Hien_thi_ds_hoa_don_tang(TREE_HOADON t);
	virtual void Hien_thi_ds_hoa_don_giam(TREE_HOADON t);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnQuanlimonanThongke();
	afx_msg void OnBnClickedBtnQlhoadonThongke();
	afx_msg void OnBnClickedBtnQlkmThongke();
	CListCtrl list_ds_hd_;
	CListCtrl list_tk_hd_;
	CEdit edt_mahoadon_timkiem_tk;
	CComboBox cb_tungay_ngay_;
	CComboBox cb_tungay_thang;
	CComboBox cb_tungay_nam;
	CComboBox cb_denngay_ngay;
	CComboBox cb_denngay_thang;
	CComboBox cb_denngay_nam;
	CEdit edt_tenkhachhang_tk;
	CEdit edt_sdt_tk;
	CEdit edt_giatri_tk;
	afx_msg void OnBnClickedBtnTimkiemTk();
	afx_msg void OnBnClickedBtnTimkiemTheongay();
	afx_msg void OnBnClickedBtnTimkiemTheotenTk();
	afx_msg void OnBnClickedBtnTimtheosdtTk();
	afx_msg void OnBnClickedBtnTimkiemGiatriTk();
	afx_msg void OnBnClickedStaticGroupNgaythangnamTk();
	CComboBox cb_timtheoma_;
	CComboBox cb_timtheothoigian_tk;
	CComboBox cb_timtheosdt_;
	afx_msg void OnBnClickedBtnSapxeptheomaTk();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnSxtheosdtTk();
	CComboBox cb_sxtheogiatri_tk;
	afx_msg void OnBnClickedButtonSxtheogiatriTk();
	CComboBox cb_sxtheoten_tk;
	afx_msg void OnBnClickedButtonSxtheotenkhTk();
	CEdit edt_tinhtonghd_tk;
	CStatic group_ma_tk;
	CBitmap cbitmap_tk;
	afx_msg void OnBnClickedBtnThongkemonanTkma();
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CFont Font1, Font2, Font3;
	
protected:
	CMFCButton btn_tk1_;
	CMFCButton btn_tk2_;
	CMFCButton btn_tk3_;
	CMFCButton btn_tk4_;
	CMFCButton btn_tk5_;
	CMFCButton btn_sx1_;
	CMFCButton btn_sx2_;
	CMFCButton btn_sx3_;
	CMFCButton btn_sx4_;
};
