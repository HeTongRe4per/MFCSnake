
// MfcSnakeDlg.cpp: ÊµÏÖÎÄ¼ş
//

#include "stdafx.h"
#include "MfcSnake.h"
#include "MfcSnakeDlg.h"
#include "afxdialogex.h"

#include <iostream>
#include <random>

#include "windows.h"
#include "mmsystem.h" 
#pragma comment(lib, "WINMM.LIB")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;



// ÓÃÓÚÓ¦ÓÃ³ÌĞò¡°¹ØÓÚ¡±²Ëµ¥ÏîµÄ CAboutDlg ¶Ô»°¿ò

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ¶Ô»°¿òÊı¾İ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Ö§³Ö

// ÊµÏÖ
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMfcSnakeDlg ¶Ô»°¿ò



CMfcSnakeDlg::CMfcSnakeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSNAKE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
	pen1.CreatePen(PS_SOLID, 4, RGB(174, 221, 129));

	// ÉèÖÃ³õÊ¼Öµ
	speed = 150;
	score = 0;
	INIT = true;
	START = false;
	DEAD = false;
}

void CMfcSnakeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_speed, Box);
	DDX_Control(pDX, IDC_EDIT_score, EDIT_Score);
}

void CPromatDlg::OnClose()
{
    // ÖØĞÂÆô¶¯¶¨Ê±Æ÷
    CWnd* pParent = GetParent();
    if (pParent != nullptr)
    {
        pParent->SetTimer(1, 300, NULL);
    }

    CDialogEx::OnClose();
}



BEGIN_MESSAGE_MAP(CMfcSnakeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Stop, &CMfcSnakeDlg::OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_Start, &CMfcSnakeDlg::OnBnClickedButtonStart)
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_COMBO_speed, &CMfcSnakeDlg::OnCbnSelchangeCombospeed)
	ON_WM_WINDOWPOSCHANGING()
	ON_BN_CLICKED(IDC_Music, &CMfcSnakeDlg::OnBnClickedMusic)
	ON_BN_CLICKED(IDC_BUTTON_quit, &CMfcSnakeDlg::OnBnClickedButtonquit)
	ON_BN_CLICKED(IDC_BUTTON_promat, &CMfcSnakeDlg::OnBnClickedButtonpromat)
END_MESSAGE_MAP()


// CMfcSnakeDlg ÏûÏ¢´¦Àí³ÌĞò

BOOL CMfcSnakeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ½«¡°¹ØÓÚ...¡±²Ëµ¥ÏîÌí¼Óµ½ÏµÍ³²Ëµ¥ÖĞ¡£

	// ÉèÖÃ´Ë¶Ô»°¿òµÄÍ¼±ê¡£  µ±Ó¦ÓÃ³ÌĞòÖ÷´°¿Ú²»ÊÇ¶Ô»°¿òÊ±£¬¿ò¼Ü½«×Ô¶¯
	//  Ö´ĞĞ´Ë²Ù×÷
	SetIcon(m_hIcon, TRUE);			// ÉèÖÃ´óÍ¼±ê
	SetIcon(m_hIcon, FALSE);		// ÉèÖÃĞ¡Í¼±ê

	// TODO: ÔÚ´ËÌí¼Ó¶îÍâµÄ³õÊ¼»¯´úÂë

	return FALSE;  // ³ı·Ç½«½¹µãÉèÖÃµ½¿Ø¼ş£¬·ñÔò·µ»Ø TRUE
}

void CMfcSnakeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


//  Èç¹ûÏò¶Ô»°¿òÌí¼Ó×îĞ¡»¯°´Å¥£¬ÔòĞèÒªÏÂÃæµÄ´úÂë
//  À´»æÖÆ¸ÃÍ¼±ê¡£  ¶ÔÓÚÊ¹ÓÃÎÄµµ/ÊÓÍ¼Ä£ĞÍµÄ MFC Ó¦ÓÃ³ÌĞò£¬
//  Õâ½«ÓÉ¿ò¼Ü×Ô¶¯Íê³É¡£

