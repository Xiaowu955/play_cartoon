#include<iostream>
#include<graphics.h>
#include<string>
#include <MMSystem.h> // ����������Ҫ��ͷ�ļ�
#pragma comment(lib, "winmm.lib") //���߱�����, ���� winmm.lib ���ļ�
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

#define COUNT 148
#define WIDTH 800
#define HIGHTH 450

int main() {

	char filename[128];

	IMAGE image[COUNT];
	cout << "-----------------���ڼ���---------------------------" << endl;
	for (int i = 0; i < COUNT; i++) {
		sprintf_s(filename, sizeof(filename), "C:\\Users\\wukaijie\\Desktop\\gou5da8\\paly_cartoon\\images2\\_%04d_ͼ��-%d.jpg", COUNT-i-1,i+1);
		loadimage(&image[i], filename);
	}

	initgraph(WIDTH, HIGHTH);

	mciSendString("play ���־���.mp3 repeat",0,0,0);
	/*DWORD result = mciSendString("play ���־���.mp3 repeat", 0, 0, 0);
	if (result != 0) {
		char buffer[256];
		mciGetErrorString(result, buffer, sizeof(buffer));
		cout << "����ʧ�ܣ�������Ϣ��" << buffer << endl;
	}*/

	while (1) {
		for (int i = 0; i < COUNT; i++) {
			putimage(0, 0, &image[i]);
			Sleep(75);//1000ms/20 = 50
		}
	}

	system("pause");
	closegraph();
	return 0;
}