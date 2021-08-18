#pragma once
#include "common.h"
extern IMAGE bk;//存放背景图片
extern IMAGE mybird[3][2];//存放鸟的图片，源码图加掩码图
extern IMAGE guid[2];//存放引导图片
extern IMAGE down[2];//朝下的柱子，源码图加掩码图
extern IMAGE up[2];//朝上的柱子，源码图加掩码图
extern IMAGE start[2];//开始动画设置
extern IMAGE end[2];//结束动画设置
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