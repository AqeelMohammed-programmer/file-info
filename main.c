#include <stdio.h>

void print_error(const char *message) {
    printf("\x1b[31m"); // red
    printf("Error: %s\n", message);
    printf("\x1b[0m");  // reset
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("the first arg is %s\n", argv[1]);
    }

    print_error("this is error!");

    return 0;
}