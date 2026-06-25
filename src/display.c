#include <stdio.h>

#include "display.h"
#include "file_info.h"

#define INFO_COLOR  "\x1b[34m"
#define ERROR_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"
#define HORIZONTAL_LINE "―――――――――――――――――――――――――――――――――――――――――――\n"

#define ONE_GB (1024 * 1024 * 1024)
#define ONE_MB (1024 * 1024)
#define ONE_KB (1024)

static void full_size_string(size_t bytes, char *out_buffer, size_t buffer_size) {
    if (bytes >= ONE_GB) {
        snprintf(out_buffer, buffer_size, "%.2f GB", (float)bytes / ONE_GB);
    } else if (bytes >= ONE_MB) {
        snprintf(out_buffer, buffer_size, "%.2f MB", (float)bytes / ONE_MB);
    } else if (bytes >= ONE_KB) {
        snprintf(out_buffer, buffer_size, "%.2f KB", (float)bytes / ONE_KB);
    } else {
        snprintf(out_buffer, buffer_size, "%zu bytes", bytes);
    }
}

void print_error(const char *message) {
    printf(ERROR_COLOR); // red
    printf("Error: %s\n", message);
    printf(RESET_COLOR);  // reset
}

void print_file_info(const struct FileInfo *file_info) {
    char size_string[32];

    printf(INFO_COLOR); // red
    printf(HORIZONTAL_LINE);
    
    printf("File name: %s\n", file_info->file_name);

    full_size_string(file_info->file_size, size_string, sizeof(size_string));
    printf("File size: %s\n", size_string);
    
    printf(HORIZONTAL_LINE);
    printf(RESET_COLOR);  // reset
}