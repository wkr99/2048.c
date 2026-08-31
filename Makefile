make:
	@gcc 2048.c -Wall -lncurses -o 2048 && ./2048

clean:
	@rm 2048
