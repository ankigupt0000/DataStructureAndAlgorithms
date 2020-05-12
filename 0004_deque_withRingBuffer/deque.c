#include <stdlib.h>
#include <assert.h>
#include <stddef.h> /* for offsetof */

#include "deque.h"

#define NUM_DIRECTIONS (2)

struct deque {
	struct deque *next[NUM_DIRECTIONS];
	void* value;
};

Deque *
dequeCreate(void)
{
	Deque *d;

	/*
	 * We don't allocate the full space for this object
	 * because we don't use the value field in the dummy head.
	 *
	 * Saving these 4 bytes doesn't make a lot of sense here,
	 * but it might be more significant if value where larger.
	 */
	d = malloc(offsetof(Deque,value));

	/* test is the deal with malloc failure */
	if(d){
		d->next[DEQUE_FRONT] = d->next[DEQUE_BACK] = d;
	}

	return d;
}

void
dequePush(Deque *d, int direction, void* value)
{
	Deque *e;
	assert(direction == DEQUE_FRONT || direction == DEQUE_BACK);

	e=malloc(sizeof(Deque));
	assert(e);

	e->next[direction] = d->next[direction];
	e->next[!direction] = d;
	e->value = value;

	d->next[direction] = e;
	e->next[direction]->next[!direction]=e; /* preserves invariant */
}

void *
dequePop(Deque *d, int direction)
{
	Deque *e;
	void* retval;

	assert(direction == DEQUE_FRONT || direction == DEQUE_BACK);

	e=d->next[direction];

	if(e==d){
		return DEQUE_EMPTY;
	}

	/* else remove it */
	d->next[direction] = e->next[direction];
	e->next[direction]->next[!direction] = d;

	retval = e->value;

	free(e);

	return retval;
}

int
dequeIsEmpty(const Deque *d)
{
	return d->next[DEQUE_FRONT] == d;
}

void
dequeDestroy(Deque *d)
{
	while(!dequeIsEmpty(d)){
		dequePop(d,DEQUE_FRONT);
	}
	free(d);
}
