#include <iostream>
#include <vector>
#include <list>
#include <cstring>
using namespace std;


class PowerOutage{
    private:
    vector<int> from;
    vector<int> to;
    vector<int> val;
    int len;
    public:
    int estimateTimeOut(vector<int> from,vector<int> to,vector<int> val){
        int result;
        int flag[100];
        memset(flag,0,sizeof(flag));
        int i;
        int size = to.size();
        int w = 0;
        for (i = 0; i < size; i++)
        {
            flag[i] = 0;
            w += val[i];
        }
        for (i = 0; i < size; i++)
            flag[to[i]] = 1;
        for (i = 0; i < size; i++)
            flag[from[i]] = 0;

        vector<int> leas;
        for (i = 0; i < 100; i++)
        {
            if(flag[i])
            leas.push_back(i);
        }

        int gh[100];
        int vals[100];
        int has[100];
        memset(gh,0,100*sizeof(int));
        memset(vals,0,100*sizeof(int));
        memset(has,0,100*sizeof(int));
        for (i = 0; i < size; i++)
        {
            gh[to[i]] = from[i];
            has[from[i]] ++;
            vals[to[i]] = val[i];
        }

        int tmpresult = 0;
        for (i = 0; i < leas.size(); i++)
        {
            int tmp = 0;
            int tmpto = leas[i];
            for (;;)
            {
                tmp += vals[tmpto];
                if( gh[tmpto] == 0)
                break;
                tmpto = gh[tmpto];
            }
            if (tmp > tmpresult)
            tmpresult = tmp;
        }
        result = 2*w - tmpresult;
        return result;
    }
};

int main()
{
    int tmp;
    vector<int>from,to,val;
    int n;
    cin>>n;
    int i;
    for(i = 0; i< n; i++)
    {
        cin>>tmp;
        from.push_back(tmp);
    }
    for(i = 0; i< n; i++)
    {
        cin>>tmp;
        to.push_back(tmp);
    }
    for(i = 0; i< n; i++)
    {
        cin>>tmp;
        val.push_back(tmp);
    }
    PowerOutage a;
    cout<<(a.estimateTimeOut(from,to,val));
    return 0;
}
