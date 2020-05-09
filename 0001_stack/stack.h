
#define STACK_EMPTY (0)

typedef struct elt *stack;

void
stackPush(stack *s, void* data);

int
stackEmpty(const stack *s);

void*
stackPop(stack *s);

