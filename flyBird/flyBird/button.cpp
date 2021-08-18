#include "button.h"
#include "music.h"
Button* CreatButton(int x, int y, int width, int height, const char* text, COLORREF buttoncolor, COLORREF textcolor)
{
	struct Button* pButton = (struct Button*)malloc(sizeof(struct Button));
	assert(pButton);
	pButton->x = x;
	pButton->y = y;
	pButton->width = width;
	pButton->height = height;
	pButton->text = (char*)malloc(strlen(text) + 1);
	assert(pButton->text);
	strcpy(pButton->text, text);
	pButton->buttoncolor = buttoncolor;
	pButton->textcolor = textcolor;
	return pButton;
}

void DrawButton(Button* pButton)
{
	setbkmode(TRANSPARENT);
	setlinecolor(RGB(243, 192, 161));
	setlinestyle(PS_SOLID, 5);
	setfillcolor(pButton->buttoncolor);
	fillrectangle(pButton->x, pButton->y, pButton->x + pButton->width, pButton->y + pButton->height);
	settextcolor(pButton->textcolor);
	settextstyle(28, 0, "����");
	int w = textwidth(pButton->text);
	int h = textheight(pButton->text);
	int textx = pButton->x + (pButton->width - w) / 2;
	int texty = pButton->y + (pButton->height - h) / 2;
	outtextxy(textx, texty, pButton->text);
}

int MouseInButton(Button* pButton, EASYXMSG* msg)
{
	if (msg->x >= pButton->x && msg->x <= pButton->x + pButton->width &&
		msg->y >= pButton->y && msg->y <= pButton->y + pButton->height) {
		pButton->buttoncolor = RGB(230, 121, 55);
		pButton->textcolor = RGB(135, 135, 135);
		return 1;//����ֵΪ1����������ڰ�ť��
	}
	pButton->buttoncolor = RGB(234, 139, 83);
	pButton->textcolor = RGB(240, 240, 240);
	return 0;//����ֵΪ0��������겻�ڰ�ť��
}

int MouseControl(Button* pButton1, Button* pButton2)
{
	static EASYXMSG msg;
	//�ж��Ƿ��������Ϣ
	if (peekmessage(&msg,EM_MOUSE)) {
		//�ж��û��Ƿ�����ť
		if (MouseInButton(pButton1, &msg) == 1 && msg.message == WM_LBUTTONDOWN) {
			musicClick();
			return 1;//����ֵΪ1��������Ϸ
		}
		else if (MouseInButton(pButton2, &msg) == 1 && msg.message == WM_LBUTTONDOWN) {
			musicClick();
			exit(0);//��Ϸ����
		}
	}
	return 0;
}
