#include"LinkedQueue.h"
#include<stdio.h>
#include<stdlib.h>
void QueueInit(Queue* qp)
{
	qp->front = NULL;
	qp->rear = NULL;
}
int QIsEmpty(Queue* qp)
{
	if (qp->front == NULL && qp->rear == NULL)return True;
	else return False;
}

void Enqueue(Queue* qp, QData data)
{
	Node* np = malloc(sizeof(Node));
	np->data = data;
	if (QIsEmpty(qp))
	{
		np->next = np;
		qp->front = np;
		qp->rear = np;
	}
	else
	{
		qp->rear->next = np;
		qp->rear = np;
	}
	return;
}
QData Dequeue(Queue* qp)
{
	if (QIsEmpty(qp))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	else
	{
		Node* dp = qp->front;
		QData Rdata = dp->data;
		qp->front = qp->front->next;
		free(dp);
		return Rdata;
	}
}
QData QPeek(Queue* qp)
{
	if (QIsEmpty(qp))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	else
		return qp->front->data;
}