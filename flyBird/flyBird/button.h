#pragma once
#include "common.h"
struct Button {//��ť
	int x;//���Ͻ�x����
	int y;//���Ͻ�y����
	int width;//��ť���
	int height;//��ť�߶�
	char* text;//��ť������
	COLORREF buttoncolor;//��ť��ɫ
	COLORREF textcolor;//��ť��������ɫ
};
struct Button* CreatButton(int x, int y, int width, int height,
	const char* text, COLORREF buttoncolor, COLORREF textcolor);
//���ư�ť
void DrawButton(struct Button* pButton);
int MouseInButton(struct Button* pButton, MOUSEMSG* msg);
//������
int MouseControl(struct Button* pButton1, struct Button* pButton2);