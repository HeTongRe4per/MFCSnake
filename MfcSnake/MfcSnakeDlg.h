
// MfcSnakeDlg.h: Õ∑Œƒº˛
//

#pragma once

#include "GGDlg.h"
#include "Snake.h"
#include "PromatDlg.h"


// CMfcSnakeDlg ∂‘ª∞øÚ
class CMfcSnakeDlg : public CDialogEx
{
// ππ‘Ï
public:
	CMfcSnakeDlg(CWnd* pParent = nullptr);	// ±Í◊ºππ‘Ï∫Ø ˝

// ∂‘ª∞øÚ ˝æ›
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSNAKE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ÷ß≥÷


//  µœ÷
protected:
	HICON m_hIcon;

	// …˙≥…µƒœ˚œ¢”≥…‰∫Ø ˝
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnCbnSelchangeCombospeed();
	CComboBox Box;
	CEdit EDIT_Score;
<<<<<<< HEAD
	CFont m_showFont1;
	CFont m_showFont2;
	CFont m_showFont3;
	CBrush m_brush[4];
	CRect m_map[30][38];
	Point pos ;//= { 0, 0 };
	CSnake my_snake;
	CPen pen1;
	int speed ;//= 150; // …Ë÷√ÀŸ∂»
	int score ;//= 0;
	bool INIT ;//= true;
	bool START ;//= false;
	bool DEAD ;//= false;
=======
	CBrush m_brush[4];
	CRect m_map[25][38];
	Point pos ;
	CSnake my_snake;
	CPen pen1;
	int speed ;
	int score ;
	bool INIT ;
	bool START ;
	bool DEAD ;
>>>>>>> 78f0edb ('Á¨¨‰∏ÄÊ¨°Êèê‰∫§')
	void SnakeInit();
	bool setBean();
	void drawSnake();
	void MvDraw();
	void MvUp();
	void MvDown();
	void MvLeft();
	void MvRight();
	void eatBean();
	bool checkLive();
	void gameOver();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	afx_msg void OnBnClickedMusic();
	afx_msg void OnBnClickedButtonquit();
	afx_msg void OnBnClickedButtonpromat();
};
