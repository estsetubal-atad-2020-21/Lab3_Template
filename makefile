default:
	gcc -Wall -o prog main.c input.c countries.c
debug:
	gcc -Wall -o prog -g main.c input.c countries.c
clean:
	rm -f prog
