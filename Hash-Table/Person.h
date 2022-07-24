#ifndef PERSON__H__
#define PERSON__H__

#define STR_LEN 50

typedef struct _person
{
    int ssn; //주민등록번호
    char name[STR_LEN]; //이름
    char addr[STR_LEN];//주소
}Person;

int GetSSN(Person *p);

void showPerInfo(Person *p);

Person *MakePersonData(int ssn,char *name,char *addr);

#endif