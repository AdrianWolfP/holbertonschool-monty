#include "monty.h"

/**
 * openFile - opens file, if it exists
 * @argc: argument count to main upon launch
 * @inFile: argv[1], or file to be opened for interpretation
 * Return: file pointer to newly opened file stream
 */

FILE *openFile(int argc, char *inFile)
{
	FILE *myS;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	myS = fopen(inFile, "r");
	if (!myS)
	{
		fprintf(stderr, "Error: Can't open file %s\n", inFile);
		exit(EXIT_FAILURE);
	}

	share.file = myS;
	return (myS);
}