#pragma once
//Ϊ�˻�������
#include <cstdlib>
#include <ctime>

#define MAXX 10     //��ʾ���ڵĺ������
#define MAXY 20     //��ʾ���ڵ��������
#define NEXTMAXX 6  //����һ������ʾ���ڵĺ������
#define NEXTMAXY 6  //����һ������ʾ���ڵ��������
#define WIDTH 30    //����Ŀ��
#define HEIGHT 30   //����ĸ߶�
#define INTERVAL 4  //����֮��ļ��
#define COUNT 4     //ÿ������ĸ���

//Block�ṹ�壺һ������
struct Block
{
	int x[COUNT];   //���鵥���x����
	int y[COUNT];   //���鵥���y����
	int centerX;    //���������x����     
	int centerY;    //���������y����
	int ID;         //�����ID
};


class Tetris
{
public:
	Tetris();
	void createBlock();             //������ǰ����
	Block getNextBlock();           //�����һ������
	Block getBlock();               //��õ�ǰ����
	int getScore();                 //��÷���
	int getBox(int x, int y);       //�����Ӧ�����״̬
	bool rotate();                  //��ת
	bool moveToLeft();              //�����ƶ�
	bool moveToRight();             //�����ƶ�
	bool moveToBottom();            //�����ƶ�
	bool isEnd();                   //�ж��Ƿ����
	void killLines();               //��ȥ����
	void clear();                   //���³�ʼ��

	static int getWidth();          //��ô��ڵĿ��
	static int getHeight();         //��ô��ڵĸ߶�
	static int getNextWidth();      //��á���һ�������ڵĿ��
	static int getNextHeight();     //��á���һ�������ڵĸ߶�



private:
	void createNextBlock();         //������һ������
	bool move(int dx, int dy);      //�Ƿ�����ƶ�
	void blockToBox();              //��block�е�����ת�Ƶ�box��
	bool isRotatable();             //�Ƿ������ת
	int getFirstFullLine();         //��õ�һ������

private:
	int score;          //����
	Block block;        //��ǰ����
	Block nextBlock;    //��һ������
	int box[MAXX][MAXY];//���������ϵ 1��ʾ�з���0��ʾû�з���


};