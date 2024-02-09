#include <bits/stdc++.h>
using namespace std;

vector<int> createVector()
{
    return vector<int>{1,2,3,4,5};
}

int main()
{
    vector<int> v1{1,2,3,4,5};
    vector<int> v2{};

    
    cout<< v1[0];
    v2 = move(v1);
    cout<< v1[0];
    
}