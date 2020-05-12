#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "deque.h"

int
main(int argc, char **argv)
{
    int i;
    int n;
    Deque *d;
    int* m;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s iterations\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);

    d = dequeCreate();

    assert(dequeIsEmpty(d));

    for(i = 0; i < n; i++) {
    	m = malloc(sizeof(int));
    	*m = i;
    	//printf("Deque push front %d\n",*m);
        dequePush(d, DEQUE_FRONT, m);
        assert(!dequeIsEmpty(d));
    }

    for(i = 0; i < n; i++) {
    	m = dequePop(d, DEQUE_BACK);
    	//printf("Deque pop back %d\n",*((int*)m));
        assert(*m == i);
    	free(m);
    }

    assert(dequeIsEmpty(d));

    for(i = 0; i < n; i++) {
    	m = malloc(sizeof(int));
    	*m = i;
    	//printf("Deque push back %d\n",*m);
        dequePush(d, DEQUE_BACK, m);
        assert(!dequeIsEmpty(d));
    }

    for(i = 0; i < n; i++) {
    	m = dequePop(d, DEQUE_FRONT);
    	//printf("Deque pop front %d\n",*((int*)m));
        assert(*m == i);
    	free(m);
    }

    assert(dequeIsEmpty(d));

    for(i = 0; i < n; i++) {
    	m = malloc(sizeof(int));
    	*m = i;
    	//printf("Deque push back %d\n",*m);
        dequePush(d, DEQUE_BACK, m);
        assert(!dequeIsEmpty(d));
    }

    for(i = n-1; i >= 0; i--) {
    	m = dequePop(d, DEQUE_BACK);
    	//printf("Deque pop back %d\n",*((int*)m));
        assert(*m == i);
    	free(m);
    }

    assert(dequeIsEmpty(d));

    for(i = 0; i < n; i++) {
    	m = malloc(sizeof(int));
    	*m = i;
    	//printf("Deque push front %d\n",*m);
        dequePush(d, DEQUE_FRONT, m);
    }

    for(i = n-1; i >= 0; i--) {
    	m = dequePop(d, DEQUE_FRONT);
    	//printf("Deque pop front %d\n",*((int*)m));
        assert(*m == i);
        free(m);
    }

    assert(dequeIsEmpty(d));

    assert(dequePop(d, DEQUE_FRONT) == DEQUE_EMPTY);

    assert(dequePop(d, DEQUE_BACK) == DEQUE_EMPTY);

    //dequePush(d, DEQUE_FRONT, 12);

    dequeDestroy(d);

    return 0;
}
