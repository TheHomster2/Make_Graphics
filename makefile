all: graphpic.c
	gcc graphpic

run: all
	./a.out

clean: rm a.out
		rm pic.ppm