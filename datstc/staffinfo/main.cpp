#include "stdio.h"
#include "string.h"
#include "Array.h"

/**********
by GreatStone   2014.03.11
    12281054@bjtu.edu.cn
***********/

void add (ARRAY* staffs)
{
    printf("Please enter informations\n");
    INFO source;
    char nametmp[20];
    char posttmp[20];
    int idtmp;
    printf ("Name:\n");
    fflush(stdin);
    scanf ("%s",nametmp);
    printf ("ID:\n");
    scanf ("%d",&idtmp);
    printf ("Post:\n");
    scanf ("%s",posttmp);
    source = newInfo(nametmp,idtmp,posttmp);
    if (pushInfo(staffs,source))
    {
        printf("Added successfully\n");
    }
    else
    {
        printf("Fail to add infomation\n");
    }
    printall(*staffs);
}

void del (ARRAY* staffs)
{
    printf ("Enter the ID need to be deleted\n");
    int id;
    scanf ("%d",&id);
    if (deleteInfo(staffs,getIndex(*staffs,id)))
    {
        printf ("Deleted successfully\n");
    }
    else
    {
        printf ("Fail to delete information");
    }
    printall(*staffs);
}

int main()
{
    ARRAY staffs;
    newArray(&staffs);
    for (;;)
    {
        int com;
        printf("1. Add an information\n2. Delete an information\n3. Print all information\n4. quit\n\n");
        fflush (stdin);
        scanf ("%d",&com);
        if (com == 1)
        {
            add(&staffs);
        }
        else if (com == 2)
        {
            del (&staffs);
        }
        else if (com == 3)
        {
            printall(staffs);
        }
        else if (com == 4)
        {
            break;
        }
        else
        {
            printf("No such a command\n");
        }
    }
    return 0;
}
