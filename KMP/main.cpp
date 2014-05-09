#include <iostream>
#include <cstring>
using namespace std;

void getpre (char* s, int* pre)
{
    int len = strlen(s);
    pre[0] = 0;
    pre[1] = 0;
    for (int i = 1; i < len; i++)
    {
        int j = pre[i];
        while (j && s[i] != s[j]) j = pre[j];
        pre[i + 1] = (s[i] == s[j]) ? j+1 : 0;
    }
}

int getsubstr (char* s, char* p)
{
	int pre[100];
	getpre (p,pre);
	int m = strlen (s);
	int n = strlen (p);
	int i,j;
	j = 0;
	for (i = 0; i < m; i++)
	{
		if (s[i] == p[j])
			j++;
		else
			j = pre[j];

		if (j == n)
			return i - n + 1;
	}
	return -1;
}

int main()
{
    char str[100];
    char tmp[100];
    cin >> str;
    cin >> tmp;
    cout << getsubstr(str,tmp);
    return 0;
}
