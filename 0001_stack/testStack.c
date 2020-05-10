#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct udt{
	int i;
	float j;
};

typedef struct udt dt;

int
main(int argc, char** argv)
{
	dt* m;
	int i;
	stack s;

	s = STACK_EMPTY;

	for(i = 0; i < 5; i++){
		m = malloc(sizeof(dt));
		m->i=i;
		m->j=(float)i;
		printf("push %d %f\n", m->i, m->j);
		stackPush(&s,m);
	}


	while(!stackEmpty(&s)){
		m = stackPop(&s);
		printf("pop gets %d %f\n",m->i, m->j);
		free(m);
	}
}
