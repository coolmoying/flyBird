#pragma once
struct Bird {//��
	double x;//���������Ͻ�x����
	double y;//���������Ͻ�y����
	double speed;//��׹�ٶ�
};
struct Bird* CreateBird(double x, double y, double speed);
void MoveBird(struct Bird* pBird);
void KeyDown(struct Bird* pBird);
