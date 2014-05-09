#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,p,k;
    cin >> n >> p >> k;
    int first = p - k;
    if (first < 1)
    first = 1;
    int last = p+k;
    if (last > n)
    last = n;
    int i;
    if (first != 1)
    cout << "<< " ;
    for (i = first; i <= last; i++)
    {
        if (i == p)
        {
            cout << '(' << i << ") ";
        }
        else
        {
            cout << i << " ";
        }
    }
    if (last != n)
    {
        cout << ">>" << endl;
    }
    return 0;
}
