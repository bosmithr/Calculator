

#include <stdio.h>
#include<stdlib.h> /* for exit() */
#include <assert.h>
#include <ctype.h> /* for isdigit(char ) */


char readchar(FILE *myfile){
    char c = getc(myfile);
    return c;
}
int main()
{
    float array[40];
    int j=0,top=0;
    char s[100];
    FILE *fp = NULL;
    
    fp = fopen("code.txt", "r");
   if ( fp == NULL) {
        fprintf(stderr, "File %s does not exist.\n", "infix.txt");
        exit(1);
    }
    
  
    
   while(!feof(fp))
    {
       char item = readchar(fp);
       if(item=='L')
        {
            fscanf(fp,"%s %f\n",&s,&array[j]);
            j++;top++;
        }
       if(item=='M')
        {
            fscanf(fp,"%s\n",&s);
            array[j-2]=array[j-2]*array[j-1];j--;top--;
        }
        if(item=='A')
        {
            fscanf(fp,"%s\n",&s);
            array[j-2]=array[j-2]+array[j-1];j--;top--;
        }
        if(item=='D')
        {
            fscanf(fp,"%s\n",&s);
            array[j-2]=array[j-2]/array[j-1];j--;top--;
        }
        if(item=='S')
        {
            fscanf(fp,"%s\n",&s);
            array[j-2]=array[j-2]-array[j-1];j--;top--;
        }
        
       
    }
     printf("%f\n",array[0]);
  
}



