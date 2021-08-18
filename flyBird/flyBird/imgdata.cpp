#include "imgdata.h"
IMAGE bk;//存放背景图片
IMAGE mybird[3][2];//存放鸟的图片，源码图加掩码图
IMAGE guid[2];//存放引导图片
IMAGE down[2];//朝下的柱子，源码图加掩码图
IMAGE up[2];//朝上的柱子，源码图加掩码图
IMAGE start[2];//开始动画设置
IMAGE end[2];//结束动画设置

void LoadResource()
{
	//加载背景图片
	loadimage(&bk, "./picture/bk.bmp", WIDTH, HEIGHT);
	//加载引导图片
	loadimage(guid, "./picture/guid.bmp");
	loadimage(guid + 1, "./picture/guidy.bmp");
	//加载鸟的图片
	loadimage(mybird[0], "./picture/bird0.bmp", BIRD_SIZE, BIRD_SIZE);
	loadimage(mybird[0] + 1, "./picture/birdy0.bmp", BIRD_SIZE, BIRD_SIZE);
	loadimage(mybird[1], "./picture/bird1.bmp", BIRD_SIZE, BIRD_SIZE);
	loadimage(mybird[1] + 1, "./picture/birdy1.bmp", BIRD_SIZE, BIRD_SIZE);
	loadimage(mybird[2], "./picture/bird2.bmp", BIRD_SIZE, BIRD_SIZE);
	loadimage(mybird[2] + 1, "./picture/birdy2.bmp", BIRD_SIZE, BIRD_SIZE);
	//加载下方向柱子图片
	loadimage(down, "./picture/down.bmp");
	loadimage(down + 1, "./picture/downy.bmp");
	//加载上方向柱子图片
	loadimage(up, "./picture/up.bmp");
	loadimage(up + 1, "./picture/upy.bmp");
	//加载游戏开始图片
	loadimage(start, "./picture/start.bmp");
	loadimage(start + 1, "./picture/starty.bmp");
	//加载游戏结束图片
	loadimage(end, "./picture/end.bmp");
	loadimage(end + 1, "./picture/endy.bmp");
}

void DrawGuid(int x, int y)
{
	//掩码图：SRCAND格式去贴图
	putimage(x, y, guid + 1, SRCAND);
	//源码图：SRCPAINT格式去贴图
	putimage(x, y, guid, SRCPAINT);
}

void DrawBird(int x, int y,int cas)
{
	//掩码图：SRCAND格式去贴图
	putimage(x, y, mybird[cas] + 1, SRCAND);
	//源码图：SRCPAINT格式去贴图
	putimage(x, y, mybird[cas], SRCPAINT);
}
