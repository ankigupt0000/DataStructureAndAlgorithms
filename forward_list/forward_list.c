/**
 * @brief Implementation of forward_list.h
 * 
 * @file forward_list.c
 * @author Ankit Gupta
 * @date 2018-08-10
 * @details forward_list similar as STL forward_list like C++
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "forward_list.h"

/**
 * @var[start] pointer to start of the list
 */
static NODE* start=NULL;

/**
 * @brief returns address of pointer to first node.
 * 
 * @return NODE**
 */
NODE** before_begin(){
    return &start;
}

/**
 * @brief Construct a new push front object
 * 
 * @param val 
 */
int push_front(void* val){
    NODE* new_node = (NODE *) malloc(sizeof(NODE));
    if(new_node == NULL)
    {
        fprintf(stderr,"Allocation Error: %s",strerr(errno));
        return errno;
    }
    new_node ->next_node = start;
    new_node -> data = val;
    start = new_node;
}

