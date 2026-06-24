#define INFO_COLOR  "\x1b[34m"
#define ERROR_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"
#define HORIZONTAL_LINE "―――――――――――――――――――――――――――――――――――――――――――\n"

#include "display.h"
#include "file_info.h"
#include <stdio.h>

void print_error(const char *message) {
    printf(ERROR_COLOR); // red
    printf("Error: %s\n", message);
    printf(RESET_COLOR);  // reset
}

void print_file_info(const struct FileInfo *file_info) {
    printf(INFO_COLOR); // red
    printf(HORIZONTAL_LINE);
    printf("File name: %s\n", file_info->file_name);
    printf("File size(in byets): %zu\n", file_info->file_size);
    printf(HORIZONTAL_LINE);
    printf(RESET_COLOR);  // reset
}