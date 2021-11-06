#ifndef LINKED__QUEUE__
#define LINKED__QUEUE__

#define True 1
#define False 0

typedef int QData;

typedef struct _node Node;
struct _node {
	QData data;
	Node* next;
};

typedef struct _queue {
	Node* front;
	Node* rear;
}Queue;

void QueueInit(Queue* qp);
int QIsEmpty(Queue* qp);

void Enqueue(Queue* qp, QData data);
QData Dequeue(Queue* qp);
QData QPeek(Queue* qp);

#endif