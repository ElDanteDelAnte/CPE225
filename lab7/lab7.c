//Sean Reddell
//Shiv Sulkar
//CPE225
//Lab 7

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//DECLARATIONS
void init_pool(POOL *p, nbuffers, size);
BUFFER * getbuffer(POOL *pp);
void freebuffer(POOL *pp, BUFFER *bp);
void initqueue(QUEUE *qp);
void enqueue(QUEUE *qp, BUFFER *bp);
BUFFER *dequeue(QUEUE *qp);


//VARIABLES



//MAIN
int main()
  {
	//create the pool
	POOL pool;
	POOL* poolptr;
	//initialize the pool
	init_pool(poolptr, 3, sizeof(BUFFER));
	//get the 3 BUFFERS
	BUFFER* bufferptr1 = getbuffer(poolptr);
	BUFFER* bufferptr2 = getbuffer(poolptr);
	BUFFER* bufferptr3 = getbuffer(poolptr);
	//set PAYLOAD values
	bufferptr1->data = (BYTE*)"PAYLOAD1";
	bufferptr2->data = (BYTE*)"PAYLOAD2";
	bufferptr3->data = (BYTE*)"PAYLOAD3";
	/***************************************************************************************/
	//Create the QUEUE
	QUEUE queue;
	QUEUE* queueptr;
	//initialize queue
	initqueue(queueptr);
	//enqueue the 3 buffers
	enqueue(queueptr,bufferptr1);
	enqueue(queueptr,bufferptr2);
	enqueue(queueptr,bufferptr3);
	//quick test for freebuffer
	freebuffer(poolptr,bufferptr3);
	BUFFER* removedBufferPtr = dequeue(queueptr);
	char removedData[] = (char*)removedBufferPtr->data; 
	//Print the contents of the dequeued BUFFER
	printf("This payload was dequeued:, %s \n", removedData);

  }

//PART1
struct BYTE{
	unsigned char;
};

//PART2
struct BUFFER{
    struct BUFFER *link;
    BYTE data[256]; /* Data area */
};

//PART3
struct POOL{
    BUFFER *link;
    int nbuffers;
    int size;
};

//PART4
void init_pool(POOL *p, nbuffers, size){
    BUFFER *
	p = (POOL*)malloc(nbuffers*size);
	BUFFER linkedList[nbuffers];
}

BUFFER * getbuffer(POOL *pp){
	BUFFER* currentBuffer = *pp.link;
	return currentBuffer;
}

void freebuffer(POOL *pp, BUFFER *bp){
	bp.link=pp;
    pp.link=bp;	
}

//PART5
struct QUEUE{
    BUFFER *head;
    BUFFER *tail;
};

//PART6
void initqueue(QUEUE *qp){
	
}

void enqueue(QUEUE *qp, BUFFER *bp){
	
}

BUFFER *dequeue(QUEUE *qp){
	
}
//PART7
