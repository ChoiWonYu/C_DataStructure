#ifndef __USEFUL_HEAP_
#define __USEFUL_HEAP_

#define True 1
#define False 0
#define HEAPLEN 100

typedef char HData;
typedef int(*PriorityComp)(HData d1, HData d2);

typedef struct _heap {
	PriorityComp comp;
	int numOfData;
	HData HeapArr[HEAPLEN];
}Heap;

void HeapInit(Heap* hp, PriorityComp cp);

int HIsEmpty(Heap* hp);

int GetParentIdx(int idx);
int GetLChildIdx(int idx);
int GetRChildIdx(int idx);
int GetHiPriChildIdx(Heap*hp, int idx);
void HInsert(Heap* hp, HData data);
HData HDelete(Heap *hp);

#endif