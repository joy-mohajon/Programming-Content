// target:
// Input : arr[] = {7, 3, 5}
// Output : 12
// 7 ^ 3 = 4
// 3 ^ 5 = 6
// 7 ^ 5 = 2
// Sum = 4 + 6 + 2
//     = 12

#include <bits/stdc++.h>

using namespace std;

int sumOfXOR(vector<int> arr)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int one = 0, zero = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if ((arr[j] & (1 << i)))
                one++;
            else
                zero++;
        }
        ans += ((1 << i) * one * zero);
    }
    return ans;
}

int main()
{
    int n, x;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    cout << sumOfXOR(arr) << endl;

    return 0;
}