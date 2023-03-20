#include <stdlib.h>
#include <stdio.h>
#include "j_priority_queue.h"

int main()
{
	PQueue *pq = PQ_Create();
	
	printf( "Size of the queue = %d\n", PQ_GetSize( pq ) );
	
	PQ_Enqueue( pq, 300, 5 );
	PQ_Enqueue( pq, 17, 1 );
	PQ_Enqueue( pq, 19, 2 );
	PQ_Enqueue( pq, 19, 1 );
	PQ_Enqueue( pq, 27, 2 );
	PQ_Enqueue( pq, 200, 6 );
	
	printf( "Size of the queue =  %d\n", PQ_GetSize( pq ) );
	printf( "Top Data is at index = %d, data = %d, priority = %d\n", PQ_PeekTopIndex( pq ), PQ_PeekTopData( pq ), PQ_PeekTopPriority( pq ) );
	
	PQ_Dequeue( pq );
	
	printf( "Top Data is at index = %d, data = %d, priority = %d\n", PQ_PeekTopIndex( pq ), PQ_PeekTopData( pq ), PQ_PeekTopPriority( pq ) );
	
	if ( PQ_IsFull( pq ) )
		return 1;

	PQ_Enqueue( pq, 27, 7 );
	
	printf( "Top Data is at index = %d, data = %d, priority = %d\n", PQ_PeekTopIndex( pq ), PQ_PeekTopData( pq ), PQ_PeekTopPriority( pq ) );	
	printf( "Size of the queue = %d\n", PQ_GetSize( pq ) );
	
	PQ_MakeEmpty( pq );
	
	printf( "Size of the queue = %d\n", PQ_GetSize( pq ) );
	
	PQ_Destroy( pq );

	return 0;
}
