#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "binarytree.h"
#include "stack.h"

void print (node* cur)
{
    if (cur->data != '.')
	printf ("%c",cur->data);
}

int main ()
{
	node* tree = NULL;
	for (;;)
	{
		printf("\nInput the number of your command\n");
		printf("\t1.input an extend-preorder array to build a tree\n");
		printf("\t2.output the preorder array of the tree built recently\n");
		printf("\t3.output the midorder array of the tree built recently\n");
		printf("\t4.output the postorder array of the tree built recently\n");
		printf("\t5.output the levelorder array of the tree built recently\n");
		printf("\t6.output the deepin of the tree built recently\n");
		printf("\t7.quit\n");
		int command;
		scanf("%d",&command);
		if (command == 1)
		{
			char tmp[200];
			scanf("%s",tmp);
			tree = buildfromarray (tmp);
			if (tree == NULL)
			{
				printf("\nerror: unavailable input\n\n");
			}
			else
			{
				printf("tree has been built succesefully\n");
			}
		}
		else if (command == 2)
		{
			printf("\n");
			previs (tree,print);
			printf("\n");
		}
		else if (command == 3)
		{
			printf("\n");
			midvis (tree,print);
			printf("\n");
		}
		else if (command == 4)
		{
			printf("\n");
			postvis (tree,print);
			printf("\n");
		}
		else if (command == 5)
		{
		    printf("\n");
		    levelvis(tree,print);
		    printf("\n");
		}
		else if (command == 6)
		{
			printf("\n");
			printf("%d\n", getdeepin(tree));
			printf("\n");
		}
		else if (command == 7)
		{
			break;
		}
		else
		{
			printf("unavailable command\n");
		}
	}
	return 0;
}
