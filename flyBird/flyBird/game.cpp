#include "game.h"
#include "button.h"
#include "imgdata.h"
#include "music.h"
#include "bkdown.h"
#include "bird.h"
#include "pillar.h"
int cas;//用于小鸟动画设置
double tempcas;//用于小鸟动画设置
struct Button* beginGame = NULL;
struct Button* endGame = NULL;
struct Bird* pBird = NULL;
void initData()
{
	beginGame = CreatButton(80, 500, 150, 50, "START", RGB(234, 139, 83), RGB(240, 240, 240));
	endGame = CreatButton(420, 500, 150, 50, "END", RGB(234, 139, 83), RGB(240, 240, 240));
	pBird = CreateBird(WIDTH / 5.0 - 50, HEIGHT * 2 / 5,0.6);
	cas = 0;
	//初始情况下，先产生两个地面
	for (int i = 0; i < 2; i++) {
		CreateBkDown(bkdown, i);
		bkdown[i].x = 1.0*WIDTH * i;
	}
	//初始情况下，先产生三对柱子
	for (int i = 0; i < PILLAR_NUM; i++) {
		CreatePillar(pillar, i);
		pillar[i].x = 0.0+WIDTH + 235 * i;
	}
}

void beginLayout() 
{
	cleardevice();//清屏
	putimage(0, 0, &bk);
	DrawGuid(10, 10);//绘制引导图片
	DrawButton(beginGame);//绘制开始按钮
	DrawButton(endGame);//绘制结束按钮
	//绘制背景图片
	for (int i = 0; i < 2; i++) {
		if (bkdown[i].flag == 1) {//当地面存在时，对地面进行绘制
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
	fflush(stdin);//清空键盘消息缓冲区
	flushmessage();//清空鼠标消息缓冲区
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
			MessageBox(GetHWnd(), "You Lose", "Game Over！", MB_OK);
			break;
		}
	}
	EndBatchDraw();
	closegraph();
}
void runAction()
{
	//设置开始动画初始坐标
	double startX = 121;
	double startY = 87;
	//设置动画漂移幅度以及状态标识
	double step = 0.38;
	int flag = 0;
	//设置局部变量用于记录位移处值
	double tempstep = step;

	while (1) {
		beginLayout();
		//设置浮动动画效果
		if (flag == 0) {//此时动画向下移动
			step -= 0.0035;
			if (step <= -tempstep) {
				step = -tempstep;
				flag = 1;//此后动画开始向上移动
			}
		}
		else if (flag == 1) {//此时动画向上移动
			step += 0.0035;
			if (step >= tempstep) {
				step = tempstep;
				flag = 0;//此后动画开始向下移动
			}
		}
		startY += step;
		//绘制动画效果
		putimage(startX, startY, start + 1, SRCAND);//贴掩码图
		putimage(startX, startY, start, SRCPAINT);//贴源码图
		BkDownMove();
		FlushBatchDraw();
		//鼠标是否点击按钮判断
		if (MouseControl(beginGame, endGame) == 1) {
			break;
		}
	}
}
//游戏结束动画
void overAction() {
	//起始坐标设置
	double startX = WIDTH / 2 - 204 / 2;
	double startY = HEIGHT;

	//绘制动画效果
	while (startY >= HEIGHT / 2 - 54 / 2)
	{
		drawGame();
		putimage(startX, startY, end + 1, SRCAND);//贴掩码图
		putimage(startX, startY, end, SRCPAINT);//贴源码图
		FlushBatchDraw();
		startY -= 0.68;//控制动画速度
		Sleep(0);//控制动画速度
	}
}
//游戏撞击动画
void hitAction() {
	//设置下落速度
	double step = -1.85;

	//绘制动画效果
	while (pBird->y + BIRD_SIZE - 15 <= 607) {
		pBird->y += step;
		step += 0.025;
		drawGame();
		FlushBatchDraw();
	}
}
//游戏扇翅膀动画
void flyAction() {
	tempcas += 0.025;
	if (tempcas >= 3) {
		tempcas = 0;
	}
	cas = (int)tempcas;
}


void drawGame()
{
	cleardevice();//清屏
	putimage(0, 0, &bk);
	//绘制背景图片
	for (int i = 0; i < 2; i++) {
		if (bkdown[i].flag == 1) {//当地面存在时，对地面进行绘制
			DrawBackground(bkdown[i]);
		}
	}

	//绘制柱子图片
	for (int i = 0; i < PILLAR_NUM; i++) {
		if (pillar[i].flag == 1) {//当柱子存在时，对柱子进行绘制
			DrawPillar(pillar[i]);
		}
	}
	//绘制小鸟
	DrawBird(pBird->x,pBird->y,cas);
}
//游戏其他状态
int HitPillar(Pillar pillar[])
{
	for (int i = 0; i < PILLAR_NUM; i++) {
		if (pillar[i].x <= pBird->x + BIRD_SIZE - 15 && pillar[i].x >= pBird->x - 65 + 10)
		{
			//判断上柱是否发生碰撞
			if (pBird->y + 15 <= pillar[i].height) {
				return 1;//返回值为1说明有碰撞发生
			}
			//判断下柱是否发生碰撞
			if (pBird->y + BIRD_SIZE - 15 >= 607.0 - (400 - pillar[i].height)) {
				return 1;//返回值为1说明有碰撞发生
			}
		}
	}
	return 0;//返回值为0说明没有碰撞
}
//游戏结束条件1
int Condition1() {
	//当小鸟撞到地板时，游戏结束
	if (pBird->y >= 607 - BIRD_SIZE + 15) {
		return 1;//返回值为1时游戏结束
	}
	//小鸟撞到天花板时，游戏结束
	else if (pBird->y <= 0 - 15) {
		return 1;//返回值为1时游戏结束
	}
	return 0;//返回值为0时游戏未结束
}
//游戏结束条件2
int Condition2() {
	//当小鸟撞到柱子时游戏结束
	return HitPillar(pillar);
}
//游戏结束条件判断
int GameOver() {
	if (Condition1() == 1 || Condition2() == 1) {
		return 1;//返回值为1时游戏结束
	}
	return 0;//返回值为0时游戏未结束
}

