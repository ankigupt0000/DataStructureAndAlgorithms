/* standard linked list element */

typedef struct elt{
	struct elt *next;
	void *value;
} elem;

typedef struct queue{
	elem *head; 	/* dequeue this next */
	elem *tail;     /* enqueue after this */
} Queue;

Queue*
queueCreate(void);

void
enqueue(Queue *q, void* value);

int
queueEmpty(const Queue *q);

void *
dequeue(Queue *q);

void
queueDestroy(Queue *q);

