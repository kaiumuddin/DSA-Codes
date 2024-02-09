#include<bits/stdc++.h>
using namespace std;

int getSize(map<string, set<string>>& tree, string man, map<string, int>& result) {
    // if (tree.count(man) == 0) {
    //     result[man] = 0;
    //     return 1;
    // }

    int sz = 0;
    for (string emp : tree[man]) {
        int cs = getSize(tree, emp, result);
        sz += cs;
    }

    result[man] = sz;
    return sz + 1;
}

void findCount(map<string, string>& mp) {
    map<string, set<string>> tree;
    string ceo;

    for (auto it : mp) {
        string emp = it.first;
        string man = it.second;

        if (man == emp) {
            ceo = man;
        }
        else {
            tree[man].insert(emp);
        }
    }

    for (auto i : tree) {
        cout << i.first << " : ";
        for (auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    map<string, int> result;

    cout << getSize(tree, ceo, result) << endl;

    for (auto it : result) {
        cout << it.first << " : " << it.second << endl;
    }
    cout << endl;
}


int main() {
    map<string, string> mp = {
        {"A", "C"},
        {"B", "C"},
        {"C", "F"},
        {"D", "E"},
        {"E", "F"},
        {"F", "F"}
    };

    // for (auto it : mp) {
    //     cout << it.first << " " << it.second << endl;
    // }
    findCount(mp);
    return 0;
}