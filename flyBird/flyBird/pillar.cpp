#include "pillar.h"
#include "common.h"
extern IMAGE down[2];//朝下的柱子，源码图加掩码图
extern IMAGE up[2];//朝上的柱子，源码图加掩码图
struct Pillar pillar[PILLAR_NUM];
void DrawPillar(Pillar mypillar)
{
	//掩码图：SRCAND格式去贴图
	putimage(mypillar.x, 0, 65, mypillar.height, down + 1, 0, 400 - mypillar.height, SRCAND);
	//源码图：SRCPAINT格式去贴图
	putimage(mypillar.x, 0, 65, mypillar.height, down, 0, 400 - mypillar.height, SRCPAINT);

	//下边柱子绘制
	//掩码图：SRCAND格式去贴图
	putimage(mypillar.x, 607 - (400 - mypillar.height), 65, 400 - mypillar.height, up + 1, 0, 0, SRCAND);
	//源码图：SRCPAINT格式去贴图
	putimage(mypillar.x, 607 - (400 - mypillar.height), 65, 400 - mypillar.height, up, 0, 0, SRCPAINT);
}

void CreatePillar(Pillar pillar[], int i)
{
	pillar[i].height = rand() % 240 + 80;
	//当生成的柱子高度与其他柱子相同时，重新生成高度
	while (pillar[i].height == pillar[(i + 1) % 3].height || pillar[i].height == pillar[(i + 2) % 3].height) {
		pillar[i].height = rand() % 240 + 80;
	}
	//设置柱子产生时的x坐标
	pillar[i].x = WIDTH;
	pillar[i].flag = 1;
}

void MovePillar()
{
	for (int i = 0; i < PILLAR_NUM; i++) {
		pillar[i].x -= MOVESTEP;
		if (pillar[i].x <= -65) {
			pillar[i].flag = 0;
			CreatePillar(pillar, i);
			//score += 1;
		}
	}
}
