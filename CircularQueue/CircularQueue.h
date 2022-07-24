#ifndef CIRCULAR__QUEUE__
#define CIRCULAR__QUEUE__

#define True 1
#define False 0

#define QUELEN 100
typedef int Data;

typedef struct _queue {
	int front;
	int rear;
	Data QueArr[QUELEN];
}Queue;

void QueueInit(Queue* qp);
int QIsEmpty(Queue* qp);

void EnQueue(Queue* qp,Data data);
Data DeQueue(Queue* qp);
Data QPeek(Queue* qp);

#endif