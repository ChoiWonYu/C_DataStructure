#include<stdio.h>
#include"Person.h"

int GetSSN(Person *p)
{
    return p->ssn;
}

void showPerInfo(Person *p)
{
    printf("주민등록번호 : %d\n",p->ssn);
    printf("이름 : %s\n",p->name);
    printf("주소 : %s\n",p->addr);
    return;

}

Person *MakePersonData(int ssn,char *name,char *addr)
{
    Person *npp;
    npp=malloc(sizeof(Person));
    npp->ssn=ssn;
    strcpy(npp->name,name);
    strcpy(npp->addr,addr);
    return npp;
}