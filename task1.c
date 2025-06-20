#include <stdio.h>
#include <stdlib.h>

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create the file.\n");
        exit(1);
    }
    printf("File created successfully.\n");
    fclose(file);
}

void write_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");  // "w" mode overwrites the file
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        exit(1);
    }
    fputs(data, file);
    printf("Data written to file.\n");
    fclose(file);
}

void append_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a");  // "a" mode appends to the file
    if (file == NULL) {
        printf("Failed to open the file for appending.\n");
        exit(1);
    }
    fputs(data, file);
    printf("Data appended to file.\n");
    fclose(file);
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        exit(1);
    }

    printf("Reading from file:\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    fclose(file);
}

int main() {
    const char *filename = "sample.txt";

    create_file(filename);
    write_file(filename, "This is the first line.\n");
    append_file(filename, "This is an appended line.\n");
    read_file(filename);

    return 0;
}