void CMfcSnakeDlg::OnPaint()
{
<<<<<<< HEAD
	// ================================ÓÎÏ·½çÃæ³õÊ¼»¯º¯Êı==============================
=======
	// ÓÎÏ·½çÃæ³õÊ¼»¯º¯Êı
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
	
	CRect rect;
	(this->GetDlgItem(IDC_game))->GetWindowRect(&rect);  // »ñÈ¡¿Ø¼şÏà¶ÔÓÚÆÁÄ»µÄÎ»ÖÃ
	ScreenToClient(rect); // ×ª»¯ÎªÏà¶ÔÓÚ¿Í»§ÇøµÄÎ»ÖÃ
<<<<<<< HEAD
	GetDlgItem(IDC_game)->MoveWindow(rect.left, rect.top + 4, 760, 500, false);
=======
	GetDlgItem(IDC_game)->MoveWindow(rect.left + 4, rect.top + 4, 760, 500, false);
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')

	CDC* pClientDC = GetDC();
	(this->GetDlgItem(IDC_game))->GetWindowRect(&rect);  // »ñÈ¡¿Ø¼şÏà¶ÔÓÚÆÁÄ»µÄÎ»ÖÃ
	ScreenToClient(rect); // ×ª»¯ÎªÏà¶ÔÓÚ¿Í»§ÇøµÄÎ»ÖÃ
	CPen pen(PS_SOLID, 6, RGB(6, 128, 67));
	CPen pen2(PS_SOLID, 10, RGB(174, 221, 129));
	CPen* oldPen = pClientDC->SelectObject(&pen2);
	pClientDC->Rectangle(rect);
	rect.left -= 5;
	rect.right += 5;
	rect.top -= 5;
	rect.bottom += 5;
	pClientDC->SelectObject(&pen);
	pClientDC->Rectangle(rect);
	pen.DeleteObject();
	pen2.DeleteObject();
	pClientDC->DeleteDC();

	// »­Ë¢³õÊ¼»¯
	CBitmap bodybmp, headbmp, beanbmp, bgbmp;
	bgbmp.LoadBitmapW(IDB_BITMAP5);
	beanbmp.LoadBitmapW(IDB_BITMAP4);
	bodybmp.LoadBitmapW(IDB_BITMAP2);
	headbmp.LoadBitmapW(IDB_BITMAP3);
	m_brush[0].CreatePatternBrush(&bodybmp);
	m_brush[1].CreatePatternBrush(&headbmp);
	m_brush[2].CreatePatternBrush(&beanbmp);
	m_brush[3].CreatePatternBrush(&bgbmp);

	// ¿Ø¼ş³õÊ¼»¯
	Box.SetCurSel(1);
	EDIT_Score.SetReadOnly(1);

	CFont* pDefaultFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));

	GetDlgItem(IDC_EDIT_score)->SetFont(pDefaultFont);
	GetDlgItem(IDC_BUTTON_Start)->SetFont(pDefaultFont);
	GetDlgItem(IDC_BUTTON_Stop)->SetFont(pDefaultFont);
	GetDlgItem(IDC_Score)->SetFont(pDefaultFont);
	GetDlgItem(IDC_Speed)->SetFont(pDefaultFont);
	((CButton*)GetDlgItem(IDC_Music))->SetFont(pDefaultFont);

	OnBnClickedButtonStop();

	SnakeInit();

	CPaintDC pDC(this);
}

//µ±ÓÃ»§ÍÏ¶¯×îĞ¡»¯´°¿ÚÊ±ÏµÍ³µ÷ÓÃ´Ëº¯ÊıÈ¡µÃ¹â±ê
//ÏÔÊ¾¡£
HCURSOR CMfcSnakeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

<<<<<<< HEAD
=======
void CMfcSnakeDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos) //½ûÖ¹´°¿Ú³ö½ç
{
	CDialogEx::OnWindowPosChanging(lpwndpos);

	// TODO: ÔÚ´Ë´¦Ìí¼ÓÏûÏ¢´¦Àí³ÌĞò´úÂë
	// »ñÈ¡ÆÁÄ»¿í¶È
	int nMaxX = GetSystemMetrics(SM_CXSCREEN);
	// »ñÈ¡ÆÁÄ»¸ß¶È
	int nMaxY = GetSystemMetrics(SM_CYSCREEN);

	// ÅĞ¶Ï´°¿ÚX×ø±êÓĞÎŞ³¬¹ı×ó±ß×ÀÃæ¡£
	if (lpwndpos->x < 0)
	{
		lpwndpos->x = 0;
	}

	// ÅĞ¶Ï´°¿ÚX×ø±êÓĞÎŞ³¬¹ıÓÒ±ß×ÀÃæ¡£
	if (lpwndpos->x + lpwndpos->cx > nMaxX)
	{
		lpwndpos->x = nMaxX - lpwndpos->cx;
	}

	// ÅĞ¶Ï´°¿ÚY×ø±êÓĞÎŞ³¬¹ı¶¥²¿×ÀÃæ¡£
	if (lpwndpos->y < 0)
	{
		lpwndpos->y = 0;
	}

	// ÅĞ¶Ï´°¿ÚY×ø±êÓĞÎŞ³¬¹ıµ×²¿×ÀÃæ¡£
	if (lpwndpos->y + lpwndpos->cy > nMaxY)
	{
		lpwndpos->y = nMaxY - lpwndpos->cy;
	}
}

