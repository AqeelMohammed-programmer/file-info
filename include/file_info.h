#ifndef FILE_INFO_H
#define FILE_INFO_H

#include <stddef.h>

struct FileInfo
{
    const char *file_name;
    size_t file_size;

};

int get_file_info(const char *file_path, struct FileInfo *file_info);

#endif