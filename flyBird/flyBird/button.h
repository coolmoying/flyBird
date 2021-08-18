#pragma once
#include "common.h"
struct Button {//按钮
	int x;//左上角x坐标
	int y;//左上角y坐标
	int width;//按钮宽度
	int height;//按钮高度
	char* text;//按钮内文字
	COLORREF buttoncolor;//按钮颜色
	COLORREF textcolor;//按钮中文字颜色
};
struct Button* CreatButton(int x, int y, int width, int height,
	const char* text, COLORREF buttoncolor, COLORREF textcolor);
//绘制按钮
void DrawButton(struct Button* pButton);
int MouseInButton(struct Button* pButton, MOUSEMSG* msg);
//鼠标控制
int MouseControl(struct Button* pButton1, struct Button* pButton2);