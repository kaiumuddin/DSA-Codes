#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = { 1,2,5,10,20,50,100,500,1000 };
    int value = 24;

    for (int i = coins.size() - 1; i >= 0; i--)
    {
        if (value >= coins[i])
        {
            cout << coins[i] << " : " << value / coins[i] << endl;
            value %= coins[i];
        }
    }
}
