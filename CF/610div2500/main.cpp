#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int com (int a, int b)
{
    return a > b;
}

void pushvec (vector<int> vec)
{
    int n = vec.size();
    cout << "***********" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << vec[i] << "  ";
    }
    cout << endl << "************" << endl;
}

class DivideByZero{
public:
    int CountNumbers(vector <int> numbers)
    {
        int i;
        for (;;)
        {
            int len = numbers.size ();
            sort (numbers.begin(),numbers.end(),com);
            for (i = 0; i < len; i++)
            {
                for (int j = i+1; j < len; j++)
                {
                    if (numbers[i]>numbers[j])
                        numbers.push_back(numbers[i]/numbers[j]);
                }
            }
            vector<int>::iterator it;
            sort (numbers.begin(),numbers.end(),com);
            it = unique(numbers.begin(),numbers.end());
            pushvec(numbers);
            numbers.erase(it,numbers.end());
            if (len == numbers.size())
                return len;
        }
    }
};

int main()
{
    int n;
    vector <int> in;
    for (;;)
    {
        cin >> n;
        in.clear();
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            in.push_back(tmp);
        }
        DivideByZero e;
        cout << e.CountNumbers(in) << endl;
    }
    return 0;
}
