
typedef struct deque Deque;

#define DEQUE_FRONT (0)
#define DEQUE_BACK	(1)

#define DEQUE_EMPTY (NULL) /* returned by dequePop if deque is empty */

/* return a new empty queue */
Deque *
dequeCreate(void);

/* push new value onto direction side of deque d */
void
dequePush(Deque *d, int direction ,void* value);

/* pop and return first value on direction side of deque d */
/* returns DEQUE_EMPTY if deque is empty */
void *
dequePop(Deque *d, int direction);

/* return 1 if deque contains no elements, 0 otherwise */
int
dequeIsEmpty(const Deque *d);

/* free space used by a deque */
void
dequeDestroy(Deque *d);
