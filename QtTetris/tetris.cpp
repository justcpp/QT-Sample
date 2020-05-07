#include "tetris.h"

Tetris::Tetris()
{
	//��ʼ�������������
	srand(unsigned(time(NULL)));

	//��ʼ����Ա����
	score = 0;
	for (int i = 0; i < MAXX; i++)
	{
		for (int j = 0; j < MAXY; j++)
		{
			box[i][j] = 0;
		}
	}
	for (int i = 0; i < COUNT; i++)
	{
		block.x[i] = -1;
		block.y[i] = -1;
	}
	block.centerX = -1;
	block.centerY = -1;
	block.ID = 0;
	//������һ������
	createNextBlock();

}


//������ǰ����
//����һ�����ɵ���һ������nextBlock���Ƹ�block
//��������һ��nextBlock
void Tetris::createBlock()
{
	//nextBlock���Ƹ�block
	for (int i = 0; i < COUNT; i++)
	{
		block.x[i] = nextBlock.x[i];
		block.y[i] = nextBlock.y[i];
	}
	block.centerX = nextBlock.centerX;
	block.centerY = nextBlock.centerY;
	block.ID = nextBlock.ID;

	//������һ��nextblock
	createNextBlock();
}


//������һ������
Block Tetris::getNextBlock()
{
	return nextBlock;
}


//���ص�ǰ����
Block Tetris::getBlock()
{
	return block;
}


//���ص�ǰ����
int Tetris::getScore()
{
	return score;
}


//�������꣨x��y����ֵ�����ж��Ƿ��ҷ���
int Tetris::getBox(int x, int y)
{
	return box[x][y];
}


//��ת��ǰ����
//��ת�ɹ�����true�����򷵻�false
bool Tetris::rotate()
{
	if (isRotatable())
	{
		return true;
	}
	else
	{
		return false;
	}
}


