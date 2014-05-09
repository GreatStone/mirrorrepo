#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#include "business.h"
#include "queue.h"

/***********
by GreatStone   2014.04.01
    12281054@bjtu.edu.cn
***********/
business fund;      //accumulation fund business
business bankcd;    //bank card
business ficcd;     //financial card
int count;

void deal (int command)
{
    count++;
    int i;
    if (command == 1)
    {
        pushperson (&fund,count);
        printf("获得号码为%d,在1号窗口等待\n",count);
    }
    else if (command == 2)
    {
        printf("获得号码为%d，在%d号窗口等待\n",count,pushperson(&bankcd,count) + 2);
    }
    else
    {
        int minindex = 0;
        for (i = 1; i < ficcd.num; i++)
        {
            if (ficcd.windows[i].size < ficcd.windows[minindex].size)
                minindex = i;
        }
        if (ficcd.windows[minindex].size == 0)
        {
            printf("获得号码为%d,在%d号窗口等待\n",count,pushperson (&ficcd,count) + 5);
        }
        else
        {
            int min2 = 0;
            for (i = 1; i < bankcd.num; i++)
            {
                if (bankcd.windows[i].size < bankcd.windows[min2].size)
                    min2 = i;
            }
            if (bankcd.windows[min2].size == 0)
            {
                printf("获得号码为%d，在%d号窗口等待\n", count, pushperson (&bankcd,count) + 2);
            }
            else
            {
                printf("获得号码为%d，在%d号窗口等待\n", count, pushperson (&ficcd, count) + 5);
            }
        }
    }
}

void end ()
{
    printf("请输入要完成业务的窗口号码(1~6)\n");
    int win;
    scanf("%d",&win);
    if (win < 1)
    {
        printf("error\n");
    }
    else if (win == 1)
    {
        printf("%d号顾客的业务完成\n",popperson(&fund,0));
    }
    else if (win > 1 && win <= 4)
    {
        printf("%d号顾客的业务完成\n",popperson(&bankcd, win - 2));
    }
    else if (win > 4 && win <= 6)
    {
        printf("%d号顾客的业务完成\n", popperson (&ficcd, win - 5));
    }
    else
    {
        printf("error\n");
    }
}

void display ()
{
    int i,j;
    printf("1号窗口有%d个顾客在等待\n",fund.windows[0].size);
    node* cur;
    for (i = 0, cur = fund.windows[0].head->pnext; i < fund.windows[0].size; i++,cur = cur->pnext)
    {
        printf("\t%d号顾客在当前队列\n",cur->id);
    }

    for (i = 0; i < bankcd.num; i++)
    {
        printf("%d号窗口有%d个顾客在等待\n",i + 2, bankcd.windows[i].size);
        for (j = 0, cur = bankcd.windows[i].head->pnext; j < bankcd.windows[i].size; j++, cur = cur->pnext)
        {
            printf("\t%d号顾客在当前队列\n",cur->id);
        }
    }
    for (i = 0; i < ficcd.num; i++)
    {
        printf("%d号窗口有%d个顾客在等待\n",i + 5, ficcd.windows[i].size);
        for (j = 0, cur = ficcd.windows[i].head->pnext; j < ficcd.windows[i].size; j++, cur = cur->pnext)
        {
            printf("\t%d号顾客在当前队列\n",cur->id);
        }
    }
}

void menu ()
{
    for (;;)
    {
        printf("请输入需要执行的命令\n");
        printf("1.办理公积金业务\n2.办理银行卡业务\n3.办理理财卡业务\n4.指定窗口业务完成\n5.显示当前窗口状态\n6.退出\n");
        int command;
        scanf("%d",&command);
        if (command == 1 || command == 2 || command == 3)
        {
            deal(command);
        }
        else if (command == 4)
        {
            end();
        }
        else if (command == 5)
        {
            display();
        }
        else if (command == 6)
        {
            return;
        }
        else
        {
            printf("error\n");
        }
    }
}

int main()
{
    count = 0;
    init (&fund,1);
    init (&bankcd,3);
    init (&ficcd,2);
    menu();
    return 0;
}
