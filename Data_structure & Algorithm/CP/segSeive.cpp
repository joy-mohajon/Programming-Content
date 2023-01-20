#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define maxx 32000

vector<ll>primes;

void seive()
{
    bool is_prime[maxx];
    
    for(int i=0; i<maxx; i++)
        is_prime[i] = true;  

    for(int i=3; i*i<=maxx; i+=2){
        if(is_prime[i]){
            for(int j=i*i; j<=maxx; j+=i)
                is_prime[j] = false;
        }
    }
    primes.push_back(2);

    for(int i=3; i<maxx; i+=2)
        if(is_prime[i]){
            primes.push_back(i);
        }
            

    ///cout << primes.size() << endl;
}

void segSieve(ll l, ll r)
{
    bool is_prime[r-l + 1];

    for(int i=0; i<r-l + 1; i++)
        is_prime[i] = true;

    for(int i=0; primes[i]*primes[i]<=r; i++){
        int current_prime = primes[i];
        ll base = (l/current_prime) * current_prime;
        if(base < l)
            base+=current_prime;
        for(ll j = base; j<=r; j+=current_prime){
            is_prime[j-l] = false;
        }  
        if(base == current_prime)
            is_prime[base-l] = true;   
    }

    for(int i=0; i<r-l+1; i++){
        if(is_prime[i])
            cout << l+i << " ";
    }
    cout << endl;
}

int main()
{
    int n, l, r;
    seive();

    while(cin >> n)
    {
        if(n==-1)
            break;

        cin >> l >> r;
        segSieve(l, r);
    }
    return 0;
}
