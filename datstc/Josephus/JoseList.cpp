#include "stdlib.h"
#include "JoseList.h"

/**********
by GreatStone   2014.03.11
    12281054@bjtu.edu.cn
***********/

/************
newJoseList by GreatStone   2014.03.11
return: void
args:   JOSELIST* source
************/
void newJoseList (JOSELIST* source)
{
    source->tail = NULL;
    source->num = 0;
}

/************
push by GreatStone  2014.03.11
return: void
args:   JOSELIST* list, PERSON source
*************/
void push (JOSELIST* list,PERSON source)
{
    NODE* nodetmp = (NODE*) malloc(sizeof(NODE));
    nodetmp->data = source;
    if (list->tail == NULL)
    {
        list->tail = nodetmp;
        nodetmp->next = nodetmp;
        list->num = 1;
        return;
    }
    NODE* head = list->tail->next;
    list->tail->next = nodetmp;
    nodetmp->next = head;
    list->tail = nodetmp;
    list->num++;
}

/************
del by GreatStone  2014.03.11
return: void
args:   JOSELIST* list, NODE* aim
*************/
void del (JOSELIST* list, NODE* aim)
{
    if (list->num == 1)
    {
        free (aim);
        list->tail = NULL;
        list->num = 0;
        return;
    }
    NODE* pre = aim;
    for ( ; pre->next != aim; pre = pre->next)
        ;
    pre->next = aim->next;
    free(aim);
    list->num--;
}
