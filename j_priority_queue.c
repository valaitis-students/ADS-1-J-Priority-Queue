#include <stdlib.h>
#include <stdio.h>
#include "j_priority_queue.h"

PQueue *PQ_Create()
{
	PQueue *pq = ( PQueue* ) malloc( sizeof( PQueue ) );
	pq->size = 0;
	pq->first = NULL;
	
	return pq;
}

int PQ_IsEmpty( PQueue *pq )
{
	return pq->size <= 0;
}

int PQ_IsFull( PQueue *pq )
{
	PQNode *entry = ( PQNode* ) malloc( sizeof( PQNode ) );
	
	int bNoMemory = entry == NULL;	// malloc failed, no more ram available
	
	free( entry );
	
	return bNoMemory;
}

int PQ_PeekTopIndex( PQueue *pq )
{
	if ( PQ_IsEmpty( pq ) )
		return -1;
	
	int highest_priority = -100000;
	int index = 0;
	
	int i = 0;
	for ( PQNode *node = pq->first; node != NULL; node = node->next )	// loop through all entries and find the first one with the highest priority
	{
		int current_priority = node->priority;
		
		if ( current_priority > highest_priority )
		{
			highest_priority = current_priority;
			index = i;
		}
		
		++i;
	}
	
	return index;
}

PQData PQ_PeekTopData( PQueue *pq )
{
	if ( PQ_IsEmpty( pq ) )
		return 0;
	
	int index = PQ_PeekTopIndex( pq );
	
	int i = 0;
	for ( PQNode *node = pq->first; node != NULL; node = node->next )
	{
		if ( i == index )
			return node->data;
		
		++i;
	}
			
	return 0;
}

int PQ_PeekTopPriority( PQueue *pq )
{
	if ( PQ_IsEmpty( pq ) )
		return 0;
	
	int index = PQ_PeekTopIndex( pq );
	
	int i = 0;
	for ( PQNode *node = pq->first; node != NULL; node = node->next )
	{
		if ( i == index )
			return node->priority;
		
		++i;
	}
			
	return 0;
}

int PQ_Enqueue( PQueue *pq, PQData data, int priority )
{
	if ( PQ_IsFull( pq ) )
		return 0;
	
	PQNode *entry = ( PQNode* ) malloc( sizeof( PQNode ) );
	entry->priority = priority;
	entry->data = data;
	entry->next = NULL;

	if ( PQ_IsEmpty( pq ) )
	{
		pq->first = entry;
		pq->size = 1;
		
		return 1;
	}
	
	for ( PQNode *node = pq->first; node != NULL; node = node->next )
	{	
		if ( node->next == NULL )
		{
			node->next = entry;
			pq->size++;
			
			return 1;
		}
	}
	
	return 0;
}

void PQ_Dequeue( PQueue *pq )
{
	if ( PQ_IsEmpty( pq ) )
		return;
		
	int index = PQ_PeekTopIndex( pq );
	if ( index == 0 )
	{
		PQNode *node = pq->first;
		pq->first = node->next;
		
		free( node );
		pq->size--;
			
		return;	
	}
	
	int i = 0;
	for ( PQNode *node = pq->first; node != NULL; node = node->next )
	{
		if ( i == index - 1 )	// find the node that is before the node which we need to dequeue
		{
			PQNode *node_dequeue = node->next;
			node->next = node_dequeue->next;
			
			free( node_dequeue );
			pq->size--;
			
			return;
		}
		
		++i;
	}
}

int PQ_GetSize( PQueue *pq )
{
	return pq->size;
}

void PQ_MakeEmpty( PQueue *pq )
{
	while ( pq->size > 0 )
	{
		PQ_Dequeue( pq );
	}
}

void PQ_Destroy( PQueue *pq )
{
	PQ_MakeEmpty( pq );
	
	free( pq );
}
