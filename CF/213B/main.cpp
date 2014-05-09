#include <iostream>

using namespace std;

int mark[100010];
int save[100010];
int main()
{
    int n;
    cin >> n;
    int i;
    int rec = 0;
    int cur = 0;
    for (i = 0; i < n; i++)
    {
        cin >> save[i];
        if (i > 1)
        {
            if (save[i] == save[i-1] + save[i-2])
            {
                mark[i] = 1;
                cur++;
            }
            else if (mark[i-1])
            {
                if (cur > rec)
                    rec = cur;
                cur = 0;
            }
        }
    }
    if (rec||cur)
        cout << (rec>cur?rec:cur)+2;
    else if (n > 1)
        cout << "2";
    else if (n == 1)
        cout << "1";
    else
        cout << "0";
    return 0;
}
