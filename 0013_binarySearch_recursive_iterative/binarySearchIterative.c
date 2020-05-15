	#include <stddef.h>

#include "binarySearch.h"

int
binarySearch(int target, const int *a, size_t length)
{
	size_t index;

	for(;;){
		index = length/2;

		if(length==0){
			/* nothing left */
			return 0;
		} else if (target == a[index]){
			/* got it */
			return 1;
		} else if (target < a[index]){
			/* recurse a botton half */
			length=index;
		} else {
			/* recurse a top half */
			/* we throw away index+1 elements (including a[index]) */
			a=a+index+1;
			length=length-(index+1);
		}
	}
}
