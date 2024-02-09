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
    for (int i = 0; i < t.size(); i++) {
        char c = t.at(i);
        mp[c]++;
    }

    int i = 0, j = 0, count = mp.size();
    int left = 0, right = s.size() - 1, mini = s.size();
    bool found = false;

    while (j < s.size()) {
        char endChar = s.at(j++);
        if (mp.count(endChar)) {
            mp[endChar]--;
            if (mp[endChar] == 0) count--;
        }

        if (count > 0) continue;

        while (count == 0) {
            char startChar = s.at(i++);
            if (mp.count(startChar)) {
                mp[startChar]++;
                if (mp[startChar] > 0) count++;
            }
        }

        if (j - i < mini) {
            left = i;
            right = j;
            mini = j - i;

            found = true;
        }
    }

    if (!found) cout << "" << endl;
    else {
        cout << s.substr(left - 1, right) << endl;
    }
}

int main() {
    solve("dbaecbbabdcaafbddcabgba", "abbcdc");
    solve("ADOBECODEBANC", "ABC");
    solve("ABOC", "ABC");
    return 0;
}