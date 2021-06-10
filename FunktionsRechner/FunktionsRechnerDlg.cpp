
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
	, m_csERG1(_T(""))
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
	DDX_Text(pDX, IDC_ERG1, m_csERG1);
	//==========================
	
	//==========================
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
	ON_EN_CHANGE(IDC_ERG1, &CFunktionsRechnerDlg::OnEnChangeErg1)
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

		//Das gehört hier definitiv nicht heroin (aber es funktioniert) xD
		m_cbCheck2.EnableWindow(FALSE);
		m_cbCheck3.EnableWindow(FALSE);
		m_cbCheck4.EnableWindow(FALSE);
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
	if (m_cbCheck1.GetCheck() == true) {
		//ABleitung 1
		int x1;
		CString xs1;
		CString pre1x(_T("NoValue/IncorrectValue"));
		CString post1x(_T("NoValue/IncorrectValue"));
		x1 = m_csTeil1.Find('x');
		xs1.Format(L"%d", x1);
		pre1x = m_csTeil1.Left(x1);
		post1x = m_csTeil1.Right(m_csTeil1.GetLength() - x1 - 2);
		int pre1xi = _wtoi(pre1x);
		int post1xi = _wtoi(post1x);
		pre1xi = post1xi * pre1xi;
		post1xi = post1xi - 1;
		pre1x.Format(L"%d", pre1xi);
		post1x.Format(L"%d", post1xi);
		m_csErg = pre1x + "x^" + post1x;
		CString erg1 = pre1x + "x^" + post1x;
		//Ableitung 2
		int x12;
		CString xs12;
		CString pre12x(_T("NoValue/IncorrectValue"));
		CString post12x(_T("NoValue/IncorrectValue"));
		x12 = erg1.Find('x');
		xs12.Format(L"%d", x12);
		pre12x = erg1.Left(x12);
		post12x = erg1.Right(erg1.GetLength() - x12 - 2);
		int pre12xi = _wtoi(pre12x);
		int post12xi = _wtoi(post12x);
		pre12xi = post12xi * pre12xi;
		post12xi = post12xi - 1;
		pre12x.Format(L"%d", pre12xi);
		post12x.Format(L"%d", post12xi);
		m_csERG1 = pre12x + "x^" + post12x;
		if (m_cbCheck2.GetCheck() == true) {
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
			CString erg2 = pre2x + "x^" + post2x;
			//Ableitung 2
			int x22;
			CString xs22;
			CString pre22x(_T("NoValue/IncorrectValue"));
			CString post22x(_T("NoValue/IncorrectValue"));
			x22 = erg2.Find('x');
			xs22.Format(L"%d", x22);
			pre22x = erg2.Left(x22);
			post22x = erg2.Right(erg2.GetLength() - x22 - 2);
			int pre22xi = _wtoi(pre22x);
			int post22xi = _wtoi(post22x);
			pre22xi = post22xi * pre22xi;
			post22xi = post22xi - 1;
			pre22x.Format(L"%d", pre22xi);
			post22x.Format(L"%d", post22xi);
			m_csERG1 = pre12x + "x^" + post12x + " + " + pre22x + "x^" + post22x;
			if (m_cbCheck3.GetCheck() == true) {
				int x3;
				CString xs3;
				CString pre3x(_T("NoValue/IncorrectValue"));
				CString post3x(_T("NoValue/IncorrectValue"));
				x3 = m_csTeil3.Find('x');
				xs3.Format(L"%d", x3);
				pre3x = m_csTeil3.Left(x3);
				post3x = m_csTeil3.Right(m_csTeil3.GetLength() - x3 - 2);
				int pre3xi = _wtoi(pre3x);
				int post3xi = _wtoi(post3x);
				pre3xi = post3xi * pre3xi;
				post3xi = post3xi - 1;
				pre3x.Format(L"%d", pre3xi);
				post3x.Format(L"%d", post3xi);
				m_csErg = pre1x + "x^" + post1x + " + " + pre2x + "x^" + post2x + " + " + pre3x + "x^" + post3x;
				CString erg3 = pre3x + "x^" + post3x;
				//Ableitung 2
				int x32;
				CString xs32;
				CString pre32x(_T("NoValue/IncorrectValue"));
				CString post32x(_T("NoValue/IncorrectValue"));
				x32 = erg3.Find('x');
				xs32.Format(L"%d", x32);
				pre32x = erg3.Left(x32);
				post32x = erg3.Right(erg3.GetLength() - x32 - 2);
				int pre32xi = _wtoi(pre32x);
				int post32xi = _wtoi(post32x);
				pre32xi = post32xi * pre32xi;
				post32xi = post32xi - 1;
				pre32x.Format(L"%d", pre32xi);
				post32x.Format(L"%d", post32xi);
				m_csERG1 = pre12x + "x^" + post12x + " + " + pre22x + "x^" + post22x + " + " + pre32x + "x^" + post32x;
				if (m_cbCheck4.GetCheck() == true) {
					int x4;
					CString xs4;
					CString pre4x(_T("NoValue/IncorrectValue"));
					CString post4x(_T("NoValue/IncorrectValue"));
					x4 = m_csTeil4.Find('x');
					xs4.Format(L"%d", x4);
					pre4x = m_csTeil4.Left(x4);
					post4x = m_csTeil4.Right(m_csTeil4.GetLength() - x4 - 2);
					int pre4xi = _wtoi(pre4x);
					int post4xi = _wtoi(post4x);
					pre4xi = post4xi * pre4xi;
					post4xi = post4xi - 1;
					pre4x.Format(L"%d", pre4xi);
					post4x.Format(L"%d", post4xi);
					m_csErg = pre1x + "x^" + post1x + " + " + pre2x + "x^" + post2x + " + " + pre3x + "x^" + post3x + " + " + pre4x + "x^" + post4x;
					CString erg4 = pre4x + "x^" + post4x;
					//Ableitung 2
					int x42;
					CString xs42;
					CString pre42x(_T("NoValue/IncorrectValue"));
					CString post42x(_T("NoValue/IncorrectValue"));
					x42 = erg4.Find('x');
					xs42.Format(L"%d", x42);
					pre42x = erg4.Left(x42);
					post42x = erg4.Right(erg4.GetLength() - x42 - 2);
					int pre42xi = _wtoi(pre42x);
					int post42xi = _wtoi(post42x);
					pre42xi = post42xi * pre42xi;
					post42xi = post42xi - 1;
					pre42x.Format(L"%d", pre42xi);
					post42x.Format(L"%d", post42xi);
					m_csERG1 = pre12x + "x^" + post12x + " + " + pre22x + "x^" + post22x + " + " + pre32x + "x^" + post32x + " + " + pre42x + "x^" + post42x;
				}
			}
		}
	}
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
		m_cbCheck2.EnableWindow(FALSE);
		m_cbCheck2.SetCheck(FALSE);
		GetDlgItem(IDC_TEIL2)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_TEIL1)->EnableWindow(TRUE);
		m_cbCheck2.EnableWindow(TRUE);
	}


}


