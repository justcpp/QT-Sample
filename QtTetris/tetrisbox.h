#pragma once

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPalette>
#include <QPen>
#include <QBrush>
#include <QColor>
//Ϊ��ʹ��Block
#include "tetris.h"

class TetrisBox : public QWidget
{
	Q_OBJECT
public:
	explicit TetrisBox(QWidget *parent = nullptr);
	void updateTetris(Tetris tetris);       //�������ݺ���ͼ
	void paintEvent(QPaintEvent *event);    //������ͼ

signals:

	public slots :

private:
	Block block;            //��������Tetris��block������
	int box[MAXX][MAXY];    //�����洢Tetris��box������
};