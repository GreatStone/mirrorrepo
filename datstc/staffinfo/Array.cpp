#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "Array.h"

/**********
by GreatStone   2014.03.11
    12281054@bjtu.edu.cn
***********/

/************
newInfo by GreatStone   2014.03.11
return: INFO
args:   char* name, int id, char* post
************/
INFO newInfo (char* sname, int nid,  char* spost)
{
    INFO result;
    sprintf(result.name,sname);
    result.id = nid;
    sprintf(result.post,spost);
    return result;
}

/************
newArray by GreatStone  2014.03.11
return: int(1 suc,0 fail)
args:   ARRAY* source
************/
int newArray(ARRAY* source)
{
    source->num = 0;
    source->pData = NULL;
    source->pData = (INFO*) malloc (INITSIZE * sizeof (INFO));
    if (source->pData != NULL)
    {
        source->size = INITSIZE;
        return 1;
    }
    else
    {
        return 0;
    }
}

/************
pushInfo by GreatStone  2014.03.11
return: int(1 suc,0 fail)
args:   ARRAY* staffs, INFO source
************/
int pushInfo (ARRAY* staffs, INFO source)
{
    if (staffs->num + 1 > staffs->size)
    {
        INFO* tmp;
        tmp = (INFO*)realloc(staffs->pData,(staffs->size + ADDSIZE) * sizeof(INFO));
        if (tmp == NULL)
            return 0;
        staffs->pData = tmp;
        staffs->size += ADDSIZE;
    }
    staffs->pData[staffs->num] = source;
    staffs->num++;
    return 1;
}

/************
getIndex by GreatStone  2014.03.11
return: int (-1 fail)
args:   ARRAY staffs, int id
************/
int getIndex (ARRAY staffs, int nid)
{
    int i;
    int len = staffs.num;
    for (i = 0; i < len; i++)
    {
        if (staffs.pData[i].id == nid)
            return i;
    }
    return -1;
}

/************
deleteInfo by GreatStone  2014.03.11
return: int (1 suc, 0 fail)
args:   ARRAY* staffs, int index
************/
int deleteInfo (ARRAY* staffs, int index)
{
    int i;
    int len = staffs->num;
    if (index < 0 || index >= len)
        return 0;
    for (i = index; i < len-1; i++)
    {
        staffs->pData[i] = staffs->pData[i+1];
    }
    staffs->num--;
    return 1;
}

/************
printInfo by GreatStone  2014.03.11
return: void
args:   ARRAY staffs, int index
************/
void printInfo (ARRAY staffs, int index)
{
    if (index < 0 || index >= staffs.num)
        return;
    printf("\n*************\nID:\t%d\nName:\t%s\nPost:\t%s\n*************\n",staffs.pData[index].id,
           staffs.pData[index].name,staffs.pData[index].post);
}

/************
printall by GreatStone  2014.03.11
return: void
args:   ARRAY staffs
************/
void printall (ARRAY staffs)
{
    int i;
    int len = staffs.num;
    for (i = 0; i < len; i++)
    {
        printInfo(staffs,i);
    }
}