>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
void CMfcSnakeDlg::SnakeInit()
{
	// »ñÈ¡ÓÎÏ·Çø
	CDC* pdc = GetDlgItem(IDC_game)->GetWindowDC();

	// ÓÎÏ·Çø³õÊ¼»¯
	CBrush* pOldBrs = pdc->SelectObject(&m_brush[3]);
	CPen* pOldPen = pdc->SelectObject(&pen1);
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 38; j++) {
			m_map[i][j].left = 0 + j * 20;
			m_map[i][j].right = 20 + j * 20;
			m_map[i][j].top = 0 + i * 20;
			m_map[i][j].bottom = 20 + i * 20;
			pdc->SelectObject(&m_brush[3]);
			pdc->Rectangle(m_map[i][j]);
		}
	}
	pdc->SelectObject(&pOldBrs);

	// Éß³õÊ¼»¯
	my_snake.init();
	score = 0;
	START = false;
	DEAD = false;
	srand((unsigned)time(NULL));
	drawSnake();
	setBean();

	// ¿Ø¼ş³õÊ¼»¯
	EDIT_Score.SetWindowTextW(_T("0"));
}

void CMfcSnakeDlg::OnBnClickedButtonStop()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼şÍ¨Öª´¦Àí³ÌĞò´úÂë
	// ÖØĞÂ¿ªÊ¼
	gameOver();
	SnakeInit();
<<<<<<< HEAD
	this->GetDlgItem(IDC_game)->SetFocus();
=======
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
}

void CMfcSnakeDlg::OnBnClickedButtonStart()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼şÍ¨Öª´¦Àí³ÌĞò´úÂë
	if (DEAD == false) {
		if (START) {
			START = false;
			KillTimer(1);
			SetDlgItemText(IDC_BUTTON_Start, _T("¼ÌĞøÓÎÏ·"));
		}
		else {
			if (INIT) {
				INIT = false;
				SnakeInit();
			}
			START = true;
			SetTimer(1, speed, NULL);
			SetDlgItemText(IDC_BUTTON_Start, _T("ÔİÍ£ÓÎÏ·"));
		}
<<<<<<< HEAD
		this->GetDlgItem(IDC_game)->SetFocus();
=======
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
	}
}

void CMfcSnakeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ÔÚ´ËÌí¼ÓÏûÏ¢´¦Àí³ÌĞò´úÂëºÍ/»òµ÷ÓÃÄ¬ÈÏÖµ
<<<<<<< HEAD
	// main function about snake
=======
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
	UpdateData(true);
	if (START && DEAD == false) {
		switch (my_snake.direc)
		{
<<<<<<< HEAD
		case 1:MvUp(); break;
		case 2:MvDown(); break;
		case 3:MvLeft(); break;
		case 4:MvRight(); break;
		default:
			break;
=======
			case 1:MvUp(); break;
			case 2:MvDown(); break;
			case 3:MvLeft(); break;
			case 4:MvRight(); break;
			default:break;
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
		}
		if (checkLive() == false) {
			DEAD = true;
			gameOver();
			// ´´½¨²¢ÏÔÊ¾ÌáÊ¾¿ò
			CGGDlg dlg(this);
			dlg.DoModal();
		} 
		eatBean();
	}

	CDialogEx::OnTimer(nIDEvent);
}

bool CMfcSnakeDlg::setBean()
{
	srand((unsigned)time(NULL));
	bool setB = false;
	bool safe = true;
	while (safe) {
		pos.x = rand() % 25;
		pos.y = rand() % 38;
		for (int i = 0; i < my_snake.len; i++) {
			if (pos.x == my_snake.body[i].x && pos.y == my_snake.body[i].y) {
				safe = false; break;
			}
		}
		if (safe) {
			setB = true;
			safe = false;
		}
		else safe = true;
	}
	CDC* pdc = GetDlgItem(IDC_game)->GetWindowDC();
	CBrush* pOldBrs = pdc->SelectObject(&m_brush[2]);
	pdc->Rectangle(m_map[pos.x][pos.y]);
	pdc->SelectObject(&pen1);
	pdc->Rectangle(m_map[pos.x][pos.y]);
	pdc->SelectObject(&pOldBrs);
	pdc->DeleteDC();
	return setB;
}

