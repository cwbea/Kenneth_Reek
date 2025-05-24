/*
** A queue implemented with a static array.
** The array size can only be changed by modifying the #define
** and recompiling the program.
*/

#include "queue.h"     // Include the queue interface header
#include <stdio.h>     // For standard I/O (not used here but commonly included)
#include <assert.h>    // For assert() to enforce safety checks

// Define the maximum number of elements that can be in the queue at a time
#define QUEUE_SIZE 100

// Define the actual size of the array (one extra space to distinguish full vs empty)
#define ARRAY_SIZE (QUEUE_SIZE + 1)

/*
** Define the static array that holds the queue values
** along with front and rear index variables
*/
static QUEUE_TYPE queue[ARRAY_SIZE];
static size_t front = 1;  // Points to the front of the queue
static size_t rear  = 0;  // Points to the last inserted item

/*
** insert
**
** Adds a new value to the rear of the queue.
** Checks if the queue is full before inserting.
*/
void insert(QUEUE_TYPE value)
{
    assert(!is_full());  // Make sure queue is not full
    rear = (rear + 1) % ARRAY_SIZE;  // Move rear index forward circularly
    queue[rear] = value;  // Place value in queue
}

/*
** delete
**
** Removes the value at the front of the queue.
** Checks if the queue is empty before removing.
*/
void delete(void)
{
    assert(!is_empty());  // Make sure queue is not empty
    front = (front + 1) % ARRAY_SIZE;  // Move front index forward circularly
}

/*
** first
**
** Returns the value at the front of the queue without removing it.
*/
QUEUE_TYPE first(void)
{
    assert(!is_empty());  // Make sure queue is not empty
    return queue[front];  // Return the front value
}

/*
** is_empty
**
** Returns 1 (true) if the queue is empty, 0 (false) otherwise.
** The queue is empty when front is just ahead of rear in circular indexing.
*/
int is_empty(void)
{
    return (rear + 1) % ARRAY_SIZE == front;
}

/*
** is_full
**
** Returns 1 (true) if the queue is full, 0 (false) otherwise.
** The queue is full when two positions ahead of rear is the front.
*/
int is_full(void)
{
    return (rear + 2) % ARRAY_SIZE == front;
}

