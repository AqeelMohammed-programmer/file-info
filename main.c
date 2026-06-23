#define _GNU_SOURCE

#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void print_error(const char *message) {
    printf("\x1b[31m"); // red
    printf("Error: %s\n", message);
    printf("\x1b[0m");  // reset
}

struct FileInfo
{
    const char *file_name;
    unsigned long file_size;

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


int main(int argc, char *argv[]) {
    if (argc <= 1) {
        print_error("you should provide the file path\n"
                    "Usage: file-info <PATH>\n"
                    "Example: file-info ./myfile.txt");
        return EXIT_FAILURE;
    }

    struct stat info;

    if (stat(argv[1], &info) == -1) {
        print_error(strerror(errno));
        return EXIT_FAILURE;
    }

    printf("the size of the file in bytes is %ld\n", info.st_size);

    return EXIT_SUCCESS;
}