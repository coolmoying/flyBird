#pragma once
struct Pillar {//����
	double x;//���������Ͻ�x����
	int height;//������ʾ�ĸ߶�
	int flag = 0;//״̬��ʶ�������ж������Ƿ���ʧ
};
void DrawPillar(struct Pillar mypillar);
void CreatePillar(struct Pillar pillar[], int i);
void MovePillar();