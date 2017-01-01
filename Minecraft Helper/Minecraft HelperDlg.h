
// Minecraft HelperDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMinecraftHelperDlg dialog
class CMinecraftHelperDlg : public CDialogEx
{
// Construction
public:
	CMinecraftHelperDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MINECRAFTHELPER_DIALOG };

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
	LRESULT OnGetDefID(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
//	afx_msg void OnNMThemeChangedScrWood(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	// zmienna listy wyniku obliczen
	CListBox m_ListEffect;
	afx_msg void OnBnClickedButton2();
};