void CFunktionsRechnerDlg::OnBnClickedCheck2()
{
	
	if (m_cbCheck2.GetCheck() == false)
	{
		m_cbCheck3.EnableWindow(FALSE);
		m_cbCheck3.SetCheck(FALSE);
		GetDlgItem(IDC_TEIL2)->EnableWindow(false);
		GetDlgItem(IDC_TEIL3)->EnableWindow(false);
		
	}
	else
	{
		GetDlgItem(IDC_TEIL2)->EnableWindow(TRUE);
		m_cbCheck3.EnableWindow(TRUE);
	}
}


void CFunktionsRechnerDlg::OnBnClickedCheck3()
{
	
	if (m_cbCheck3.GetCheck() == false)
	{
		m_cbCheck4.SetCheck(FALSE);
		m_cbCheck4.EnableWindow(FALSE);
		GetDlgItem(IDC_TEIL3)->EnableWindow(false);
		GetDlgItem(IDC_TEIL4)->EnableWindow(FALSE);
		
	}
	else
	{
		GetDlgItem(IDC_TEIL3)->EnableWindow(TRUE);
		m_cbCheck4.EnableWindow(TRUE);
	}
}


void CFunktionsRechnerDlg::OnBnClickedCheck4()
{
	if (m_cbCheck4.GetCheck() == false)
	{
		GetDlgItem(IDC_TEIL4)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_TEIL4)->EnableWindow(TRUE);
	}
}


void CFunktionsRechnerDlg::OnEnChangeErg1()
{
	// TODO:  Falls dies ein RICHEDIT-Steuerelement ist, wird das Kontrollelement
	// diese Benachrichtigung nicht senden, es sei denn, Sie überschreiben die CDialogEx::OnInitDialog()-
	// Funktion und rufen CRichEditCtrl().SetEventMask() auf
	// mit dem ENM_CHANGE-Flag ORed in der Eingabe.

	// TODO:  Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
}
