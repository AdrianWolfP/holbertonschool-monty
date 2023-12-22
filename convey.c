#include "monty.h"

/**
 * convey - conveys instruction line (if applicable) to op verifier
 * @stack: empty stack upon which operations are expected to be performed
 * Return: total number of characters retrieved, used mainly for debug
 */

ssize_t convey(stack_t **stack)
{
	char *inPut = NULL, *cmd = NULL;
	ssize_t gotLine = 0, gotTotal = 0;
	size_t inLen = 0, line_n = 1;

	for (gotTotal = 0;
	     (gotLine = getline(&inPut, &inLen, share.file)) != -1;
	     line_n++, gotTotal += gotLine)
	{
		cmd = strtok(inPut, SPC_DELIM);
		share.line = cmd;
		if (cmd)
			opVerify(stack, cmd, line_n);
	}
	return (gotTotal);
}