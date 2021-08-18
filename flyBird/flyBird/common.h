#pragma once
#include <stdio.h>				 //C语言标准库
#include <assert.h>
#include <time.h>				 //time()函数需要
#include <conio.h>				 //_kbhit()函数需要
#include <string.h>				 //字符串处理
#include <graphics.h>			 //easyx图形库
#include <mmsystem.h>			 //包含多媒体设备头文件
#pragma comment (lib,"winmm.lib")//加载静态库

#define WIDTH 640		//窗口宽度
#define HEIGHT 720		//窗口高度
#define BIRD_SIZE 60	//加载鸟图片的大小
#define PILLAR_NUM 3	//游戏界面中柱子数量
#define MOVESTEP 0.7	//柱子以及背景图片的移动速度