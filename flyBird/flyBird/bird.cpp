#include "bird.h"
#include "common.h"
#include "music.h"
struct Bird* CreateBird(double x, double y, double speed)
{
    struct  Bird* pBird = (struct Bird*)malloc(sizeof(struct Bird));
    assert(pBird);
    pBird->x = x;
    pBird->y = y;
    pBird->speed = speed;
    return pBird;
}

void KeyDown(struct Bird* pBird)
{
	//判断是否有按键消息
	while (_kbhit()) {
		//用于接收按键消息
		char userKey = _getch();
		fflush(stdin);//清空键盘消息缓冲区
		//对按键消息进行分发
		switch (userKey) {
		case ' '://上
			musicFly();
			pBird->y -= (pBird->speed + 130);
		}
	}
}
void MoveBird(struct Bird* pBird)
{
	//鸟自己向下移动
	pBird->y += pBird->speed;
	//对鸟的移动边界进行限制
	if (pBird->y >= 607.0 - BIRD_SIZE + 15) 
	{
		pBird->y = 607.0 - BIRD_SIZE + 15;
	}
	else if (pBird->y <= 0 - 15.0)
	{
		pBird->y = 0 - 15.0;
	}
}
