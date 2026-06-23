CFLAGS = -Wall -Wextra -Wpedantic 
# -Werror
file-info: main.c
	cc $(CFLAGS) main.c display.c file_info.c -o file-info