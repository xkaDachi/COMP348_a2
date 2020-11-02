#pragma once
#include <stdio.h>
#include <stdlib.h> //has functions malloc() and free()
#include <string.h>
#define MAX 256  //maximum characters in the word
#define QUIT "." //end the loop
#define END_OF_STRING '\0'

int getstring(char[], const int);
int getline2(char[], const int);

struct Node {
	char data[MAX];
	struct Node* next;
};

//type definition for "new" data types
typedef struct Node node;
typedef struct Node* NodePointer;

//receives a word (of type char*) 
//and inserts is into the right position
/*
Inserts a word in alphabetical order into a linked list
word2: is a string
head2: is the a pointer to the 1st node in a linked list
This parameter is a pointer to a pointer,
because we are passing the address of the linked list to the function,
and the linked list itself is a pointer to the 1st node in the list.
*/
void insert_dictionary_order(char word2[], NodePointer* head2) {
    //pointer to a new node to be inserted into linked list
    NodePointer newNode = NULL;
    //pointer to the previous node in the linked list
    NodePointer previous = NULL;
    //pointer to the current node in the linked list
    NodePointer current = *head2;

    //create a node on the heap
    newNode = malloc(sizeof(node));
    /*
    check to see if space is available
    if no space on heap, malloc() will return NULL
    */
    if (NULL != newNode) {
        //copy over word to the node
        strcpy(newNode->data, word2);
        //figure out where to insert in linked list
        while (NULL != current && strcmp(word2, current->data) > 0) {
            //move previous to current
            previous = current;
            //move current to next node
            current = current->next;
        }//end of while
        //insert at beginning of linked list
        if (NULL == previous) {
            newNode->next = current;
            //change the address stored in head
            *head2 = newNode;
        }//end of if
        else {
            //insert between previous and current
            previous->next = newNode;
            newNode->next = current;
        }//end of else
    }//end of if
}//end of function

//prints the list
//displays the linked list
void print_list(NodePointer current) {
    //for empty list
    if (NULL == current) {
        printf("The linked list is empty!\n\n");
        return;
    }
    printf("linked list items: ");
    //loop through list
    while (NULL != current) {
        //display each node
        printf("%s -> ", current->data);
        //go to next node
        current = current->next;
    }
    printf("\n\n");
}//end of function














/*
  This function reads characters from the input steam,
  and stores the characters in a string,
  and adds a null character ('\0') after the last character in the string.
  It will read up to size-1 number of characters.
  And will read until the end of file, newline, blank space, or tab.
  And will leave the rest of the characters on the input stream.
  Warning: If the string array has less than size number of characters,
  this may crash the program, or write over memory!
  If there are no characters added to the string, a 0 is returned.
  string: An array of characters, with size number of elements.
  size: The number of characters in the string array.
  returns: The number of characters read into the string.
*/

int getstring(char string[], const int size) {
    int index = 0;
    char character = 'z';
    //get input from the user
    for (index = 0; index < size - 1; index++) {
        character = getchar();
        //check for end of file
        if (EOF == character)
            break;
        //check for end of line
        if ('\n' == character)
            break;
        //check for space
        if (' ' == character)
            break;
        //check for a tab
        if ('\t' == character)
            break;
        string[index] = character;
    }
    //add the null character
    string[index] = END_OF_STRING;
    return index; //number of characters in the string
}

/*
  This function reads characters from the input steam,
  and stores the characters in a string,
  and adds a null character ('\0') after the last character in the string.
  It will read up to size-1 number of characters.
  And will read until the end of file or newline.
  And will remove the rest of the characters from the input steam.
  Warning: If the string has less than size number of characters,
  this may crash the program, or write over memory!
  If there are no characters added to the string, a 0 is returned.
  string: An array of characters, with size number of elements.
  size: The number of characters in the string array.
  returns: The number of characters read into the string.
*/

int getline2(char string[], const int size) {
    int index = 0;
    char character = 'z';
    //get input from the user
    for (index = 0; index < size - 1; index++) {
        character = getchar();
        //check for end of file
        if (EOF == character)
            break;
        //check for end of line
        if ('\n' == character)
            break;
        string[index] = character;
    }
    //add the null character
    string[index] = END_OF_STRING;

    //remove the rest of the characters from input stream
    while (('\n' != character) && (EOF != character)) {
        character = getchar();
    }

    return index; //number of characters in the string
}