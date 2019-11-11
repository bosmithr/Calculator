/*
    Codegen.h
    Kevin Smith
    11 November 2019
*/
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "string.h"

#ifndef CODEGEN_H
#define CODEGEN_H

	char readchar(FILE *myfile);
	void writechar(FILE *newfile, char c);
	void cases(char pt, char nt, FILE *myfile, FILE *newfile);

    void Codegen();


#endif
