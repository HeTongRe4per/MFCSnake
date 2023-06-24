// PromatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MfcSnake.h"
#include "PromatDlg.h"
#include "afxdialogex.h"


// CPromatDlg 对话框

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


// CPromatDlg 消息处理程序


void CPromatDlg::OnBnClickedPromatIk()
{
    // TODO: 在此添加控件通知处理程序代码

    CMfcSnakeDlg* pMainDlg = (CMfcSnakeDlg*)AfxGetMainWnd(); // 获取主对话框指针

    if (pMainDlg->START) // 判断 START 变量是否为真
    {
        pMainDlg->SetTimer(1, pMainDlg->speed, NULL); // 设置计时器
        EndDialog(IDD_PROMAT); // 关闭 IDD_PROMAT 对话框
    }
    else
    {
        EndDialog(IDD_PROMAT); // 直接关闭 IDD_PROMAT 对话框
    }
}

