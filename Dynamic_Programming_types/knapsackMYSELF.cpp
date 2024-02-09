#include <bits/stdc++.h>
using namespace std;
int cnt;

//Bounded Knapsack
// int knapsack(int W, vector<int> weights, vector<int> profits, int n)
// {
//     // ++cnt;

//     if (n == 0 || W <= 0)
//         return 0;

//     if (weights[n] > W)
//         return knapsack(W, weights, profits, n - 1);

//     else
//         return max(profits[n] + knapsack(W - weights[n], weights, profits, n - 1), knapsack(W, weights, profits, n - 1));
// }

//Unbounded knapsack
// int knapsack(int W, vector<int> weights, vector<int> profits, int n)
// {
//     if (n == 0 || W < 0)
//         return 0;
//     if (weights[n] > W)
//         return knapsack(W, weights, profits, n - 1);
//     else
//         return max(profits[n] + knapsack(W - weights[n], weights, profits, n), knapsack(W, weights, profits, n - 1));
// }

// Unbounded Knapsack
int knapsack(int W, vector<int> weights, vector<int> profits, int n)
{
    if (W < 0)
        return 0;

    int result = INT_MIN;
    for (int i = 0; i < weights.size(); i++)
    {
        result = max(result + profits[i], knapsack(W - weights[i], weights, profits, n));
    }
    return result;
}

int main()
{
    // cout << knapsack(50, {0, 10, 20, 30}, {0, 60, 100, 120}, 3) << endl; //220
    // cout << knapsack(100, {0, 5, 10, 15}, {0, 10, 30, 20}, 3) << endl; //300
    // cout << knapsack(5, {0, 2, 3, 4}, {0, 5, 6, 7}, 3) << endl;
    // cout << knapsack(50, {0, 10, 20, 30}, {0, 60, 100, 120}, 3) << endl;
    // cout << cnt << endl;
    cout << "Hello world!" << endl;
    return 0;
}