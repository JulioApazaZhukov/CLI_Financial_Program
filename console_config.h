#include <Windows.h>

void gotoxy(int, int);

void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void appearance(void){
    system("color 0A");
    system("mode con: cols=100 lines=30");
}