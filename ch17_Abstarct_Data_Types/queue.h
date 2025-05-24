/*
** Interface for a queue module
*/

#include <stdlib.h>     // For size_t

// Define the type of value stored in the queue
#define QUEUE_TYPE int

/*
** create_queue
** 
** Creates a queue with a maximum size specified by the user.
** This function is relevant only for the dynamically allocated array implementation.
**
** Parameters:
** - size: the maximum number of elements the queue can hold
*/
void create_queue(size_t size);

/*
** destroy_queue
**
** Frees any memory used by the queue.
** This is used in linked list and dynamic array implementations.
*/
void destroy_queue(void);

/*
** insert
**
** Adds a new value to the rear (back) of the queue.
**
** Parameters:
** - value: the value to insert into the queue
*/
void insert(QUEUE_TYPE value);

/*
** delete
**
** Removes the front value from the queue and discards it.
*/
void delete(void);

/*
** first
**
** Returns the value at the front of the queue without removing it.
**
** Returns:
** - the first (front) value in the queue
*/
QUEUE_TYPE first(void);

/*
** is_empty
**
** Checks if the queue is empty.
**
** Returns:
** - 1 (true) if the queue is empty
** - 0 (false) otherwise
*/
int is_empty(void);

/*
** is_full
**
** Checks if the queue is full (for fixed-size implementations).
**
** Returns:
** - 1 (true) if the queue is full
** - 0 (false) otherwise
*/
int is_full(void);