void CMfcSnakeDlg::drawSnake()
{
	CDC* pdc = GetDlgItem(IDC_game)->GetWindowDC();
	CBrush* pOldBrs = pdc->SelectObject(&m_brush[0]);
	for (int i = 1; i < my_snake.len; i++) {
		pdc->SelectObject(&m_brush[0]);
		pdc->Rectangle(m_map[my_snake.body[i].x][my_snake.body[i].y]);
		pdc->SelectObject(&pen1);
		pdc->Rectangle(m_map[my_snake.body[i].x][my_snake.body[i].y]);
	}
	pdc->SelectObject(&m_brush[1]);
	pdc->Rectangle(m_map[my_snake.body[0].x][my_snake.body[0].y]);
	pdc->SelectObject(&pen1);
	pdc->Rectangle(m_map[my_snake.body[0].x][my_snake.body[0].y]);
	pdc->SelectObject(&pOldBrs);
	pdc->DeleteDC(); 
}

void CMfcSnakeDlg::MvDraw() // »­ÉßÒÆ¶¯Ê±
{
    CDC* pdc = GetDlgItem(IDC_game)->GetWindowDC();
    if (pdc == nullptr) {
<<<<<<< HEAD
        // ´¦ÀíÎŞ·¨»ñÈ¡Éè±¸ÉÏÏÂÎÄµÄÇé¿ö
=======
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
        return;
    }

    int s_x = my_snake.body[my_snake.len - 1].x;
    int s_y = my_snake.body[my_snake.len - 1].y;

    if (s_x >= 0 && s_x < 25 && s_y >= 0 && s_y < 38) {
        // ½«×îºóÒ»¸ö»Ö¸´±³¾°É«
        pdc->SelectObject(&pen1);
        pdc->Rectangle(m_map[s_x][s_y]);
        CBrush* pOldBrs = pdc->SelectObject(&m_brush[3]);
        pdc->Rectangle(m_map[s_x][s_y]);
        pdc->SelectObject(pOldBrs);
    }

    pdc->DeleteDC();
}

<<<<<<< HEAD

=======
// ÉßµÄÒÆ¶¯
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
void CMfcSnakeDlg::MvUp()
{
	MvDraw();
	my_snake.UpMove();
	drawSnake();
}

void CMfcSnakeDlg::MvDown()
{
	MvDraw();
	my_snake.DownMove();
	drawSnake();
}

void CMfcSnakeDlg::MvLeft()
{
	MvDraw();
	my_snake.LeftMove();
	drawSnake();
}

void CMfcSnakeDlg::MvRight()
{
	MvDraw();
	my_snake.RightMove();
	drawSnake();
}


void CMfcSnakeDlg::eatBean() //³Ôµ½¶¹×ÓµÄÅĞ¶¨
{
	if (pos.x == my_snake.body[0].x && pos.y == my_snake.body[0].y) {
		my_snake.len++;
		setBean();
		score += 10;
		CString str;
		str.Format(_T("%d"), score);
		EDIT_Score.SetWindowTextW(str);
	}
}

bool CMfcSnakeDlg::checkLive() //ÉßµÄ´æ»î¼ì²é
{
	// ÅĞ¶ÏÊÇ·ñ³ö½ç
	if (my_snake.body[0].x < 0 || my_snake.body[0].x >= 25 || my_snake.body[0].y < 0 || my_snake.body[0].y >= 38) 
	{
		SetDlgItemText(IDC_BUTTON_Start, _T("¿ªÊ¼ÓÎÏ·"));
		return false;
	}
	// ÅĞ¶ÏÊÇ·ñ×²µ½ÁË×Ô¼º
	for (int i = 1; i < my_snake.len; i++) {
		if (my_snake.body[0].x == my_snake.body[i].x && my_snake.body[0].y == my_snake.body[i].y) 
		{
			SetDlgItemText(IDC_BUTTON_Start, _T("¿ªÊ¼ÓÎÏ·"));
			return false;
		}
	}
	return true;
}

