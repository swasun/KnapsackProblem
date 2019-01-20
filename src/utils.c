#include "utils.h"

int get_lines_number(FILE *file) {
    int lines;
    char c;

    lines = 0;
    fseek(file, 0, SEEK_SET);

    while (!feof(file)) {
        c = fgetc(file);
        if(c == '\n') {
            lines++;
        }
    }

    fseek(file, 0, SEEK_SET);

    return lines;
}
