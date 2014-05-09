#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class BinaryCode{
    public:
    vector<string> decode (string in){
        string result[2];
        char source[100];
        sprintf(source,"%s",in.c_str());
        int len = strlen (source);
        int i;
        char resulta[100];
        char resultb[100];
        resulta[0] = '0';
        resultb[0] = '1';
        resulta[len] = resultb[len] = 0;
        resulta[1] = source[0] - resulta[0] + '0';
        resultb[1] = source[0] - resultb[0] + '0';
    /*    printf("a %d \n",resulta[0]);
        printf("b %d \n",resultb[0]);
        printf("a %d \n",resulta[1]);
        printf("b %d \n",resultb[1]);   */
        if (resulta[1]!='0' && resulta[1]!='1')
        resulta[0] = 0;
        if (resultb[1]!='0' && resultb[1]!='1')
        resultb[0] = 0;
        for (i = 2; i < len; i++)
        {
            resulta[i] = source[i-1] - resulta[i-1] - resulta[i-2] + '0'*2;
            resultb[i] = source[i-1] - resultb[i-1] - resultb[i-2] + '0'*2;
            if (resulta[i]!= '0' && resulta[i] != '1')
            {
                resulta[0] = 0;
            }
            if (resultb[i]!= '0' && resultb[i] != '1')
            {
                resultb[0] = 0;
            }

     /*       printf("a %d \n",resulta[i]);
            printf("b %d \n",resultb[i]);*/
        }
        if (resulta[0])
        {
            result[0] = string(resulta);
        }
        else
        {
            result[0] = string("NONE");
        }
        if(resultb[0])
        {
            result[1] = string(resultb);
        }
        else
        {
            result[1] = string("NONE");
        }
        vector<string> re;
        re.push_back(result[0]);
        re.push_back(result[1]);
        return re;
    }
};

int main()
{
    BinaryCode code;
    string in;
    cin>> in;
    vector<string> na = code.decode(in);
    cout<<na[0]<<na[1];
    return 0;
}
