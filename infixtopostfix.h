/*
    infix2postfix.h
    Tingting Xun
    24 November 2019
*/

#include <stdio.h>
#include<stdlib.h> /* for exit() */
#include <assert.h>
#include <ctype.h> /* for isdigit(char ) */

#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#define SIZE 100
	
	void push(char item);
	char pop();
	char readchar(FILE *myfile);
	void writechar(FILE *newfile, char c);
	int is_operator(char symbol);
	int precedence(char symbol);
	void infix2postfix(FILE *myfile, FILE *newfile);
	void testinfixtopostfix();

#endif

