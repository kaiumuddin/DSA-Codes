#include<bits/stdc++.h>
using namespace std;

class Pair {
public:
    int li;
    int di;
    int val;

    Pair(int li, int di, int val) {
        this->li = li;
        this->di = di;
        this->val = val;
    }
};

class cmp {
public:
    bool operator()(Pair a, Pair b) {
        if (a.val > b.val) return true;
        return false;
    }
};

vector<int> merge(vector<vector<int>>& lists) {
    vector<int> ans;

    priority_queue<Pair, vector<Pair>, cmp> pq; // min heap
    for (int i = 0; i < lists.size(); i++) {
        Pair p(i, 0, lists.at(i).at(0)); // lists[i][0]
        pq.push(p);
    }

    while (pq.size() > 0) {
        Pair top = pq.top();
        pq.pop();

        ans.push_back(top.val);
        top.di++;

        if (top.di < lists.at(top.li).size()) {
            top.val = lists.at(top.li).at(top.di);
            pq.push(top);
        }
    }

    return ans;
}

int main() {
    vector<vector<int> > lists = { {10,20,30,40}, {15,25,50}, {5,12} };
    vector<int> ans = merge(lists);

    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}