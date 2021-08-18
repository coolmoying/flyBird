#pragma once
struct Pillar {//柱子
	double x;//贴柱子左上角x坐标
	int height;//柱子显示的高度
	int flag = 0;//状态标识，用于判断柱子是否消失
};
void DrawPillar(struct Pillar mypillar);
void CreatePillar(struct Pillar pillar[], int i);
void MovePillar();