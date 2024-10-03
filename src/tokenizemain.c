#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(){
  while(1){
    printf("Welcome to the program.If you'd like to exit, please type END. Otherwise, input a string to tokenize.\n>");
    int c, i = 0;
    char userInput[100];
    do{
      c = getchar();
      userInput[i] = c;
      i++;
      if(i == 99){
	goto endInput;
      }
    }while(c != '\n'); //if c = \n we will assume the person has pressed "enter" to end their input
   endInput:
    userInput[i] = 0;
    if(userInput[0] == 'E' && userInput[1] == 'N' && userInput[2] == 'D'){
      goto out;
    }
   printf("The user has input: ");
   for(int j = 0; j < (sizeof(userInput) / sizeof(char)); j++){
     if((i != 99 && i == j) || userInput[j] == 0){
       goto endPrint;
     }
     printf("%c", userInput[j]);
   }
   endPrint:
   printf("\n");

   printf("Pointer of the end of the first word is at address: %p\n", token_terminator(&userInput[0]));
   printf("The value at the address is: %c\n", *(token_terminator(&userInput[0])));
   printf("The value at the address - 1 is: %c\n\n", *(token_terminator(&userInput[0]) - 1));
   
   printf("Pointer of the second word is at address: %p\n", token_start(&userInput[0]));
   printf("The value at the address is: %c\n\n", *(token_start(&userInput[0])));

   printf("The number of tokens in the string is: %d\n\n", count_tokens(&userInput[0]));

   printf("Copying 3 characters from userInput: %s\n\n", copy_str(&userInput[0], 3));

   print_tokens(tokenize(&userInput[0]));
   printf("\n");
  }
 out:
  return 0;
}
