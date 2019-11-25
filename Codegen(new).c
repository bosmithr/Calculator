/*
    Codegen.c
    Kevin Smith
    11 November 2019
*/
#include "Codegen.h"

char readchar(FILE *myfile) {
	char c = getc(myfile);
	return c;
}

/*-------------------------------------------------------------------------
	evaluate the next token, nt, to generate the appropriate code to output
---------------------------------------------------------------------------*/
void cases(char pt, char nt, FILE *myfile, FILE *newfile) {	//pt=prev_token  and  nt=new_token
	switch(nt) {

		case '*': fputs("MUL", newfile);
		break;

		case '/': fputs("DIV", newfile);
		break;

		case '-': fputs("SUB", newfile);
		break;

		case '+': fputs("ADD", newfile);
		break;
            
        case '.': fputs(".", newfile);
            break;
		case ' ': fputs("\n", newfile);
		break;

		default:
			if(isdigit(nt)) {			//check if the token is an integer between 0 and 9
				if(isdigit(pt)||pt=='.') { 		//check previous token(pt) to see if the new token(nt) is part of multidigit integer
					fputc(nt, newfile);	//new token is appended without the string "LOADINT   "
					break;
				}

				char str[] = "LOADNUM  ";
				str[8] = nt;			//8 is the index of str[] representing integer inputs

				fputs(str, newfile);
				break;
			}
			else{
				fputs("erroneous input detected", newfile);
			}
	}

}

void Codegen() {
	FILE *fp = NULL; 				//File for reading input
	fp = fopen("postfix.txt", "r"); //open and read the Infix2Postfix output file "postfix.txt"

	if (fp == NULL) {
		fprintf(stderr, "File %s does not exist.\n", "postfix.txt");
		FILE *output = fopen("code.txt", "w"); 	//write blank file to output: code.txt
		return;
	}

	char prev_token = ' ';					//keep track of the previous token for multidigit inputs 
	char next_token = readchar(fp); 		//dynamic variable used to hold value of each subsequent token
	
	FILE *output = fopen("code.txt", "w"); 	//File where the generated code is written

	while (!feof(fp)) {							//examine each token until the next token is 'eof'
		cases(prev_token, next_token, fp, output); 
		prev_token = next_token;
		next_token = readchar(fp);
	}
	
	char c = readchar(fp);

}


