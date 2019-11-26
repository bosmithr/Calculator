/*
    infixtopostfix.h
    Tingting Xun
    26 November 2019
*/

#include "tokenizer.h"

/* function to read char by char from file and return single value*/
char readchar(FILE *myfile){
	char c = getc(myfile);
	return c;
}

/* define operator checker */
int is_operator(char symbol)
{
	if(symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-' || symbol == '^' || symbol == '%')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

// test
void testtokenizer(){
	FILE *fp = NULL;
	
	fp = fopen("infix.txt", "r");
	if ( fp == NULL) {
		fprintf(stderr, "File does not exist.\n");
		exit(1);
	}
	char c = readchar(fp);
}