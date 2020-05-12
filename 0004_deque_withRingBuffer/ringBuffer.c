#include <stdlib.h>
#include <assert.h>

#include "deque.h"

/*
 * Alternative implementation of a deque using a ring buffer.
 *
 * Conceptually, this is an array whose indices wrap around at
 * the end-points.
 *
 * The region in use is specified by a base index pointing
 * to the first element,and a length count giving the number
 * of elements, A size field specifies the number of slots
 * in the block
 *
 * Picture:
 *
 * -------------------------------------------------------
 * |7|8|9| | | | | | | | | | | | | | | | | | |1|2|3|4|5|6|
 * -------------------------------------------------------
 *        ^                                 ^
 *        |                                 |
 *        base + length -1                  base
 *
 */

struct deque {
	size_t base;	/* location of front element */
	size_t length;  /* length of region in use */
	size_t size;    /* total number of positions in contents */
	void** contents;
};

#define INITIAL_SIZE (8)

/* create a new deque of the given size */
static Deque*
dequeCreateInternal(size_t size)
{
	Deque *d;
	d = malloc(sizeof(Deque));
	assert(d);

	d->base = 0;
	d->length = 0;
	d->size = size;

	d->contents = malloc(sizeof(void*) * d->size);
	assert(d->contents);

	return d;
}

/* return a new empty deque */
Deque *
dequeCreate(void)
{
	return dequeCreateInternal(INITIAL_SIZE);
}

void
dequePush(Deque *d, int direction, void* value)
{
	Deque *d2;			/* replacement deque if we grow */
	void **oldContents; 	/* old contents of d */

	/*
	 * First make sure we have space
	 */

	if(d->length == d->size){
		/* nope */
		d2 = dequeCreateInternal(d->size * 2);

		/* evacuate d */
		while(!dequeIsEmpty(d)){
			dequePush(d2, DEQUE_BACK, dequePop(d,DEQUE_FRONT));
		}

		/* do a transplant from d2 to d */
		/* but save old contents so we cna fre them */

		oldContents = d->contents;
		*d = *d2; 	/* this is equivalent to copying the components one by one */

		/* these are the pieces we don't need any more */
		free(oldContents);
		free(d2);
	}

	/*
	 * This requires completely different code
	 * depending on the direction, whi is
	 * annoying
	 */
	if(direction == DEQUE_FRONT){
		/* d->base is unsinged, so we have to check for zero frist */
		if(d->base == 0){
			d->base = d->size - 1;
		} else {
			d->base--;
		}

		d->length++;

		d->contents[d->base] = value;
	} else {
		d->contents[(d->base + d->length++)% d->size ] = value;
	}
}

/* pop and return first value on direction side of deque d */
/* returns DEQUE_EMPTY if deque s empty */
void *
dequePop(Deque *d, int direction)
{
	void* retval;

	if(dequeIsEmpty(d)){
		return DEQUE_EMPTY;
	}

	/* else */
	if(direction == DEQUE_FRONT){
		/* base goes up by one, lenght goes down by one */
		retval = d->contents[d->base];

		d->base = (d->base+1) % d->size;
		d->length--;
		return retval;
	} else {
		return d->contents[(d->base + --d->length) % d->size];
	}
}

int
dequeIsEmpty(const Deque *d)
{
	return d->length == 0;
}

void
dequeDestroy(Deque *d)
{
	free(d->contents);
	free(d);
}
