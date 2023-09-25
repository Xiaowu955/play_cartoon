#include<iostream>
#include<graphics.h>
#include<string>
#include <MMSystem.h> // 播放音乐需要的头文件
#pragma comment(lib, "winmm.lib") //告诉编译器, 加载 winmm.lib 库文件
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

#define COUNT 148
#define WIDTH 800
#define HIGHTH 450

int main() {

	char filename[128];

	IMAGE image[COUNT];
	cout << "-----------------正在加载---------------------------" << endl;
	for (int i = 0; i < COUNT; i++) {
		sprintf_s(filename, sizeof(filename), "C:\\Users\\wukaijie\\Desktop\\gou5da8\\paly_cartoon\\images2\\_%04d_图层-%d.jpg", COUNT-i-1,i+1);
		loadimage(&image[i], filename);
	}

	initgraph(WIDTH, HIGHTH);

	mciSendString("play 极乐净土.mp3 repeat",0,0,0);
	/*DWORD result = mciSendString("play 极乐净土.mp3 repeat", 0, 0, 0);
	if (result != 0) {
		char buffer[256];
		mciGetErrorString(result, buffer, sizeof(buffer));
		cout << "播放失败，错误信息：" << buffer << endl;
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