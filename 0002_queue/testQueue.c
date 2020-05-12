#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


typedef struct udt{
	int i;
	float j;
} Udt;

void
queuePrint(Queue* q)
{
	elem *e;

	for( e = q->head; e != 0; e = e->next){
		printf("%d %f, ",((Udt*)e->value)->i,((Udt*)e->value)->j);
	}
	putchar('\n');
}

int
main(int argc, char** argv)
{
	int i;
	Queue* q;
	Udt* m;

	q=queueCreate();

	for(i = 0; i < 5 ; i++) {
		printf("enqueue %d %f\n",i,(float)i);
		m=malloc(sizeof(Udt));
		m->i=i;
		m->j=i;
		enqueue(q,m);
		queuePrint(q);
	}

	while(!queueEmpty(q)){
		m=dequeue(q);
		printf("dequeue get %d %f\n",m->i,m->j);
		free(m);
		queuePrint(q);
	}

	queueDestroy(q);

	return 0;
}
