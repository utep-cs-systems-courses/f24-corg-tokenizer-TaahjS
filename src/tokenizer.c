#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if(c == ' ' || c == '\n' || c == '\t'){
    return 1;
  }
  return 0; //we return if we hit 0 because it marks the end of our array
}

int non_space_char(char c){
  if(c == ' ' || c == '\n' || c == '\t' || c == 0){
    return 0;
  }
  return 1;
}

//str points to the array of an index in the array
//array indices are next to one another
//look for beginning of next word
char *token_start(char *str){
  char arrayEnd = 0;
  char *ptr = &arrayEnd;
  int i = 0;
  while(1){
    if(*(str + i) == 0){ //this means we have hit the end of the array
      goto end;
    }
    if(space_char(*(str + i))){ //this indicates we've escaped our current token
      while(1){
	if(non_space_char(*(str + i))){
	  ptr = str + i;
	  goto end;
	}else if(*(str + i) == 0){ //this happens if the string ends in white space
	  goto end;
	}else{
	  i++;
	}
      }
      goto end;
    }
    i++;
  }
 end:
  return ptr;
}

char *token_terminator(char *token){
  int i = 0;
  char *ptr;
  while(1){
    if(non_space_char(*(token + i))){
      i++;
    }else{
      ptr = token + i;
      return ptr;
    }
  }
}

int count_tokens(char *str){
  int count = 0;
  if(non_space_char(*str)){
    count++;
  }
  int i = 0; //keeps track of index
  char *ptr = str;
 loop:
  ptr = token_start(ptr);
  if(*ptr != 0){
    count++;
    goto loop;
  }else{  
    return count;
  }
}

//inStr is the userInput, len is the number of chars you want to be in new string
char *copy_str(char *inStr, short len){
  char *copy = malloc((len + 1) * sizeof(char));
  if(copy == NULL){
    printf("Copy String: Failed to allocate memory.");
    return NULL;
  }
  for(int i = 0; i < len; i++){
    copy[i] = *(inStr + i);
  }
  copy[len] = 0;
  return copy;
}

char **tokenize(char* str){
  char numTokens = count_tokens(str); //if we add 1, it prints out something when 4+?
  char **tokenArray = malloc((numTokens + 1) * sizeof(char));
  if(tokenArray == NULL){
    printf("Tokenize: Failed to allocate memory.");
    return NULL;
  }
  for(int i = 0; i < numTokens; i++){
    char *wordStart = str;
    for(int j = 0; j < i; j++){
      wordStart = token_start(wordStart);
    }
    char *wordEnd = token_terminator(wordStart);
    tokenArray[i] = copy_str(wordStart, wordEnd-wordStart);
  }
  tokenArray[numTokens] = 0;
  return tokenArray;
}

//when we reach 4 tokens, it omits the first token while printing
void print_tokens(char **tokens){
  printf("Printing out tokens: \n");
  int numTokens = sizeof(*tokens)/sizeof(char);
  for(int i = 0; i < numTokens; i++){
    if(!tokens[i]){
      return;
    }
    printf("%s\n", tokens[i]);
  }
}

//anything beyond 2 tokens breaks
void free_tokens(char **tokens){
  printf("Landed");
  int i = 0;
  while(i != sizeof(*tokens)/sizeof(char)){
    free(tokens[i]);
    i++;
  }
  free(tokens);
  printf("\nFreed tokens.\n");
}
