#ifndef Q13_H
#define Q13_H

#define QUIT "." //end the loop call with user input as '.'
#define EOF "EOF" //end the loop call with user input as ''EOF''
#define SIZE 255

/*
* Struct Node to be used for ''LinkedList'' behavior
*/
struct Node {
	char data[SIZE];
	struct Node* next;
};

//Giving Node a new name
typedef struct Node node;
typedef struct Node* NodePointer;

//Function declarations
void insert_dictionary_order(char string[], NodePointer* head);
void print_list(NodePointer head);

#endif