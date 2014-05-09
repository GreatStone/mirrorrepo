#include "stdio.h"
#include "string.h"
#include "JoseList.h"

/**********
by GreatStone   2014.03.11
    12281054@bjtu.edu.cn
***********/

int main()
{
    int i,n;
    JOSELIST pers;
    printf("Please enter the size of Josephus\n");
    scanf("%d",&n);
    newJoseList(&pers);
    printf("Plese enter everyone's key in order(from 1 to n)\n");
    for (i = 0; i < n; i++)
    {
        int key;
        scanf("%d",&key);
        PERSON pertmp;
        pertmp.key = key;
        pertmp.order = i+1;
        push(&pers,pertmp);
    }
    printf("Please enter the first key (m)\n");
    int m;
    scanf("%d",&m);
    NODE* cur = pers.tail->next;
    for (;pers.num;)
    {
        NODE* aim = cur;
        for (i = 0; i < m-1; i++)
        {
            aim = aim->next;
        }
        cur = aim->next;
        m = aim->data.key;
        printf("%d  ",aim->data.order);
        del (&pers,aim);
    }
    return 0;
}
