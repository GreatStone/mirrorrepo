#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "tree.h"

tree* t;

void build ()
{
    t = newtree();
	printf("please input the edges in this tree with format \"a b\"(without quote) means a is b's father node, where \".\" stands for the null\n");
	printf("(root node can be represented as \". r\")\n");
	printf("input \". .\" to end input\n");
	char a[1];
	char b[1];
	for (;;)
	{
		scanf("%s %s",a,b);
		if (a[0] == '.' && b[0] != '.')
		{
			push (t,newtnode (b[0] ));
		}
		else if (a[0] != '.' && b[0] == '.')
		{
			push (t,newtnode(a[0] ));
		}
		else if (a[0] != '.' && b[0] != '.')
		{
			if (!addtoson (t, a[0], b[0]))
			{
				printf("an error occur when run\n");
				return;
			}
		}
		else
            break;
	}
}

void deep ()
{
	printf("the deepin of the tree you have input is %d\n", deepin (t));
}

int main()
{
	for (;;)
	{
		fflush (stdin);
		printf("please input the number of your command\n");
		printf("\t1.bulid a tree\n");
		printf("\t2.get deepin of the tree you have input recently\n");
		printf("\t3.quit\n");
		int command;
		scanf("%d",&command);
		if (command == 1)
		{
			build();
		}
		else if (command == 2)
			deep();
		else if (command == 3)
			break;
		else
			printf("unavaliable command\n");
	}
    return 0;
}
