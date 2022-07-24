#ifndef TABLE__H__
#define TABLE__H__

#include"Slot.h"

#define MAX_TBL 100

typedef int (*HashFunc)(Key k);

typedef struct _table
{
    HashFunc hf;
    Slot tbl[MAX_TBL];

}Table;

void TBLInit(Table*tp,HashFunc *f);
void TBLInsert(Table*tp,Key k,Value v);
Value TBLDelete(Table*tp,Key k);
Value TBLSearch(Table*tp,Key k);

#endif
