
// FunktionsRechnerDlg.h : header file
//

#pragma once


// CFunktionsRechnerDlg dialog
class CFunktionsRechnerDlg : public CDialogEx
{
// Construction
public:
	CFunktionsRechnerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FUNKTIONSRECHNER_DIALOG };
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
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	CString m_csGrad;
	CString m_csTeil1;
	CString m_csTeil2;
	CString m_csTeil3;
	CString m_csTeil4;
	CString m_csErg;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	CButton m_cbCheck1;
	CButton m_cbCheck2;
	CButton m_cbCheck3;
	CButton m_cbCheck4;
};
