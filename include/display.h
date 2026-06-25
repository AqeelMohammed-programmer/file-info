#ifndef DISPLAY_H
#define DISPLAY_H

#include "file_info.h"

void print_error(const char *message);
void print_file_info(const struct FileInfo *file_info);
void full_size_string(size_t bytes, char *out_buffer, size_t buffer_size);

#endif