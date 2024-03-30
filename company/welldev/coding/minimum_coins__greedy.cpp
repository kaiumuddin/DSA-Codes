#include<bits/stdc++.h>
using namespace std;

void getMinCoins2(vector<int>& coins, int value)
{
    vector<int> ans;

    for (int i = coins.size() - 1; i >= 0; i--)
    {
        while (value >= coins[i])
        {
            value -= coins[i];
            ans.push_back(coins[i]);
        }
    }

    cout << "The minimum number of coins is: " << ans.size() << endl;
    cout << "The coins are: " << endl;
    for (int coin : ans)
        cout << coin << endl;
}

void getMinCoins(vector<int>& coins, int value)
{
    int ansMinCoins = 0;
    vector<int> ansCoinsNeeded(coins.size(), 0);

    for (int i = coins.size() - 1; i >= 0; i--)
    {
        if (value >= coins[i])
        {
            ansCoinsNeeded[i] = value / coins[i];
            value %= coins[i];

            ansMinCoins += ansCoinsNeeded[i];
        }
    }

    cout << ansMinCoins << endl;
    for (int i = 0; i < coins.size(); i++)
    {
        cout << coins[i] << " : " << ansCoinsNeeded[i] << endl;
    }
}

int main() {
    vector<int> coins = { 1,2,5,10,20,50,100,500,1000 };
    int value = 8;

    cout << endl;
    getMinCoins(coins, value);
}
