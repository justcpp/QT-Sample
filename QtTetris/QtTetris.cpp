#include "QtTetris.h"


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//��������
	tetrisBox = new TetrisBox;
	nextTetrisBox = new NextTetrisBox;
	nextTetrisLabel = new QLabel(tr("Next:"));
	controlLabel = new QLabel(tr("Control:"));
	w_controlLabel = new QLabel(tr("W-Revolve"));
	s_controlLabel = new QLabel(tr("S-Down"));
	a_controlLabel = new QLabel(tr("A-Left"));
	d_controlLabel = new QLabel(tr("D-Right"));
	h_controlLabel = new QLabel(tr("H-Start"));
	j_controlLabel = new QLabel(tr("J-Pause"));
	c_controlLabel = new QLabel(tr("C-Restart"));
	m_controlLabel = new QLabel(tr("M-GameOver"));
	scoreTitleLabel = new QLabel(tr("Scores:"));
	scoreLabel = new QLabel(tr("0"));
	mainLayout = new QGridLayout;
	//����mainLayout��ˮƽ�ͺ���ļ��Ϊ20
	mainLayout->setHorizontalSpacing(20);
	mainLayout->setVerticalSpacing(20);
	//����mainLayout����
	mainLayout->setAlignment(Qt::AlignCenter);
	//��Ӹ���widget
	mainLayout->addWidget(tetrisBox, 0, 0, 14, 1);
	mainLayout->addWidget(nextTetrisLabel, 0, 1);
	mainLayout->addWidget(nextTetrisBox, 1, 1, 1, 1);
	mainLayout->addWidget(controlLabel, 5, 1);
	mainLayout->addWidget(w_controlLabel, 6, 1);
	mainLayout->addWidget(s_controlLabel, 6, 2);
	mainLayout->addWidget(a_controlLabel, 7, 1);
	mainLayout->addWidget(d_controlLabel, 7, 2);
	mainLayout->addWidget(h_controlLabel, 8, 1);
	mainLayout->addWidget(j_controlLabel, 8, 2);
	mainLayout->addWidget(c_controlLabel, 9, 1);
	mainLayout->addWidget(m_controlLabel, 9, 2);
	mainLayout->addWidget(scoreTitleLabel, 12, 1);
	mainLayout->addWidget(scoreLabel, 12, 2);

	//��ΪmainWindow����һ��layout�����Բ���ֱ�ӽ�mainLayout
	//���õ�mainWindow�У���Ҫ�Ƚ�mainLayout����Ϊһ��widget��layout
	//�ڽ�widget����ΪmainLayout��centralWidget
	QWidget *widget = new QWidget(this);
	widget->setLayout(mainLayout);
	setCentralWidget(widget);

	//���ô��ڱ���Ϊ��ɫ
	setPalette(Qt::gray);
	//���ô����ڵ�����Ļ�Ͼ���
	QDesktopWidget *desktopWidget = QApplication::desktop();
	int w = (desktopWidget->width() - this->width()) / 2;
	int h = 5;
	move(w, h);

	//��ʼ��
	status = STATUS_OFF;
	nextTetrisBox->updateNextTetris(tetris);
	setWindowTitle(tr("Game_Tetris - OFF"));
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
}

MainWindow::~MainWindow()
{

}


