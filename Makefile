all:
	gcc bigchar.c terminal.c bigchar.h terminal.h -o bigchar

clean:
	\rm -fr ll