#include "music.h"
void musicBGM()
{
	mciSendString("open ./music/bk.mp3 alias BGM", NULL, 0, NULL);
	mciSendString("play BGM repeat", NULL, 0, NULL);
}
void musicFly()
{
	mciSendString("close fly", NULL, 0, NULL);
	mciSendString("open ./music/fly.mp3 alias fly", NULL, 0, NULL);
	mciSendString("play fly", NULL, 0, NULL);
}
void musicClick()
{
	mciSendString("close click", NULL, 0, NULL);
	mciSendString("open ./music/click.wav alias click", NULL, 0, NULL);
	mciSendString("play click", NULL, 0, NULL);
}
void musicEnd()
{
	mciSendString("close end", NULL, 0, NULL);
	mciSendString("open ./music/end.wav alias end", NULL, 0, NULL);
	mciSendString("play end", NULL, 0, NULL);
}
