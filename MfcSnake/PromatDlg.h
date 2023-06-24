#pragma once

#include "MfcSnakeDlg.h"
// CPromatDlg 对话框

class CPromatDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPromatDlg)

public:
	CPromatDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPromatDlg();

	// 对话框数据
	enum { IDD = IDD_PROMAT };

	void OnClose();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP();

public:
	afx_msg void OnBnClickedPromatIk();
};
