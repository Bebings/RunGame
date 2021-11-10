
#include <iostream>
#include<windows.h>
#include<stdio.h>
using namespace std;

#define ArryX 4
#define ArryY 4

int CoordinateX, CoordinateY; //��������

char ShapeArray[ArryX][ArryY] = {{0,0,0,0},{1,1,1,1},{0,0,1,1},{1,1,0,0}};//��ά��������
//��切
int ti(float a) 
{ 
    return ((int)(a * 10 + 5)) / 10; 
}
void Setpos(float x, float y) 
{ 
    COORD pos; pos.X = ti(y * 4) / 2; 
    pos.Y = ti(x); 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

void Color(int a) 
{ 
    if (a == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
    if (a == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); 
    if (a == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); 
    if (a == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE); 
    if (a == 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); 
    if (a == 5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); 
    if (a == 6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE); 
    if (a == 7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
    if (a == 8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); 
    if (a == 9) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
    if (a == 10) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
    if (a == 11) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE); 
    if (a == 12) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN); 
    if (a == 13) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);
    if (a == 14) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE);
}

void DrowRect(int X, int Y)  //��������
{
    system("cls");
    Setpos(X, Y+1); cout << "��";
    Setpos(X+1, Y); cout << "��/";
    Setpos(X+2, Y); cout << "���v";
    Sleep(150);
}

void Drow4char(int X, int Y, const char Shape[][4])  //�ö�ά���黭ͼ
{
    for (size_t i = 0; i < ArryX; i++)
    {
        for (size_t j = 0; j < ArryY; j++)
        {
            Color(j);
            if (Shape[i][j] == 1)
            {
                Setpos(X + i, Y + j); cout << "��";
            }
            else if(Shape[i][j] == 0)
            {
                Setpos(X + i, Y + j); cout << "��";
            }
        }
    }
}


int main()
{
    system("mode con cols=100 lines=30");  //����DOS���ڴ�С
    CONSOLE_CURSOR_INFO cursor_info = { 1,0 }; //���ù��Ŀ�Ⱥ��Ƿ���ʾ
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); //���ù������
    DrowRect(CoordinateX, CoordinateY);//�������ͼ��
    while (1)
    {   
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) //��������ƽ�ɫλ��
        {
            if (CoordinateY > 0)
            {
                CoordinateY--;
                DrowRect(CoordinateX, CoordinateY);
            }
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            if (CoordinateY < 30)
            {
                CoordinateY++;
                DrowRect(CoordinateX, CoordinateY);
            }
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            if (CoordinateX > 0)
            {
                CoordinateX--;
                DrowRect(CoordinateX, CoordinateY);
            }
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            if (CoordinateX < 20)
            {
                CoordinateX++;
                DrowRect(CoordinateX, CoordinateY);
            }
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) //�л�������ɫ
        {
            Color(rand()%13);
            DrowRect(CoordinateX, CoordinateY);
        }
    }

}