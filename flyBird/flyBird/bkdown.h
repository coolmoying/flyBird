#pragma once
#include "common.h"
struct BkDown {//����ͼ�²��ֵ���
	double x;//������ͼ���Ͻ�x����
	int flag = 0;//״̬��ʶ�������жϵ����Ƿ���ʧ
};
void DrawBackground(struct BkDown bkdown);
void CreateBkDown(struct BkDown bkdown[], int i);
void BkDownMove();