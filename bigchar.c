#include "terminal.h"
#include "bigchar.h"
#include <stdio.h>
#include <unistd.h>

int bc_printA(char* str)
{
    printf("\E(0");
    printf("%s", str);
    printf("\E(B");
    return 0;
}

int bc_box(int x1, int y1, int x2, int y2)
{
    {
    int rows, cols;
    if (mt_getscreensize(&rows, &cols) != 0)
        return -1;
    if (rows < (x1 + x2) || cols < (y1 + y2))
        return -1;
    }
   mt_gotoXY(x1, y1);
   printf("\E(0");
   putchar('l');
   for (int i = 1; i < x2; i++) {
       putchar('q');
   }
   putchar('k');
   mt_gotoXY(x1 + 1, y1);
   for (int i = 1; i < (y2 - 1); i++) {
       putchar('x');
       mt_gotoXY(x1 + i, y1 + x2);
       putchar('x');
       mt_gotoXY(x1 + i + 1, y1);
   }
   putchar('m');
   for (int i = 1; i < x2; i++)
       putchar('q');
   putchar('j');

   printf("\E(B");
   return 0;
}

int bc_printbigchar(int big[2], int x, int y,
    enum colors colorbg, enum colors colorfg)
{
    {
        int rows, cols;
        if (mt_getscreensize(&rows, &cols) != 0)
            return -1;
        if (rows < (x + 8) || cols < (y + 8))
            return -1;
    }
    mt_setbgcolor(colorbg);
    mt_setfgcolor(colorfg);

    printf("\E(0");
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 4; i++) {
			mt_gotoXY(y + i + k * 4, x);
			for (int j = 0; j < 8; j++) {
				if ((big[k] >> (i * 8 + j)) & 1) {
					//printf("%c", bc_shadedCell);
					printf("a");
				} else {
					printf("%c", ' ');
				}
			}
		}
	}
    printf("\E(B");
    return 0;
}

int bc_setbigcharpos(int* big, int x, int y, int val)
{
    if (x > 7 || y > 7)
        return -1;
    if (y < 4) {
		if (val) {
			big[0] |= 1 << (y * 8 + x);
		} else {
			big[0] = ~(1 << (y * 8 + x));
		}
	} else {
		if (val) {
			big[1] |= 1 << (y * 8 + x);
		} else {
			big[1] = ~(1 << (y * 8 + x));
		}
	}
    return 0;
}

int bc_getbigcharpos(int* big, int x, int y, int* val)
{
	
    if (x > 7 || y > 7 || !big)
        return -1;

    if (y < 4) {
        *val = (big[0] >> (y * 8 + x)) & 1;
		//return *val;
	} else {
		y -= 4;
		//printf("y = %d\n", y);
		*val = (big[1] >> (y * 8 + x)) & 1;
		//return *val;
	}

	//printf("%d\n", *val);

    return 0;
}

int bc_bigcharwrite(int fd, int* big, int count)
{
    if (fd == -1)
        return -1;
    for (int i = 0; i < count; i++) {
        int retval = write(fd, big + (i * 2), sizeof (int) * 2);
        if (retval != sizeof (int) * 2)
            return -1;
    }
    return 0;
}

int bc_bigcharread(int fd, int* big, int need_count, int* count)
{
    if (fd == -1)
        return -1;
    for (int i = 0; i < need_count; i++) {
        int retval = read(fd, big + (i * 2), sizeof (int) * 2);
        if (retval == 0) {
            *count = i;
            return 0;
        }
        if (retval != sizeof (int) * 2) {
            *count = 0;
            return -1;
        }
    }
    return 0;
}

int main()
{
    mt_clrscr();
    bc_box(5, 5, 9, 10);
    int sym[2] = bc0;
    //bc_setbigcharpos(sym, 1, 0, 1);
	int val = 110;
    bc_printbigchar(sym, 6, 6, black, green);
	int toPr = bc_getbigcharpos(sym, 2, 5, &val);
	//printf("%d\n", val);
	mt_gotoXY(0, 0);
    return 0;
}