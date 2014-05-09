#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int i,j;
    int fl[200];
    for (i = 0; i < 100; i++)
    {
        fl[i] = 1;
    }
    cin >> n;
    int l,r;
    int l1,r1;
    cin >> l1 >> r1;
    for(i = 1; i < n; i++)
    {
        cin >> l >> r;
        for (j = l; j < r; j++)
        {
            fl[j] = 0;
        }
    }
    int sum = 0;
    for (i = l1; i < r1; i++)
    {
        if (fl[i])
            sum++;
    }
    cout << sum << endl;
    return 0;
}
