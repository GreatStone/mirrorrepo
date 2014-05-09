#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
using namespace std;

class Time {
    public:
    string whatTime (int cur){
        int hour,min,sec;
        hour = cur / 3600;
        cur %= 3600;
        min = cur / 60;
        sec = cur % 60;
        char tmp[200];
        sprintf(tmp,"%d:%d:%d",hour,min,sec);
        return string(tmp);
    }
};

int main ()
{
    int sec;
    cin >> sec;
    Time newtime;
    cout << newtime.whatTime(sec);
}
