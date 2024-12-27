// GGDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MfcSnake.h"
#include "GGDlg.h"
#include "afxdialogex.h"
#include "MfcSnakeDlg.h"


// CGGDlg �Ի���

IMPLEMENT_DYNAMIC(CGGDlg, CDialogEx)

CGGDlg::CGGDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGGDlg::IDD, pParent)
{
}

CGGDlg::~CGGDlg()
{
}

void CGGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGGDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CGGDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CGGDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CGGDlg ��Ϣ�������


void CGGDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

    CMfcSnakeDlg* pSnakeDlg = dynamic_cast<CMfcSnakeDlg*>(AfxGetMainWnd()); // ��ȡ���Ի���ָ�룬��ת��Ϊ CMfcSnakeDlg ���͵�ָ��

    if (pSnakeDlg)
    {
        pSnakeDlg->SnakeInit(); // ���� SnakeInit() ����
    }

    EndDialog(IDD_GAMEOVER);
}



void CGGDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}
