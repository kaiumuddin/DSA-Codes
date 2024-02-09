#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> mp;
    mp.insert({ "sakib al hasan", 75 });
    mp.insert({ "tamim iqbal", 19 });
    mp.insert({ "shamim", 79 });

    mp["kaium"] = 100;

    // for (auto it : mp) {
    //     cout << it.first << " " << it.second << endl;
    // }

    // for (auto it = mp.begin(); it != mp.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }

    // cout << mp["shamima"] << endl;

    if (mp.count("akib") > 0) cout << "Akib ace" << endl;
    else cout << "Akib nai" << endl;
    return 0;
}