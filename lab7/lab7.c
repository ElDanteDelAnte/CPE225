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
typedef unsigned char BYTE;

typedef struct _buffer
  {
    struct _buffer* link;
    BYTE data[256];
  } BUFFER;

typedef struct _pool
  {
    BUFFER* link;
    int nbuffers;
    int size;
  } POOL;
  
typedef struct _queue
  {
    BUFFER* head;
    BUFFER* tail;
  } QUEUE;



void init_pool(POOL* p, int nbuffers, int size);
BUFFER* getbuffer(POOL* pp);
void freebuffer(POOL* pp, BUFFER* bp);
void initqueue(QUEUE* qp);
void enqueue(QUEUE* qp, BUFFER* bp);
BUFFER* dequeue(QUEUE* qp);



//MAIN
int main()
  {
	
  }

//PART1
/*
struct BYTE{
	unsigned char;
};
*/

//PART2
/*
struct BUFFER{
    struct BUFFER *link;
    BYTE data[256]; // Data area
};
*/

//PART3
/*
struct POOL{
    BUFFER* link;
    int nbuffers;
    int size;
};
*/
//PART4

/**
 * Initializes a buffer pool using malloc.
 * 
 * @param p Pointer to the buffer pool.
 * @param nbuffers Number of buffers in the pool.
 * @param size Size of the buffers in bytes.
 */
void init_pool(POOL* p, int nbuffers, int size)
  {
    BUFFER* last = NULL;
    BUFFER* currB;
    
    //allocate buffers
    for (int i = 0; i < nbuffers; i++)
      {
        currB = (BUFFER*) malloc(size);
        currB->link = last;
        last = currB;
	  }
	
	//initialize pool struct
	p->link = currB;
	p->nbuffers = nbuffers;
	p->size = size;
  }

/**
 * Retrieves the next buffer from a pool and 
 * increments the pool pointer.
 * 
 * @param pp Pointer to the pool.
 * @return Pointer to next buffer.
 */
BUFFER* getbuffer(POOL* pp)
  {
	BUFFER* currB = pp->link;    //get curr buff
	BUFFER* nextB = currB->link; //get next buff
	pp->link = nextB;            //inc pool pointer
	return currB;
  }

/**
 * Returns a buffer back into the pool.
 * 
 * @param pp Pointer to pool that buffer is being freed to.
 * @param bp Pointer to buffer to be freed.
 */
void freebuffer(POOL* pp, BUFFER* bp)
  {
    bp->link = pp->link;  //link new to current
    pp->link = bp;	      //make new the current
  }

//PART5
/*
struct QUEUE{
    BUFFER *head;
    BUFFER *tail;
};
*/
//PART6
/**
 * Initializes an empty queue.
 * 
 * @param qp Pointer to queue to initialize.
 */
void initqueue(QUEUE *qp)
  {
    qp->head = NULL;
    qp->tail = NULL;
  }

/**
 * Enques a buffer to the queue.
 * 
 * @param qp Pointer to queue.
 * @param bp Buffer to be queued.
 */
void enqueue(QUEUE *qp, BUFFER *bp)
  {
    //empty queue case
    if (qp->head == NULL)
      {
        qp->head = bp;
        qp->tail = bp;
        //don't need to change buffer link
        //because dequeue() re-inits queue
        //in last element case
      }
    else
      {
        qp->tail->link = bp;  //link tail to new buffer
        qp->tail = bp;        //update tail
      }
  }

/**
 * Dequeue a buffer from the queue.
 * 
 * @param qp Pointer to queue
 * @return Pointer to dequeued buffer.
 */
BUFFER *dequeue(QUEUE *qp)
  {
    //empty queue case
    if (qp->head == NULL) return NULL;
    
    //last element case
    if (qp->head == qp->tail)
      {
        BUFFER* last = qp->head;
        initqueue(qp);
        return last;
      }
    
    //else
    BUFFER* nextB = qp->head;  //get next buffer
    qp->head = nextB->link;    //inc queue head
    return nextB;
  }
//PART7
