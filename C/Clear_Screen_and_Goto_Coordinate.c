#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()
{
    // COORD c;       //  COORD is a predefind structure in c
    // c.X = 130;
    // c.Y = 8;
    // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);  // Function to set Coordinate
    // printf("Hello everyone\n");

    system("cls");    //  This function clears screen of terminal

    gotoxy(10, 26);   
    printf("Hello everyone\n");
    return 0;
}