void CMfcSnakeDlg::gameOver()
{
	KillTimer(1);
	START = false;
<<<<<<< HEAD
=======
	SetDlgItemText(IDC_BUTTON_Start, _T("¿ªÊ¼ÓÎÏ·"));
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
}

void CMfcSnakeDlg::OnCbnSelchangeCombospeed() //ËÙ¶ÈÑ¡Ôñ
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼şÍ¨Öª´¦Àí³ÌĞò´úÂë
	CString mode;
	Box.GetLBText(Box.GetCurSel(), mode);
	int tmp = 0;
	tmp = mode[0] - '0';
	speed = 300 / tmp;
	SetTimer(1, speed, NULL);
	this->GetDlgItem(IDC_game)->SetFocus();
}

BOOL CMfcSnakeDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ÔÚ´ËÌí¼Ó×¨ÓÃ´úÂëºÍ/»òµ÷ÓÃ»ùÀà
	if (START && DEAD == false) {
		if (my_snake.direc != 2 && (pMsg->wParam == VK_UP || pMsg->wParam == 'w' || pMsg->wParam == 'W')) my_snake.direc = 1;
		else if (my_snake.direc != 1 && (pMsg->wParam == VK_DOWN || pMsg->wParam == 's' || pMsg->wParam == 'S')) my_snake.direc = 2;
		else if (my_snake.direc != 4 && (pMsg->wParam == VK_LEFT || pMsg->wParam == 'a' || pMsg->wParam == 'A')) my_snake.direc = 3;
		else if (my_snake.direc != 3 && (pMsg->wParam == VK_RIGHT || pMsg->wParam == 'd' || pMsg->wParam == 'D')) my_snake.direc = 4;
<<<<<<< HEAD
=======
		else if (pMsg->wParam == VK_SPACE) CMfcSnakeDlg::OnBnClickedButtonStart();
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
	}
	return 0;
}

<<<<<<< HEAD
void CMfcSnakeDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos) //½ûÖ¹´°¿Ú³ö½ç
{
	CDialogEx::OnWindowPosChanging(lpwndpos);

	// TODO: ÔÚ´Ë´¦Ìí¼ÓÏûÏ¢´¦Àí³ÌĞò´úÂë
	// »ñÈ¡ÆÁÄ»¿í¶È
	int nMaxX = GetSystemMetrics(SM_CXSCREEN);
	// »ñÈ¡ÆÁÄ»¸ß¶È
	int nMaxY = GetSystemMetrics(SM_CYSCREEN);

	// ÅĞ¶Ï´°¿ÚX×ø±êÓĞÎŞ³¬¹ı×ó±ß×ÀÃæ¡£
	if (lpwndpos->x < 0)
	{
		lpwndpos->x = 0;
	}

	// ÅĞ¶Ï´°¿ÚX×ø±êÓĞÎŞ³¬¹ıÓÒ±ß×ÀÃæ¡£
	if (lpwndpos->x + lpwndpos->cx > nMaxX)
	{
		lpwndpos->x = nMaxX - lpwndpos->cx;
	}

	// ÅĞ¶Ï´°¿ÚY×ø±êÓĞÎŞ³¬¹ı¶¥²¿×ÀÃæ¡£
	if (lpwndpos->y < 0)
	{
		lpwndpos->y = 0;
	}

	// ÅĞ¶Ï´°¿ÚY×ø±êÓĞÎŞ³¬¹ıµ×²¿×ÀÃæ¡£
	if (lpwndpos->y + lpwndpos->cy > nMaxY)
	{
		lpwndpos->y = nMaxY - lpwndpos->cy;
	}
}
=======
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')

void CMfcSnakeDlg::OnBnClickedMusic()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼şÍ¨Öª´¦Àí³ÌĞò´úÂë
	int state = ((CButton*)GetDlgItem(IDC_Music))->GetCheck();
	
	if (state == 0) { PlaySound(NULL, NULL, NULL); }
	else { PlaySound(LPWSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP); }
}

void CMfcSnakeDlg::OnBnClickedButtonpromat()
{
	KillTimer(1);

    // ´´½¨²¢ÏÔÊ¾ÌáÊ¾¿ò
    CPromatDlg dlg(this);
    dlg.DoModal();
}

void CMfcSnakeDlg::OnBnClickedButtonquit()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼şÍ¨Öª´¦Àí³ÌĞò´úÂë
	exit(0);
}