#include "pillar.h"
#include "common.h"
extern IMAGE down[2];//���µ����ӣ�Դ��ͼ������ͼ
extern IMAGE up[2];//���ϵ����ӣ�Դ��ͼ������ͼ
struct Pillar pillar[PILLAR_NUM];
void DrawPillar(Pillar mypillar)
{
	//����ͼ��SRCAND��ʽȥ��ͼ
	putimage(mypillar.x, 0, 65, mypillar.height, down + 1, 0, 400 - mypillar.height, SRCAND);
	//Դ��ͼ��SRCPAINT��ʽȥ��ͼ
	putimage(mypillar.x, 0, 65, mypillar.height, down, 0, 400 - mypillar.height, SRCPAINT);

	//�±����ӻ���
	//����ͼ��SRCAND��ʽȥ��ͼ
	putimage(mypillar.x, 607 - (400 - mypillar.height), 65, 400 - mypillar.height, up + 1, 0, 0, SRCAND);
	//Դ��ͼ��SRCPAINT��ʽȥ��ͼ
	putimage(mypillar.x, 607 - (400 - mypillar.height), 65, 400 - mypillar.height, up, 0, 0, SRCPAINT);
}

void CreatePillar(Pillar pillar[], int i)
{
	pillar[i].height = rand() % 240 + 80;
	//�����ɵ����Ӹ߶�������������ͬʱ���������ɸ߶�
	while (pillar[i].height == pillar[(i + 1) % 3].height || pillar[i].height == pillar[(i + 2) % 3].height) {
		pillar[i].height = rand() % 240 + 80;
	}
	//�������Ӳ���ʱ��x����
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
