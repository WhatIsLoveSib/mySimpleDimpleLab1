#include "terminal.h"

int mt_clrscr()
{
	printf("\E[H\E[J");

	return 0;
}

int mt_gotoXY(int y, int x)
{

	printf("\E[%d;%dH", y, x);

	return 0;
}

int mt_getscreensize(int *rows, int *cols)
{
	struct winsize ws;
	
	if (*rows > ws.ws_row || *cols > ws.ws_col) {
	  return -1;
	} else {
	  mt_gotoXY(*rows, *cols);
		*rows = ws.ws_row;
		*cols = ws.ws_col;
	}

	return 0;
}

int mt_setfgcolor(enum colors color)
{
	printf("\E[3%dm", color);

	return 0;
}

int mt_setbgcolor(enum colors color)
{
	printf("\E[4%dm", color);

	return 0;
}

int mt_stopcolor()
{
	printf("\E[0m");

	return 0;
}

void print_test_lab2() {
        mt_clrscr();
	int x = 10000;
	int y = 5;
	mt_getscreensize(&y, &x);
	mt_setbgcolor(black);
	mt_setfgcolor(red);
	printf("Vladislav");

	x = 16;
	y = 13;
	mt_getscreensize(&y, &x);
	mt_setbgcolor(white);
	mt_setfgcolor(green);
	printf("IV-022");

	mt_setbgcolor(black);
	mt_setfgcolor(white);;
        
}

int main()
{
	print_test_lab2();
	return 0;
}
