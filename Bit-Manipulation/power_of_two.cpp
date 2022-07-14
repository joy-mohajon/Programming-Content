#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    //    32       16      8       4       2       1
    //    100000   10000   1000    100     10      1

    if ((n & (n - 1)))
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true" << endl;
    }
    return 0;
}