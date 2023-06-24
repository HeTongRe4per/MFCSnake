#pragma once


// CGameOverDlg 对话框

class CGameOverDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameOverDlg)

public:
	CGameOverDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGameOverDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
