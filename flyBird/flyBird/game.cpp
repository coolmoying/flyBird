#include "game.h"
#include "button.h"
#include "imgdata.h"
#include "music.h"
#include "bkdown.h"
#include "bird.h"
#include "pillar.h"
int cas;//����С�񶯻�����
double tempcas;//����С�񶯻�����
struct Button* beginGame = NULL;
struct Button* endGame = NULL;
struct Bird* pBird = NULL;
void initData()
{
	beginGame = CreatButton(80, 500, 150, 50, "START", RGB(234, 139, 83), RGB(240, 240, 240));
	endGame = CreatButton(420, 500, 150, 50, "END", RGB(234, 139, 83), RGB(240, 240, 240));
	pBird = CreateBird(WIDTH / 5.0 - 50, HEIGHT * 2 / 5,0.6);
	cas = 0;
	//��ʼ����£��Ȳ�����������
	for (int i = 0; i < 2; i++) {
		CreateBkDown(bkdown, i);
		bkdown[i].x = 1.0*WIDTH * i;
	}
	//��ʼ����£��Ȳ�����������
	for (int i = 0; i < PILLAR_NUM; i++) {
		CreatePillar(pillar, i);
		pillar[i].x = 0.0+WIDTH + 235 * i;
	}
}

void beginLayout() 
{
	cleardevice();//����
	putimage(0, 0, &bk);
	DrawGuid(10, 10);//��������ͼƬ
	DrawButton(beginGame);//���ƿ�ʼ��ť
	DrawButton(endGame);//���ƽ�����ť
	//���Ʊ���ͼƬ
	for (int i = 0; i < 2; i++) {
		if (bkdown[i].flag == 1) {//���������ʱ���Ե�����л���
			DrawBackground(bkdown[i]);
		}
	}
}
void run()
{
	LoadResource();
	initData();
	initgraph(WIDTH, HEIGHT);
	musicBGM();
	BeginBatchDraw();
	runAction();
	fflush(stdin);//��ռ�����Ϣ������
	flushmessage();//��������Ϣ������
	while (1)
	{
		KeyDown(pBird);
		MoveBird(pBird);
		MovePillar();
		BkDownMove();
		drawGame();
		flyAction();
		FlushBatchDraw();
		if (GameOver() == 1) 
		{
			musicEnd();
			hitAction();
			overAction();
			MessageBox(GetHWnd(), "You Lose", "Game Over��", MB_OK);
			break;
		}
	}
	EndBatchDraw();
	closegraph();
}
void runAction()
{
	//���ÿ�ʼ������ʼ����
	double startX = 121;
	double startY = 87;
	//���ö���Ư�Ʒ����Լ�״̬��ʶ
	double step = 0.38;
	int flag = 0;
	//���þֲ��������ڼ�¼λ�ƴ�ֵ
	double tempstep = step;

	while (1) {
		beginLayout();
		//���ø�������Ч��
		if (flag == 0) {//��ʱ���������ƶ�
			step -= 0.0035;
			if (step <= -tempstep) {
				step = -tempstep;
				flag = 1;//�˺󶯻���ʼ�����ƶ�
			}
		}
		else if (flag == 1) {//��ʱ���������ƶ�
			step += 0.0035;
			if (step >= tempstep) {
				step = tempstep;
				flag = 0;//�˺󶯻���ʼ�����ƶ�
			}
		}
		startY += step;
		//���ƶ���Ч��
		putimage(startX, startY, start + 1, SRCAND);//������ͼ
		putimage(startX, startY, start, SRCPAINT);//��Դ��ͼ
		BkDownMove();
		FlushBatchDraw();
		//����Ƿ�����ť�ж�
		if (MouseControl(beginGame, endGame) == 1) {
			break;
		}
	}
}
//��Ϸ��������
void overAction() {
	//��ʼ��������
	double startX = WIDTH / 2 - 204 / 2;
	double startY = HEIGHT;

	//���ƶ���Ч��
	while (startY >= HEIGHT / 2 - 54 / 2)
	{
		drawGame();
		putimage(startX, startY, end + 1, SRCAND);//������ͼ
		putimage(startX, startY, end, SRCPAINT);//��Դ��ͼ
		FlushBatchDraw();
		startY -= 0.68;//���ƶ����ٶ�
		Sleep(0);//���ƶ����ٶ�
	}
}
//��Ϸײ������
void hitAction() {
	//���������ٶ�
	double step = -1.85;

	//���ƶ���Ч��
	while (pBird->y + BIRD_SIZE - 15 <= 607) {
		pBird->y += step;
		step += 0.025;
		drawGame();
		FlushBatchDraw();
	}
}
//��Ϸ�ȳ�򶯻�
void flyAction() {
	tempcas += 0.025;
	if (tempcas >= 3) {
		tempcas = 0;
	}
	cas = (int)tempcas;
}


void drawGame()
{
	cleardevice();//����
	putimage(0, 0, &bk);
	//���Ʊ���ͼƬ
	for (int i = 0; i < 2; i++) {
		if (bkdown[i].flag == 1) {//���������ʱ���Ե�����л���
			DrawBackground(bkdown[i]);
		}
	}

	//��������ͼƬ
	for (int i = 0; i < PILLAR_NUM; i++) {
		if (pillar[i].flag == 1) {//�����Ӵ���ʱ�������ӽ��л���
			DrawPillar(pillar[i]);
		}
	}
	//����С��
	DrawBird(pBird->x,pBird->y,cas);
}
//��Ϸ����״̬
int HitPillar(Pillar pillar[])
{
	for (int i = 0; i < PILLAR_NUM; i++) {
		if (pillar[i].x <= pBird->x + BIRD_SIZE - 15 && pillar[i].x >= pBird->x - 65 + 10)
		{
			//�ж������Ƿ�����ײ
			if (pBird->y + 15 <= pillar[i].height) {
				return 1;//����ֵΪ1˵������ײ����
			}
			//�ж������Ƿ�����ײ
			if (pBird->y + BIRD_SIZE - 15 >= 607.0 - (400 - pillar[i].height)) {
				return 1;//����ֵΪ1˵������ײ����
			}
		}
	}
	return 0;//����ֵΪ0˵��û����ײ
}
//��Ϸ��������1
int Condition1() {
	//��С��ײ���ذ�ʱ����Ϸ����
	if (pBird->y >= 607 - BIRD_SIZE + 15) {
		return 1;//����ֵΪ1ʱ��Ϸ����
	}
	//С��ײ���컨��ʱ����Ϸ����
	else if (pBird->y <= 0 - 15) {
		return 1;//����ֵΪ1ʱ��Ϸ����
	}
	return 0;//����ֵΪ0ʱ��Ϸδ����
}
//��Ϸ��������2
int Condition2() {
	//��С��ײ������ʱ��Ϸ����
	return HitPillar(pillar);
}
//��Ϸ���������ж�
int GameOver() {
	if (Condition1() == 1 || Condition2() == 1) {
		return 1;//����ֵΪ1ʱ��Ϸ����
	}
	return 0;//����ֵΪ0ʱ��Ϸδ����
}

