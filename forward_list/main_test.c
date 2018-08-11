#include <stdio.h>
#include "forward_list.h"
int main()
{
    NODE** start = before_begin();
    push_front(10);
    /* Print all emement values */
    for(NODE* itr=start;itr != NULL; itr = itr -> next_node)
    {
        printf("%d\n",(int)itr->data);
    }
}