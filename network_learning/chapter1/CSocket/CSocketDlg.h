// CSocketDlg.h : header file
//

#if !defined(AFX_CSOCKETDLG_H__2EA69D8D_5C41_462A_9D38_3CC11BC1D4D6__INCLUDED_)
#define AFX_CSOCKETDLG_H__2EA69D8D_5C41_462A_9D38_3CC11BC1D4D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCSocketDlg dialog

class CCSocketDlg : public CDialog
{
// Construction
public:
	CCSocketDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCSocketDlg)
	enum { IDD = IDD_CSOCKET_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSocketDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCSocketDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSOCKETDLG_H__2EA69D8D_5C41_462A_9D38_3CC11BC1D4D6__INCLUDED_)
