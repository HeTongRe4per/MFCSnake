#pragma once

#include "MfcSnakeDlg.h"
// CPromatDlg �Ի���

class CPromatDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPromatDlg)

public:
	CPromatDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPromatDlg();

	// �Ի�������
	enum { IDD = IDD_PROMAT };

	void OnClose();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP();

public:
	afx_msg void OnBnClickedPromatIk();
};
