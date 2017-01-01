#pragma once


// HelpDlg dialog

class HelpDlg : public CDialogEx
{
public:
	HelpDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
};

