#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void count_file(FILE *file, bool count_lines, bool count_words, bool count_chars) {
    int lines = 0, words = 0, characters = 0;
    char ch, prev = '\0';

    while ((ch = fgetc(file)) != EOF) {
        characters++;

        if (ch == '\n') lines++;

        if ((ch == ' ' || ch == '\n' || ch == '\t') && prev != ' ' && prev != '\n' && prev != '\t')
            words++;

        prev = ch;
    }

    if (count_lines) printf("Lines: %d\n", lines);
    if (count_words) printf("Words: %d\n", words);
    if (count_chars) printf("Characters: %d\n", characters);

    if (!count_lines && !count_words && !count_chars)  // Default: Show all counts
        printf("Lines: %d  Words: %d  Characters: %d\n", lines, words, characters);
}

int main(int argc, char *argv[]) {
    bool count_lines = false, count_words = false, count_chars = false;
    int file_index = 1;

    if (argc < 2) {
        printf("Usage: %s [-l | -w | -c] <filename>\n", argv[0]);
        return 1;
    }

    // Check for options
    while (file_index < argc && argv[file_index][0] == '-') {
        if (strcmp(argv[file_index], "-l") == 0) count_lines = true;
        else if (strcmp(argv[file_index], "-w") == 0) count_words = true;
        else if (strcmp(argv[file_index], "-c") == 0) count_chars = true;
        else {
            printf("Unknown option: %s\n", argv[file_index]);
            return 1;
        }
        file_index++;
    }

    // Process each file
    for (int i = file_index; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (!file) {
            perror("Error opening file");
            continue;
        }
        printf("=== %s ===\n", argv[i]);
        count_file(file, count_lines, count_words, count_chars);
        fclose(file);
    }

    return 0;
}
