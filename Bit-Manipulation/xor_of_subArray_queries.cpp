#include <bits/stdc++.h>

using namespace std;

vector<int> xorOfSubArray(vector<int> arr, vector<vector<int>> &queries)
{
    vector<int> pre;

    pre.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        pre.push_back(pre[i - 1] ^ arr[i]);
    }

    int l, r;
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        l = queries[i][0];
        r = queries[i][1];
        if (l == 0)
            ans.push_back(pre[r]);
        else
            ans.push_back(pre[r] ^ pre[l - 1]);
    }
    return ans;
}

int main()
{
    int n, m, x;
    vector<int> arr;
    vector<vector<int>> queries;

    cin >> n;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    cin >> m;
    vector<int> temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> x;
            temp.push_back(x);
        }
        queries.push_back(temp);
        temp.clear();
    }

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << queries[i][j] << endl;
    //     }
    // }

    xorOfSubArray(arr, queries);

    return 0;
}