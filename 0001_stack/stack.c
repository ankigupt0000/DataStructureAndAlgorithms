#include <assert.h>
#include <stdlib.h>
#include "stack.h"

struct elt{
	stack next;
	void* data;
};

void
stackPush(stack *s, void* data)
{
	stack e;
	e=malloc(sizeof(struct elt));
	assert(e);

	e->data = data;
	e->next = *s;
	*s=e;
}

int
stackEmpty(const stack *s)
{
	return (*s == STACK_EMPTY);
}

void*
stackPop(stack *s){
	void* ret;
	stack e;

	assert(!stackEmpty(s));

	ret = (*s)->data;
	e=*s;

	*s=e->next;
	free(e);

	return ret;
}

