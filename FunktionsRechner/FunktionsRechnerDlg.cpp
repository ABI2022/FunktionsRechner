
// FunktionsRechnerDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "FunktionsRechner.h"
#include "FunktionsRechnerDlg.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFunktionsRechnerDlg dialog



CFunktionsRechnerDlg::CFunktionsRechnerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FUNKTIONSRECHNER_DIALOG, pParent)
	, m_csGrad(_T(""))
	, m_csTeil1(_T(""))
	, m_csTeil2(_T(""))
	, m_csTeil3(_T(""))
	, m_csTeil4(_T(""))
	, m_csErg(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFunktionsRechnerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEIL1, m_csTeil1);
	DDX_Text(pDX, IDC_TEIL2, m_csTeil2);
	DDX_Text(pDX, IDC_TEIL3, m_csTeil3);
	DDX_Text(pDX, IDC_TEIL4, m_csTeil4);
	DDX_Text(pDX, IDC_ERG, m_csErg);
	DDX_Control(pDX, IDC_CHECK1, m_cbCheck1);
	DDX_Control(pDX, IDC_CHECK2, m_cbCheck2);
	DDX_Control(pDX, IDC_CHECK3, m_cbCheck3);
	DDX_Control(pDX, IDC_CHECK4, m_cbCheck4);
}

BEGIN_MESSAGE_MAP(CFunktionsRechnerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CFunktionsRechnerDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_ERG, &CFunktionsRechnerDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_CHECK1, &CFunktionsRechnerDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CFunktionsRechnerDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CFunktionsRechnerDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CFunktionsRechnerDlg::OnBnClickedCheck4)
END_MESSAGE_MAP()


// CFunktionsRechnerDlg message handlers

BOOL CFunktionsRechnerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFunktionsRechnerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFunktionsRechnerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFunktionsRechnerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFunktionsRechnerDlg::OnBnClickedOk()
{

	UpdateData(TRUE);
	int x1;
	CString xs1;
	CString pre1x(_T("NoValue/IncorrectValue"));
	CString post1x(_T("NoValue/IncorrectValue"));
	x1 = m_csTeil1.Find('x');
	xs1.Format(L"%d", x1);
	pre1x = m_csTeil1.Left(x1);
	post1x = m_csTeil1.Right(m_csTeil1.GetLength() - x1 -2);
	//m_csErg.Format(L"%d", x1);
	int pre1xi = _wtoi(pre1x);
	int post1xi = _wtoi(post1x);
	pre1xi = post1xi * pre1xi;
	post1xi = post1xi - 1;
	pre1x.Format(L"%d", pre1xi);
	post1x.Format(L"%d", post1xi);
	//Teil2
	int x2;
	CString xs2;
	CString pre2x(_T("NoValue/IncorrectValue"));
	CString post2x(_T("NoValue/IncorrectValue"));
	x2 = m_csTeil2.Find('x');
	xs2.Format(L"%d", x2);
	pre2x = m_csTeil2.Left(x2);
	post2x = m_csTeil2.Right(m_csTeil2.GetLength() - x2 - 2);
	int pre2xi = _wtoi(pre2x);
	int post2xi = _wtoi(post2x);
	pre2xi = post2xi * pre2xi;
	post2xi = post2xi - 1;
	pre2x.Format(L"%d", pre2xi);
	post2x.Format(L"%d", post2xi);
	m_csErg = pre1x + "x^" + post1x + " + " + pre2x + "x^" + post2x;
	UpdateData(FALSE);
}


void CFunktionsRechnerDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}



void CFunktionsRechnerDlg::OnBnClickedCheck1()
{	
	if (m_cbCheck1.GetCheck() == false)
	{
		GetDlgItem(IDC_TEIL1)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_TEIL1)->EnableWindow(TRUE);
	}


}


void CFunktionsRechnerDlg::OnBnClickedCheck2()
{
	if (m_cbCheck2.GetCheck() == false)
	{
		GetDlgItem(IDC_TEIL2)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_TEIL2)->EnableWindow(TRUE);
	}
}


void CFunktionsRechnerDlg::OnBnClickedCheck3()
{
	if (m_cbCheck3.GetCheck() == false)
	{
		GetDlgItem(IDC_TEIL3)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_TEIL3)->EnableWindow(TRUE);
	}
}


void CFunktionsRechnerDlg::OnBnClickedCheck4()
{
	if (m_cbCheck4.GetCheck() == false)
	{
		GetDlgItem(IDC_TEIL4)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_TEIL4)->EnableWindow(TRUE);
	}
}
