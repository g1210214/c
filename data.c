#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main() {
 
    char *filename = "output.txt";
    char *new_filename = "output_new.txt";
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }
    printf("hello");
    
    fflush(stdout);

    fprintf(fp, "hello world");
    fflush(fp);

    // rename(filename, new_filename);

    fclose(fp);

    return 0;
}
