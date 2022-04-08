#ifndef BIGCHARS_H
#define BIGCHARS_H
#include "terminal.h"

#define BIT(n) (1u << (n))

#define bc0 {1717976064, 3958374}
#define bc1 {471341056, 3938328}
#define bc2 {538983424, 3935292}
#define bc3 {2120252928, 8282238}
#define bc4 {2120640000, 6316158}
#define bc5 {2114092544, 8273984}
#define bc6 {33701376, 4071998}
#define bc7 {811630080, 396312}
#define bc8 {2120646144, 8283750}
#define bc9 {2120646144, 8282208}
#define bcA {1715214336, 6710910}
#define bcB {1044528640, 4080194}
#define bcC {37912064, 8274434}
#define bcD {1111637504, 4080194}
#define bcE {2114092544, 8258050}
#define bcF {33701376, 131646}
//#define bc_Plus {2115508224, 1579134}

//! Выводит строку символов с использованием
//! дополнительной кодировочной таблицы
int bc_printA(char* str);

//! Выводит на экран псевдографическую рамку, с верхним
//! левым углом row,column, шириной width и высотой height
int bc_box(int x1, int y1, int x2, int y2);

//! Выводит на экран большой символ размером 8x8,
//! с верхним углом в row,column с фоном colorbg цвета colorfg
int bc_printbigchar(int symbol[2], int x, int y,
    enum colors colorbg, enum colors colorfg);

//! устанавливает значение row,column символа big в val
int bc_setbigcharpos(int* big, int x, int y, int val);

//! возвращает значение row,column символа big в val
int bc_getbigcharpos(int* big, int x, int y, int* val);

//! записывает заданое число больших символов в файл fd
int bc_bigcharwrite(int fd, int* big, int count);

//! считывает из файла заданное количество больших символов
int bc_bigcharread(int fd, int* big, int need_count, int* count);
#endif // BIGCHARS_H