#include <bits/stdc++.h>

using namespace std;

bool leftShift(int n, int i)
{
    if ((n & (1 << i)))
    {
        return true;
    }
    else
        return false;
}

bool rightShift(int n, int i)
{
    if (((n >> i) & 1))
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int n, i;

    cin >> n >> i;

    cout << "left Shift: " << endl;
    if (leftShift(n, i))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    cout << "Right shift: " << endl;
    if (rightShift(n, i))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
