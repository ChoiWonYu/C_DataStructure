#include<stdio.h>
#include<stdlib.h>
#include"Person.h"
#include"Table.h"

int MyHashFunc(int k)
{
    return k%100;
}

int main(void)
{
    Table myTbl;
    Person *np;
    Person*sp;
    Person*rp;
    TBLInit(&myTbl,MyHashFunc);
    np=MakePersonData(20120003,"Lee","Seoul");
    TBLInsert(&myTbl,GetSSN(np),np);

    np=MakePersonData(20120012,"KIM","Jeju");
    TBLInsert(&myTbl,GetSSN(np),np);

    np=MakePersonData(20120049,"Choi","Suwon");
    TBLInsert(&myTbl,GetSSN(np),np);

    sp=TBLSearch(&myTbl,20120003);
    if(sp!=NULL)showPerInfo(sp);

    sp=TBLSearch(&myTbl,20120012);
    if(sp!=NULL)showPerInfo(sp);

    sp=TBLSearch(&myTbl,20120049);
    if(sp!=NULL)showPerInfo(sp);

    rp=TBLDelete(&myTbl,20120003);
    if(rp!=NULL)free(rp);

    rp=TBLDelete(&myTbl,20120012);
    if(rp!=NULL)free(rp);

    rp=TBLDelete(&myTbl,20120049);
    if(rp!=NULL)free(rp);

    return 0;
}