 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include  "tokenizer.h"
#include "readinput.h"

char** tokenizer(char* command_input) {
    char* temp;
    int count = 0;
    char** tokens = NULL;
    temp = strtok(command_input, " ");

    while (temp != NULL) {
        count++;
        tokens = realloc(tokens, (count + 1) * sizeof(char*));

        if (tokens == NULL) {
            perror("Memory allocation failed for tokens");
            exit(1);
        }
        tokens[count - 1] = strdup(temp);
        temp = strtok(NULL, " ");
    }

    tokens = realloc(tokens, (count + 1) * sizeof(char*));
    tokens[count] = NULL;

    return tokens;
}



void command_seprator(char* string){


}

// This function is intended to remove any kind of extra space

void trim_white_spaces(char* string ){

  int i = 0 ;
  int index = 0 ;
  int space = 0 ;

  // This while loop escaping leading space
  while (isspace(string[i])) {
    i++ ;
  }
  
  while (string[i] != '\0') {
    if(!isspace(string[i])){
    
    if(space){
        string[index] = ' ';
        index ++ ;
        space = 0 ;

      }

    string[index] = string[i] ;
    index ++ ;

    }else{
      space = 1;
    }
  i++ ;
  }

  if(index>0 && string[index-1] == ' '){
    index -- ;
  }

  string[index] = '\0';

}

int check_input_length(char* command_input){

  size_t input_length = strlen(command_input);
  return input_length <= 8190; 

}



void free_tokens(char** commands_arguments) {
    int items = 0;
    while (commands_arguments[items] != NULL) {
        free(commands_arguments[items]);
        items++;
    }
    free(commands_arguments);
}



