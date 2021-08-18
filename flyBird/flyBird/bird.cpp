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
	//�ж��Ƿ��а�����Ϣ
	while (_kbhit()) {
		//���ڽ��հ�����Ϣ
		char userKey = _getch();
		fflush(stdin);//��ռ�����Ϣ������
		//�԰�����Ϣ���зַ�
		switch (userKey) {
		case ' '://��
			musicFly();
			pBird->y -= (pBird->speed + 130);
		}
	}
}
void MoveBird(struct Bird* pBird)
{
	//���Լ������ƶ�
	pBird->y += pBird->speed;
	//������ƶ��߽��������
	if (pBird->y >= 607.0 - BIRD_SIZE + 15) 
	{
		pBird->y = 607.0 - BIRD_SIZE + 15;
	}
	else if (pBird->y <= 0 - 15.0)
	{
		pBird->y = 0 - 15.0;
	}
}
