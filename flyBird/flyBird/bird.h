#pragma once
struct Bird {//鸟
	double x;//贴柱子左上角x坐标
	double y;//贴柱子坐上角y坐标
	double speed;//下坠速度
};
struct Bird* CreateBird(double x, double y, double speed);
void MoveBird(struct Bird* pBird);
void KeyDown(struct Bird* pBird);
