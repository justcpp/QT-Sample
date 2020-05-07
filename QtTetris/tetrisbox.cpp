#include "tetrisbox.h"
TetrisBox::TetrisBox(QWidget *parent) : QWidget(parent)
{
	//��block��ʼ��
	for (int i = 0; i < COUNT; i++)
	{
		block.x[i] = -1;
		block.y[i] = -1;
	}
	block.centerX = -1;
	block.centerY = -1;
	block.ID = -1;
	//��box��ʼ��
	for (int i = 0; i < MAXX; i++)
	{
		for (int j = 0; j < MAXY; j++)
		{
			box[i][j] = 0;
		}
	}

	//���ñ���Ϸ���ڵĿ��Ⱥ͸߶�
	//�����ñ���Ϊ��ɫ
	int w = Tetris::getWidth();
	int h = Tetris::getHeight();
	setFixedSize(w, h);
	setPalette(QPalette(Qt::black));
	setAutoFillBackground(true);
}


void TetrisBox::updateTetris(Tetris tetris)
{
	//����block
	block = tetris.getBlock();
	//����box
	for (int i = 0; i < MAXX; i++)
	{
		for (int j = 0; j < MAXY; j++)
		{
			box[i][j] = tetris.getBox(i, j);
		}
	}
	repaint();
}


void TetrisBox::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QPen pen;
	QBrush brush;
	pen.setStyle(Qt::SolidLine);
	pen.setColor(QColor(255, 0, 0));
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(QColor(255, 0, 0));
	painter.setPen(pen);
	painter.setBrush(brush);

	//����box�е�����
	for (int i = 0; i < MAXX; i++)
	{
		for (int j = 0; j < MAXY; j++)
		{
			if (box[i][j] == 1)
			{
				int x = i * WIDTH + i * INTERVAL;
				int y = j * HEIGHT + j * INTERVAL;
				painter.drawRect(x, y, WIDTH, HEIGHT);
			}
		}
	}
	//����block�е�����
	for (int i = 0; i < COUNT; i++)
	{
		int x = block.x[i];
		int y = block.y[i];
		int x1 = x * WIDTH + x * INTERVAL;
		int y1 = y * HEIGHT + y * INTERVAL;
		painter.drawRect(x1, y1, WIDTH, HEIGHT);
	}
}