#include <stdio.h>
#include "forward_list.h"
int main()
{
    int itr=0;
    NODE** start = before_begin();
    int* dataptr=NULL;

    int val[]={10,20,30};
    /* test push front */
    for(itr=0;itr<3;itr++)
    {
        push_front((void*)&(val)+(sizeof(int)*itr));
    }

    /* Print all emement values */
    for(NODE* itr=*start;itr != NULL; itr = itr -> next_node)
    {
        dataptr=(int*)itr->data;
        printf("%d\n",*dataptr);
    }
}