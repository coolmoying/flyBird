#pragma once
#include "common.h"
extern IMAGE bk;//��ű���ͼƬ
extern IMAGE mybird[3][2];//������ͼƬ��Դ��ͼ������ͼ
extern IMAGE guid[2];//�������ͼƬ
extern IMAGE down[2];//���µ����ӣ�Դ��ͼ������ͼ
extern IMAGE up[2];//���ϵ����ӣ�Դ��ͼ������ͼ
extern IMAGE start[2];//��ʼ��������
extern IMAGE end[2];//������������
extern struct BkDown bkdown[2];
extern struct Pillar pillar[PILLAR_NUM];

void run();
void runAction();
void flyAction();
void overAction();
void hitAction();
void drawGame();
void initData();
int HitPillar(struct Pillar pillar[]);

int Condition1();
int Condition2();
int GameOver();