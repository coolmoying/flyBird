#pragma once
#include "common.h"
struct BkDown {//背景图下部分地面
	double x;//贴地面图坐上角x坐标
	int flag = 0;//状态标识，用于判断地面是否消失
};
void DrawBackground(struct BkDown bkdown);
void CreateBkDown(struct BkDown bkdown[], int i);
void BkDownMove();