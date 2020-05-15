#include <stdio.h>

void
printRangeRecursive(int start, int stop)
{
	if(start < stop)
	{
		printf("%d\n",start);
		printRangeRecursive(start+1,stop);
	}
}
/* above is a tail recursive function
 * because recursive function call is the last call
 * as we see there is no purpose of having the old
 * variables in program call stack because there is no
 * further processing pending, so we basically can
 * adjust the parameters in same code and jump to start
 * of the function to reuse the current stack.
 */

void
printRangeRecursiveGoTo(int start, int stop)
{
program_start:
	if(start < stop)
	{
		printf("%d\n",start);
		//printRangeRecursive(start+1,stop);
		start = start+1;
		goto program_start;
	}
}

/* else we can use less dangerous loops in order to
 * convert goto code into iteration, because goto are
 * expensive and not recommended.
 */

void
printRangeRecursiveWhile(int start, int stop)
{
//program_start:
//  if(start < stop)
	while(start < stop)
	{
		printf("%d\n",start);
		start = start+1;
		//goto program_start;
	}
}
#define Noisy(x) (puts(#x),x)

int
main(int argc, char** argv)
{
	Noisy(printRangeRecursive(0,10));
	Noisy(printRangeRecursiveGoTo(0,10));
	Noisy(printRangeRecursiveWhile(0,10));

	return 0;
}
