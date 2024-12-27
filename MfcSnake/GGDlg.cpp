// GGDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MfcSnake.h"
#include "GGDlg.h"
#include "afxdialogex.h"
#include "MfcSnakeDlg.h"


// CGGDlg 对话框

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


// CGGDlg 消息处理程序


void CGGDlg::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码

    CMfcSnakeDlg* pSnakeDlg = dynamic_cast<CMfcSnakeDlg*>(AfxGetMainWnd()); // 获取主对话框指针，并转换为 CMfcSnakeDlg 类型的指针

    if (pSnakeDlg)
    {
        pSnakeDlg->SnakeInit(); // 调用 SnakeInit() 函数
    }

    EndDialog(IDD_GAMEOVER);
}



void CGGDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
