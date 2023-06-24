#pragma once


// CGGDlg 对话框

class CGGDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGGDlg)

public:
	CGGDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGGDlg();

// 对话框数据
	enum { IDD = IDD_GAMEOVER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
