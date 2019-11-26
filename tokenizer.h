/*
    infixtopostfix.h
    Tingting Xun
    26 November 2019
*/

#include <stdio.h>
#include<stdlib.h> /* for exit() */
#include <assert.h>
#include <ctype.h> /* for isdigit(char ) */
#include <string.h>

#ifndef TOKENIZER_H
#define TOKENIZER_H
	
	char readchar(FILE *myfile);
	int  is_operator(char symbol);
	int  precedence(char symbol);
	
#endif