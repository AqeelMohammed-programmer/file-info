#include "file_info.h"
#include "display.h"

#include <errno.h>
#include <string.h>
#include <stdlib.h>

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