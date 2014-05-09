#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int is (int n)
{
    string str;
    for ( ; n > 0 ; )
    {
        str += (n % 10) + '0';
        n /= 10;
    }
    char tmp[10];
    sprintf(tmp,"%s",str.c_str());
    int i;
    int len = strlen(tmp);
    int res = 1;
    for (i = 0; i <= len/2; i++)
    {
        if (tmp[i] != tmp[len-i-1])
        {
            res = 0;
            break;
        }
    }
    return res;
}

class PalindromizationDiv2{
public:
    int getMinimumCost(int X)
    {
        int res1,res2;
        res1 = res2 = 0;
        int i;
        for (i = 0; ; i++)
        {
            if (is(X+i))
            {
                res1 = i;
                break;
            }
        }
        for (i = -1; ;i--)
        {
            if (is (X+i))
            {
                res2 = -i;
                break;
            }
        }
        return res1 < res2 ? res1 : res2;
    }
};

int main()
{
    int n;
    PalindromizationDiv2 e;
    for (;;)
    {
        cin >> n;
        cout << e.getMinimumCost(n) << endl;
    }
    return 0;
}
