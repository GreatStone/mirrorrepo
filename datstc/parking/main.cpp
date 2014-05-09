#include <iostream>
#include <cstdio>
using namespace std;
#include "que.h"
#include "park.h"
#include "history.h"

queue wait;
hisbook record;
park P;

void showall()
{
    parknode* cur;
    int i;
    for (i = 0, cur = P.head->pnext; i < P.size; i++, cur = cur->pnext)
    {
        printf("第%d辆车车牌号为%s\n",i+1,cur->id);
    }
}

void menu ()
{
    while(1)
    {
        printf("1.车辆入库\n2.车辆出库\n3.查看消费记录\n4.查看库中所有车辆\n5.退出\n");
        int command;
        scanf("%d",&command);
        char id[20];
        if (command == 1)
        {
            printf("请输入车牌号\n");
            scanf("%s",id);
            in(id,&P,&wait);
        }
        else if (command == 2)
        {
            printf("请输入车牌号\n");
            scanf("%s",id);
            out(id,&P,&record,&wait);
        }
        else if (command == 3)
        {
            printf("请输入车牌号\n");
            scanf("%s",id);
            history* tmp = searchId(&record,id);
            if (tmp != NULL)
                printHis(tmp);
            else
            {
                printf("error\n");
            }
        }
        else if (command == 4)
        {
            showall();
        }
        else if (command == 5)
        {
            break;
        }
        else
        {
            printf("error\n");
        }
    }
}

int main()
{
    init (&wait);
    bookinit (&record);
    parkinit(&P);
    menu();
    return 0;
}
