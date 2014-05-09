#include "stdio.h"
#include "string.h"

char save[1000000];
int is[1000000];

int in (char c)
{
	return c-'0';
}

int main ()
{
	scanf("%s",save);
	int i,j;
	int len = strlen(save);
	for (i = 0; i < len-1; i++)
	{
		if (in(save[i]) + in(save[i+1]) == 9)
			is[i] = 1;
	}
	long long int tmplen;
	long long int result = 0;
	for (i = 0; i < len-1; )
	{
		tmplen = 0;
		if (is[i] == 0)
			i++;
		else
		{
			for (;is[i] == 1 && i < len-1;)
			{
				tmplen++;
				i++;
			}
			if (tmplen == 2)
				result += 1;
			else
				result += tmplen/2+tmplen%2;
		}
	}
	printf("%I64d\n", result);
	return 0;
}
