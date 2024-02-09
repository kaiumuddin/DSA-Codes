#include<bits/stdc++.h>
using namespace std;

void printmp(map<char, int>& mp) {
    if (mp.size() == 0) {
        cout << "Nothing to print" << endl;
        return;
    }
    for (auto it : mp) {
        cout << it.first << ":" << it.second << " ";
    }
    cout << endl;
}

void solve(string s, string t) {

    map<char, int> mp;
    map<char, int> window;
    for (int i = 0; i < t.size(); i++) {
        char c = t.at(i);
        mp[c]++;
    }

    int l = 0, r = 0;
    while (r < s.size()) {
        if (mp.count(s[r])) {
            window[s[r]]++;
        }
        r++;
    }
    printmp(window);
}

int main() {
    // solve("dbaecbbabdcaafbddcabgba", "abbcdc");
    // solve("ADOBECODEBANC", "ABC");
    solve("ABOCJC", "ABC");
    return 0;
}