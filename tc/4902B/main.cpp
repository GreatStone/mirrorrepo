#include <iostream>

using namespace std;

class Starport{
    public :
    double getExpectedTime(int N, int M)
    {
        int gnm = gcd (N,M);

    }
    int gcd(int a,int b)
    {
        return (b>0)?gcd(b,a%b):a;
    }
};

int main()
{
}