//��Ӧ�����¼�
void MainWindow::keyPressEvent(QKeyEvent *event)
{
	//W��-������ת��������Ϸ��������
	if (event->key() == Qt::Key_W)
	{
		if (tetris.rotate())
		{
			//��Ҫ��Ϸ״̬Ϊ����������
			if (status == STATUS_ON)
			{
				tetrisBox->updateTetris(tetris);
			}
		}
	}
	//A��-�����������ƶ���������Ϸ��������
	else if (event->key() == Qt::Key_A)
	{
		//��Ҫ��Ϸ״̬Ϊ����������
		if (status == STATUS_ON)
		{
			if (tetris.moveToLeft())
			{
				tetrisBox->updateTetris(tetris);

			}
		}
	}
	//S��-�����������ƶ���������Ϸ��������
	else if (event->key() == Qt::Key_S)
	{
		//��Ҫ��Ϸ״̬����������
		if (status == STATUS_ON)
		{
			if (tetris.moveToBottom())
			{
				tetrisBox->updateTetris(tetris);
				nextTetrisBox->updateNextTetris(tetris);
				updateScore();
			}
			else    //��Ϸ����
			{
				//��ʱ��ֹͣ
				timer->stop();
				//���������ʾ
				QString str;
				str += QString("Game Over!\nYour Score is: %1!").arg(tetris.getScore());
				QMessageBox::information(this, tr("Game Over"), str);
				//������Ϸ״̬Ϊ����Ϸ����
				status = STATUS_END;
				setWindowTitle(tr("Game_Tetris - END"));
			}
		}
	}
	//D��-�����������ƶ���������Ϸ��������
	else if (event->key() == Qt::Key_D)
	{
		//��Ҫ��Ϸ״̬Ϊ����������
		if (status == STATUS_ON)
		{
			if (tetris.moveToRight())
			{
				tetrisBox->updateTetris(tetris);
			}
		}
	}
	//H��-��ʼ��Ϸ
	//��ͬ״̬����Ӧ��
	//֮ǰ״̬    ֮��״̬
	//��Ϸ��ͣ -> ��������
	//��δ��ʼ -> ��������
	//��Ϸ���� -> ��������
	else if (event->key() == Qt::Key_H)
	{
		if (status == STATUS_PAUSE)
		{
			timer->start(500);
			status = STATUS_ON;
			setWindowTitle(tr("Game_Tetris - ON"));
		}
		else if (status == STATUS_OFF)
		{
			//��ʼ��������ͼ
			tetris.createBlock();
			tetrisBox->updateTetris(tetris);
			nextTetrisBox->updateNextTetris(tetris);
			updateScore();

			status = STATUS_ON;
			setWindowTitle(tr("Game_Tetris - ON"));
			timer->start(500);
		}
		else if (status == STATUS_END)
		{
			//��ʼ��tetris
			tetris.clear();
			tetris.createBlock();
			tetrisBox->updateTetris(tetris);
			nextTetrisBox->updateNextTetris(tetris);
			updateScore();

			status = STATUS_ON;
			setWindowTitle(tr("Game_Tetris - ON"));
			timer->start(500);
		}
	}
	//J��-��Ϸ��ͣ
	else if (event->key() == Qt::Key_J)
	{
		//��Ҫ��Ϸ״̬Ϊ����������
		if (status == STATUS_ON)
		{
			timer->stop();
			status = STATUS_PAUSE;
			setWindowTitle(tr("Game_Tetris - PAUSE"));
		}
	}
	//C��-���¿�ʼ��Ϸ
	else if (event->key() == Qt::Key_C)
	{
		timer->stop();
		tetris.clear();
		tetrisBox->updateTetris(tetris);
		nextTetrisBox->updateNextTetris(tetris);
		updateScore();
		status = STATUS_OFF;
		setWindowTitle(tr("Game_Tetris - OFF"));

	}
	//M��-�ر���Ϸ
	else if (event->key() == Qt::Key_M)
	{
		close();
	}

}


void MainWindow::onTimer()
{
	if (tetris.moveToBottom())
	{
		tetrisBox->updateTetris(tetris);
		nextTetrisBox->updateNextTetris(tetris);
		updateScore();
	}
	else
	{
		timer->stop();
		QString str;
		str += QString("Game Over!\nYour Score is: %1!").arg(tetris.getScore());
		QMessageBox::information(this, tr("Game Over"), str);
		status = STATUS_END;
		setWindowTitle(tr("Game_Tetris - END"));
	}
}


void MainWindow::updateScore()
{
	QString str;
	int score = tetris.getScore();
	str += QString("%1").arg(score);
	scoreLabel->setText(str);
}


//��������С����ֹͣ��ʱ��
void MainWindow::changeEvent(QEvent *event)
{
	if (event->type() != QEvent::WindowStateChange)
	{
		return;
	}
	if (windowState() == Qt::WindowMinimized)
	{
		timer->stop();
	}
}