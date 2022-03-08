#pragma once

#include"ctdl.h"
#include"xu_li_de.h"
// ThongKeMonAn dialog

class ThongKeMonAn : public CDialogEx
{
	DECLARE_DYNAMIC(ThongKeMonAn)

public:
	ThongKeMonAn(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ThongKeMonAn();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual	BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual void In_danh_sach_ma(DS_MON_AN& ds);
	virtual void Hien_thi_mon_an(MON_AN* p);
	virtual void Hien_thi_ds_mon_an_tang(TREE_MON_AN t);
	virtual void Hien_thi_ds_mon_an_giam(TREE_MON_AN t);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnQlmonanTkma();
	afx_msg void OnBnClickedBtnQlhoadonTkma();
	afx_msg void OnBnClickedBtnQlkmTkma();
	afx_msg void OnBnClickedBtnTkhdTkma();
	CListCtrl list_ds_monan_all;
	CListCtrl list_ds_monan_tkma;
	CComboBox combo_loaimon_tkma_;
	afx_msg void OnStnClickedStaticDsmonanTkma();
	CComboBox cb_sxntn_tkma;
	CComboBox cb_tungay_ngay;
	CComboBox cb_tungay_thang;
	CComboBox cb_tungay_nam;
	CComboBox cb_denngay_ngay;
	CComboBox cb_denngay_thang;
	CComboBox cb_denngay_nam;
	afx_msg void OnBnClickedBtnTimkiemTkma();
	CEdit edtt_dongia_tkma;
	CComboBox edt_dongia_tkma;
	CMFCButton btn_timkiemtheodongia_tkma;
	afx_msg void OnBnClickedButtonTimkiemtheodongiaTkma();
	afx_msg void OnBnClickedButtonSxtheodongiaTkma();
	CComboBox cb_loaimon_tkma;
	afx_msg void OnBnClickedButtonLoaimonTkma();
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CFont Font1,Font2;
protected:
	CMFCButton btn_tk1_;
	CMFCButton btn_sx1_;
	CMFCButton btn_tk2_;
};
