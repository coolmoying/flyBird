#include "imgdata.h"
IMAGE bk;//��ű���ͼƬ
IMAGE mybird[3][2];//������ͼƬ��Դ��ͼ������ͼ
IMAGE guid[2];//�������ͼƬ
IMAGE down[2];//���µ����ӣ�Դ��ͼ������ͼ
IMAGE up[2];//���ϵ����ӣ�Դ��ͼ������ͼ
IMAGE start[2];//��ʼ��������
IMAGE end[2];//������������

void LoadResource()
{
	//���ر���ͼƬ
	loadimage(&bk, "./picture/bk.bmp", WIDTH, HEIGHT);
	//��������ͼƬ
	loadimage(guid, "./picture/guid.bmp");
	loadimage(guid + 1, "./picture/guidy.bmp");
	//�������ͼƬ
	loadimage(mybird[0], "./picture/bird0.bmp", BIRD_SIZE, BIRD_SIZE);
	loadimage(mybird[0] + 1, "./picture/birdy0.bmp", BIRD_SIZE, BIRD_SIZE);
	loadimage(mybird[1], "./picture/bird1.bmp", BIRD_SIZE, BIRD_SIZE);
	loadimage(mybird[1] + 1, "./picture/birdy1.bmp", BIRD_SIZE, BIRD_SIZE);
	loadimage(mybird[2], "./picture/bird2.bmp", BIRD_SIZE, BIRD_SIZE);
	loadimage(mybird[2] + 1, "./picture/birdy2.bmp", BIRD_SIZE, BIRD_SIZE);
	//�����·�������ͼƬ
	loadimage(down, "./picture/down.bmp");
	loadimage(down + 1, "./picture/downy.bmp");
	//�����Ϸ�������ͼƬ
	loadimage(up, "./picture/up.bmp");
	loadimage(up + 1, "./picture/upy.bmp");
	//������Ϸ��ʼͼƬ
	loadimage(start, "./picture/start.bmp");
	loadimage(start + 1, "./picture/starty.bmp");
	//������Ϸ����ͼƬ
	loadimage(end, "./picture/end.bmp");
	loadimage(end + 1, "./picture/endy.bmp");
}

void DrawGuid(int x, int y)
{
	//����ͼ��SRCAND��ʽȥ��ͼ
	putimage(x, y, guid + 1, SRCAND);
	//Դ��ͼ��SRCPAINT��ʽȥ��ͼ
	putimage(x, y, guid, SRCPAINT);
}

void DrawBird(int x, int y,int cas)
{
	//����ͼ��SRCAND��ʽȥ��ͼ
	putimage(x, y, mybird[cas] + 1, SRCAND);
	//Դ��ͼ��SRCPAINT��ʽȥ��ͼ
	putimage(x, y, mybird[cas], SRCPAINT);
}
