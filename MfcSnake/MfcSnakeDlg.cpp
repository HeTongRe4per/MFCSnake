
// MfcSnakeDlg.cpp: ʵ���ļ�
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



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMfcSnakeDlg �Ի���



CMfcSnakeDlg::CMfcSnakeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSNAKE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
	pen1.CreatePen(PS_SOLID, 4, RGB(174, 221, 129));

	// ���ó�ʼֵ
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
    // ����������ʱ��
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


// CMfcSnakeDlg ��Ϣ�������

BOOL CMfcSnakeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return FALSE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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


//  �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMfcSnakeDlg::OnPaint()
{
	// ��Ϸ�����ʼ������
	
	CRect rect;
	(this->GetDlgItem(IDC_game))->GetWindowRect(&rect);  // ��ȡ�ؼ��������Ļ��λ��
	ScreenToClient(rect); // ת��Ϊ����ڿͻ�����λ��
	GetDlgItem(IDC_game)->MoveWindow(rect.left + 4, rect.top + 4, 760, 500, false);

	CDC* pClientDC = GetDC();
	(this->GetDlgItem(IDC_game))->GetWindowRect(&rect);  // ��ȡ�ؼ��������Ļ��λ��
	ScreenToClient(rect); // ת��Ϊ����ڿͻ�����λ��
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

	// ��ˢ��ʼ��
	CBitmap bodybmp, headbmp, beanbmp, bgbmp;
	bgbmp.LoadBitmapW(IDB_BITMAP5);
	beanbmp.LoadBitmapW(IDB_BITMAP4);
	bodybmp.LoadBitmapW(IDB_BITMAP2);
	headbmp.LoadBitmapW(IDB_BITMAP3);
	m_brush[0].CreatePatternBrush(&bodybmp);
	m_brush[1].CreatePatternBrush(&headbmp);
	m_brush[2].CreatePatternBrush(&beanbmp);
	m_brush[3].CreatePatternBrush(&bgbmp);

	// �ؼ���ʼ��
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMfcSnakeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMfcSnakeDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos) //��ֹ���ڳ���
{
	CDialogEx::OnWindowPosChanging(lpwndpos);

	// TODO: �ڴ˴������Ϣ����������
	// ��ȡ��Ļ���
	int nMaxX = GetSystemMetrics(SM_CXSCREEN);
	// ��ȡ��Ļ�߶�
	int nMaxY = GetSystemMetrics(SM_CYSCREEN);

	// �жϴ���X�������޳���������档
	if (lpwndpos->x < 0)
	{
		lpwndpos->x = 0;
	}

	// �жϴ���X�������޳����ұ����档
	if (lpwndpos->x + lpwndpos->cx > nMaxX)
	{
		lpwndpos->x = nMaxX - lpwndpos->cx;
	}

	// �жϴ���Y�������޳����������档
	if (lpwndpos->y < 0)
	{
		lpwndpos->y = 0;
	}

	// �жϴ���Y�������޳����ײ����档
	if (lpwndpos->y + lpwndpos->cy > nMaxY)
	{
		lpwndpos->y = nMaxY - lpwndpos->cy;
	}
}

void CMfcSnakeDlg::SnakeInit()
{
	// ��ȡ��Ϸ��
	CDC* pdc = GetDlgItem(IDC_game)->GetWindowDC();

	// ��Ϸ����ʼ��
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

	// �߳�ʼ��
	my_snake.init();
	score = 0;
	START = false;
	DEAD = false;
	srand((unsigned)time(NULL));
	drawSnake();
	setBean();

	// �ؼ���ʼ��
	EDIT_Score.SetWindowTextW(_T("0"));
}

void CMfcSnakeDlg::OnBnClickedButtonStop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ���¿�ʼ
	gameOver();
	SnakeInit();
}

void CMfcSnakeDlg::OnBnClickedButtonStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (DEAD == false) {
		if (START) {
			START = false;
			KillTimer(1);
			SetDlgItemText(IDC_BUTTON_Start, _T("������Ϸ"));
		}
		else {
			if (INIT) {
				INIT = false;
				SnakeInit();
			}
			START = true;
			SetTimer(1, speed, NULL);
			SetDlgItemText(IDC_BUTTON_Start, _T("��ͣ��Ϸ"));
		}
	}
}

void CMfcSnakeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
			// ��������ʾ��ʾ��
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

void CMfcSnakeDlg::MvDraw() // �����ƶ�ʱ
{
    CDC* pdc = GetDlgItem(IDC_game)->GetWindowDC();
    if (pdc == nullptr) {
        return;
    }

    int s_x = my_snake.body[my_snake.len - 1].x;
    int s_y = my_snake.body[my_snake.len - 1].y;

    if (s_x >= 0 && s_x < 25 && s_y >= 0 && s_y < 38) {
        // �����һ���ָ�����ɫ
        pdc->SelectObject(&pen1);
        pdc->Rectangle(m_map[s_x][s_y]);
        CBrush* pOldBrs = pdc->SelectObject(&m_brush[3]);
        pdc->Rectangle(m_map[s_x][s_y]);
        pdc->SelectObject(pOldBrs);
    }

    pdc->DeleteDC();
}

// �ߵ��ƶ�
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


void CMfcSnakeDlg::eatBean() //�Ե����ӵ��ж�
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

bool CMfcSnakeDlg::checkLive() //�ߵĴ����
{
	// �ж��Ƿ����
	if (my_snake.body[0].x < 0 || my_snake.body[0].x >= 25 || my_snake.body[0].y < 0 || my_snake.body[0].y >= 38) 
	{
		SetDlgItemText(IDC_BUTTON_Start, _T("��ʼ��Ϸ"));
		return false;
	}
	// �ж��Ƿ�ײ�����Լ�
	for (int i = 1; i < my_snake.len; i++) {
		if (my_snake.body[0].x == my_snake.body[i].x && my_snake.body[0].y == my_snake.body[i].y) 
		{
			SetDlgItemText(IDC_BUTTON_Start, _T("��ʼ��Ϸ"));
			return false;
		}
	}
	return true;
}

void CMfcSnakeDlg::gameOver()
{
	KillTimer(1);
	START = false;
	SetDlgItemText(IDC_BUTTON_Start, _T("��ʼ��Ϸ"));
}

void CMfcSnakeDlg::OnCbnSelchangeCombospeed() //�ٶ�ѡ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ����ר�ô����/����û���
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int state = ((CButton*)GetDlgItem(IDC_Music))->GetCheck();
	
	if (state == 0) { PlaySound(NULL, NULL, NULL); }
	else { PlaySound(LPWSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP); }
}

void CMfcSnakeDlg::OnBnClickedButtonpromat()
{
	KillTimer(1);

    // ��������ʾ��ʾ��
    CPromatDlg dlg(this);
    dlg.DoModal();
}

void CMfcSnakeDlg::OnBnClickedButtonquit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}