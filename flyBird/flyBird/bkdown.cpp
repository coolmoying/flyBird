#include "bkdown.h"
#include "imgdata.h"
struct BkDown bkdown[2];
extern IMAGE bk;
void DrawBackground(BkDown bkdown)
{
	//���²����汳��ͼƬ
	putimage(bkdown.x, 607, WIDTH - 1, HEIGHT - 607, &bk, 0, 607);
}

void CreateBkDown(BkDown bkdown[], int i)
{
		//���õ������ʱ��x����
	bkdown[i].x = WIDTH - 1.0;
	bkdown[i].flag = 1;
}

void BkDownMove()
{
	for (int i = 0; i < 2; i++) {
		bkdown[i].x -= MOVESTEP;
		if (bkdown[i].x <= -WIDTH) {
			bkdown[i].flag = 0;
			CreateBkDown(bkdown, i);
		}
	}
}
