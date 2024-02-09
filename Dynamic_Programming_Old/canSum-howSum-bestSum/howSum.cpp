#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;

map<int, ull> memo = {};

void pMemo()
{
    for (auto e : memo)
        cout << e.first << "\t" << e.second;
}
void pVector(vector<int>* v)
{
    cout << &v;
    for (int i = 0; i < v->size(); i++)
        cout << v->at(i);
}

void pVector(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";

    cout << endl;
}

vector<int>* make(int m = 0, int n = 0)
{
    return new vector<int>(m, n);
}

// bool howSum(int targetSum, vector<int> numbers)
// {
//     static vector<int> seq;

//     if (targetSum == 0)
//     {
//         pVector(seq);
//         seq.clear();
//         return true;
//     }
//     if (targetSum < 0)
//         return false;

//     for (auto num : numbers)
//     {
//         seq.push_back(num);

//         int remain = targetSum - num;

//         if (howSum(remain, numbers) == true)
//             return true;
//         else
//             seq.pop_back();
//     }

//     return false;
// }

bool howSum(int targetSum, vector<int> numbers)
{
    static vector<int> seq;

    if (targetSum == 0)
    {
        pVector(seq);
        return true;
    }
    if (targetSum < 0)
        return false;

    for (auto num : numbers)
    {
        seq.push_back(num);

        int remain = targetSum - num;

        if (howSum(remain, numbers) == true)
            seq.pop_back();
        else
            seq.pop_back();
    }
}

int main()
{
    // system("cls");
    howSum(7, { 3, 1 });
    // howSum(7, { 7, 7 });
    // howSum(7, {5, 3});
    // howSum(7, {3, 2});
    // howSum(7, {7, 5, 4, 3});
    // howSum(7, {4, 2});
    // howSum(6, {3, 2, 1});
    // howSum(8, {3, 5, 2});
    // howSum(6, {7, 6, 3});
}