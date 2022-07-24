#include"CircularQueue.h"
#include<stdio.h>
int NextIdx(int num)
{
	if (num == QUELEN - 1)return 0;
	else return ++num;
}
void QueueInit(Queue* qp)
{
	qp->front = 0;
	qp->rear = 0;
}
int QIsEmpty(Queue* qp)
{
	if (qp->front == qp->rear)return True;
	else return False;
}

void EnQueue(Queue* qp, Data data)
{
	if (NextIdx(qp->rear) == qp->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	qp->rear = NextIdx(qp->rear);
	qp->QueArr[qp->rear] = data;

}
Data DeQueue(Queue* qp)
{
	if (QIsEmpty(qp))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	else
	{
		qp->front = NextIdx(qp->front);
		return qp->QueArr[qp->front];
	}
}
Data QPeek(Queue* qp)
{
	if (QIsEmpty(qp))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	return qp->QueArr[NextIdx(qp->front)];
}