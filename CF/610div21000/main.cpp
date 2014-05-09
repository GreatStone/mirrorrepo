#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class TheMatrix{
public:
    int n,m;
    int chess[200][200];
    int dp[200][200];
    int min (int i,int j)
    {
        return i < j ? i : j;
    }
    int getarea (int ari,int arj)
    {
        int i;
        int cur = dp[ari][arj];
        int res,tmpres;
        tmpres = res = cur;
        for (i = ari+1; i < n; i++)
        {
            if (chess[i][arj] == chess[i-1][arj])
                break;
            cur = min (cur,dp[i][arj]);
            tmpres = (i - ari + 1)*cur;
            if (tmpres > res)
                res = tmpres;
        }
        return res;
    }
    int MaxArea(vector <string> board)
    {
        n = board.size();
        m = board[0].length();
        int i,j,k;
        for (i = 0; i < n; i++)
        {
            const char* ctmp = board[i].c_str();
            for (j = 0; j < m; j++)
            {
                if (ctmp[j] == '0')
                    chess[i][j] = 0;
                else
                    chess[i][j] = 1;
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                dp[i][j] = 1;
                for (k = j; k < m-1; k++)
                {
                    if (chess[i][k+1] != chess[i][k])
                        dp[i][j]++;
                    else
                        break;
                }
            }
        }

        int result = 1;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                int tmpr = getarea(i,j);
                if (tmpr > result)
                result = tmpr;
            }
        }
        return result;
    }
};

int main()
{
    int n;
    string str;
    vector <string> in;
    for(;;)
    {
        cin >> n;
        in.clear();
        TheMatrix e;
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            in.push_back(str);
        }
        cout << e.MaxArea(in) << endl;
    }
    return 0;
}
