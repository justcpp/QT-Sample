#pragma once

#include <QMainWindow>
#include <QMainWindow>
#include <QPainter>
#include <QEvent>
#include <QPaintEvent>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QKeyEvent>
#include <QTimer>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>
#include "tetris.h"
#include "tetrisbox.h"
#include "nexttetrisbox.h"

//��Ϸ��״̬
#define STATUS_ON 0     //��Ϸ��������
#define STATUS_PAUSE 1  //��Ϸ��ͣ
#define STATUS_OFF 2    //��Ϸδ��ʼ
#define STATUS_END 3    //��Ϸ����

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void keyPressEvent(QKeyEvent *event);   //��Ӧ�����¼�
	void changeEvent(QEvent *event);        //������С������ͣ
	void updateScore();                     //���·��������ݺ���ʾ

	public slots:
	void onTimer();

private:
	int status;                     //��Ϸ״̬
	Tetris tetris;                  //����˹���������
	QTimer *timer;                  //��ʱ��
	TetrisBox *tetrisBox;           //��Ϸ����
	NextTetrisBox *nextTetrisBox;   //����һ��������
	QGridLayout *mainLayout;        //mainLayout
	QLabel *nextTetrisLabel;        //����һ�������ڵı�ǩ
	QLabel *controlLabel;           //�����ơ���ǩ
	QLabel *w_controlLabel;         //W���ı�ǩ
	QLabel *s_controlLabel;         //S���ı�ǩ
	QLabel *a_controlLabel;         //A���ı�ǩ
	QLabel *d_controlLabel;         //D���ı�ǩ
	QLabel *h_controlLabel;         //H���ı�ǩ
	QLabel *j_controlLabel;         //J���ı�ǩ
	QLabel *c_controlLabel;         //C���ı�ǩ
	QLabel *m_controlLabel;         //M���ı�ǩ
	QLabel *scoreTitleLabel;        //���������ǩ
	QLabel *scoreLabel;             //������ǩ��������ʾ������

};