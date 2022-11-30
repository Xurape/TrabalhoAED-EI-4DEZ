#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main (int argc, char *argv[]) {
    char string[15];

    printf("Separar IP por pontos\n\n> ");
    fgets(string, 15, stdin);
    // printf("%s", ip);
    // char* tokens = strtok(ip, '.');
    // printf(" %s\n", tokens);
    // for (size_t i = 0; i < 4; i++)
    // {
    //     printf("\nToken %d: %s", i, tokens[i]);
    // }

    // char string[50] = "Hello! We are learning about strtok";
   // Extract the first token
   char * token = strtok(string, ".");
   // loop through the string to extract all other tokens
   printf("%s", token[1]);
//    while(token != NULL) {
//       printf( " %s\n", token ); //printing each token
//       token = strtok(NULL, ".");
//    }
}