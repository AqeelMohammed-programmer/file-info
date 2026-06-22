#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

void print_error(const char *message) {
    printf("\x1b[31m"); // red
    printf("Error: %s\n", message);
    printf("\x1b[0m");  // reset
}

int main(/*int argc, char *argv[]*/) {
    // if (argc > 1) {
    //     printf("the first arg is %s\n", argv[1]);
    // }

    // print_error("this is error!");

    struct stat info;

    if (stat("./.gitignor", &info) == -1) {
        print_error(strerror(errno));
    }

    return 0;
}