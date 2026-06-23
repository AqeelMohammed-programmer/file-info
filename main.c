#define _GNU_SOURCE

#define INFO_COLOR  "\x1b[34m"
#define ERROR_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"
#define HORIZONTAL_LINE "―――――――――――――――――――――――――――――――――――――――――――\n"

#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void print_error(const char *message) {
    printf(ERROR_COLOR); // red
    printf("Error: %s\n", message);
    printf(RESET_COLOR);  // reset
}

struct FileInfo
{
    const char *file_name;
    size_t file_size;

};

int get_file_info(const char *file_path, struct FileInfo *file_info) {
    struct stat info;

    if (stat(file_path, &info) < 0) {
        return -1;
    }

    file_info->file_size = info.st_size;

    file_info->file_name = basename(file_path);

    return 0;
}

void print_file_info(const struct FileInfo *file_info) {
    printf(INFO_COLOR); // red
    printf(HORIZONTAL_LINE);
    printf("File name: %s\n", file_info->file_name);
    printf("File size(in byets): %zu\n", file_info->file_size);
    printf(HORIZONTAL_LINE);
    printf(RESET_COLOR);  // reset
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        print_error("you should provide the file path\n"
                    "Usage: file-info <PATH>\n"
                    "Example: file-info ./myfile.txt");
        return EXIT_FAILURE;
    }

    size_t file_path_len = strlen(argv[1]);
    char *file_path = malloc(file_path_len + 1);
    strcpy(file_path, argv[1]);

    struct FileInfo file_info;

    if (get_file_info(file_path, &file_info) < 0) {
        print_error("cannot get file info");
        return EXIT_FAILURE;
    }

    print_file_info(&file_info);

    free(file_path);

    file_path = NULL; 

    return EXIT_SUCCESS;
}