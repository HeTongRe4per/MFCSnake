#pragma once


// CGGDlg �Ի���

class CGGDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGGDlg)

public:
	CGGDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGGDlg();

// �Ի�������
	enum { IDD = IDD_GAMEOVER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
