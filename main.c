#pragma warning(disable : 4996)

#include <stdio.h>
#include <conio.h>
#include "Setting.h"
#include "card.h"
#include "mylib.h"
#include "game.h"
#include "initialize.h"

void remove_cursor()
{
  CONSOLE_CURSOR_INFO curInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
  curInfo.bVisible = 0;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

int main()
{
  remove_cursor();
  system("mode con cols=160 lines=40");

  Init();
  Game();

  End();

  getch();
}