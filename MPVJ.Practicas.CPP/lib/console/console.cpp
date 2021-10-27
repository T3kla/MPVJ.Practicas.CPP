#include "console.h"

namespace clsw
{

void gotoxy(int x, int y)
{
    COORD pos = {(short)x, (short)y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void hidecursor(void)
{
    HANDLE hdl;
    hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO t;
    t.bVisible = false;
    SetConsoleCursorInfo(hdl, &t);
}

void clear()
{
    system("cls");
}

} // namespace clsw
