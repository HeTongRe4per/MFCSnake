// PromatDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MfcSnake.h"
#include "PromatDlg.h"
#include "afxdialogex.h"


// CPromatDlg �Ի���

IMPLEMENT_DYNAMIC(CPromatDlg, CDialogEx)

CPromatDlg::CPromatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPromatDlg::IDD, pParent)
{

}

CPromatDlg::~CPromatDlg()
{
}

void CPromatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}



BEGIN_MESSAGE_MAP(CPromatDlg, CDialogEx)
	ON_BN_CLICKED(IDC_PROMAT_ik, &CPromatDlg::OnBnClickedPromatIk)
END_MESSAGE_MAP()


// CPromatDlg ��Ϣ�������


void CPromatDlg::OnBnClickedPromatIk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

    CMfcSnakeDlg* pMainDlg = (CMfcSnakeDlg*)AfxGetMainWnd(); // ��ȡ���Ի���ָ��

    if (pMainDlg->START) // �ж� START �����Ƿ�Ϊ��
    {
        pMainDlg->SetTimer(1, pMainDlg->speed, NULL); // ���ü�ʱ��
        EndDialog(IDD_PROMAT); // �ر� IDD_PROMAT �Ի���
    }
    else
    {
        EndDialog(IDD_PROMAT); // ֱ�ӹر� IDD_PROMAT �Ի���
    }
}

