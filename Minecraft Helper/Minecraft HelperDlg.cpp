
// Minecraft HelperDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Minecraft Helper.h"
#include "Minecraft HelperDlg.h"
#include "HelpDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMinecraftHelperDlg dialog




CMinecraftHelperDlg::CMinecraftHelperDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMinecraftHelperDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MCICON);
}

void CMinecraftHelperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_EFFECT, m_ListEffect);
}

BEGIN_MESSAGE_MAP(CMinecraftHelperDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(DM_GETDEFID, OnGetDefID)
ON_BN_CLICKED(IDC_BUTTON3, &CMinecraftHelperDlg::OnBnClickedButton3)
//ON_NOTIFY(NM_THEMECHANGED, IDC_SCR_WOOD, &CMinecraftHelperDlg::OnNMThemeChangedScrWood)
ON_BN_CLICKED(IDC_BUTTON1, &CMinecraftHelperDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CMinecraftHelperDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMinecraftHelperDlg message handlers

LRESULT CMinecraftHelperDlg::OnGetDefID(WPARAM wp, LPARAM lp) 
{
    return MAKELONG(0,DC_HASDEFID); 
} 

BOOL CMinecraftHelperDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	CString str[6];
	for(int i=0;i<6;i++)
		str[i].Format(_T("%d"),theApp.resTable[i]);

	this->SetDlgItemTextW(IDC_EDIT_WOOD,str[0]);
	this->SetDlgItemTextW(IDC_EDIT_WOODENPLANK,str[1]);
	this->SetDlgItemTextW(IDC_EDIT_COBBLESTONE,str[2]);
	this->SetDlgItemTextW(IDC_EDIT_STONE,str[3]);
	this->SetDlgItemTextW(IDC_EDIT_CLAY,str[4]);
	this->SetDlgItemTextW(IDC_EDIT_SAND,str[5]);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMinecraftHelperDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMinecraftHelperDlg::OnPaint()
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
HCURSOR CMinecraftHelperDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}







//void CMinecraftHelperDlg::OnLbnSelchangeList1()
//{
//	// TODO: Add your control notification handler code here
//}


void CMinecraftHelperDlg::OnBnClickedButton3()
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}



//void CMinecraftHelperDlg::OnNMThemeChangedScrWood(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// This feature requires Windows XP or greater.
//	// The symbol _WIN32_WINNT must be >= 0x0501.
//	// TODO: Add your control notification handler code here
//	*pResult = 0;
//}

//0 wood, 1 woodenplank, 2 cobblestone, 3 stone, 4 clay, 5 sand 

void CMinecraftHelperDlg::OnBnClickedButton1()
{
	m_ListEffect.ResetContent();

	theApp.resTable[0]=this->GetDlgItemInt(IDC_EDIT_WOOD);
	theApp.resTable[1]=this->GetDlgItemInt(IDC_EDIT_WOODENPLANK);
	theApp.resTable[2]=this->GetDlgItemInt(IDC_EDIT_COBBLESTONE);
	theApp.resTable[3]=this->GetDlgItemInt(IDC_EDIT_STONE);
	theApp.resTable[4]=this->GetDlgItemInt(IDC_EDIT_CLAY);
	theApp.resTable[5]=this->GetDlgItemInt(IDC_EDIT_SAND);
	


	//wood
	if(theApp.resTable[0]>=1)
	{
		m_ListEffect.AddString(_T("Wooden Plank"));
	}

	//wooden plank
	if(theApp.resTable[1]>=2)
	{
		m_ListEffect.AddString(_T("Stick"));
		m_ListEffect.AddString(_T("Wooden Pressure Plate"));
		if(theApp.resTable[1]>=3)
		{
			m_ListEffect.AddString(_T("Wooden Slab"));
			m_ListEffect.AddString(_T("Bowl"));
			if(theApp.resTable[1]>=4)
			{
				m_ListEffect.AddString(_T("Crafting Table"));
				if(theApp.resTable[1]>=5)
				{
					m_ListEffect.AddString(_T("Boat"));
					if(theApp.resTable[1]>=6)
					{
						m_ListEffect.AddString(_T("Door"));
						m_ListEffect.AddString(_T("Trapdoor"));
						m_ListEffect.AddString(_T("Wooden Stairs"));
						if(theApp.resTable[1]>=8)
						{
							m_ListEffect.AddString(_T("Chest"));
						}
					}
				}
			}
		}
	}

	//cobblestone
	if(theApp.resTable[2]>=3)
	{
		m_ListEffect.AddString(_T("Cobblestone Slab"));
		if(theApp.resTable[2]>6)
		{
			m_ListEffect.AddString(_T("Cobblestone Stairs"));
			if(theApp.resTable[2]>=8)
			{
				m_ListEffect.AddString(_T("Furnace"));
			}
		}
	}

	//stone
	if(theApp.resTable[3]>=2)
	{
		m_ListEffect.AddString(_T("Stone Button"));
		m_ListEffect.AddString(_T("Stone Pressure Plate"));
		if(theApp.resTable[3]>=3)
		{
			m_ListEffect.AddString(_T("Stone Slab"));
			if(theApp.resTable[3]>=4)
			{
				m_ListEffect.AddString(_T("Stone Brick"));
			}
		}
	}

	//clay
	if(theApp.resTable[4]>4)
	{
		m_ListEffect.AddString(_T("Clay Block"));
	}

	//sand
	if(theApp.resTable[5]>=4)
	{
		m_ListEffect.AddString(_T("Sandstone"));
	}
}


void CMinecraftHelperDlg::OnBnClickedButton2()
{
	HelpDlg help;
	help.DoModal();
}
