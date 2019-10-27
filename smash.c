#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "smash.h"

#define MAXLINE 4096
#define NUMBER_OF_ARGUMENTS 10



void loop(Shell *sh_ptr) {

    char bfr[MAXLINE];
    // char (*ptr);
    // void *ptr;
    

    char *line;
    fputs("$ ", stderr);    //Output the first prompt
    int index = 0;
    while (fgets(bfr, MAXLINE, stdin) != NULL) {
        // Marks the end of input stream with null character
        if (bfr[strlen(bfr) - 1] == '\n') { //Replace newline character with null character
            bfr[strlen(bfr) - 1] = '\0';
        } else if (bfr[strlen(bfr) - 1] != '\0') {  //Append null character to input
            bfr[strlen(bfr)] = '\0';
        }   

        line = strtok(bfr, " ");
        while((line != NULL) && (*line != '\n')) {
            if (*line == ' ') {  //Prevents an input with consecutive spaces
                fprintf(stderr, "Error: invalid input");
                break;
            } else {
                sh_ptr->arr[index] = line;
                line = strtok(NULL, " ");
                index++;
            }

        }

        
        for (int i=0; i < index; i++) { // Checks arrg acuracy
            printf("The line token: %s\n", sh_ptr->arr[i]);
        }
        // const char *ptr;
        // cmd_ptr->arr = malloc((sizeof(&arr)));
        printf("The malloc pointer is: %s\n", sh_ptr->arr[0]);
        executeCommand(sh_ptr);
        fputs("$ ", stderr);
    }
    
}

int main(void) {

    Shell *sh_ptr = malloc(sizeof(Shell));
    init_commands(sh_ptr);
    // init_commands();
    loop(sh_ptr);
    // free(sh_ptr);
    
    return 0;
}