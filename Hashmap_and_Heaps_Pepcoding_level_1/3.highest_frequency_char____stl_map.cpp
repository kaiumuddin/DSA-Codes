#include<bits/stdc++.h>
using namespace std;

void highest(string str) {
    map<char, int> mp;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        mp[ch]++;
    }

    int maxFreq = INT_MIN;
    char maxFreqChar = ' ';

    for (auto it : mp) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxFreqChar = it.first;
        }
    }

    cout << maxFreqChar << " : " << maxFreq << endl;
}

int main() {
    highest("kaiumk");
    return 0;
}