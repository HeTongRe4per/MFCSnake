#pragma once


// CGameOverDlg �Ի���

class CGameOverDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameOverDlg)

public:
	CGameOverDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGameOverDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
