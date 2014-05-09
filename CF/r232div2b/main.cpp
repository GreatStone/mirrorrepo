#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long int

int main()
{
    ll n,l,r;
    int cas;
    ll i;
    cin >> cas;
    for (i = 0; i < cas; i++)
    {
        cin >> n >> l >> r;
        ll k = n / l;
        if (n < l)
        cout << "No" << endl;
        else if (n >= k*l && n <= k*r)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
