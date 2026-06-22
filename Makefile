CFLAGS = -Wall -Wextra -Wpedantic 
# -Werror
file-info: main.c
	cc $(CFLAGS) main.c -o file-info