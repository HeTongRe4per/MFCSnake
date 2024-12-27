
// MfcSnakeDlg.h: 头文件
//

#pragma once

#include "GGDlg.h"
#include "Snake.h"
#include "PromatDlg.h"


// CMfcSnakeDlg 对话框
class CMfcSnakeDlg : public CDialogEx
{
// 构造
public:
	CMfcSnakeDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSNAKE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
