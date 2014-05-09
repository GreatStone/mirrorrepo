#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

/***********
by GreatStone   2014.03.28
    12281054@bjtu.edu.cn
***********/

typedef struct que{
    int* num;
    int size;
    int len;
    int rear;
}que;

/************
init by GreatStone   2014.03.28
return: int (1 success,0 fail)
args:   que* q, int size
************/
int init (que* q, int size)
{
    q->num = (int*)malloc (size * sizeof (int));
    if (q->num == NULL)
        return 0;
    else
    {
        q->size = size;
        q->len = 0;
        q->rear = -1;
        return 1;
    }
}

/************
push by GreatStone   2014.03.28
return: int (1 success,0 fail)
args:   que* q, int elem
************/
int push (que* q, int elem)
{
    if (q->len == q->size)
        return 0;

    q->len++;
    q->num[(++(q->rear))%q->size] = elem;
    q->rear = q->rear% q->size;
    return 1;
}

/************
pop by GreatStone   2014.03.28
return:
        -1  error , poped element
args:   que* q, int size
************/
int pop (que* q)
{
    if (q->len == 0)
        return -1;

    q->len--;
    return q->num[((q->rear) - q->len + 1 + q->size) % q->size];
}

int main()
{
    int i,j;
    int k,n;
    printf ("please input the k\n");
    scanf ("%d",&k);
    printf ("please input the size of sequence\n");
    scanf ("%d",&n);

    que q;
    init (&q,k);
    for (i = 0; i < k-1; i++)
    {
        push (&q, 0);
        printf("fib[%d] = %d\n",i,0);
    }
    push(&q,1);
    printf("fib[%d] = %d\n",k-1,1);
    for (i = k; i < n; i++)
    {
        int res = 0;
        for (j = (q.rear + 1) % q.size; (j + q.size) % q.size != (q.rear + q.size) % q.size ; j++)
        {
            res += q.num[j%q.size];
        }
        res+=q.num[(q.rear + q.size) % q.size];
        pop(&q);
        push (&q,res);
        printf("fib[%d] = %d\n",i,res);
    }
    return 0;
}
