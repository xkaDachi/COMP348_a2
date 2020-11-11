#include "Q13.h"
#include <stdlib.h>

/*
Receives a word (of type char*)
Inserts is into the right position and in alphabetical order
wordArray: is a string
head: is the a pointer to the 1st node in a linked list
This parameter is a pointer to a pointer because we are passing the address of the linked list to the function,
and the linked list itself is a pointer to the head node in the list.
*/
void insert_dictionary_order(char string[], NodePointer* head) {
    //pointer to a new node to be inserted into linked list
    NodePointer newNode = NULL;
    //pointer to the previous node in the linked list
    NodePointer previous = NULL;
    //pointer to the current node in the linked list
    NodePointer current = *head;

    //create a node on the heap
    newNode = malloc(sizeof(node));
    /*
    check to see if space is available
    if no space on heap, malloc() will return NULL
    */
    if (NULL != newNode) {
        //copy over word to the node
        strcpy(newNode->data, string);
        //figure out where to insert in linked list
        while (NULL != current && strcmp(string, current->data) > 0) {
            //move previous to current
            previous = current;
            //move current to next node
            current = current->next;
        }//end of while
        //insert at beginning of linked list
        if (NULL == previous) {
            newNode->next = current;
            //change the address stored in head
            *head = newNode;
        }//end of if
        else {
            //insert between previous and current
            previous->next = newNode;
            newNode->next = current;
        }//end of else
    }//end of if
}//end of function



//prints the dictionary that is a linkedlist
void print_list(NodePointer head) {
    //for empty list
    if (NULL == head) {
        printf("The Dictionary is empty!\n\n");
        return;
    }
    printf("Dictionary is the following: ");
    //loop through linkedlist
    while (NULL != head) {
        //display each node
        printf("%s -> ", head->data);
        //go to next node
        head = head->next;
    }
    printf("\n\n");
}//end of function