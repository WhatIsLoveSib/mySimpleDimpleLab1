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

	if (ioctl(1, TIOCGWINSZ, &ws)) {
		return 1;
	} else {
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
	mt_gotoXY(10, 5);
	mt_setbgcolor(black);
	mt_setfgcolor(red);
	printf("Vladislav");
	
	mt_gotoXY(11, 6);
	mt_setbgcolor(white);
	mt_setfgcolor(green);
	printf("IV-022");
	
	int rows, cols;
	mt_getscreensize(&rows, &cols);
	mt_setbgcolor(black);
	mt_gotoXY(1, 10);
	printf("Rows: %d Rols: %d", rows, cols);	
}

/*int main()
{
	print_test_lab2();
	return 0;
}*/