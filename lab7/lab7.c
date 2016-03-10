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
