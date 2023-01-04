#include "libs.h"

void PrintLogo(void)
{
    FILE *logo = fopen("uttooti.b", "r");

    char point = 'A';
    while (point != 0)
    {
        point = (char)getc(logo);
        switch (point)
        {
        case '0':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
            printf("#");

            break;
        case '1':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
            printf("#");

            break;
        case '2':
            printf("\n");

            break;
        case '3':
            point = 0;
            break;
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    printf("\n");
}