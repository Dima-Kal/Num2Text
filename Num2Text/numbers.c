/*
 ============================================================================
 Name        : numbers.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Converts Numbers to Text taken from a file containing those names ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numbers.h"

/* the method receives an integer, finds the correct word from the structure and returns a result string */
char* findNumber(int number){
	char *string;
	string = malloc(25); /* default size */

	if (number < 10){
		strcpy(string, single[number].name);
	}
	else if (number > 19){
		strcpy(string,tens[number / 10 -2].name);
		strcat(string," ");
		if(number % 10 != 0)
			strcat(string,single[number % 10 ].name);

	}
	else {
		strcpy(string,other[number%10 -1 ].name);
	}
	return string;

}

int main(int argc, char *argv[]) {

	FILE *fpin;  /*input file pointer*/
	FILE *fpou;  /*output file pointer*/
	char *input;
	char *p;
	char *numtext;
	int number;
	int sz;


	input = (char *) malloc(DEFAULT);

	if (argc == 1){
		fprintf(stdout, "no input file! using standard input\n");
		fprintf(stdout, "no output file! using standard output\n");
	}
	else if (argc == 2)
		fprintf(stdout, "no output file! using standard output\n");
	else if (argc > 3){
		fprintf(stderr, "too many files\n");
		return EXIT_FAILURE;
	}

	if ( ((fpin = fopen(argv[1], "r")) == NULL) && argc > 1){
		fprintf(stderr, "did not find input file\n");
		return EXIT_FAILURE;
	}

	if ( ((fpou = fopen(argv[2], "w")) == NULL) && argc > 2){
		fprintf(stderr, "did not find output file\n");
		return EXIT_FAILURE;
	}

	if (fpin){

		fseek(fpin,0L,SEEK_END); /*get file size for the string memory allocation*/
		sz = ftell(fpin);
		fseek(fpin, 0L, SEEK_SET); /*back to beginning*/

		input = (char*)malloc(sz*sizeof(char));  /*allocate string size according to file size*/
		memset(input,0,sizeof(char)+1);

		if( fread (input, sizeof(char)	, sz, fpin)!=sz ) /*read input from file*/
		{
			return EXIT_FAILURE;
		}

		p = strtok (input," \t\n");

		while (p != NULL)
		{
			number = atoi(p); /*string to int*/
			numtext = findNumber(number); /*turn number to text*/

			if (fpou) /* check if output to file or standard output*/
				fprintf(fpou,"%s\n",numtext);
			else
				fprintf(stdout,"%s\n",numtext);

			p = strtok (NULL, " \t\n");

			free(numtext);

		}

		fclose(fpin);
		if (fpou)
			fclose(fpou);
	}

	else{  /*no input file, use standard input*/
		scanf("%[^\n]", input); /*read everything to input*/

		p = strtok (input," \t\n");

		while (p != NULL)
		{
			number = atoi(p); /*string to int*/
			numtext = findNumber(number); /*turn number to text*/
			fprintf(stdout,"%s\n",numtext);
			free(numtext);

			p = strtok (NULL, " \t\n"); /*next token*/



		}

	}

	return EXIT_SUCCESS;
}










/* solution without strtok, searching the string at a step */

/*

int main(int argc, char *argv[]) {

	FILE *fpin;  input file pointer
	FILE *fpou;  output file pointer
	char *input;
	char *p;
	int number;

	input = (char *) malloc(DEFAULT);

	if (argc == 1){
		fprintf(stdout, "no input file! using standard input\n");
		fprintf(stdout, "no output file! using standard output\n");
	}
	else if (argc == 2)
		fprintf(stdout, "no output file! using standard output\n");
	else if (argc > 3){
		fprintf(stderr, "too many files\n");
		return EXIT_FAILURE;
	}

	if ( ((fpin = fopen(argv[1], "r")) == NULL) && argc > 1){
		fprintf(stderr, "did not find input file\n");
		return EXIT_FAILURE;
	}

	if ( ((fpou = fopen(argv[2], "w")) == NULL) && argc > 2){
		fprintf(stderr, "did not find output file\n");
		return EXIT_FAILURE;
	}

	if (fpin){

		while (!feof(fpin)){
			free(input);

			input = (char *) malloc(DEFAULT);
			p = input;

			for (; ((*p = fgetc(fpin)) != ' ') && (!feof(fpin)) ; p++);  Get char from file
 *p = '\0';  replace space with null termination

			if (!(input[0] == '\0') && (!(input[0] == '\n'))){  check if string not empty
				number = atoi(input);
				input = findNumber(number);


			if (fpou)  check if output to file or standard output
				fprintf(fpou,"%s\n",input);
			else
				fprintf(stdout,"%s\n",input);
			}

		}

		fclose(fpin);
		if (fpou)
			fclose(fpou);
	}

	else{  no input file, use standard input
		scanf("%s", input);
		number = atoi(input);
		free(input);
		input = findNumber(number);

		fprintf(stdout,"%s\n",input);
	}

	return EXIT_SUCCESS;
}

 */







