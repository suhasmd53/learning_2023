#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void copyFile(const char* sourceFileName, const char* destinationFileName, int option) {
    FILE* sourceFile;
    FILE* destinationFile;
    char ch;

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return;
    }

    // Open the destination file in write mode
    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        return;
    }

    // Copy the contents of the source file to the destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        if (option == 1) {
            // Convert to uppercase
            fputc(toupper(ch), destinationFile);
        } else if (option == 2) {
            // Convert to lowercase
            fputc(tolower(ch), destinationFile);
        } else if (option == 3) {
            // Convert to purely uppercase
            if (isalpha(ch)) {
                fputc(toupper(ch), destinationFile);
            } else {
                fputc(ch, destinationFile);
            }
        } else {
            // Normal copy
            fputc(ch, destinationFile);
        }
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        return 1;
    }

    int option = 0;

    if (strcmp(argv[1], "-u") == 0) {
        option = 1;
    } else if (strcmp(argv[1], "-l") == 0) {
        option = 2;
    } else if (strcmp(argv[1], "-s") == 0) {
        option = 3;
    }

    if (option == 0) {
        // Normal copy
        copyFile(argv[1], argv[2], 0);
    } else if (argc == 4) {
        // Copy with text case option
        copyFile(argv[2], argv[3], option);
    } else {
        printf("Invalid arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        return 1;
    }

    return 0;
}

