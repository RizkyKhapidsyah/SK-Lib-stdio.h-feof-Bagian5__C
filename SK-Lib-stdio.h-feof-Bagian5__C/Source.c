#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main(void) {
    int is_ok = EXIT_FAILURE;
    const char* fname = "/tmp/unique_name.txt"; // or tmpnam(NULL);
    FILE* fp = fopen(fname, "w+");

    if (!fp) {
        perror("File opening failed");
        return is_ok;
    }

    fputs("Halo Manusia!\n", fp);
    rewind(fp);

    int c; // note: int, not char, required to handle EOF
    while ((c = fgetc(fp)) != EOF) { // standard C I/O file reading loop
        putchar(c);
    }

    if (ferror(fp)) {
        puts("I/O error when reading");
    } else if (feof(fp)) {
        puts("End of file reached successfully");
        is_ok = EXIT_SUCCESS;
    }

    fclose(fp);
    remove(fname);

    _getch();
    return is_ok;
}