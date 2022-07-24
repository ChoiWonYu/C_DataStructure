#include"UsefulHeap.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void HeapInit(Heap* hp, PriorityComp cp)
{
	hp->numOfData = 0;
	hp->comp=cp;
}

int HIsEmpty(Heap* hp)
{
	if(hp->numOfData == 0)return True;
	
	else  return False;
}

int GetParentIdx(int idx)
{
	return idx/2;
}
int GetLChildIdx(int idx)
{
	return idx * 2;
}
int GetRChildIdx(int idx)
{
	return idx * 2 + 1;
}
int GetHiPriChildIdx(Heap* hp, int idx)
{
	if (GetLChildIdx(idx) > hp->numOfData)return 0;
	else if (GetLChildIdx(idx) == hp->numOfData)return GetLChildIdx(idx);
	else
	{
		if (hp->comp(hp->HeapArr[GetLChildIdx(idx)], hp->HeapArr[GetRChildIdx(idx)]) >= 0)
		{
			return GetLChildIdx(idx);
		}
		else return GetRChildIdx(idx);
	}
}

void HInsert(Heap* hp, HData data)
{
	int Idx = ++hp->numOfData;
	while (Idx != 1)
	{
		if (hp->comp(data, hp->HeapArr[GetParentIdx(Idx)])>0)
		{
			hp->HeapArr[Idx] = hp->HeapArr[GetParentIdx(Idx)];
			Idx = GetParentIdx(Idx);
		}
		else break;
	}
	hp->HeapArr[Idx] = data;
	
}
HData HDelete(Heap* hp)
{
	HData rdata = hp->HeapArr[1];
	int ParentIdx = 1;
	int ChildIdx;
	HData ComData = hp->HeapArr[hp->numOfData];
	while (ChildIdx = GetHiPriChildIdx(hp, ParentIdx))
	{
		if (hp->comp(ComData, hp->HeapArr[ChildIdx]) >= 0)
		{
			
			break;
		}
		else {
			hp->HeapArr[ParentIdx] = hp->HeapArr[ChildIdx];
			ParentIdx = ChildIdx;
		}
	}
	hp->HeapArr[ParentIdx] = ComData;
	hp->numOfData -= 1;
	return rdata;
}