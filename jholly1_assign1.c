/* 
    Joshua Holly (jholly1)
    CSCI 4100 Summer 2022
    Assignment 1
*/

/*
    Display content from one of more text files.
    If no arguments, displays text from standard input.
    If one or more arguments are provided:
        Attempt to open the file for reading with the argument as the filename
        If the file fails to open, display a message indicating the file was not found and then exit the program
        Otherwise, display the contents of the file to standard output
        Close the file
*/

// A preprocessor stmnt to incld a header file containing definitions of I/O functions
#include<stdio.h>
#include<stdlib.h>

// A prototype for a function to be defined later
void display_message(const char *filename);

// Definition of the main function
int main(int argc, char *argv[]) {
    char string[1000], s;
    // If no arguments, display from input
    if (argc == 1) {
        fgets(string, 1000, stdin);
        printf("%s", string);
    }
    // If one or more arguments, attempt to open the file for reading
    else {
        for (int i = 1; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            // If the file fails to open, display a message indicating the file was not found and then exit the program
            if (fp == NULL) {
                printf("Error: file not found\n");
                exit(0);
            }
            // Otherwise, display the contents of the file to standard output
            while((s = fgetc(fp)) != EOF) {
                printf("%c", s);
            }
            printf("\n");
            fclose(fp);
        }
    }
    return 0;
} 

// Definition of the display_message function
void display_message(const char *message) {
    puts(message);
}