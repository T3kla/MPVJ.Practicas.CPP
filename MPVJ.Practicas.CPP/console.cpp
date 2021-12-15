#include "console.h"

namespace fer::cls {

void GotoXY(int x, int y) {
  COORD pos = {(short)x, (short)y};
  HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(output, pos);
}

void HideCursor() {
  HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO t;
  t.bVisible = false;
  SetConsoleCursorInfo(hdl, &t);
}

void Clear() { system("cls"); }

} // namespace fer::cls
