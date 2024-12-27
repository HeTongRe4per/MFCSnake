
// MfcSnakeDlg.cpp: 实现文件
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



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMfcSnakeDlg 对话框



CMfcSnakeDlg::CMfcSnakeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSNAKE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
	pen1.CreatePen(PS_SOLID, 4, RGB(174, 221, 129));

	// 设置初始值
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
    // 重新启动定时器
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


// CMfcSnakeDlg 消息处理程序

BOOL CMfcSnakeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
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


//  如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMfcSnakeDlg::OnPaint()
{
	// 游戏界面初始化函数
	
	CRect rect;
	(this->GetDlgItem(IDC_game))->GetWindowRect(&rect);  // 获取控件相对于屏幕的位置
	ScreenToClient(rect); // 转化为相对于客户区的位置
	GetDlgItem(IDC_game)->MoveWindow(rect.left + 4, rect.top + 4, 760, 500, false);

	CDC* pClientDC = GetDC();
	(this->GetDlgItem(IDC_game))->GetWindowRect(&rect);  // 获取控件相对于屏幕的位置
	ScreenToClient(rect); // 转化为相对于客户区的位置
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

	// 画刷初始化
	CBitmap bodybmp, headbmp, beanbmp, bgbmp;
	bgbmp.LoadBitmapW(IDB_BITMAP5);
	beanbmp.LoadBitmapW(IDB_BITMAP4);
	bodybmp.LoadBitmapW(IDB_BITMAP2);
	headbmp.LoadBitmapW(IDB_BITMAP3);
	m_brush[0].CreatePatternBrush(&bodybmp);
	m_brush[1].CreatePatternBrush(&headbmp);
	m_brush[2].CreatePatternBrush(&beanbmp);
	m_brush[3].CreatePatternBrush(&bgbmp);

	// 控件初始化
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMfcSnakeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMfcSnakeDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos) //禁止窗口出界
{
	CDialogEx::OnWindowPosChanging(lpwndpos);

	// TODO: 在此处添加消息处理程序代码
	// 获取屏幕宽度
	int nMaxX = GetSystemMetrics(SM_CXSCREEN);
	// 获取屏幕高度
	int nMaxY = GetSystemMetrics(SM_CYSCREEN);

	// 判断窗口X坐标有无超过左边桌面。
	if (lpwndpos->x < 0)
	{
		lpwndpos->x = 0;
	}

	// 判断窗口X坐标有无超过右边桌面。
	if (lpwndpos->x + lpwndpos->cx > nMaxX)
	{
		lpwndpos->x = nMaxX - lpwndpos->cx;
	}

	// 判断窗口Y坐标有无超过顶部桌面。
	if (lpwndpos->y < 0)
	{
		lpwndpos->y = 0;
	}

	// 判断窗口Y坐标有无超过底部桌面。
	if (lpwndpos->y + lpwndpos->cy > nMaxY)
	{
		lpwndpos->y = nMaxY - lpwndpos->cy;
	}
}

void CMfcSnakeDlg::SnakeInit()
{
	// 获取游戏区
	CDC* pdc = GetDlgItem(IDC_game)->GetWindowDC();

	// 游戏区初始化
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

	// 蛇初始化
	my_snake.init();
	score = 0;
	START = false;
	DEAD = false;
	srand((unsigned)time(NULL));
	drawSnake();
	setBean();

	// 控件初始化
	EDIT_Score.SetWindowTextW(_T("0"));
}

void CMfcSnakeDlg::OnBnClickedButtonStop()
{
	// TODO: 在此添加控件通知处理程序代码
	// 重新开始
	gameOver();
	SnakeInit();
}

void CMfcSnakeDlg::OnBnClickedButtonStart()
{
	// TODO: 在此添加控件通知处理程序代码
	if (DEAD == false) {
		if (START) {
			START = false;
			KillTimer(1);
			SetDlgItemText(IDC_BUTTON_Start, _T("继续游戏"));
		}
		else {
			if (INIT) {
				INIT = false;
				SnakeInit();
			}
			START = true;
			SetTimer(1, speed, NULL);
			SetDlgItemText(IDC_BUTTON_Start, _T("暂停游戏"));
		}
	}
}

void CMfcSnakeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UpdateData(true);
	if (START && DEAD == false) {
		switch (my_snake.direc)
		{
			case 1:MvUp(); break;
			case 2:MvDown(); break;
			case 3:MvLeft(); break;
			case 4:MvRight(); break;
			default:break;
		}
		if (checkLive() == false) {
			DEAD = true;
			gameOver();
			// 创建并显示提示框
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

void CMfcSnakeDlg::MvDraw() // 画蛇移动时
{
    CDC* pdc = GetDlgItem(IDC_game)->GetWindowDC();
    if (pdc == nullptr) {
        return;
    }

    int s_x = my_snake.body[my_snake.len - 1].x;
    int s_y = my_snake.body[my_snake.len - 1].y;

    if (s_x >= 0 && s_x < 25 && s_y >= 0 && s_y < 38) {
        // 将最后一个恢复背景色
        pdc->SelectObject(&pen1);
        pdc->Rectangle(m_map[s_x][s_y]);
        CBrush* pOldBrs = pdc->SelectObject(&m_brush[3]);
        pdc->Rectangle(m_map[s_x][s_y]);
        pdc->SelectObject(pOldBrs);
    }

    pdc->DeleteDC();
}

// 蛇的移动
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


void CMfcSnakeDlg::eatBean() //吃到豆子的判定
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

bool CMfcSnakeDlg::checkLive() //蛇的存活检查
{
	// 判断是否出界
	if (my_snake.body[0].x < 0 || my_snake.body[0].x >= 25 || my_snake.body[0].y < 0 || my_snake.body[0].y >= 38) 
	{
		SetDlgItemText(IDC_BUTTON_Start, _T("开始游戏"));
		return false;
	}
	// 判断是否撞到了自己
	for (int i = 1; i < my_snake.len; i++) {
		if (my_snake.body[0].x == my_snake.body[i].x && my_snake.body[0].y == my_snake.body[i].y) 
		{
			SetDlgItemText(IDC_BUTTON_Start, _T("开始游戏"));
			return false;
		}
	}
	return true;
}

void CMfcSnakeDlg::gameOver()
{
	KillTimer(1);
	START = false;
	SetDlgItemText(IDC_BUTTON_Start, _T("开始游戏"));
}

void CMfcSnakeDlg::OnCbnSelchangeCombospeed() //速度选择
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加专用代码和/或调用基类
	if (START && DEAD == false) {
		if (my_snake.direc != 2 && (pMsg->wParam == VK_UP || pMsg->wParam == 'w' || pMsg->wParam == 'W')) my_snake.direc = 1;
		else if (my_snake.direc != 1 && (pMsg->wParam == VK_DOWN || pMsg->wParam == 's' || pMsg->wParam == 'S')) my_snake.direc = 2;
		else if (my_snake.direc != 4 && (pMsg->wParam == VK_LEFT || pMsg->wParam == 'a' || pMsg->wParam == 'A')) my_snake.direc = 3;
		else if (my_snake.direc != 3 && (pMsg->wParam == VK_RIGHT || pMsg->wParam == 'd' || pMsg->wParam == 'D')) my_snake.direc = 4;
		else if (pMsg->wParam == VK_SPACE) CMfcSnakeDlg::OnBnClickedButtonStart();
	}
	return 0;
}

void CMfcSnakeDlg::OnBnClickedMusic()
{
	// TODO: 在此添加控件通知处理程序代码
	int state = ((CButton*)GetDlgItem(IDC_Music))->GetCheck();
	
	if (state == 0) { PlaySound(NULL, NULL, NULL); }
	else { PlaySound(LPWSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP); }
}

void CMfcSnakeDlg::OnBnClickedButtonpromat()
{
	KillTimer(1);

    // 创建并显示提示框
    CPromatDlg dlg(this);
    dlg.DoModal();
}

void CMfcSnakeDlg::OnBnClickedButtonquit()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}