//����ǰ���������ƶ�һ��
//�ɹ�����true�����򷵻�false
bool Tetris::moveToLeft()
{
	if (move(-1, 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//����ǰ���������ƶ�һ��
//�ɹ�����true�����򷵻�false
bool Tetris::moveToRight()
{
	if (move(1, 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//�����������ƶ�һ��
//�ɹ�����true�� ��Ϸ��������false
bool Tetris::moveToBottom()
{
	if (!move(0, 1))
	{
		//�ƶ����ɹ�

		blockToBox();   //����ǰ���鸴�Ƶ�box��
		killLines();    //����

						//�ж��Ƿ����
						//���򴴽��µķ���
		if (isEnd())
		{
			return false;
		}
		else
		{
			createBlock();
		}
	}
	return true;
}


//�ж���Ϸ�Ƿ����
//��������Ϊ��һ���з���
bool Tetris::isEnd()
{
	int j = 0;
	for (int i = 0; i < MAXX; i++)
	{
		if (box[i][j] == 1)
		{
			return true;
		}
	}
	return false;
}


//�������в����з�������
void Tetris::killLines()
{
	int count = 0;  //һ������������
					//ͨ��getFirstFullLine()������ô��ϵ��µ�һ������
					//�������ϵ�������ƽ��һ�У��ﵽ���е�Ч��
	int temp = 0;
	while ((temp = getFirstFullLine()) != -1)
	{
		for (int j = temp; j > 0; j--)
		{
			for (int i = 0; i < MAXX; i++)
			{
				box[i][j] = box[i][j - 1];
			}
		}
		count++;
	}
	//���еķ�������
	score += count * count * 10;
}


//�Գ�Ա�������г�ʼ�������¿�ʼ��Ϸ
void Tetris::clear()
{
	//��ʼ��
	score = 0;
	srand(unsigned(time(NULL)));
	for (int i = 0; i < MAXX; i++)
	{
		for (int j = 0; j < MAXY; j++)
		{
			box[i][j] = 0;
		}
	}
	for (int i = 0; i < COUNT; i++)
	{
		block.x[i] = -1;
		block.y[i] = -1;
	}
	block.centerX = -1;
	block.centerY = -1;
	block.ID = 0;
	//������һ������
	createNextBlock();
}


//�����Ϸ���ڵĿ��
int Tetris::getWidth()
{
	return MAXX * WIDTH + (MAXX - 1) * INTERVAL;
}


//�����Ϸ���ڵĸ߶�
int Tetris::getHeight()
{
	return MAXY * HEIGHT + (MAXY - 1) * INTERVAL;
}


//��á���һ�������ڵĿ��
int Tetris::getNextWidth()
{
	return NEXTMAXX * WIDTH + (NEXTMAXX - 1) * INTERVAL;
}


//��á���һ�������ڵĸ߶�
int Tetris::getNextHeight()
{
	return NEXTMAXY * WIDTH + (NEXTMAXY - 1) * INTERVAL;
}


//��������һ��������
void Tetris::createNextBlock()
{
	int centerX = (MAXX - 1) / 2;   //����x����
	int ID = rand() % 7;            //���0 - 6�������
									//���ݲ�ͬ���������������
	switch (ID)
	{
	case 0:
		//##
		//##
		nextBlock.x[0] = centerX;
		nextBlock.x[1] = centerX;
		nextBlock.x[2] = centerX + 1;
		nextBlock.x[3] = centerX + 1;
		nextBlock.y[0] = -2;
		nextBlock.y[1] = -1;
		nextBlock.y[2] = -2;
		nextBlock.y[3] = -1;
		nextBlock.centerX = 0;
		nextBlock.centerY = 0;
		nextBlock.ID = 0;
		break;
	case 1:
		//####
		//
		nextBlock.x[0] = centerX - 1;
		nextBlock.x[1] = centerX;
		nextBlock.x[2] = centerX + 1;
		nextBlock.x[3] = centerX + 2;
		nextBlock.y[0] = -1;
		nextBlock.y[1] = -1;
		nextBlock.y[2] = -1;
		nextBlock.y[3] = -1;
		nextBlock.centerX = centerX;
		nextBlock.centerY = -1;
		nextBlock.ID = 1;
		break;
	case 2:
		//##
		// ##
		nextBlock.x[0] = centerX - 1;
		nextBlock.x[1] = centerX;
		nextBlock.x[2] = centerX;
		nextBlock.x[3] = centerX + 1;
		nextBlock.y[0] = -2;
		nextBlock.y[1] = -2;
		nextBlock.y[2] = -1;
		nextBlock.y[3] = -1;
		nextBlock.centerX = centerX;
		nextBlock.centerY = -2;
		nextBlock.ID = 2;
		break;
	case 3:
		// ##
		//##
		nextBlock.x[0] = centerX;
		nextBlock.x[1] = centerX + 1;
		nextBlock.x[2] = centerX - 1;
		nextBlock.x[3] = centerX;
		nextBlock.y[0] = -2;
		nextBlock.y[1] = -2;
		nextBlock.y[2] = -1;
		nextBlock.y[3] = -1;
		nextBlock.centerX = centerX;
		nextBlock.centerY = -2;
		nextBlock.ID = 3;
		break;
	case 4:
		//#
		//###
		nextBlock.x[0] = centerX - 1;
		nextBlock.x[1] = centerX - 1;
		nextBlock.x[2] = centerX;
		nextBlock.x[3] = centerX + 1;
		nextBlock.y[0] = -2;
		nextBlock.y[1] = -1;
		nextBlock.y[2] = -1;
		nextBlock.y[3] = -1;
		nextBlock.centerX = centerX;
		nextBlock.centerY = -1;
		nextBlock.ID = 4;
		break;
	case 5:
		//  #
		//###
		nextBlock.x[0] = centerX + 1;
		nextBlock.x[1] = centerX - 1;
		nextBlock.x[2] = centerX;
		nextBlock.x[3] = centerX + 1;
		nextBlock.y[0] = -2;
		nextBlock.y[1] = -1;
		nextBlock.y[2] = -1;
		nextBlock.y[3] = -1;
		nextBlock.centerX = centerX;
		nextBlock.centerY = -1;
		nextBlock.ID = 5;
		break;
	case 6:
		// #
		//###
		nextBlock.x[0] = centerX;
		nextBlock.x[1] = centerX - 1;
		nextBlock.x[2] = centerX;
		nextBlock.x[3] = centerX + 1;
		nextBlock.y[0] = -2;
		nextBlock.y[1] = -1;
		nextBlock.y[2] = -1;
		nextBlock.y[3] = -1;
		nextBlock.centerX = centerX;
		nextBlock.centerY = -1;
		nextBlock.ID = 6;
		break;
	default:
		break;
	}
}


//�����ƶ��Ͷ�block���б任������true
//���򷵻�false
bool Tetris::move(int dx, int dy)
{
	int newX[COUNT];
	int newY[COUNT];
	int newCenterX;
	int newCenterY;
	for (int i = 0; i < COUNT; i++)
	{
		newX[i] = block.x[i] + dx;
		newY[i] = block.y[i] + dy;

		//�Ա任�����������ж�

		//x���곬����Χ����false
		if (newX[i] < 0 || newX[i] >= MAXX)
		{
			return false;
		}
		//y������0 - MAXY֮��Ͷ�box�е�״̬�����ж�
		//box��Ϊ1�򷵻�false
		if (newY[i] >= 0 && newY[i] < MAXY)
		{
			if (box[newX[i]][newY[i]] == 1)
			{
				return false;
			}
		}//y���곬�����ֵ����false
		else if (newY[i] >= MAXY)
		{
			return false;
		}

	}
	newCenterX = block.centerX + dx;
	newCenterY = block.centerY + dy;

	//���������ͽ��µ�x��y���긳ֵ��block
	for (int i = 0; i < COUNT; i++)
	{
		block.x[i] = newX[i];
		block.y[i] = newY[i];
	}
	block.centerX = newCenterX;
	block.centerY = newCenterY;

	return true;
}


//������ת�Ͷ�block���б任������true
//���򷵻�false
bool Tetris::isRotatable()
{
	int newX[COUNT];
	int newY[COUNT];
	int newCenterX;
	int newCenterY;

	if (block.ID == 0)
	{
		return false;
	}

	for (int i = 0; i < COUNT; i++)
	{
		int nx = block.x[i] - block.centerX;
		int ny = block.y[i] - block.centerY;
		newX[i] = nx * 0 + ny * (-1) + block.centerX;
		newY[i] = nx * 1 + ny * 0 + block.centerY;

		//�Ա任�����������ж�

		//x���곬����Χ����false
		if (newX[i] < 0 || newX[i] >= MAXX)
		{
			return false;
		}
		//y������0 - MAXY ֮��Ͷ�box�е�״̬�����ж�
		//box��Ϊ1�򷵻�false
		if (newY[i] >= 0 && newY[i] < MAXY)
		{
			if (box[newX[i]][newY[i]] == 1)
			{
				return false;
			}
		}//y���곬�����ֵ����false
		else if (newY[i] >= MAXY)
		{
			return false;
		}
	}
	newCenterX = block.centerX;
	newCenterY = block.centerY;

	//�������������block�ĸ�ֵ
	for (int i = 0; i < COUNT; i++)
	{
		block.x[i] = newX[i];
		block.y[i] = newY[i];
	}
	block.centerX = newCenterX;
	block.centerY = newCenterY;

	return true;
}


//��block�����ݸ��Ƶ�box��
void Tetris::blockToBox()
{
	for (int i = 0; i < COUNT; i++)
	{
		int x = block.x[i];
		int y = block.y[i];
		if (y >= 0)
		{
			box[x][y] = 1;
		}
	}
}


//��õ�һ�����е�������������
int Tetris::getFirstFullLine()
{
	//����j��1��ʼ�ͺ�
	for (int j = 0; j < MAXY; j++)
	{
		bool judgement = true;
		for (int i = 0; i < MAXX; i++)
		{
			if (box[i][j] == 0)
			{
				judgement = false;
				break;
			}
		}
		if (judgement)
		{
			return j;
		}
	}
	return -1;
}