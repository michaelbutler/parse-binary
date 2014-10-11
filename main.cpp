/* 
 * File:   main.cpp
 * Author: michael
 *
 * Created on October 9, 2014, 8:58 PM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

// Memory efficient method but uses more disk reads
void processFile2(char* filename) {
    int x = 0, is_letter = 0, is_whitespace = 0;
    int total_bytes = 0;
    char buffer[64];
    FILE *file = fopen(filename, "rb");
    if (file == 0) {
        printf("ERROR: Could not open file.\n");
        return;
    }
    while ((x = fgetc(file)) != EOF) {
        total_bytes += 1;
        is_letter = (x >= 32 && x <= 126);
        is_whitespace = (x == 9 || x == 10 || x == 13);
        if (x == 13) {
            // Fix windows line ending to Unix
            x = 10;
        }
        if (is_letter || is_whitespace) {
            printf("%c", x);
        } else if (x != 0) {
            printf(".");
        }
    }
    if (ferror(file)) {
        printf("There was an error reading the file during processing.\n");
    }
    printf("\nProcessed through %d bytes\n", total_bytes);
    fclose(file);
}

// Full file in memory method (fast but requires memory)
void processFile(char* filename) {
    int x = 0, y = 0;
    char is_letter = 0, is_whitespace = 0;
    int total_bytes = 0;
    int result;
    char *buffer;
    FILE *file = fopen(filename, "rb");
    
    if (file == 0) {
        printf("ERROR: Could not open file.\n");
        return;
    }
   
    // obtain file size:
    fseek(file, 0, SEEK_END);
    total_bytes = ftell(file);
    rewind(file);
    
    // allocate memory to contain the whole file:
    buffer = (char*) malloc(sizeof(char) * total_bytes);
    if (buffer == NULL) {
        fputs("Memory error", stderr);
        exit(2);
    }
    
    // copy the file into the buffer:
    result = fread(buffer, 1, total_bytes, file);
    if (result != total_bytes) {
        fputs("Reading error", stderr);
        exit(3);
    }
    
    fclose(file);

    for (y = 0; y < total_bytes; y++) {
        x = buffer[y];
        is_letter = (x >= 32 && x <= 126);
        is_whitespace = (x == 9 || x == 10 || x == 13);
        if (x == 13) {
            // Fix windows line ending to Unix
            x = 10;
        }
        if (is_letter || is_whitespace) {
            printf("%c", x);
        } else if (x != 0) {
            printf(".");
        }
    }
    
    free(buffer);
}

/*
 * Entry function
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        return 1;
    }
    processFile(argv[1]);
    return 0;
}
