#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ' or '\n').  
   Zero terminators are not printable (therefore false) */
int space_char(char c);

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c);

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
//is this asking me to jump between words? ex: ab cd, function would return the index of 'c'
//token = word
//if there's no more white space in the word, then return 0
char *token_start(char *str); 

/* Returns a pointer terminator char following *token */
//points to the index after a token finishes (probably white space)
//return 0 if it reaches end of array
char *token_terminator(char *token);

/* Counts the number of tokens in the string argument. */
//count then umber of words in a string
int count_tokens(char *str);

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
//new array made has final index in 0
char *copy_str(char *inStr, short len);

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
