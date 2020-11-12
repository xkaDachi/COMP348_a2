#include <stdio.h>
#include <stdlib.h>
#include "selectionsort.h" //#include "selectionsort.h"
#include "selectionsort.h" //#include "selectionsort.h" // included twice

#define QUIT "." //end the loop call with user input as '.'
#define EOF "EOF" //end the loop call with user input as ''EOF''
#define SIZE 255

//									 --------------------------
//									 |     Q9 DECLARATIONS    |
//									 --------------------------
/*
* findmin declaration for Q9
*/
int* findminQ9(int* arr, int size);


//									 --------------------------
//									 |     Q13 DECLARATIONS   |
//									 --------------------------
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

//Initializing Linked list to be empty
NodePointer head = NULL;

//Function declarations
void insert_dictionary_order(char string[]);
void print_list();


//									    	-----------------
//									    	| MAIN FUNCTION |
//									    	-----------------
//----------------------------------------------------------------------------------------------------l
int main() {
    
    //Question Q9
    printf("Question 9: \n");
    int arr[] = { 1, 4, 5, 6, -1 };
    int* m = findminQ9(arr, 5);
    printf("%d", *m); // -1

    printf("\n");
    printf("\n");

   //----------------------------------------------------------------------------------------------------
   //Question 10
   printf("Question 10: \n");
   int i;
   selectionsort(arr, 5);
   for (i = 0; i < 5; i++) 
     printf("%d ", arr[i]);

   printf("\n");
   printf("\n");

   //----------------------------------------------------------------------------------------------------
   //Question 11
   printf("Question 11: \n");
   int arr2[] = { 1, 4, 5, 6, -1 };
   int* aFctPtr = NULL;
   int* aPtr;
   aPtr = selectionsortQ11(arr2, 5, aFctPtr); //Null Pointer
   for (i = 0; i < 5; i++)
       printf("%d ", aPtr[i]);

   printf("\n");

   aFctPtr = &findminQ9;
   aPtr = selectionsortQ11(arr2, 5, aFctPtr); //Non-Null Pointer
   for (i = 0; i < 5; i++)
       printf("%d ", aPtr[i]);

   printf("\n");
   printf("\n");

   //----------------------------------------------------------------------------------------------------
   //Question 12
   printf("Question 12: \n");
   int* dynamicArray;
   dynamicArray = (int*)malloc(sizeof(int)*5);      // allocate 5 ints
   if (dynamicArray == NULL) {
	   printf("Unable to allocate memory for a dynamic array.");
   } else {
   dynamicArray[0] = 1;
   dynamicArray[1] = 4;
   dynamicArray[2] = 5;
   dynamicArray[3] = 6;
   dynamicArray[4] = -1;
   question12Output(dynamicArray, 5);
   }
   //delete/free dynamic array memory on Heap
   free(dynamicArray);

   printf("\n");

   //----------------------------------------------------------------------------------------------------
   //Question 13
   printf("Question 13: \n");
   //stores each word
   char word[SIZE] = { '\0' };
   char input[SIZE] = { '\0' };
   //stores a pointer to the 1st node in the dictionary linked list
   NodePointer head = NULL;
   //keep inserting until user enters "quit"
   while ((0 != strcmp(input, QUIT)) && (0 != strcmp(input, EOF))) {
	   printf("Enter a word to INSERT into linked list (enter '.' or 'EOF' to quit): ");
	   gets(word);
	   strcpy(input, word);
	   char* token = strtok(word, " "); // Extract the first token
	   while (token != NULL) { // loop through the string to extract all other tokens
		   insert_dictionary_order(token);
		   print_list();
		   token = strtok(NULL, " ");
	   }
   }//end of while
    return 0;
}
//----------------------------------------------------------------------------------------------------

//								 ------------------------------
//								 |  Q9 FUNCTION DEFINITIONS   |
//								 ------------------------------
/*
* findminQ9 definition, TO SHOW FOR DEMO
* Q10 and onwards will use the one defined in selection.c (Internal)
* receives an array of integers and returns a pointer to its smallest element
*/
int* findminQ9(int* arr, int size) {
	int smallestAddress = &arr[0]; 
	int smallestValue = arr[0];

	for (int i = 1; i < size; i++) {
		if (arr[i] < smallestValue) {
			smallestAddress = &arr[i];
			smallestValue = arr[i];
		}
	}
	return smallestAddress;
}

//								 ------------------------------
//								 |  Q13 FUNCTION DEFINITIONS  |
//								 ------------------------------
/*
Receives a word (of type char*)
Inserts is into the right position and in alphabetical order
wordArray: is a string
head: is the a pointer to the 1st node in a linked list
This parameter is a pointer to a pointer because we are passing the address of the linked list to the function,
and the linked list itself is a pointer to the head node in the list.
*/
void insert_dictionary_order(char string[]) {
    //pointer to a new node to be inserted into linked list
    NodePointer newNode = NULL;
    //pointer to the previous node in the linked list
    NodePointer previous = NULL;
    //pointer to the current node in the linked list
    NodePointer current = head;

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
            head = newNode;
        }//end of if
        else {
            //insert between previous and current
            previous->next = newNode;
            newNode->next = current;
        }//end of else
    }//end of if
}//end of function

//prints the dictionary that is a linkedlist
void print_list() {
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