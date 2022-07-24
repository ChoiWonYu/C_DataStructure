#include<stdio.h>
#include<stdlib.h>
#include"Table.h"
#include"Slot.h"
#include"Person.h"

void TBLInit(Table*tp,HashFunc *f)
{
    tp->hf=f;
    for(int i=0;i<MAX_TBL;i++)
    {
        (tp->tbl[i]).status=EMPTY;
    }
    return;
}
void TBLInsert(Table*tp,Key k,Value v)
{
    int hv=tp->hf(k);
    (tp->tbl[hv]).key=k;
    (tp->tbl[hv]).val=v;
    (tp->tbl[hv]).status=INUSE;
    return; 
}
Value TBLDelete(Table*tp,Key k)
{
    int hv=tp->hf(k);
    if(((tp->tbl[hv]).status)!=INUSE)
    {
        return NULL;
    }
    else
    {
       (tp->tbl[hv]).status=DELETED;
       return (tp->tbl[hv]).val; 
    }
}

Value TBLSearch(Table*tp,Key k)
{
    int hv=tp->hf(k);
    if(((tp->tbl[hv]).status)!=INUSE)return NULL;
    else
    {
        return (tp->tbl[hv]).val;
    }
}
