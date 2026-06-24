#define _GNU_SOURCE

#include "file_info.h"
#include <sys/stat.h>
#include <string.h>


int get_file_info(const char *file_path, struct FileInfo *file_info) {
    struct stat info;

    if (stat(file_path, &info) < 0) {
        return -1;
    }

    file_info->file_size = info.st_size;

    file_info->file_name = basename(file_path);

    return 0;
}