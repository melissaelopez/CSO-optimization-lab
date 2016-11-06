/*
 * author: Melissa Lopez
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_4_opt. It should perform the same 
// task as the implemented level_4 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
//

// Note: Data structures like linked lists are not very
// cache friendly (their nodes can be scattered all over
// the heap). The following method compacts the nodes of a linked 
// list into adjacent memory locations in an array and it also
// preserves the traditional linked list connections. 
// Your own code needs to accomplish the same. 
 
void level_4(node** head, int length){
    // malloc a contiguous block of memory on the heap
    // that is big enough for the entire list.
    node* new_list = malloc(sizeof(node) * length);

    // go through the list and make a copy of all the 
    // nodes and place them into the contiguous block in order
    node* n = *head;
    int i;
    for(i = 0 ; i < length ; ++i) {
        node copy = { n->value, NULL };
        new_list[i] = copy;
        n = n->next;
    }

    // go through the list again and "link" each node in 
    // the contiguous block to the next node in memory; 
    // free all the nodes in the old list
    n = *head;
    for(i = 0 ; i < length - 1 ; ++i) {
        // link each node in the new list
        new_list[i].next = &new_list[i+1];
        // free the old nodes
        node* free_me = n;
        n = n->next;
        free(free_me);
    }

    // free the last node of the old list
    free(n);

    // point head at the new packed list
    *head = new_list;
}

// 150,003    78,126  /home/stud/Desktop/Projects/melissaelopez-proj3/level_4.c:level_4
// 100,001    45,316  /home/stud/Desktop/Projects/melissaelopez-proj3/level_4.c:level_4_opt

// This version is optimied by combining the two for loops, to take advantage of only 
// having to go through the for loop and access all the nodes once, rather then going
// through the whole thing just to reset it to the start after the first loop.
void level_4_opt(node** head, int length){
    // malloc a contiguous block of memory on the heap
    // that is big enough for the entire list.
    node * new_list = malloc(sizeof(node) * length);

    // go through the list and make a copy of all the 
    // nodes and place them into the contiguous block in order
    node * n = *head;
    int i;
    for(i = 0 ; i < length ; ++i) {
        
        node copy = { n->value, NULL };
        new_list[i] = copy;

        // link each node in the new list **************
        new_list[i].next = &new_list[i+1];
        // free the old nodes **************************
        node* free_me = n;
        n = n->next;
        free(free_me);
    }

    // free the last node of the old list
    free(n);

    // point head at the new packed list
    *head = new_list;

}

/* DO NOT MODIFY THE FUNCTION THAT FOLLOWS */

void addFront(data * s,  node ** head) {
	if (head == 0 ) return;
	if (s == 0 ) return; 
	
    //allocate memory for storing the node 
    node *n = ( node *)malloc(sizeof( node));
    //make sure that the memory was allocated,
    //if not, just quit
    if (n == NULL) return;
    n->value = *s;
    
    n->next = (*head);
    (*head) = n;
}
