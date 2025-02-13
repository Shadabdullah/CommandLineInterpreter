#ifndef TOKENIZER_H

#define TOKENIZER_H

char** tokenizer(char* command_input);
void  free_tokens(char** command_arguments);
void trim_white_spaces(char* command_input);

#endif // TOKENIZER_H
