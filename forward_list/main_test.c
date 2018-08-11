#include <stdio.h>
#include <stdlib.h>
#include "forward_list.h"
void insert_list()
{
    int i=0;
    int val[]={10,20,30};
    int* value;
    /* test push front */
    for(i=0;i<3;i++)
    {
        value=(int*)malloc(sizeof(int));
        *value=val[i];
        push_front((void*)value);
    }
}
void clean_list()
{
    NODE **start = before_begin();
    NODE *itr=NULL,*oldnode=NULL;
    for(itr=*start;itr != NULL;)
    {
        free(itr-> data);
        oldnode=itr;
        itr=itr -> next_node;
        free(oldnode);
        oldnode=NULL;
    }
}
int main()
{
    NODE** start = before_begin();
    NODE* itr=NULL;
    int* dataptr=NULL;
    insert_list();
    /* Print all emement values */
    for(itr=*start;itr != NULL; itr = itr -> next_node)
    {
        dataptr=(int*)itr->data;
        printf("%d\n",*dataptr);
    }
    clean_list();
}