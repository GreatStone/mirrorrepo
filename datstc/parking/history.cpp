#include <stdio.h>
#include <time.h>

void bookinit (hisbook* book)
{
    book->size = 0;
    book->head = (history*) malloc (sizeof(history));
    book->tail = (history*) malloc (sizeof(history));
    book->head->ppre = book->tail->pnext = NULL;
    book->head->pnext = book->tail;
    book->tail->ppre = book->head;
}

void hisinit (history* his)
{
    his->size = 0;
    his->head = (info*) malloc (sizeof(info));
    his->tail = (info*) malloc (sizeof(info));
    his->head->ppre = his->tail->pnext = NULL;
    his->head->pnext = his->tail;
    his->tail->ppre = his->head;
}

        hisinit(aim);
        aim->ppre = book->tail->ppre;
        aim->pnext = book->tail;
        book->tail->ppre = aim;
        book->size++;
    pushinfo(aim,source);
{
    int i;
    history* aim = NULL;
    history* cur;
    for (i = 0, cur = book->head->pnext; i < book->size; i++)
    return aim;

}
{
    printf("\t进入车库时间: %s\n",ctime((const time_t*)&source->login));
    printf("\t本次消费金额: %d\n",source->charge);
}
{
    int i;
    printf("车牌号: %s\n",source->id);
    info* cur;
    for (cur = source->head->pnext, i = 1; i <= source->size; i++, cur = cur->pnext)
    {
        printf("第%d单消费\n",i);
        printInfo(cur);
    }
}