#ifndef J_PRIORITY_QUEUE_H_INCLUDE
#define J_PRIORITY_QUEUE_H_INCLUDE

#include <stdlib.h>
#include <stdio.h>

typedef int PQData;

typedef struct PQNode
{
	int priority;
	PQData data;
	struct node *next;
} PQNode;

typedef struct PQueue
{
	int size;
	PQNode *first;
} PQueue;

// Create an empty priority queue
PQueue* PQ_Create();
// Returns true when priority queue is empty
int PQ_IsEmpty( PQueue *pq );
// Returns true when no more memory can be allocated
int PQ_IsFull( PQueue *pq );
// Adds an entry to the priority queue, returns false if not successful
int PQ_Enqueue( PQueue *pq, PQData data, int priority );
// Removes an entry with highest priority from the priority queue. If there are couple such entries, removes the one which was added the earliest
void PQ_Dequeue( PQueue *pq );
// Returns the index of the highest priority entry, returns -1 if the queue is empty
int PQ_PeekTopIndex( PQueue *pq );
// Returns the data of the highest priority entry, returns 0 if queue is empty
PQData PQ_PeekTopData( PQueue *pq );
// Returns what is the highest priority, returns 0 if queue is empty
int PQ_PeekTopPriority( PQueue *pq );
// Returns the size of the priority queue (number of entries)
int PQ_GetSize( PQueue *pq );
// Makes the priority queue empty
void PQ_MakeEmpty( PQueue *pq );
// Frees the priority queue
void PQ_Destroy( PQueue *pq );

#endif	// J_PRIORITY_QUEUE_H_INCLUDE
