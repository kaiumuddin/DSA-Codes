#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> mp = {
        {"Chennai", "Bangalore"},
        {"Bombay", "Delhi"},
        {"Goa", "Chennai"},
        {"Delhi", "Goa"},
    };

    map<string, bool> source;

    for (auto it : mp) {
        if (source.count(it.first) == 0) {
            source[it.first] = true;
        }
        source[it.second] = false;
    }

    string src = "";
    for (auto it : source) {
        // cout << it.first << " : " << it.second << endl;
        if (it.second == true) {
            src = it.first;
            break;
        }
    }

    while (true) {
        if (mp.count(src)) {
            cout << src << " -> ";
            src = mp[src];
        }
        else {
            cout << src << ".";
            break;
        }
    }

    return 0;
}