#pragma once

#include <QWidget>
#include <QWidget>
#include <QPaintEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QColor>
#include "tetris.h"

#define RESTX (MAXX - NEXTMAXX) / 2     //����x�����ת������
#define RESTY 4                         //����y�����ת������

class NextTetrisBox : public QWidget
{
	Q_OBJECT
public:
	explicit NextTetrisBox(QWidget *parent = nullptr);
	void updateNextTetris(Tetris tetris);   //���¡���һ���������ݺ���ͼ
	void paintEvent(QPaintEvent *event);    //������ͼ

signals:

	public slots :

private:
	Block nextBlock;    //����һ��������
};