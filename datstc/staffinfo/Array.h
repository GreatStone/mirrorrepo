#ifndef ARRAY_H
#define ARRAY_H

#define INITSIZE 30
#define ADDSIZE 10

/**********
by GreatStone   2014.03.11
    12281054@bjtu.edu.cn
***********/

typedef struct {
    char name[20];
    int id;
    char post[20];
}INFO;

typedef struct {
    INFO* pData;
    int num;
    int size;
}ARRAY;

INFO newInfo (char* sname, int nid,  char* spost);

int newArray(ARRAY* source);

int pushInfo (ARRAY* staffs, INFO source);

int getIndex (ARRAY staffs, int nid);

int deleteInfo (ARRAY* staffs, int index);

void printInfo (ARRAY staffs, int index);

void printall (ARRAY staffs);

#endif
