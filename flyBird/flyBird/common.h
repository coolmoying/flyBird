#pragma once
#include <stdio.h>				 //C���Ա�׼��
#include <assert.h>
#include <time.h>				 //time()������Ҫ
#include <conio.h>				 //_kbhit()������Ҫ
#include <string.h>				 //�ַ�������
#include <graphics.h>			 //easyxͼ�ο�
#include <mmsystem.h>			 //������ý���豸ͷ�ļ�
#pragma comment (lib,"winmm.lib")//���ؾ�̬��

#define WIDTH 640		//���ڿ��
#define HEIGHT 720		//���ڸ߶�
#define BIRD_SIZE 60	//������ͼƬ�Ĵ�С
#define PILLAR_NUM 3	//��Ϸ��������������
#define MOVESTEP 0.7	//�����Լ�����ͼƬ���ƶ��ٶ