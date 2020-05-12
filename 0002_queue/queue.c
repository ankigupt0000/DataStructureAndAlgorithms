#include <stdlib.h>
#include <assert.h>
#include "queue.h"


Queue*
queueCreate(void)
{
	Queue *q;

	q=malloc(sizeof(Queue));

	q -> head = q-> tail = 0;

	return q;
}

/* add a new value to back of queue */
void
enqueue(Queue *q, void* value)
{
	elem* e;

	e = malloc(sizeof(elem));
	assert(e);

	e->value = value;

	/* Because I will be tail nobody is behind me */
	e->next = 0;

	if(q->head == 0){
		/* If the queue was empty , I became the head */
		q->head = e;
	} else {
		/* Otherwise I get in line after the old tail */
		q->tail->next = e;
	}
	/* I become the new tail */
	q->tail = e;
}

int
queueEmpty(const Queue *q)
{
	return(q->head == 0);
}

/* remove and return value from front of queue */
void *
dequeue(Queue *q)
{
	void* ret;
	elem *e;

	assert(!queueEmpty(q));

	ret = q->head->value;

	/* patch our first element */
	e = q->head;
	q->head = e->next;

	free(e);

	return ret;
}

void
queueDestroy(Queue *q)
{
	while(!queueEmpty(q)){
		dequeue(q);
	}
	free(q);
}
