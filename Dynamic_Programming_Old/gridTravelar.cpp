#include <bits/stdc++.h>
using namespace std;
map<string, int> memo = {};

// int gridTravelar(int m, int n)
// {
//     if (m == 1 && n == 1)
//         return 1;
//     if (m == 0 || n == 0)
//         return 0;

//     return gridTravelar(m - 1, n) + gridTravelar(m, n - 1);
// }

int gridTravelar(int m, int n)
{
    string s = to_string(m) + "," + to_string(n);
    if (memo.find(s) != memo.end())
        return memo[s];
    if (m == 1 && n == 1)
        return 1;
    if (m == 0 || n == 0)
        return 0;

    memo[s] = gridTravelar(m - 1, n) + gridTravelar(m, n - 1);
    return memo[s];
}

int main()
{
    cout << gridTravelar(20, 20) << endl;

    for (auto e : memo)
        cout << e.first << "\t" << e.second << endl;

    cout << memo["20,20"] << endl;
}