#pragma once


// Doimk dialog

class Doimk : public CDialogEx
{
	DECLARE_DYNAMIC(Doimk)

public:
	Doimk(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Doimk();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOIMK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CEdit edt_tk_dmk;
	CEdit edt_mkc_dmk;
	CEdit edt_mkm_dmk;
	afx_msg void OnEnChangeEditMatkhacuDmk3();
	CEdit edt_nhaplaimkm_dmk;
	afx_msg void OnBnClickedButtonXacnhanDmk();
	afx_msg void OnBnClickedButtonHuyDmk();
	CFont Font1, Font2 ;
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	CMFCButton btn_huy_dmk;
	CMFCButton btn_xacnhan_dmk;
};
