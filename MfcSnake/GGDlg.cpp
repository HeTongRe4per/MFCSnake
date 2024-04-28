// GGDlg.cpp : ÊµÏÖÎÄ¼ş
//

#include "stdafx.h"
#include "MfcSnake.h"
#include "GGDlg.h"
#include "afxdialogex.h"
#include "MfcSnakeDlg.h"


// CGGDlg ¶Ô»°¿ò

IMPLEMENT_DYNAMIC(CGGDlg, CDialogEx)

CGGDlg::CGGDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGGDlg::IDD, pParent)
{
<<<<<<< HEAD

=======
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
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


// CGGDlg ÏûÏ¢´¦Àí³ÌĞò


void CGGDlg::OnBnClickedOk()
{
    // TODO: ÔÚ´ËÌí¼Ó¿Ø¼şÍ¨Öª´¦Àí³ÌĞò´úÂë

    CMfcSnakeDlg* pSnakeDlg = dynamic_cast<CMfcSnakeDlg*>(AfxGetMainWnd()); // »ñÈ¡Ö÷¶Ô»°¿òÖ¸Õë£¬²¢×ª»»Îª CMfcSnakeDlg ÀàĞÍµÄÖ¸Õë

    if (pSnakeDlg)
    {
        pSnakeDlg->SnakeInit(); // µ÷ÓÃ SnakeInit() º¯Êı
    }

    EndDialog(IDD_GAMEOVER);
}



void CGGDlg::OnBnClickedCancel()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼şÍ¨Öª´¦Àí³ÌĞò´úÂë
	exit(0);
}
