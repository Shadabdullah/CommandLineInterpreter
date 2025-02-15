#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "readinput.h"
#include <unistd.h>

#define MAX_CMD_LENGTH 500

int read_input() {
    char command_input[MAX_CMD_LENGTH];
    int running = 1; // Use a flag for clarity

    while (running) {
        // Print shell prompt
        printf("sh> ");
        fflush(stdout);

        // Read input
       
        size_t read_bytes = read(STDIN_FILENO,command_input , sizeof(command_input));

        // Remove newline if present
      if(read_bytes >0){
        command_input[read_bytes] = '\0';
      }else{
        continue;
      }
        // Trim whitespace
        trim_white_spaces(command_input);

        // Exit on "exit" command
        if (strcmp(command_input, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        // Tokenize input
        char** commands_arguments = tokenizer(command_input);
        if (commands_arguments == NULL) {
            fprintf(stderr, "Error: Failed to tokenize input.\n");
            continue;
        }

        // Print the cleaned command and its tokens
        printf("You entered: '%s'\n", command_input);
        printf("Here are the tokens:\n");

        int index = 0;
        while (commands_arguments[index] != NULL) {
            printf("Token[%d]: %s\n", index, commands_arguments[index]);
            index++;
        }

        // Free allocated tokens
        free_tokens(commands_arguments);
    }

    return 0; // Return success
}
