#include<bits/stdc++.h>

using namespace std;

long long phi(long long n)
{
    int flag=0;
    long long m = n; 
    double result = (double)n;

    if(m%2==0){
        while(m%2==0){
            m = m / 2;
            flag=1;
        } 
        result = result * (1.0 - (1.0/2.0));
    }

    for(int i=3; m!=1; i+=2){
        if(m%i==0){
            while(m%i==0){
                m = m / i;
                flag=1;
            }
            result = result * (1.0 - (1.0/(double)i));
        }
    }

    if(n==1)
        return 1;
    else if(flag==0)
        return n-1;
    else
        return (long long)result;
}
int main()
{
    long long n;

    while(cin >> n){
        cout << "phi("<<n<<") = " << phi(n) << endl;
    }

    return 0;
}